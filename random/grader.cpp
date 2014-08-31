#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <memory.h>
#include <pthread.h>
#include <unistd.h>
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

/**
 * Start of reactive1 checker template
 * */
 
#include <fstream>
#include <assert.h>
 
#define OK "[OK]"
#define FAILED "[FAILED]"

pthread_t t;
 
using namespace std;
 
FILE *Testcase;
 
/**
 * This program will be called with command: [PROBLEM_PATH]/grader [TESTCASE], with argc == 2
 * You are free to re-arrange, modify or ignore arguments in your problem configuration.
 * */

int n, m;
char ans[260][260];
char kasus[2048];

//On failure 
void fail()
{
    cerr << FAILED << endl;
    exit(0);
}

//On success
void woke()
{
	printf("selesai\n"); fflush( stdout );
	cerr << OK << endl;
	cerr << 100 << endl;
	exit( 0 );
}

void* guard(void*) {
	int i = 0;
	while (i <= 5) {
		i++;
		sleep(1);
	}
	fail();
}

int get_ipt()
{
	char i[n+3][n+3];
	ren (y,0,n) gets( i[y] );
	int ret = 0;
	ren (y,0,n) ren(x,0,n)
		if (i[y][x] != ans[y][x]) ++ret;
	return ret;
}

void DEBUGTABLE()
{
	printf("========\n");
	ren(y,0,n)
	{
		ren(x,0,n) printf("%c", ans[y][x]);
		printf("\n");
	}
	printf("========\n");
}

int main(int argc , char** argv) {
    assert(argc == 2);
    
    //pthread_create(&t , NULL , guard , NULL);
     
    Testcase = fopen( argv[1], "r" );
    fscanf( Testcase, "%[^\n]", kasus );
    fscanf( Testcase, "%*c" );
    fscanf( Testcase, "%d", &n);
    fscanf( Testcase, "%*c" );
    ren(y,0,n)
    {
		ren(x,0,n) fscanf( Testcase, "%c", &ans[y][x] );
		fscanf( Testcase, "%*c" );
	}
	fscanf( Testcase, "%d", &m );
    
    ///Checker logic here. Use stdin (cin) and stdout (cout) to interact with contestant program
    //DEBUGTABLE();
    printf( "%s\n", kasus ); fflush( stdout );
    printf( "%d\n", n ); fflush( stdout );
    
    int cnt = 0;
    try
    {
		while (true)
		{
			if (++cnt > m) fail();
			int a = get_ipt();
			if (a) printf("%d\n", a), fflush( stdout );
				else woke();
		}
	}
	
	catch( exception e ){}
     
    ///Output, use stderr (cerr)
    //On failure
    cerr << FAILED << endl;
     
    return 0;
}
