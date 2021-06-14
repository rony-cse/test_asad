#include<bits/stdc++.h>
using namespace std;
#define pb              push_back
#define vi              vector<int>
#define int             long long int
#define mk(arr,n,type)  type *arr=new type[n];
#define test_case(x)    int x; cin>>x; while(x--)
#define w(a)            int w=a+1; while(w-->1)
#define f(a,n)          for(int f=a;f<n;f++) //a to n-1 loop
#define speedup         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod             1000000007
void solve();
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b) ;
}
int fact(int n)
{
    if (n == 1)
        return 1;
    else
        return (n * fact(n - 1)) ;
}




int32_t main()
{
    speedup;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    test_case(t)
    {
        solve();
    }

    // solve();

    return 0;
}


void solve()
{
    int n, item;
    // cin >> n;
    f(1, 40)
    cout << fact(f) << endl;
}
