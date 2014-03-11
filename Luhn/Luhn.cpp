//luhn
bool luhnAlg(string ccNum)
{
	//start from the last digit
	int curDigit = 0;
	int sum = 0;
	for (int i = ccNum.length - 1; i >= 0; i--)
	{
		curDigit = 2 * atoi(&ccNum[i]);
		if (curDigit > 9) {
			curDigit = 1 + (curDigit % 10);
		}
		sum += curDigit;
		if (i > 0)
		{
			i--;
			sum += (atoi(&ccNum[i]));
		}
	}
	return sum % 10 == 0;
}

int main()
{


}
