#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <memory.h>
using namespace std;
 
#define fi first
#define sc second
#define mp make_pair
#define pb push_back
#define ALL(c) (c).begin(), (c).end()
#define RESET(a,b) memset( (a), b, sizeof(a) )
#define ren(a,b,c) for (int a=b; a<c; ++a)
#define red(a,b,c) for (int a=b; a>=c; --a)
#define repi(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
 
const double eps = 1e-9;
typedef long long ll;
typedef pair <int,int> pii;
 
//lintaor1's template
 
#define N 266
 
int n;
char o[N+3][N+3];
char apapun[1024];

void fill( pii, pii, char );
void cetak();
void paruh( pii, pii );
 
int main()
{
    
    gets( apapun );
    int i;
    scanf("%d", &n);
     
    fill( mp(0,0), mp(n,n), '1' );
    cetak();
     
    scanf("%d", &i);
    if ( i ) fill( mp(0,0), mp(n,n), '0' );
    if ( (i<n*n) && (i>0) ) paruh( mp(0,0), mp(n,n) );
    cetak();
     
    return 0;
}
 
 
//----------------------------------------------------------------------
void cetak()
{
    ren(y,0,n) puts(o[y]);
    fflush( stdout );
}
 
void fill( pii awl, pii akh, char clr )
{
    ren( y, awl.fi, akh.fi )
        ren( x, awl.sc, akh.sc )
            o[y][x] = clr;
}
 
void paruh( pii awl, pii akh )
{
    pii tgh = mp( ((awl.fi+akh.fi) / 2), ((awl.sc+akh.sc) / 2) );
    //!printf("Paruh:  %d,%d  ->  %d,%d\n", awl.fi, awl.sc, akh.fi, akh.sc);
     
    //=== Try ===
    int a, b, c, d;
     
    fill( awl, tgh, '1' );
    cetak(); scanf("%d",&a);
    fill( awl, tgh, '0' );
     
    fill( mp( awl.fi, tgh.sc ),  mp( tgh.fi, akh.sc ),  '1' );
    cetak(); scanf("%d",&b);
    fill( mp( awl.fi, tgh.sc ),  mp( tgh.fi, akh.sc ),  '0' );
     
    fill( mp( tgh.fi, awl.sc ),  mp( akh.fi, tgh.sc ),  '1' );
    cetak(); scanf("%d",&c);
    fill( mp( tgh.fi, awl.sc ),  mp( akh.fi, tgh.sc ),  '0' );
     
    fill( tgh, akh, '1' );
    cetak(); scanf("%d",&d);
    fill( tgh, akh, '0' );
     
     
    //=== get_ans ===
    int mx = max( max( a,b ), max( c,d ) ),
        mn = min( min( a,b ), min( c,d ) );
    //!printf("> mn=%d  mx=%d\n", mn, mx);
     
    if (mn == a) fill( awl, tgh, '1' );
    if (mn == b) fill( mp( awl.fi, tgh.sc ),  mp( tgh.fi, akh.sc ), '1' );
    if (mn == c) fill( mp( tgh.fi, awl.sc ),  mp( akh.fi, tgh.sc ), '1' );
    if (mn == d) fill( tgh, akh, '1' );
     
    if ( (mn < a) && (a < mx) ) paruh( awl, tgh );
    if ( (mn < b) && (b < mx) ) paruh( mp( awl.fi, tgh.sc ),  mp( tgh.fi, akh.sc ) );
    if ( (mn < c) && (c < mx) ) paruh( mp( tgh.fi, awl.sc ),  mp( akh.fi, tgh.sc ) );
    if ( (mn < d) && (d < mx) ) paruh( tgh, akh );
     
}