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
#define MAXN 1005
#define EPS 1e-9
// kopas template sepiring bertiga :3
struct point {
	double x,y;										
	point() { x = y = 0.0; }
	point(double _x, double _y) : x(_x), y(_y) {}
	bool operator == (point other) const {
		return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
	}
};

// >>>> Constructor of line (ax + by = c)
struct line {
	double a,b,c;
};
// >>>> Constructor of vector
struct vec {
	double x, y;
	vec(double _x, double _y) : x(_x), y(_y) {}
};

// Distance of two points
double dist(point p1, point p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

// Convert 2 points to vector A -> B
vec toVec(point a, point b) {
	return vec(b.x - a.x, b.y - a.y);
}

// Scale a vector
vec scale(vec v, double s) {
	return vec(v.x * s, v.y * s);
}

// Translate P according to v
point translate(point p, vec v) {
	return point(p.x + v.x, p.y + v.y);
}

// Dot product of two vectors
double dot(vec a, vec b) {
	return a.x * b.x + a.y * b.y;
}

// Cross product of two vectors
double cross(vec a, vec b) {
	return a.x * b.y - a.y * b.x;
}

// .......................
double norm_sq(vec v) {
	return v.x * v.x + v.y * v.y;
}
// Make a line l from 2 given points
void pointsToLine(point p1, point p2, line &l) {
	if (fabs(p1.x - p2.x) < EPS) {
		l.a = 1.0 ; l.b = 0.0 ; l.c = -p1.x;
	} else {
		l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
		l.b = 1.0;
		l.c = -(double)(l.a * p1.x) - p1.y;
	}
}

// Check if two lines are parallel
bool areParallel(line l1, line l2) {
	return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}

// Check if two lines are intersect (at point P)
bool areIntersect(line l1, line l2, point &p) {
	if (areParallel(l1, l2)) return false;
	p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
					else  p.y = -(l2.a * p.x + l2.c);
	return true;
}

// Get the minimum distance of point P and line AB
// Line PC is the minimum distance
double distToLine(point p, point a, point b, point &c) {
	vec ap = toVec(a, p), ab = toVec(a,b);
	double u = dot(ap, ab) / norm_sq(ab);
	c = translate(a, scale(ab, u));
	return dist(p,c);
}
int r,x,y,n,ans;
pair<point,point> kya2[MAXN];
line kya[MAXN];
point tmp;
int a,b,c,d;

int main(){
	while (1){
		scanf("%d %d %d %d",&r,&x,&y,&n);
		if (r == 0) return 0;
		ans = 1;
		for (int i = 0; i < n; ++i){
			scanf("%d %d %d %d",&a,&b,&c,&d);
			pointsToLine(point(a,b),point(c,d),kya[i]);
			kya2[i] = make_pair(point(a,b),point(c,d));
		}
		for (int i = 0; i < n; ++i){
			if (distToLine(point(x,y),kya2[i].fi,kya2[i].se,tmp) >= r) continue; // ga intersect sama lingkaran
			ans++;
			//cout << i << endl;
			for (int j = 0; j < i; ++j){
				if (areIntersect(kya[i],kya[j],tmp)){
					if (dist(tmp,point(x,y))<r) {
						ans++;
			//			cout << i << " " <<j << endl;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
}