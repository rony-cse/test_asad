//ID: 174067
#include<bits/stdc++.h>
using namespace std;
#define pb              push_back
#define vi              vector<int>
// #define int             long long int
#define mk(arr,n,type)  type *arr=new type[n];
#define test_case(x)    int x; cin>>x; while(x--)
#define w(a)            int w=a+1; while(w-->1)
#define f(a,n)          for(int f=a;f<n;f++) //a to n-1 loop
#define speedup         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod             1000000007

#define SIZE 999
#define BLACK 1
#define WHITE 0
map<string, int> city;

int color[SIZE];
int totalCost[SIZE];
int cost, node_num = 1;
int adj_mat[SIZE][SIZE];
string city_from, city_to;
int totalNodes, totalEdge;
int path[999];
int32_t main()
{
    // speedup;
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
	freopen("input.txt", "r",stdin);
	cin >> totalNodes >> totalEdge;
	// cout<<totalNodes<<totalEdge;

	while (totalEdge--)
	{
		cin.ignore(); //avoid newline
		getline(cin, city_from);getline(cin, city_to);
		cin >> cost;
		if (city[city_from] == 0)
			city[city_from] = node_num++;
		if (city[city_to] == 0)
			city[city_to] = node_num++;
		adj_mat[city[city_from]][city[city_to]] = cost;
		adj_mat[city[city_to]][city[city_from]] = cost;
	}

	cin.ignore(); //avoid newline
	string city_1, city_2;
	getline(cin, city_1);
	getline(cin, city_2);

	int source_city = city[city_1];
	int destination_city = city[city_2];
	for (int i = 1; i <= totalNodes; i++)
	{
		if (adj_mat[source_city][i] != 0)
        {
			totalCost[i] = adj_mat[source_city][i];
            path[i]=source_city;
        }
        else
			totalCost[i] = 999999;

		color[i] = WHITE;
	}

	int i = 1; 
	color[source_city] = BLACK;
	totalCost[source_city] = 0;
	while(i <= totalNodes){
		int nearestNode = 1, minCost = 999999;
		for (int j = 1; j <= totalNodes; j++)
			if (color[j] == WHITE && minCost >= totalCost[j])
			{
				minCost = totalCost[j];
				nearestNode = j;
			}

		color[nearestNode] = BLACK;
		for (int j = 1; j <= totalNodes; j++)
		{
			if (adj_mat[nearestNode][j] != 0 && color[j] == WHITE)
            {
				if (totalCost[nearestNode] + adj_mat[nearestNode][j] < totalCost[j])
                {
					totalCost[j] = totalCost[nearestNode] + adj_mat[nearestNode][j];
                    // cout<<adj_mat[nearestNode][j]<<" ";
                    // cout<<"j="<<j<<endl;
                    path[j]=nearestNode;
                }
                
            }
		}
		i++;
	}

    vector<int>ans;
    int tmp= city[city_2];
    while ( tmp != path[city[city_1]])
    {
        ans.push_back(tmp);
        tmp=path[tmp];
    }
    reverse(ans.begin(), ans.end());


	cout << "Minimum distance Between " << city_1 << " to " << city_2 << "is: " << totalCost[destination_city] << "   and path is:\n";
    for(auto itr:ans)
        for(auto itr2:city)
        {
            if(itr2.second == itr)
                cout<<itr2.first<<" -> ";
        }
    cout<<endl;
    return 0;
}