#include <iostream>
using namespace std;

// Recursive function using static variable
int staticFun(int n)
{
	static int st_x = 0;
	if (n > 0)
	{
		st_x++;
		return staticFun(n - 1) + st_x;
	}
	return 0;
}

// Recursive function using global variable
int gl_x = 0;
int globalFun(int n)
{

	if (n > 0)
	{
		gl_x++;
		return globalFun(n - 1) + gl_x;
	}
	return 0;
}

// Head Recursion
void headRec(int n)
{
	if (n > 0)
	{
		headRec(n - 1);
		cout << n << " ";
	}
}

// Tail Recursion
void tailRec(int n)
{
	if (n > 0)
	{
		cout << n << " ";
		tailRec(n - 1);
	}
}

// Tree Recursion
void treeRec(int n)
{
	if (n > 0)
	{
		cout << n << " ";
		treeRec(n - 1);
		treeRec(n - 1);
	}
}

// Indirect Recursion
void funB(int);

void funA(int n)
{
	if (n > 0)
	{
		cout << n << " ";
		funB(n - 1);
	}
}

void funB(int n)
{
	if (n > 1)
	{
		cout << n << " ";
		funA(n / 2);
	}
}

// Nested Recusrion
int nestedRec(int n)
{
	if (n > 100)
		return n - 10;
	return (nestedRec(nestedRec(n + 11)));
}

int main()
{
	int x = 5;
	cout << "Answer using Function with Static Variable: " << staticFun(x) << endl;
	cout << "Answer using Function with Global Variable: " << globalFun(x) << endl;
	cout << "Head Recursion: ";
	headRec(x);
	cout << endl;
	cout << "Tail Recursion: ";
	tailRec(x);
	cout << endl;
	cout << "Tree Recursion: ";
	treeRec(3);
	cout << endl;
	cout << "Indirect Recursion: ";
	funA(x);
	cout << endl;

	cout << "Nested Recursion: " << nestedRec(95) << endl;
}
