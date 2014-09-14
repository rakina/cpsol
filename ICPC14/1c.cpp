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
#define INF 1000000

char s[25];
int n, tc=0;
int dp[1<<18][19];
int kya;
int dist(char a, char b){
	if (a > b) swap(a,b);
	return min(b-a,a+26-b);
}

int solve(int pos, int mask){
	if (mask == kya) return 0;
	if (dp[pos][mask] != -1) return dp[pos][mask];
	int ret = INF;
		// ke kanan
		int cost = 0;
		for (int i = pos+1; i < n; ++i){
			int tmp = (mask|(1<<i));
			if (tmp==mask) {cost++; continue; }
			ret = min(ret,solve(i,tmp)+cost+1+dist(s[pos],s[i]));
		}
		//ke kiri
		cost = 1;
		for (int i = pos-1; i >=0; --i){
			int tmp = (mask|(1<<i));
			if (tmp==mask) {cost++; continue; }
			ret = min(ret,solve(i,tmp)+cost+1+dist(s[pos],s[i]));
		}
//	cout << pos << " " << mask << " "<< ret << endl;
	return dp[pos][mask] = ret;
}

int main(){
	while (1){
		gets(s); if(s[0] == '0') return 0;
		n = strlen(s); 		kya = (1<<n);
		int ans = INF;
		memset(dp,-1,sizeof(dp));
		for (int i = 0; i < n; ++i){
			dp[0][i] = 0;
			dp[1<<i][i]=dist('A',s[i])+1;
		}
		for (int mask = 1; mask < kya; ++mask){
			for (int pos = 0; pos <n; ++pos){
				if (dp[mask][pos] > -1) continue;
				int tmp = mask^(1<<pos);
				if (tmp>mask) continue; //gaada
				// mask =  yg udah didapat dan pos = posisi kursor dimana!
				// datang dari kiri
				int ret = INF;
				int cost = -1;
				for (int i = pos-1; i >=0; --i){
					if (dp[tmp][i]==-1) continue;
					if ((tmp&(1<<i))==0) continue;
					cost++;

				//	cout << tmp << " " << i << ": " << dp[tmp][i] << " " << dist(s[i],s[pos]) << " " << cost << endl;
					
					ret = min(ret,dp[tmp][i]+dist(s[i],s[pos])+cost+1);
				}
				cost = 0;
				//datang dari kanan
				for (int i = pos+1; i < n; ++i){
					if (dp[tmp][i]==-1) continue;
					if ((tmp&(1<<i))==0) continue;
					cost++;

					//cout << tmp << " " << i << ": " << dp[tmp][i] << " " << dist(s[i],s[pos]) << " " << cost << endl;
					
					ret = min(ret,dp[tmp][i]+dist(s[i],s[pos])+cost+1);
				}
				dp[mask][pos]=ret;
				//cout << mask << ", " << pos <<  " - "<<tmp <<" = " << ret << endl;
			}
		}
		for (int i = 0; i < n; ++i)
			ans = min(ans,dp[kya-1][i]);
		printf("%d\n",ans);
	}
}