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
int total_panalty = 0, k = 1, visited[100], upper = 0;
class node
{
public:
    int pth[100] = {0};
    int u = 0, t = 0, cost = 0, total_pen_sum = 0, time_limit = 0;
};

bool lc(node a, node b)
{
    return a.cost < b.cost;
}

int32_t main()
{
    speedup;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    list<node>bfs;
    int sum_pent[n + 1], penalty = 0, p[n + 1], d[n + 1], t[n + 1];
    sum_pent[0] = 0; node ans;
    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i] >> d[i] >> t[i];
        sum_pent[i] = sum_pent[i - 1] + p[i];
        total_panalty += p[i];
    }
    upper = total_panalty;
    for (int i = 1; i <= n; ++i)
    {
        node cls;
        cls.u = total_panalty - p[i];
        cls.cost = sum_pent[i - 1];
        cls.time_limit = d[i];
        if (cls.cost <= upper)
        {
            upper = cls.u;
            cls.total_pen_sum = p[i];
            cls.pth[i];
            cls.t = t[i];
            bfs.push_back(cls);
            ans = cls, penalty = cls.u;
        }
    }
    bfs.sort(lc);
    node tempNd;
    while (!bfs.empty())
    {
        tempNd = bfs.front();
        bfs.pop_front();
        for (int i = 1; i <= n; ++i)
        {
            node temp;
            if (tempNd.pth[i] != 1 && visited[i] != 1)
            {
                temp.u = total_panalty - p[i] - tempNd.total_pen_sum;
                temp.cost = sum_pent[i - 1] - tempNd.total_pen_sum;
                temp.t = tempNd.t + t[i];
                temp.time_limit = max(tempNd.time_limit, d[i]);

                if (temp.cost <= upper && temp.t <= temp.time_limit)
                {
                    upper = temp.u;
                    temp.total_pen_sum = p[i] + tempNd.total_pen_sum;
                    temp.pth[i] = 1;
                    for (int j = 1; j <= n; ++j)
                        if (tempNd.pth[j] != 0) temp.pth[j] = 1;
                    bfs.push_back(temp);
                    ans = temp, penalty = temp.u;
                }
            }
        }
        bfs.sort(lc);   // least cost
        visited[k++] = 1;
    }
    cout << "Total Penalty= " << penalty << endl;
    return 0;
}
