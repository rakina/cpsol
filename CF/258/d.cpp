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
char s[100005];
int n;
long long tmp, genap, ganjil, odda[100005],oddb[100005], evena[100005],evenb[100005],next[100005];

int main(){
	gets(s);
	n = strlen(s);
	next[n-1] = next[n] = n;
	for (int i = n-2; i>=0; --i){
		if (s[i+1]==s[i])
			next[i]=next[i+1];
		else
			next[i]=i+1;
	}
	odda[n]=evena[n]=0;
	oddb[n]=evenb[n]=0;
	for (int i = n-1; i>=0; --i){
		odda[i]=odda[i+1];
		oddb[i]=oddb[i+1];
		evenb[i]=evenb[i+1];
		evena[i]=evena[i+1];

		if ('a'==s[i]){
			if (i%2==0)
				evena[i]++;
			else
				odda[i]++;
		}
		else
			if (i%2==0)
				evenb[i]++;
			else
				oddb[i]++;
	}
	genap = ganjil = 0;
	for (int i = 0; i < n; ++i){
		if (s[i]=='a'){
			//aaaa
			if (i%2==1){
				genap += evena[i];
				ganjil += odda[i]; 
			}
			else{
				genap += odda[i];
				ganjil += evena[i];
			}
		}
		else{
			//bbb
			if (i%2==1){
				genap += evenb[i];
				ganjil += oddb[i]; 
			}
			else{
				genap += oddb[i];
				ganjil += evenb[i];
			}
		}
	}
	cout << genap << " " << ganjil << endl;
}