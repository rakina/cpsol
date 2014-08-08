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
#define MAXN 100100
int win[MAXN],lose[MAXN],dp[MAXN];
int l,n,k,node;
char s[MAXN];
int kya[MAXN][30];
int canwin(int pos){
	if (win[pos]>-1)
		return win[pos];
	int ret = 0;
	for (int i = 0; i < 26; ++i)
		if (kya[pos][i]>0)
			if (!canwin(kya[pos][i])){
				ret = 1;
				break;
			}

	return win[pos] = ret;
}
int willwin(int pos){
	if (dp[pos]>-1) return dp[pos];
	int ret = 0;
	for (int i = 0; i < 26; ++i){
		if (kya[pos][i]>0){
			ret = 1;
			if (canwin(kya[pos][i])){
				ret = 0;
				break;
			}
		}
	}
	return dp[pos]=ret;
}
int canlose(int pos){
	if (lose[pos]>-1)
		return lose[pos];
	int ret = 0;
	for (int i = 0; i < 26; ++i)
		if (kya[pos][i]>0){
			ret = 1;
			if (canlose(kya[pos][i])){
				ret = 0;
				break;
			}
		}
	//cout << pos << " " << ret << endl;
	return lose[pos] = ret;
}
int main(){
	scanf("%d %d",&n,&k);
	node = 1;
	memset(kya,0,sizeof(kya));
	for (int i = 0; i < n; ++i){
		scanf("%s",s);
		l = strlen(s);
		int cur = 0;
		for (int j = 0; j < l; ++j){
			if (kya[cur][s[j]-'a']>0){
				//udah adac
				cur = kya[cur][s[j]-'a'];
			}
			else{
				kya[cur][s[j]-'a']=node++;
				cur = node-1;
			}
		}
	}
	memset(win,-1,sizeof(win));
	memset(lose,-1,sizeof(lose));
	memset(dp,-1,sizeof(dp));
	int kalah = 0;
	int menang = canwin(0);
	for (int i = 0; i < 26; ++i){
		if (kya[0][i]>0){
			kalah |= canlose(kya[0][i]);
		}
	}
	//cout << menang << " " << kalah << endl;
	if (menang && kalah){
		puts("First");
	}
	else if (menang){
		if (k%2==0)
			puts("Second");
		else puts("First");
	}
	else {
		puts("Second");
	}

}