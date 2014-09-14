/*
	ICPC Jakarta 2013 Problem B - Network Packet Ordering
	Basically dynamic programming, but with a cool trick to save space and time.
*/

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
#define MOD 1000000009
#define MAXN 50005
int t,n,m,d,a[MAXN],b[MAXN];
int dp[MAXN][250];
int solve(int pa,int pb){
	if (pa >=n || pb >=m)
		return 1;
	if (b[pb]-a[pa]>=d) return solve(pa+1,pb);
	if (a[pa]-b[pb]>=d) return solve(pa,pb+1);
	if (dp[pa][b[pb]-a[pa]+125]>-1) return dp[pa][b[pb]-a[pa]+125];

	int ret = 0;
	if (a[pa]-b[pb]<d)
		ret = solve(pa+1,pb);
	if (b[pb]-a[pa]<d)
		ret = (ret+solve(pa,pb+1))%MOD;
	//cout << pa << " " << pb << " " << ret << endl;
	return dp[pa][b[pb]-a[pa]+125]=ret;
}

int main(){
	scanf("%d",&t);
	for (int tc=1; tc<=t; ++tc){
		scanf("%d %d %d",&n,&m,&d);
		for (int i = 0; i < n; ++i)
			scanf("%d",&a[i]);
		for (int i = 0; i < m; ++i)
			scanf("%d",&b[i]);
		memset(dp,-1,sizeof(dp));
		printf("Case #%d: %d\n",tc,solve(0,0));
	}
}
