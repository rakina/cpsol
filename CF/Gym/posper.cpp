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
#define MOD 1000000007
int n,k, dp[1005][1005][3][3];
int solve(int pos, int k, bool m1, bool m2){
	if (pos >= n) return ((k==0)?1:0);
	if (dp[pos][k][m1][m2]>-1) return dp[pos][k][m1][m2];
	int ret = solve(pos+1,k,m2,0);
	if ((k>0) && m1 && (pos+2<n)){
		ret = (ret + solve(pos+1,k-1,m2,1)) % MOD;
	}
	else if ((k>0) && !m1 && (pos+2>=n)){
		ret = (ret + solve(pos+1,k-1,m2,0)) % MOD;
	}
	else if (k>0){
		ret = (((ret + solve(pos+1,k-1,m2,1)) % MOD) + solve(pos+1,k-1,m2,0)) % MOD;
	}
	return dp[pos][k][m1][m2]=ret;
}

int main(){
	scanf("%d %d",&n,&k);
	memset(dp,-1,sizeof(dp));
	cout << solve(0,k,0,0) << endl;
}