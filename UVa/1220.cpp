#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
#include <map>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
map<string,int> m;
vector<int> adj[205];
int n, dp[205][4];
bool uni[205][4];
string boss,a,b;

int num(string s){
	if (m.find(s)!=m.end())
		return m[s];
	else return m[s] = m.size();
}

bool ok(int v)
{
   	if (dp[v][0]==dp[v][1]) return false;
   	if (dp[v][0] > dp[v][1])
   		return uni[v][0];
   	else
   		return uni[v][1];
}

int solve(int u, bool x)
{
	if (u > n) return 0;
    dp[u][x] = x;
    uni[u][x] = 1;
    for (int i = 0; i < adj[u].size(); ++i){
        int v = adj[u][i];
        if (x){
            dp[u][1] += solve(v, 0);
            if (!uni[v][0]) uni[u][1] = 0;
        }
        else{
            dp[u][0] += max(solve(v, 0), solve(v, 1));
            if (!ok(v)) uni[u][0] = 0;
        }
    }
    return dp[u][x];
}
int main(){
	while (1){
    scanf("%d",&n);
    if (n==0) break;
		cin >> boss;
		m.clear();
		for (int i = 0; i <= n; ++i)
			adj[i].clear();
		num(boss);
		for (int i = 1; i < n; ++i){
			cin >> a >> b;
			adj[num(b)].pb(num(a));
		}

		printf("%d ", max(solve(1, 0), solve(1, 1)));
        puts(ok(1) ? "Yes" : "No");
	}
}