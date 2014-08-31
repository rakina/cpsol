#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
long long dp[100100][3],a[100100];
int n,x;
long long score[100100];
int main(){
	n = 100000;
	memset(a,0,sizeof(a));
	for (int i = 0; i < n; ++i){
		x = 100000;
		a[x]++;
	}
	long long ans = 0;
	memset(dp,0,sizeof(dp));
	for (long long pos = 100000; pos>0; --pos){
		dp[pos][1] = max(dp[pos+1][0],max(dp[pos+2][1],dp[pos+2][0])+a[pos]*pos);
		dp[pos][0] = max(max(dp[pos+1][0],dp[pos+1][1]),max(dp[pos+2][1],dp[pos+2][0]));
		ans = max(ans,max(dp[pos][1],dp[pos][0]));
	}
	cout << ans << endl;
}