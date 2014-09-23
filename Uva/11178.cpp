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

typedef long long ll;
using namespace std;

// Point
struct Point{
	double x,y;
	//constructor
	Point(double x=0,double y=0):x(x),y(y){

	}
};
//Vector
typedef Point Vector;

//Vector+Vector=Vector
Vector operator + (Vector A,Vector B){
	return Vector(A.x+B.x,A.y+B.y);
}

//Point-Point=Vector or Vector-Vector=Vector
Vector operator - (Point A,Point B){
	return Vector(A.x-B.x,A.y-B.y);
}

//Vector*p=Vector
Vector operator * (Vector A,double p){
	return Vector(A.x*p,A.y*p);
}

//Vector/p=Vector
Vector operator / (Vector A,double p){
	return Vector(A.x/p,A.y/p);
}

//Point comparision
bool operator < (const Point& a,const Point& b){
	if(a.x==b.x){
		return a.y<b.y;
	}else
		return a.x<b.x;
}

double Dot(Vector A,Vector B){
	return A.x*B.x+A.y*B.y;
}

double Length(Vector A){
	return sqrt(Dot(A,A));
}

double Angle(Vector A,Vector B){
	return acos(Dot(A,B)/Length(A)/Length(B));
}

double Cross(Vector A,Vector B){
	return A.x*B.y-A.y*B.x;
}

Point GetLineIntersection(Point P,Vector v,Point Q,Vector w){
	Vector u=P-Q;
	double t=Cross(w,u)/Cross(v,w);
	return P+v*t;
}

Vector Rotate(Vector A,double rad){
	return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));
}

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		Point a,b,c;
		scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y);
		Point zero(0,0);
		Vector ab(b.x-a.x,b.y-a.y),bc(c.x-b.x,c.y-b.y),ca(a.x-c.x,a.y-c.y);
		double abc=Angle(ab,zero-ca);
		double bca=Angle(ca,zero-bc);
		double cab=Angle(ab,zero-ca);
		Point d=GetLineIntersection(b,Rotate(bc,abc/3),c,Rotate(zero-bc,-bca/3));
		Point e=GetLineIntersection(c,Rotate(ca,bca/3),a,Rotate(zero-ca,-cab/3));
		Point f=GetLineIntersection(a,Rotate(ab,cab/3),b,Rotate(zero-ab,-abc/3));
		printf("%f %f %f %f %f %f\n",d.x,d.y,e.x,e.y,f.x,f.y);
	}
	return 0;
}
