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
int t,n,m,a[50005];

int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d %d",&n,&m);
		for (int i = 0; i < n; ++i)
			scanf("%d",&a[i]);
		sort(a,a+n);
		int ka = 0;
		int ans = 0;
		int cur = 0;
		for (int i = 0; i < n; ++i){
			while(ka+1<n){
				if (cur+a[ka+1]-a[ka]>m)
					break;
				cur += a[ka+1]-a[ka];
				++ka;
			}
			ans = max(ans,ka-i+1);
		//	cout << i << " " << ka << endl;
			cur -= (a[i+1]-a[i]);
			if (ka < i+1){
				ka = i+1;
				cur = 0;
			}
		}
		cout << ans << endl;
	}
}