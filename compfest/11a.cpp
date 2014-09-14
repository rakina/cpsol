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
int t,x,y,z;
long long ans;
long long sum(long long a, long long b){
	// (z-i-1) + (z-i-2) + (z-i-3).... (z-i-(y-i))
	return (a*(a+1LL))/2LL - ((a-b)*(a-b+1))/2LL;
}
// 

int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d %d %d",&x,&y,&z);
		ans = 0;
		if (x > y) swap(x,y);
		if (y > z) swap(y,z);
		if (x > y) swap(x,y);
		for (long long i = 1; i <=x; ++i){
			//x < y < z
			ans += sum(z-i-1,y-i)*6LL;
		//	cout << i << " " << ans << endl;
			//x = y < z
			ans += (z-i)*3LL;
		//	cout << i << " " << ans << endl;
			//x < y = z
			ans += (y-i)*3LL;
		//	cout << i << " " << ans << endl;
			//x = y = z
			ans+=1LL;
		//	cout << i << " " << ans << endl;
		}
		cout << ans << endl;
	}
}