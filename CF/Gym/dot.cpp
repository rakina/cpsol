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
int x,y,n,d,a[25],b[25],dp[1005][1005];
int solve(int r, int c){
	if (r*r+c*c>=d*d)
		return 1;
	int tx=r+400,ty=c+400;
	if (dp[tx][ty]>-1)
		return dp[tx][ty];
	for (int i = 0; i < n; ++i)
		if (!solve(r+a[i],c+b[i]))
			return dp[tx][ty] = 1;
	return dp[tx][ty]=0;
}

int main(){
	scanf("%d %d %d %d",&x,&y,&n,&d);
	for (int i = 0; i < n; ++i)
		scanf("%d %d",&a[i],&b[i]);
	memset(dp,-1,sizeof(dp));
	if (solve(x,y)==1)
		puts("Anton");
	else
		puts("Dasha");
}