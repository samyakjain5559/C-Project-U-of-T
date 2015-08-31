#include <iostream>
using namespace std;

// calculates factorial(n) calculates n! recursively as n!=n*(n-1)!

int factorial(int n)
{
	int f_n_minus_one=1;
	if (n>1)
	{
		f_n_minus_one=factorial(n-1);
		return f_n_minus_one*n;
	}
	else
		return 1;
}

int main(int argc,char **argv)
{
    unsigned i_factorial;
        for(unsigned i=0;i<=10;++i)
        {
            cout << "Factorial of " << i << " is ";
            i_factorial=factorial(i);
            cout << i_factorial << endl;
            // ...
        }
	return 0;
}
