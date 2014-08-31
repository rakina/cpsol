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
#define INF 100000000
int n, a[105];
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
int dp[105][70105], val[105][70105], nxt[105][70105];
int m[105][70105];
vector<int> adj;
int bisa(int val, int mask){
	if (val == 1) return m[val][mask]=0;
	if (m[val][mask]!=-1) return m[val][mask];
	int ret = -2;
	for (int i = 0; i < 16; ++i)
		if (val%primes[i]==0){
			if (mask&(1<<i)){
				 ret = -2;
			}
			else{
				int tmp = val;
				while (tmp%primes[i]==0) tmp/=primes[i];
			 	ret = (bisa(tmp,mask)|(1<<i));
			}				 
			break;
		}
	m[val][mask]= ret;
	return ret;
}
int cnt = 0;
int solve(int pos, int mask){
	if (pos >= n)
		return 0;
	if (dp[pos][mask]>-1) return dp[pos][mask];
	int ret = INF;
	for (int i = 0; i < hm[mask].size(); ++i){
		int x = hm[mask][i];
		if (x>=a[pos]*2) break;
		cnt++;
			int kya = mask|bisa(x,mask);
			int tmp = max(a[pos]-x,x-a[pos]) + solve(pos+1,kya);
			if (tmp < ret){
				val[pos][mask]=x;
				nxt[pos][mask]=kya;
				ret = tmp;
			}
	}
	return dp[pos][mask]=ret;
}

int main(){
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
		scanf("%d",&a[i]);
	
	memset(m,-1,sizeof(m));
	memset(dp,-1,sizeof(dp));
	memset(val,0,sizeof(val));
	for (int i = 1; i < 59; ++i){
		for (int j = 0;  j < (1<<16); ++j){
			int tmp = bisa(i,0);
			if ((tmp&j)>0) continue;
			for (int k = 1; k <= 30; ++k){
				if (abs(k-i)<abs(k-val[k][tmp]))
					val[k][tmp]=i;
			}

		}
	}
	
	for (int j = 0;  j < (1<<16); ++j){
		for (int i = 1; i < 31; ++i){
			if (val[i][j]!=0){
				adj[j].pb();
			}
		}
	}
	solve(0,0); 
	int x =0;
	for (int i = 0; i < n; ++i){
		printf("%d",val[i][x]);
		x = nxt[i][x];
		if (i+1==n) puts("");
		else printf(" ");
	}
}