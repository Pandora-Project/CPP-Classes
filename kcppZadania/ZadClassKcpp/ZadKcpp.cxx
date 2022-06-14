#include <iostream>
#include <Class.h>
#include <conio.h>

using namespace std;

union basicUnion
{
	int a;
	int b[2];
	double c;
	double d[2];
};

class kcpp
{
private:
	void funA(int num);

	void funB(int num);

	void funC(int num);

	void funWar(int a)
	{
		a = a * 2;
	}

	void funRef(int &a)
	{
		a = a * 2;
	}

	void funWsk(int *a)
	{
		*a = *a * 2;
	}

	void funClass()
	{
		Frog *treefrog = new Frog("Green", "Croak");
		treefrog->setvelocity(12);
		Frog *Dtreefrog = treefrog->sethopDist(30);
		Dtreefrog->setvelocity(22);
		treefrog->show();
		Dtreefrog->show();
		if (treefrog->equals(*Dtreefrog))
		{
			cout << endl
				 << "Duplicate Frog" << endl;
		}
		delete treefrog;
		Frog *dartfrog = new Frog("Red", "ribbit", 22, 25);
		dartfrog->show();

		Frog *dartfrog2 = dartfrog;
		dartfrog2->show();
		delete dartfrog;

		Frog bullfrog("GreenYellow", "booaoOAO", 30, 60);
		bullfrog.sethopDist2(65).show();
	}

	void funUnia()
	{
		basicUnion bu;
		bu.a = 7;
		bu.b[0] = 1;
		bu.b[1] = 2;
		cout << "a: " << bu.a << endl;
		cout << "b[0]: " << bu.b[0] << endl;
		cout << "b[1]: " << bu.b[1] << endl;

		bu.c = 3.14;
		bu.d[0] = 3.1415;
		bu.d[1] = 3.14159;
		cout << "a: " << bu.a << endl;
		cout << "b[0]: " << bu.b[0] << endl;
		cout << "b[1]: " << bu.b[1] << endl;
		cout << "c: " << bu.c << endl;
		cout << "d[0]: " << bu.d[0] << endl;
		cout << "d[1]: " << bu.d[1] << endl;
		cout << "Change to double type" << endl;
	}

	void orEven1(int number)
	{
		if (number & 1 == 1)
		{
			cout << "Number is odd" << endl;
		}
		else
		{
			cout << "Number is even" << endl;
		}
	}

	void orEven2(int number)
	{
		if (number % 2 == 0)
		{
			cout << "Number is even" << endl;
		}
		else
		{
			cout << "Number is odd" << endl;
		}
	}

	void orEven3(int number)
	{
		number % 2 != 0 ? cout << "Number is odd" << endl : cout << "Number is even" << endl;
	}

	void funParzysteCase()
	{
		int number;
		cout << "Type number: ";
		cin >> number;

		cout << "Choose a mode: " << endl;
		cout << "1. Bit operation" << endl;
		cout << "2. Modulo" << endl;
		cout << "3. Conditional operrand" << endl;

		char choose;
		cin >> choose;
		switch (choose)
		{
		case '1':
			orEven1(number);
			break;
		case '2':
			orEven2(number);
			break;
		case '3':
			orEven3(number);
			break;
		default:
			cout << "Incorrect number" << endl;
		}
	}

public:
	void ZadZwracanie()
	{
		int a = 2;
		int *sign = &a;
		cout << "A val: " << a << endl;
		funWar(a);
		cout << "A val: " << a << endl;
		funRef(a);
		cout << "A val: " << a << endl;
		funWsk(sign);
		cout << "A val: " << a << endl;
	}

	void ZadPetle()
	{
		int num = 5;
		funA(num);
		funB(num);
		funC(num);
	}

	void ZadClass()
	{
		funClass();
	}

	void ZadUnia()
	{
		funUnia();
	}

	void ZadParzysteCase()
	{
		funParzysteCase();
	}
};

void kcpp::funA(int num)
{
	int i = 0;
	cout << "while i++" << endl;
	while (i++ < num)
	{
		if (i == num)
		{
			cout << "i==num, break";
			break;
		}
		cout << i << " ";
	}
	cout << endl
		 << "while ++i" << endl;
	i = 0;
	while (++i < num)
	{
		if (i == num)
		{
			cout << "i==num, break";
			break;
		}
		cout << i << " ";
	}
	cout << endl
		 << endl;
}

void kcpp::funB(int num)
{
	int i = 0;
	cout << "do-while i++" << endl;
	do
	{
		if (i == 3)
			continue;
		cout << i << " ";
	} while (i++ < num);
	cout << endl
		 << "do-while ++i" << endl;
	i = 0;
	do
	{
		if (i == 3)
			continue;
		cout << i << " ";
	} while (++i < num);
	cout << endl
		 << endl;
}

void kcpp::funC(int num)
{
	cout << "for" << endl;
	for (int i = 0; i < num; i++)
	{
		if (i == 3)
		{
			cout << "i==3, return funC(" << num - 1 << ")" << endl;
			return funC(num - 1);
		}
		cout << i << " ";
	}
	cout << endl
		 << endl;
}

int main()
{
	kcpp *classCpp = new kcpp();

	unsigned char sign;
	std::cout << "ESC quits the program" << std::endl;
	do
	{
		while (kbhit())
		{
			sign = getch();
		}
		std::cout << "Choose assignment?" << std::endl;
		std::cout << "0- ZadZwracanie.cc" << std::endl;
		std::cout << "1- ZadPetle.cc" << std::endl;
		std::cout << "2- ZadClass.cc" << std::endl;
		std::cout << "3- ZadUnia.cc" << std::endl;
		std::cout << "4- ZadParzysteCase.cc" << std::endl;
		sign = getch();
		if ('0' == sign)
		{
			classCpp->ZadZwracanie();
		}
		else if ('1' == sign)
		{
			classCpp->ZadPetle();
		}
		else if ('2' == sign)
		{
			classCpp->ZadClass();
		}
		else if ('3' == sign)
		{
			classCpp->ZadUnia();
		}
		else if ('4' == sign)
		{
			classCpp->ZadParzysteCase();
		}
		else if (27 != sign)
		{
			std::cout << "Incorrect sign" << std::endl;
		}
	} while (sign != 27);
	return 0;
}