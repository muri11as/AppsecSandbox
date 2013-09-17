#import <iostream>

using namespace std;

int fib(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if( n == 1)
	{
		return 1;
		
	}
	else
	{
		return fib(n-1) + fib(n-2);
	}
}


int main()
{
	int res;
	for(int i = 0; i < 10; i++)
	{
		res = fib(i);
		cout << "Fibonacci Number of " << i  << " = " << res << endl;
	}
	
}