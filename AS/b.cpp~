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
typedef unsigned long long ull;
using namespace std;
typedef vector<double> vec;
typedef vector<vec> mat;

const double PI = acos(-1.0);

mat mul(mat &A,mat &B){
	mat C(A.size(),vec(B[0].size()));
	for(int i=0;i<A.size();i++)
		for(int k=0;k<B.size();k++)
			for(int j=0;j<B[0].size();j++)
				C[i][j]=(C[i][j]+A[i][k]*B[k][j]);
	return C;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		mat all(3,vec(3));
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++){
				if(i==j){
					all[i][j]=1;
				}else
					all[i][j]=0;
			}
		scanf("%d",&n);
		double ap=0.0;
		for(int i=0;i<n;i++){
			double x,y,p;
			scanf("%lf%lf%lf",&x,&y,&p);
			ap+=p;
			mat A(3,vec(3));
			A[0][0]=1;A[0][1]=0;A[0][2]=-x;
			A[1][0]=0;A[1][1]=1;A[1][2]=-y;
			A[2][0]=0;A[2][1]=0;A[2][2]=1;
			all=mul(A,all);
			A[0][0]=cos(p);A[0][1]=-sin(p);A[0][2]=0;
			A[1][0]=sin(p);A[1][1]=cos(p);A[1][2]=0;
			A[2][0]=0;A[2][1]=0;A[2][2]=1;
			all=mul(A,all);
			A[0][0]=1;A[0][1]=0;A[0][2]=x;
			A[1][0]=0;A[1][1]=1;A[1][2]=y;
			A[2][0]=0;A[2][1]=0;A[2][2]=1;
			all=mul(A,all);
		}
		ap=fmod(ap,2*PI);
		double a=1-cos(ap),b=sin(ap),c=all[0][2],d=all[1][2];
		double y=(c*b+a*d)/(a*a+b*b);
		double x=(c-b*y)/a;
		printf("%.10f %.10f %.10f\n",x,y,ap);
	}
	return 0;
}
