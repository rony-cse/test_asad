#include <bits/stdc++.h>

using namespace std;

const int SIZE = 100, BLACK = 1, WHITE = 2;
const int INF = 10000007;
int node, edge;
map<string, int> ma;
int matrix[SIZE][SIZE];
int totalCost[SIZE];
int color[SIZE];

int main(int argc, char const *argv[])
{
	 freopen("input.txt", "r",stdin);
	cin >> node >> edge;
	string str1, str2;
	int cost, ind = 1;

	while(edge--)
	{
		getchar();
		getline(cin, str1);
		getline(cin , str2);
		cin >> cost;
		if(ma[str1] == 0)
		{
			ma[str1] = ind;
			ind++;
		}
		if(ma[str2] == 0)
		{
			ma[str2] = ind;
			ind++;
		}
		int row = ma[str1];
		int col = ma[str2];
		//cout << row << " " << col << '\n';
		matrix[row][col] = cost;
		matrix[col][row] = cost;
	}
	getchar();
	string source, destination;
	getline(cin, source);
	getline(cin , destination);

	int sr = ma[source];
	int des = ma[destination];

	///cout << sr << " " << des << " \n";

	for(int i = 1; i <= node; i++)
	{
		if(matrix[sr][i] != 0)
		{
			totalCost[i] = matrix[sr][i];
		}
		else
		 {
		  totalCost[i] = INF;
		 }

		color[i] = WHITE;
	}

	totalCost[sr] = 0;
	color[sr] = BLACK;
	//cout << sr << endl;

	for(int i = 1; i <= node; i++)
	{
		int minNode = 1, minCost = INF;
		for(int j = 1; j <= node; j++)
		{
			if(color[j] == WHITE && minCost >= totalCost[j])
			{
				minCost = totalCost[j];
				minNode = j;
			}
		}
		//cout << minNode << endl;
		
		color[minNode] = BLACK;
		for(int j = 1; j <= node; j++)
		{
			if(matrix[minNode][j] != 0 && color[j] == WHITE)
			{
				if(totalCost[minNode]+matrix[minNode][j] < totalCost[j])
				{
					totalCost[j] = totalCost[minNode] + matrix[minNode][j];
				}
			}
		}
		
	}

    cout << source << " to " << destination;
    cout << " Minimum distance is: " << totalCost[des] << "\n";



	//  cout << '\n';

    // cout << "Row/Column:\n";
    // cout << "\t";
    // for(int i = 1; i <= node; i++)
    // {
    //    cout << " " << i << "\t";
    // }
    // cout << '\n';
    // for(int i = 1; i <= node; i++)
    // {
    //     cout << i << ":\t";
    //     for(int j = 1; j <= node; j++)
    //     {
    //         cout << matrix[i][j] << "\t";
    //     }
    //     cout << '\n';
    // }

    return 0;
}