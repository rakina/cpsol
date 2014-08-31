#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
#include <map>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
long long m,n;
double ans, tmp;

double pkt(int a, int b, double d){
	if (b == 0)
		return 1/d;
	if (b == 1)
		return a/d;
	double tmp = pkt(a,b/2,d);
	if (b%2==0)
		return tmp*tmp;
	return (tmp*tmp)*(a/d);
}

int main(){
	cin >> m >> n;
	ans = 0;
	tmp = 0;
	double sum = 0;
	for (long long i = 1; i <= m; ++i){

		double tmp2 = pkt(i,n,m)-tmp;
				tmp = pkt(i,n,m);

		sum += tmp2;
		ans += tmp2*i;
	}
	printf("%.10lf\n",ans);
}