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
#define MAXN 10005
int n,m;
long long k,nine[20];
int id[MAXN],dig[20];
char s[MAXN];
vector<int> pos[25];
bool udah[15];
bool bisa(int l, int r, int lvl){
	if (l > r) return 1;
	m = max(m,lvl);
	if ((r-l+1)%2 == 0) return 0;
	int mid = l + (r-l)/2;
	id[mid] = lvl;
	//cout << l << "  " << r << "-- "<<mid << " " << lvl << endl;
	if (s[mid]!='?'){
		if (dig[lvl]!=-1){
			if (dig[lvl] != s[mid]-'0') return 0;
		}
		else dig[lvl] = s[mid]-'0';
		udah[dig[lvl]] = true;
	}
	return (bisa(l,mid-1,lvl+1)&bisa(mid+1,r,lvl+1));
}


int main(){
	nine[0] = 1;
	for (int i = 1; i < 19; ++i)
		nine[i]=nine[i-1]*9LL;
	while (1){
		scanf("%lld",&k);
		if (k == 0) break;
		k--; memset(udah,0,sizeof(udah));
		m = 0;
		scanf("%s",s);
		n = strlen(s);
		for (int i = 0; i < 25; ++i)
			pos[i].clear();
		memset(dig,-1,sizeof(dig));
		if (!bisa(0,n-1,0)) { puts("-1"); continue;}

		int cnt = 0;
		for (int i = 0; i < m; ++i)
			if (dig[i] == -1) cnt++;
		long long kali2 = 0;
		if (dig[m]==-1){
			for (long long i = 1; i < 10; ++i){
				if (udah[i]) continue;
				//cout << i << " " << k << " " << i*nine[cnt]<<endl;
				kali2++;
				if (i == 9 || k < kali2*nine[cnt]){
					dig[m]=i; k -= (kali2-1LL)*nine[cnt];
					break;
				}
			}
		}
		if (dig[m]==0) { puts("-1"); continue;}
		if (nine[cnt] <= k)  { puts("-1"); continue;} //gacukup gan
		for (int i = m-1; i >=0; --i){
			if (dig[i]!=-1) continue;
			--cnt; long long kali = 0;
			//cout << i << " "<< cnt << endl;
			for (int j = 0; j < 10; ++j){
				if (dig[m]==j) continue; ++kali;
				//cout << i << " "<<j << " "<< kali << " "<< nine[cnt] << endl;
				if (j==9 || k < kali*nine[cnt]){
					dig[i]=j; 
					k-=(kali-1LL)*nine[cnt];
					break;
				}
			}
		}

		for (int i = 0; i < n; ++i){
			s[i] = (dig[id[i]]+'0');
		//	cout << i << " ~ "<< id[i] << " " << dig[id[i]] << endl;
		}
		puts(s);
	}
}