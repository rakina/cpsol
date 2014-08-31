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
#define MAXN 100005
int t,n,m;
int a[MAXN],b[MAXN], kya[MAXN], grundy[MAXN];
priority_queue<int> pq;
int ans,x;

int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d %d",&n,&m);
		for (int i = 2; i <= n; ++i)
			scanf("%d %d",&a[i],&b[i]);
		memset(kya,0,sizeof(kya));
		memset(grundy,0,sizeof(grundy));
		if (b[2] >= 1) kya[0]=1;
		grundy[1]=0;
		while (!pq.empty()) pq.pop();
		a[1] = 1;
		b[1] = 1;
		if (b[2]>= 1) {
			for (int i = 1; i <=MAXN; ++i)
				pq.push(-i);
		}
		else{
			for (int i = 0; i <=MAXN; ++i)
				pq.push(-i);
		}

		for (int i = 2; i <= n; ++i){
			//cout << i <<": a[i] ="<<a[i] << "  b[i]="<<b[i] << endl;
			//cout << "a[i-1]= "<<a[i-1] << " " << "b[i-1]= "<<b[i-1] << endl;
			for (int j = a[i-1]; j < a[i]; ++j){
				kya[grundy[j]]--;
				//cout << j << " ---- " << grundy[j] <<"  ~~ "<<kya[grundy[j]] <<endl;
				if (kya[grundy[j]]==0)
					pq.push(-grundy[j]);
			}
			for (int j = b[i-1]+1; j <=b[i]; ++j){
				kya[grundy[j]]++;
				//	cout << j << " ---- " << grundy[j] <<"  --- "<<kya[grundy[j]] <<endl;
			
			}

			grundy[i]=0;

			while (!pq.empty()){
				if (kya[-pq.top()] == 0){
					grundy[i]=-pq.top();
					break;
				}
				pq.pop();
			}
			//cout << i <<  " " << grundy[i] << "  ~ " <<pq.top()<< endl;
		}
		ans = 0;
		for (int i = 0; i < m; ++i){
			scanf("%d",&x);
			ans ^=grundy[x];
		}
		if (ans == 0)
			puts("Ferde");
		else puts("Marko");
	}
}