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
int n, cnt[10005];
char s[10005];
int main(){
	while (1){
		gets(s);
		if (strcmp(s,"0")==0) return 0;
		n = strlen(s);
		memset(cnt,0,sizeof(cnt));
		bool pertamax = true;
		for (int i = 1; i < n; ++i){
			if (cnt[i]%2 != s[i]-'0'){
				for (int j = 1; j*i < n; ++j)
					cnt[j*i]++;
				if (pertamax) pertamax = 0;
				else printf(" ");
				printf("%d",i);
			}
		}
		puts("");
	}
}