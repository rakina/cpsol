#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
int cnt = 0;
long long tmp[5005];
int n,l,r;
int dp[5005][5005];
char vis[5005][5005];
int com[5005][5005];
long long f[5005];
/*
	solve(n,l)
	kita punya n buah tower
	berapa banyak cara sdm sehingga yg keliatan <= l
*/

int choose(int n,int k){
	//cout << n << " " << k <<" " << com[n][k]<<endl;
	if (com[n][k]>-1)return com[n][k];
	if (n == 0){ 
		if (k > 0) return 0;
		return 1;
	}
	if (k > 0)  com[n][k]=(choose(n-1,k-1)+choose(n-1,k))%MOD;
	else com[n][k]=choose(n-1,k);
	//cout << n << " " << k << ": "<<com[n][k]<<endl;
	return com[n][k];
}
long long tepat(int a, int b){
	if (b == 0) return dp[a][0];
	return (dp[a][b]-dp[a][b-1]+MOD)%MOD;
}
int main(){
	memset(com,-1,sizeof(com));
	memset(vis,0,sizeof(vis));
	memset(dp,0,sizeof(dp));
	for (int i = 0; i < 5005; ++i)
		dp[0][i]=1;
	f[0]=1;
	for (int i= 1; i < 5005; ++i)
		f[i] = (f[i-1]*(1LL*i))%MOD;
	for (int i = 1; i < 5005; ++i){
		dp[i][1] =  f[i-1];
		for (int j = 2; j < 5005; ++j){
			dp[i][j] = (dp[i-1][j-1] + ((i-1LL)*dp[i-1][j])%MOD)%MOD;
		}
	}

	while (1){
		scanf("%d %d %d",&n,&l,&r);
		if (n+l+r==0) break;
		long long ans = 0;
		for (int i = 0; i < n; ++i)
			tmp[i] = (1LL*choose(n-1,i)*tepat(i,l-1))%MOD;
		for (int i = 0; i <n; ++i){
		//	cout << i << " " <<tepat(i,l-1) << " "<< tepat(n-1-i,r-1)<<" "<<choose(n-1,i)<<endl;
			ans = (ans + (tmp[i]*tepat(n-1-i,r-1))%MOD)%MOD;
		}
		cout << ans << endl;
	}
}