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
int solveor(int x, int num){
	if (x>=18) return  ((isi[num]==tc)?0:1);
	if ((atau&(1<<x))==0) return solveor(x+1,num);
	return solv
}
int main(){
	scanf("%d",&t);
	memset(isi,0,sizeof(isi));
	for (tc = 1; tc<=t; ++tc){
		scanf("%d",&n);
		atau = 0; dan = (1<<18)-1;
		for (int i = 0; i < n; ++i){
			scanf("%d",&a[i]);
			isi[a[i]] = tc;
			atau |= a[i]; dan &= a[i];
		}
		printf("Case #%d: %d\n",tc,solveor(0,0)+solveand(0,0));
	}
}