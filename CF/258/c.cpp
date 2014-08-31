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
long long t,n,k,d1,d2,tmp;
int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%lld %lld %lld %lld",&n,&k,&d1,&d2);
		if (n%3==0){
			tmp = n-k;
			if (d1+d2>tmp)
				puts("no");
			else if ((tmp-d1-d2)%3==0)
				puts("yes");
			else
				puts("no");
		}
		else puts("no");
	}
}