/**
 * Multiplies two numbers using the Russian pesant Method
 * @author SyntaxRules
 * @version 1.0
 */
public class PesantMultiplication
{
   ////////////////////////// Private Member Varriales
   private int mM;
   private int mN;

   ///////////////////////// Public Member Varriables
   public int mAnswer;

   ///////////////////////// Constructors
   /**
    * @param pN N to be multiplied
    * @param pM M to be multiplied
    */
   public PesantMultiplication(int pN, int pM)
   {
      mM = pM;
      mN = pN;
      mAnswer = 0;
   }

   /**
    * multiplyies and displays the result.
    */
   public void multiply()
   {
      System.out.println(" N   *   M   +  R");
      int r = 0;
      System.out.println(mN + " " + mM + " " + r);
      while (mN > 1)
      {
         if (mN % 2 == 0)
         {
            mN /= 2;
            mM *= 2;
         }
         else if (mN % 2 == 1)
         {
            mN /= 2;
            r += mM;
            mM *= 2;
         }
         System.out.println(mN + " " + mM + " " + r);
      }
      mAnswer = mM + r;
      System.out.println("Answer is: " + mAnswer);
   }

   /**
    * To test the function and make it useable.
    */
   public static void main(String[] args)
   {
      if (args.length == 2)
      {
         new PesantMultiplication(Integer.parseInt(args[0]),Integer.parseInt(args[1])).multiply();
      }
      else
         System.out.println("Usage PesantMultiplication <N> <M>");
   }
}
