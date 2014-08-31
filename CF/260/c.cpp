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
int solve(int pos){

}
int main(){
	scanf("%d %d %d",&n,&m,&q);
	while(m--){
		scanf("%d %d",&a,&b);
		adj[a].pb(b);
		adj[b].pb(a);
	}

	//dsuin dulu
	memset(par,-1,sizeof(par));
	for (int i = 1; i <= n; ++i){
		if (par[i]==-1){
			dfs(i);
			solve(i);
		}
	}
	while (q--){
		scanf("%d",&t);
		if (t == 1){
			scanf("%d",&x);
			printf("%d\n",&ex[papa(x)]);
		}
		else{
			scanf("%d %d",&x,&y);
			merge(x,y);
		}
	}
}