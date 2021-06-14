#include<iostream>
using namespace std;
int x[100];
int place(int k, int i)
{
	for (int j = 1; j < k; ++j)
	{
		if ( x[j] == i || (abs(x[j] - i) == abs(j - k)))
			return 1;
	}
	return 0;
}
void nQueen(int k, int n)
{
	for (int i = 1; i <= n; i ++)
		if ( place(k, i))
		{
			x[k] = i;
			if (k == n)
			{
				for (int j = 1; j <= n; j++)
					cout << x[j] << " ";
				cout << endl;
			}
			else
				nQueen(k + 1, n);
		}
}
int main()
{
	nQueen(1, 4);
	return 0;
}