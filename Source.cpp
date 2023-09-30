#include <iostream>
using namespace std;
int main() {
	setlocale (0, "");
	cout << "int: " << sizeof(int) << "  short int: " << sizeof(short int) << "  float: " << sizeof(float) << "  double: " << sizeof(double) << "  long double: " << sizeof(long double) << "  char: " << sizeof(char) << "  bool: " << sizeof(bool);
	cout << "\n";
	cout << "������� ����� �����, �������� ������������� �������� ������ ��������: ";
	int a;
	cin >> a;
	cout << "\n";
	int order = sizeof(int) * 8;
	unsigned int mask = 1 << order - 1;
	cout << "a:" << " " << a << " " << "����� � ������" << " " << '-' << " " << &a << " " << "mask:" << " " << mask << " " << "\n";
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
	cout << "������� ����� ���� float, �������� ������������� �������� ������ ��������: ";
	cin >> floatB;
	mask = 1 << order - 1;
	cout << "\n";
	cout << "integerA:" << " " << integerA << " " << "����� � ������" << " " << '-' << " " << &integerA << " " << "floatB:" << " " << floatB << " " << "����� � ������" << " " << '-' << " " << &floatB << "\n";
	for (int i = 1; i <= order; i++)
	{
		putchar(integerA & mask ? '1' : '0');
		mask >>= 1;
		/*if (i % 8 == 0)
		{
			putchar(' ');
		}*/
		if ((i % order - 1 == 0) || (i % order - 9 == 0))
		{
			putchar(' ');
		}
	}
	union {
		int A[2] /*= { 127, 128 } */;
		double doubleC /*= 1.2345e+2*/;
	};
	cout << "\n";
	cout << "������� ����� ���� double, �������� ������������� �������� ������ ��������: ";
	cin >> doubleC;
	cout << "\n";
	cout << "A:" << " " << "{" << A[0] << "," << A[1] << "}" << " " << "����� � ������" << " " << "-" << " " << &A << " " << "doubleC:" << " " << doubleC << " " << "����� � ������" << " " << "-" << " " << &doubleC << "\n";
	int order2 = sizeof(double) * 8;
	//cout << A << " " << order2 << " " << &A << endl;
	for (int j = 1; j >= 0; j--)
	{
		mask = 1 << order - 1;
		for (int i = 1; i <= order2/2; i++) {
			putchar(A[j] & mask ? '1' : '0');
			mask >>= 1;
			/*if (i % 8 == 0)
			{
				putchar(' ');
			}*/
			if (((j == 1) && (i % order - 1 == 0)) || ((j == 1) && (i % order - 12 == 0)))
			{
				putchar(' ');
			}
		}
	}
}