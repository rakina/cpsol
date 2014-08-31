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
int n,x,a[50][50];
int main(){
	scanf("%d",&n);
	x = (n+1)/2;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d",&a[i][j]);

	for (int i = 0; i+x <=n; ++i)
		for (int j = 0; j+x <=n; ++j){
			int tmp = 0;
			for (int k = 0; k < x; ++k)
				for (int l = 0; l < x; ++l)
					tmp += a[i+k][j+l];
			if (tmp < 0){
				cout << i << " " << j << endl;
				for (int k = 0; k < x; ++k)
					for (int l = 0; l < x; ++l)
						a[i+k][j+l] *= -1;
			}
		}
		for (int i = 0; i+x <=n; ++i)
		for (int j = 0; j+x <=n; ++j){
			int tmp = 0;
			for (int k = 0; k < x; ++k)
				for (int l = 0; l < x; ++l)
					tmp += a[i+k][j+l];
			if (tmp < 0){
				cout << i << " " << j << endl;
				for (int k = 0; k < x; ++k)
					for (int l = 0; l < x; ++l)
						a[i+k][j+l] *= -1;
			}
		}
	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			ans += a[i][j];
	cout << ans << endl;


}