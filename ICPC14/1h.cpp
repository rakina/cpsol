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
#define MAXN 30015
template <class T> inline void getint(T &num)
{
	bool neg=0;
	num=0;
	char c;
	while ((c=getchar_unlocked()) && (!isdigit(c) && c!='-'));

	do{num=num*10+c-'0';
	
	}while ((c=getchar_unlocked()) && isdigit(c));
}

vector<int> primes;
int n, a[MAXN];
bool kya[MAXN];
long long p[MAXN],p2[MAXN],ans,p3[MAXN];

long long sum(int a, int x, int b){
	return (p[b]-p[x])-(1LL*x*(p3[b]-p3[x]))  + (p2[a]-p2[x])-((n-x+1LL)*(p3[x-1]-p3[a-1]));
}

int main(){
	primes.pb(2);
	memset(kya,0,sizeof(kya));
	for (int i = 3; i < MAXN; i+=2){
		if (kya[i]) continue;
		primes.pb(i);
		for (int j = i; j*i < MAXN; ++j)
			kya[j*i] = true; 
	}
	int m = primes.size();
	while (1){
		scanf("%d",&n);
		if (n == 0) return 0;
		p[0] = 0;
		p2[n+1]=0; p3[0] = 0;
		for (int i = 1; i <= n; ++i){
			getint(a[i]); p3[i]=p3[i-1]+a[i];
			p[i] = p[i-1] + (1LL*i*a[i]);
		}
		for (int i = n; i>0; --i){
			p2[i] = p2[i+1] + (1LL*(n-i+1)*a[i]);
		}
		p3[n+1]=p3[n];
		
		ans = p[n];
		p[n+1] = p[n]; p2[0] = p2[1];
		for (int i = 1; i <= n; ++i){
			//di i doang
			ans = min(ans,sum(1,i,n));

			for (int j = 0; j < m; ++j){
				int pr = primes[j];
				if (i+pr>n) break;
				//i,i+primes[j]
				int x = i, y = i+pr; int z = i+2+pr; 
				if (j==0 || kya[pr+2] || z > n) {
					ans = min(ans,sum(1,x,(x+y)>>1)+sum(((x+y)>>1)+1,y,n));
					continue;
				}
				int z2 = i+pr+4; 
				if (kya[pr+4]||z2>n){
					y = i+2;
					ans = min(ans,sum(1,x,x+1)+sum(y,y,(y+z)>>1)+sum(((y+z)>>1)+1,z,n));
					//i,i+primes[j],i+primes[j]+2
					y = i+pr;
					ans = min(ans,sum(1,x,(x+y)>>1)+sum(((x+y)>>1)+1,y,y+1)+sum(z,z,n));
					continue;
				}
				//i,i+2,i+primes[j]+2,i+primes[j]+4
				y = i+2;
				ans = min(ans,sum(1,x,x+1)+sum(y,y,(y+z)>>1)+sum(((y+z)>>1)+1,z,z+1)+sum(z2,z2,n));
			}
			//cout << i << " " << ans << endl;
		}
		printf("%lld\n",ans);
	}
}