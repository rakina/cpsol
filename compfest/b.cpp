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

int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		scanf("%d",&m);
		for (int i = 0; i < m; ++i){
			scanf("%d %d %d",&x,&y,&z);
			bisa[x][y][z] = t;
		}
	}
}