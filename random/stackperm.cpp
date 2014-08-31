#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
#include <stack>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n, arr[15];
bool flag[15];
stack<pair<int,int> > s;

int main(){
	scanf("%d",&n);
	for (int i = n;i>=1; --i)
		s.push(mp(i,1));
	while (!s.empty()){
		pair<int,int> state = s.top();
		s.pop();
		arr[state.se-1] = state.fi;
		if (state.se == n){
			for (int i = 0; i < n-1;++i)
				printf("%d ",arr[i]);
			printf("%d\n",arr[n-1]);
		}
		else{
			memset(flag,0,sizeof(flag));
			for (int i = 0; i < state.se; ++i)
				flag[arr[i]] = 1;
			for (int i = n;i>=1; --i)
				if (!flag[i])
					s.push(mp(i,state.se+1));
		}
	}
}