#include <iostream>
#include <conio.h>
#include <list>

using namespace std;

template <class T>
class MyLLop : public list <T>
{
public:
	bool operator==(MyLLop <T> &ll1)
	{
		MyLLop::iterator tl1 = ll1.begin();
		MyLLop::iterator tl2 = begin();

		while (tl1 != ll1.end() && tl2 != end())
		{
			if (*tl1 == *tl2)
			{
				tl1++;
				tl2++;
			}
			else
			{
				return false;
			}
		}
		return true;
	}

	bool operator!=(MyLLop <T> &ll1)
	{
		MyLLop::iterator tl1 = ll1.begin();
		MyLLop::iterator tl2 = begin();

		while (tl1 != ll1.end() && tl2 != end())
		{
			if (*tl1 != *tl2)
			{
				return true;
			}
			else
			{
				tl1++;
				tl2++;
			}
		}
		return false;
	}

	void operator+(MyLLop <T> &ll1)
	{
		MyLLop::iterator tl1 = ll1.begin();
		MyLLop::iterator tl2 = begin();

		while (tl1 != ll1.end() && tl2 != end())
		{
			*tl2 = *tl2 + *tl1;
			tl1++;
			tl2++;
		}
	}

	void operator*(MyLLop <T> &ll1)
	{
		MyLLop::iterator tl1 = ll1.begin();
		MyLLop::iterator tl2 = begin();

		while (tl1 != ll1.end() && tl2 != end())
		{
			*tl2 = (*tl2) * (*tl1);
			tl1++;
			tl2++;
		}
	}

	void DisplayLL()
	{
		MyLLop <T>::iterator t = begin();

		for (t; t != end(); t++)
		{
			cout << *t << " ";
		}
		cout << "\n\n";
	}

};


void main()
{
	MyLLop <int> la;
	MyLLop <int> lb;

	la.push_back(10);
	la.push_back(20);
	la.push_back(30);
	la.push_back(40);

	lb.push_back(10);
	lb.push_back(20);
	lb.push_back(30);
	lb.push_back(40);


	if (la == lb)
	{
		cout << "== ? equal\n";
	}
	lb.push_back(50);

	if (la != lb)
	{
		cout << "!= ? not equal\n";
	}
	la.DisplayLL();
	lb.DisplayLL();

	la + lb;
	cout << "adding: \n";
	la.DisplayLL();

	lb*la;
	cout << "multiplying: \n";
	lb.DisplayLL();

	_getch();
}
