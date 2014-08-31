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
int t,n,p;
double ans,kya;
int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d %d",&n,&p);
		ans = 0;
		kya = p/100.0;
		for (int i = 0; i < n; ++i){
			ans += kya;
			kya *= 2.0;
		}
		printf("%.10lf\n",ans);
	}
}