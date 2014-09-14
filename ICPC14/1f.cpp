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
int n,m,a,b,c;
int dist[505][245];
vector<pair<int,int> > adj[505];
vector<pair<pair<int,int>,int> > cost[1505];

priority_queue<pair<int,pair<int,int> > > pq;

int main(){
	while (1){
		scanf("%d %d",&n,&m);
		if (n+m==0) return 0;
		for (int i = 0; i < n; ++i)
			adj[i].clear();
		for (int i = 0; i < m; ++i)
			cost[i].clear();
		while (m--){
			scanf("%d %d",&a,&b);
			adj[a].pb(mp(b,m)); adj[b].pb(mp(a,m));
			while (1){
				scanf("%d %d %d",&a,&b,&c);
				cost[m].push_back(mp(mp(a,b),c));
				if (b == 1439) break;
			//	cout << a << " ~ " << b <<  " ~ " << c << endl;
			}
		}
		while (!pq.empty()) pq.pop();
		memset(dist,-1,sizeof(dist));
		pq.push(mp(-720,mp(0,240)));
		dist[0][240]=720;
		while (!pq.empty()){
			int d = -pq.top().fi;
			int pos = pq.top().se.fi;
			int fuel = pq.top().se.se;
			pq.pop();
		//	cout << pos <<" with fuel: "<< fuel << "   cur dist = " << d << endl;
			if (pos == n-1){
				//ketemu gan!
				printf("%d\n",d-720);
				break;
			}
			// wait here ajah
			if (fuel != 240){
				if (dist[pos][fuel+1]==-1 || dist[pos][fuel+1]>d+2){
					pq.push(mp(-(d+2),mp(pos,fuel+1)));
					dist[pos][fuel+1]=d+2;
				}
			}

			//kunjungi tetangga2 :3			
			for (int i = 0; i < adj[pos].size(); ++i){
				int nxt = adj[pos][i].fi; int id = adj[pos][i].se;
				for (int j = 0; j < cost[id].size(); ++j){
					c = cost[id][j].se;
					int tunggu = 0;
					if (cost[id][j].fi.fi > (d%1440)) tunggu = cost[id][j].fi.fi - (d%1440);
					else if ((d%1440) > cost[id][j].fi.se){
						tunggu = 1440-(d%1440) + cost[id][j].fi.fi;
					}
					if (min(fuel+tunggu/2,240) < c){
						if (cost[id][j].fi.fi > (d%1440)){
							if (min(fuel+(tunggu+(cost[id][j].fi.se-cost[id][j].fi.fi))/2,240) < c) continue;
							else tunggu += (c*2-tunggu-fuel);
						}
						else if ((d%1440) > cost[id][j].fi.se){
							if (min(fuel+(tunggu+(cost[id][j].fi.se-cost[id][j].fi.fi))/2,240) < c) continue;
							else tunggu +=  (c*2-tunggu-fuel);
						}
						else{
							if (min(fuel+(cost[id][j].fi.se-(d%1440))/2,240) < c) continue;
							else tunggu +=  (c*2-fuel);
						}
					}
					if (dist[nxt][min(fuel+tunggu/2,240)-c]==-1 || dist[nxt][min(fuel+tunggu/2,240)-c]> tunggu + d + c){
						dist[nxt][min(fuel+tunggu/2,240)-c] = tunggu + d+c;
						pq.push(mp(-(d+c+tunggu),mp(nxt,min(fuel+tunggu/2,240)-c)));
					}
				}
			}
		}
	}
}