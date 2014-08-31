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
unsigned long long x,y;
int t;
int main(){
	scanf("%d",&t);
	while (t--){
		cin >> x >> y;
		if (x == y){
			puts("Voting Ulang");
		}
		else if (x > y){
			if (x-y == 1){
				puts("Voting Ulang");
			}
			else puts("Tere");
		}
		else{
			if (y-x == 1){
				puts("Voting Ulang");
			}
			else puts("Toni");
		}
	}
}