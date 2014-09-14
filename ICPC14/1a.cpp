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
#define MAXN 1005
int n,k,root,prev;
int node;
vector<int> adj[MAXN];

int findpar(int cur, int tar){
	for (int i = 0; i < adj[cur].size(); ++i)
		if (tar == adj[cur][i]) return cur;

	for (int i = 0; i < adj[cur].size(); ++i){
		int tmp = findpar(adj[cur][i],tar);
		if (tmp != -1) return tmp;
	}
	return -1;
}


int main(){
	while (1){
		scanf("%d %d",&n,&k);
		if(n+k==0) break;
		for (int i = 0; i <=n; ++i)
			adj[i].clear();
		scanf("%d",&root);
		prev = root; if (k == root) k = 0;
		int it = -1;
		for (int i = 1; i < n; ++i){
			scanf("%d",&node);
			if (node == k) k = i;
			if (node != prev+1){
				// new kid for new parent!
				++it;
			}
			adj[it].push_back(i);
			prev = node;
		}

		if (k == 0){
			puts("0");
		}
		else{
			int papa = findpar(0,k);
			if (papa == 0){ puts("0"); continue; }
			int kakek = findpar(0,papa);
			int ans = 0;
			for (int i = 0; i < adj[kakek].size(); ++i){
				if (adj[kakek][i] != papa)
					ans += adj[adj[kakek][i]].size();
			}
			printf("%d\n",ans);
		}
	}
}