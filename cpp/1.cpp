#include<bits/stdc++.h>
using namespace std;
int vertex = 0;
void BFS(int arr[][8], int s)
{
	string color[vertex + 1];
	int d[vertex + 1], pi[vertex + 1];
	for (int i = 0; i <= vertex; ++i)
	{
		color[i] = "WHITE";
		d[i] = 100000;
		pi[i] = 0;
	}
	color[s] = "GRAY"; d[s] = 0; pi[s] = 0;
	queue<int> Q;
	Q.push(s);
	while (Q.size() > 0)
	{
		int u = Q.front();
		Q.pop();
		for (int i = 0; i < ver; ++i)
		{
			/* code */
		}

	}
}
int main()
{
	fstream file;
	file.open("testFile.txt");
	int n1, n2, d;
	file >> vertex;

	cout << "vertex=" << vertex << endl;
	int arr[vertex + 1][8] = {};
	file >> d;
	cout << "d=" << d << endl;
	while (file >> n1 >> n2)
	{
		if (d == 0)
			arr[n1][n2] = 1;
		else
		{
			arr[n1][n2] = 1;
			arr[n2][n1] = 1;
		}
	}
	// for (int i = 1; i <= vertex; ++i)
	// {
	// 	for (int j = 1; j <= vertex; ++j)
	// 		cout << arr[i][j] << " ";
	// 	cout << endl;
	// }
	BFS(arr, 1);
	// list <int> l;
	// l.push_back(10);
	// for (list<int>::iterator i = l.begin(); i != l.end(); ++i)
	// {
	// 	cout << *i;
	// }
	file.close();

	return 0;
}
