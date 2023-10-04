#include <iostream>
using namespace std;
int main() {
	setlocale (0, "");
	cout << "int: " << sizeof(int) << "  short int: " << sizeof(short int) << "  float: " << sizeof(float) << "  double: " << sizeof(double) << "  long double: " << sizeof(long double) << "  char: " << sizeof(char) << "  bool: " << sizeof(bool);
	cout << "\n";
	cout << "Enter the integer whose binary representation you want to get: ";
	int a;
	cin >> a;
	cout << "\n";
	int order = sizeof(int) * 8;
	unsigned int mask = 1 << order - 1;
	cout << "a:" << " " << a << " " << "place in memory" << " " << '-' << " " << &a << " " << "mask:" << " " << mask << " " << "\n";
	for (int i = 1; i <= order; i++)
	{
		putchar(a & mask ? '1' : '0');
		mask >>= 1;
		if (i % 8 == 0)
		{
			putchar(' ');
		}
		if (i % order - 1 == 0)
		{
			putchar(' ');
		}
	}
	union {
		int integerA;
		float floatB;
	};
	cout << "\n";
	cout << "Enter the float type number whose binary representation you want to get: ";
	cin >> floatB;
	mask = 1 << order - 1;
	cout << "\n";
	cout << "integerA:" << " " << integerA << " " << "place in memory" << " " << '-' << " " << &integerA << " " << "floatB:" << " " << floatB << " " << "place in memory" << " " << '-' << " " << &floatB << "\n";
	for (int i = 1; i <= order; i++)
	{
		putchar(integerA & mask ? '1' : '0');
		mask >>= 1;
		if ((i % order - 1 == 0) || (i % order - 9 == 0))
		{
			putchar(' ');
		}
	}
	union {
		int A[2];
		double doubleC;
	};
	cout << "\n";
	cout << "Enter a number of type double whose binary representation you want to get: ";
	cin >> doubleC;
	cout << "\n";
	cout << "A:" << " " << "{" << A[0] << "," << A[1] << "}" << " " << "place in memory" << " " << "-" << " " << &A << " " << "doubleC:" << " " << doubleC << " " << "place in memory" << " " << "-" << " " << &doubleC << "\n";
	int order2 = sizeof(double) * 8;
	for (int j = 1; j >= 0; j--)
	{
		mask = 1 << order - 1;
		for (int i = 1; i <= order2/2; i++) {
			putchar(A[j] & mask ? '1' : '0');
			mask >>= 1;
			if (((j == 1) && (i % order - 1 == 0)) || ((j == 1) && (i % order - 12 == 0)))
			{
				putchar(' ');
			}
		}
	}
}