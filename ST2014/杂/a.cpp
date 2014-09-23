#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<cmath>
#include<sstream>
#include<string>
#define MAXN 50
#define eps 1e-9

typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int n; 
// Point
struct Point{
	double x,y;
	//constructor
	Point(double x=0,double y=0):x(x),y(y){

	}
}p[MAXN];

typedef Point Vector;

//Point-Point=Vector or Vector-Vector=Vector
Vector operator - (Point A,Point B){
	return Vector(A.x-B.x,A.y-B.y);
}

double Dot(Vector A,Vector B){
	return A.x*B.x+A.y*B.y;
}

double Length(Vector A){
	return sqrt(Dot(A,A));
}

Vector Rotate(Vector A,double rad){
	return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));
}

double f(double m){
	Point t1,t2;
	double maxx=-505,minx=505,maxy=-505,miny=505;
	for(int i=0;i<n;i++){
		t1=Rotate(p[i],m);
		maxx=max(maxx,t1.x);
		minx=min(minx,t1.x);
		maxy=max(maxy,t1.y);
		miny=min(miny,t1.y);
	}
	double d=max(maxx-minx,maxy-miny);
	return d*d;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%lf%lf",&p[i].x,&p[i].y);
		}
		double l,r;
		l=0.0;r=acos(-1.0);
		double m1,m2;
		while(r-l>eps){
//			cout<<1<<endl;
			m1=l+(r-l)/3;
			m2=r-(r-l)/3;
			if(f(m1)>f(m2))
				l=m1;
			else
				r=m2;
		}
		printf("%.2f\n",f(l));
	}
	return 0;
}
