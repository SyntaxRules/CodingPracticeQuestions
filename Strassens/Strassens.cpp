/************************************************************************
 * Strassens Algorithm for Matrix Multiplication
 * By: Devyn Stott
 * The rest written by Bro Neff
 *   Exact output! hoorray! I am confident that this algorithm will work
 * for any even sized array. Test it and you will be filled with joy!
 ***********************************************************************/
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Matrix
{
private:
   int** mRows;
   int mSize;

public:
   Matrix(int size)
   {
      mRows = new int*[size];
      for (int i = 0; i < size; i++)
      {
         mRows[i] = new int[size];
      }   
      mSize = size;
   }

   Matrix(const Matrix& matrixB)
   {
      mSize = matrixB.getSize();

      mRows = new int*[mSize];
      for (int i = 0; i < mSize; i++)
      {
         mRows[i] = new int[mSize];
         for (int j = 0; j < mSize; j++)
         {
            mRows[i][j] = matrixB.mRows[i][j];
         }
      }
   }

   Matrix& operator=(const Matrix& matrixB)
   {
      for (int i = 0; i < mSize; i++)
      {
         delete [] mRows[i];
      }
      delete [] mRows;

      mSize = matrixB.getSize();

      mRows = new int*[mSize];
      for (int i = 0; i < mSize; i++)
      {  
         mRows[i] = new int[mSize];  
         for (int j = 0; j < mSize; ++j)  
            mRows[i][j] = matrixB.mRows[i][j];  
      }  
      return *this;  
   }  

   ~Matrix()
   {
      for (int i = 0; i < mSize; i++)
      {
         delete [] mRows[i];
      }   
      delete [] mRows;
   }

   int* operator[](int row) const
   {
      return mRows[row];
   }

   int getSize() const
   {
      return mSize;
   }

   void read(istream& is) const
   {
      for (int i = 0; i < mSize; i++)
      {
         for (int j = 0; j < mSize; j++)
         {
            is >> mRows[i][j];
         }      
      }
   }

   void write(ostream& os) const
   {
      for (int i = 0; i < mSize; i++)
      {
         for (int j = 0; j < mSize; j++)
         {
            os << mRows[i][j] << " ";
         }
         os << endl;
      }
   }

   Matrix operator+(Matrix matrixB)
   {
      Matrix result(mSize);
      for (int i = 0; i < mSize; i++)
      {
         for (int j = 0; j < mSize; j++)
         {
            result[i][j] = (*this)[i][j] + matrixB[i][j];
         }
      }
      return result;
   }

   Matrix operator-(Matrix matrixB)
   {
      Matrix result(mSize);
      for (int i = 0; i < mSize; i++)
      {
         for (int j = 0; j < mSize; j++)
         {
            result[i][j] = (*this)[i][j] - matrixB[i][j];
         }
      }
      return result;
   }

   Matrix operator * (Matrix rhs)
   {
      if (this->getSize() == 1 && rhs.getSize() == 1)
      {
         Matrix done(1);
         done[0][0] = mRows[0][0] * rhs[0][0];
         return done;
      }
      if (this->getSize() != rhs.getSize())
      {
         cout << "Error: matrix not the same size!";
         Matrix done(1);
         done [0][0] = -1;
         return done;
      }
      
      // The new Matrix's
      // Matrix A (the lhs matrix)
      Matrix a00(this->getSize()/2.0);
      for (int i = 0; i < this->getSize()/2.0; i++)
         for (int j = 0; j < this->getSize()/2.0; j++)
            a00[i][j] = mRows[i][j];
      Matrix a01(this->getSize() / 2.0);
      for (int i = 0; i < this->getSize() / 2.0; i++)
         for (int j = this->getSize() / 2.0; j < this->getSize(); j++)
            a01[i][j - a01.getSize()] = mRows[i][j];
      Matrix a10(this->getSize() / 2.0);
      for (int i = this->getSize()/2.0; i < this->getSize(); i++)
         for (int j = 0; j < this->getSize()/2.0; j++)
            a10[i - a10.getSize()][j] = mRows[i][j];
      Matrix a11(this->getSize()/2.0);
      for (int i = this->getSize()/2.0; i < this->getSize(); i++)
         for (int j = this->getSize()/2.0; j < this->getSize(); j++)
            a11[i - a11.getSize()][j - a11.getSize()] = mRows[i][j];

      // Matrix B (the rhs matrix)
      Matrix b00(rhs.getSize()/2.0);
      for (int i = 0; i < rhs.getSize()/2.0; i++)
         for (int j = 0; j < rhs.getSize()/2.0; j++)
            b00[i][j] = rhs[i][j];
      Matrix b01(rhs.getSize()/2.0);
      for (int i = 0; i < rhs.getSize()/2.0; i++)
         for (int j = rhs.getSize()/2.0; j < rhs.getSize(); j++)
            b01[i][j - b01.getSize()] = rhs[i][j];
      Matrix b10(rhs.getSize()/2.0);
      for (int i = rhs.getSize()/2.0; i < rhs.getSize(); i++)
         for (int j = 0; j < rhs.getSize()/2.0; j++)
            b10[i - b10.getSize()][j] = rhs[i][j];
      Matrix b11(rhs.getSize()/2.0);
      for (int i = rhs.getSize()/2.0; i < rhs.getSize(); i++)
         for (int j = rhs.getSize()/2.0; j < rhs.getSize(); j++)
            b11[i - b11.getSize()][j - b11.getSize()] = rhs[i][j];

      // The M's (or next matrixs)
      Matrix m1 = (a00 + a11) * (b00 + b11);
      Matrix m2 = (a10 + a11) * b00;
      Matrix m3 = a00 * (b01 - b11);
      Matrix m4 = a11 * (b10 - b00);
      Matrix m5 = (a00 + a01) * b11;
      Matrix m6 = (a10 - a00) * (b00 + b01);
      Matrix m7 = (a01 - a11) * (b10 + b11);

      // intermediate results matrix
      Matrix c00 = m1 + m4 - m5 + m7;
      Matrix c01 = m3 + m5;
      Matrix c10 = m2 + m4;
      Matrix c11 = m1 + m3 - m2 + m6;

      //Result: combine the four corners into one matrix
      Matrix result(c00.getSize() * 2.0);
      for (int i = 0; i < result.getSize() / 2.0; i++)
         for ( int j = 0; j < result.getSize() / 2.0; j++)
            result[i][j] = c00[i][j];
      for (int i = 0; i < result.getSize() / 2.0; i++)
         for ( int j = result.getSize() / 2.0; j < result.getSize(); j++)
            result[i][j] = c01[i][j - c01.getSize()];
      for (int i = result.getSize()/2.0; i < result.getSize(); i++)
         for ( int j = 0; j < result.getSize() / 2.0; j++)
            result[i][j] = c10[i-c10.getSize()][j];
      for (int i = result.getSize() / 2.0; i < result.getSize(); i++)
         for ( int j = result.getSize() / 2.0; j < result.getSize(); j++)
            result[i][j] = c11[i - c11.getSize()][j - c11.getSize()];
      return result;
   }

};

istream& operator>>(istream& is, const Matrix& m)
{
   m.read(is);
   return is;
}

ostream& operator<< (ostream& os, const Matrix& m)
{
   m.write(os);
   return os;
}

int main(int argc, char* argv[])
{
   int size = 32;
   ifstream inFile;
   string file;

   if (argc == 2)
   {
      file = argv[1];
   }
   else if (argc > 2)
   {
      file = argv[1];
      size = atoi(argv[2]);
   }
   else 
   {
      file = "/home/cs306/files/diviconq.in";
   }   

   Matrix matrixA(size);
   Matrix matrixB(size);

   inFile.open(file.c_str());
   
   if (inFile.is_open())
   {
      inFile >> matrixA >> matrixB;
      inFile.close();
   }
   else 
   {
      cout << "Unable to open " + file;
      return 1;
   }

   cout << (matrixA * matrixB);

   return 0;
}
