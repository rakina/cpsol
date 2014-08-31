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
#define MAXN 10005
bool vis[MAXN][11][11][11];
pair<int,int> dp[MAXN][11][11][11];
int t,l,n,c,r,d,is;
int node;
char tmp[MAXN],query[MAXN];
string s[MAXN];
int fin[MAXN], adj[MAXN][27];
pair<int,int> solve(int pos, int posq, int c, int r, int is, int d){
	if (vis[pos][r][is][d]) return dp[pos][r][is][d];
	vis[pos][r][is][d] = true;
	if (posq==l){
		if (fin[pos]!=-1)
			return mp(c,fin[pos]);
	}
	
	pair<int,int> ret = mp(-1,-1);

	//delete sampe mampus
	if (l-posq<=d && l-posq <= c && fin[pos]!=-1){
		ret = mp(c-(l-posq), fin[pos]);
	}
	for (int i = 0; i < 26; ++i){
		if (adj[pos][i]==-1) continue;
			
			int nxt = adj[pos][i];
			// normal ajah
			if (posq<l)
				if (query[posq]-'a' == i){
					if (solve(nxt,posq+1,c,r,i,d).fi-1 > ret.fi){
						ret = solve(nxt,posq+1,c,r,i,d);
						ret.fi--;
					}
				}

			// insert
			if (is > 0 && c > 0) 
				if (solve(nxt,posq,c-1,r,is-1,d).fi-1 >ret.fi){
					ret = solve(nxt,posq,c-1,r,is-1,d);						ret.fi--;

				}

			// delete
			if (d > 0 && c > 0) 
				if (solve(pos,posq+1,c-1,r,is,d-1).fi-1>ret.fi){
					ret = solve(pos,posq+1,c-1,r,is,d-1);						ret.fi--;

				}

			// replace
			if (r > 0 && c > 1) 
				if (solve(nxt,posq+1,c-2,r-1,is,d).fi-2>ret.fi){
					ret = solve(nxt,posq+1,c-2,r-1,is,d);						ret.fi-=2;

				}
	}
	cout << pos << " "<< posq << " ----- "<<c <<" | " <<r << " " << is << " " << d << endl;
	cout << ret.fi << "  "<< ret.se << endl;
	return dp[pos][r][is][d]=ret;
}

int main(){
	scanf("%d",&t);
	while (t--){
		memset(adj,-1,sizeof(adj));
		memset(fin,-1,sizeof(fin));
		scanf("%s",query);
		l = strlen(query);
		scanf("%d",&n);
		
		node = 1;
		for (int i = 0; i < n; ++i){
			scanf("%s",tmp);
			int len = strlen(tmp);
			s[i] = tmp;
			int last = 0;
			for (int j = 0; j < len; ++j){
				if (adj[last][s[i][j]-'a']==-1){
					adj[last][s[i][j]-'a']=node++;
				}
				last = adj[last][s[i][j]-'a'];
				if (j == len-1){
					fin[last] = i;
				}
			}
		}scanf("%d %d %d %d",&c,&r,&is,&d);
		memset(vis,0,sizeof(vis));
		if (solve(0,0,c,r,is,d).fi == -1)
			puts("-1");
		else cout << s[solve(0,0,c,r,is,d).se] <<endl;
	}
}