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

const int MAXN=105;
const double INF=1e200;
const double EPS=1e-7;

double w[MAXN][MAXN],Lx[MAXN],Ly[MAXN],slack[MAXN];
int left[MAXN];
bool S[MAXN],T[MAXN];
int n;

struct Point{
	int x,y;
}ants[MAXN],apple[MAXN];

double Distance(Point &a,Point &b){
	return sqrt(double((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}

bool match(int i){
	S[i]=true;
	for(int j=1;j<=n;j++)
		if(!T[j]){
			double tmp=Lx[i]+Ly[j]-w[i][j];
			if(fabs(tmp)<EPS){
				T[j]=true;
				if(!left[j]||match(left[j])){
					left[j]=i;
					return true;
				}
			}else
				slack[j]=std::min(slack[j],tmp);
		}
	return false;
}

void update(){
	double a=INF;
	for(int i=1;i<=n;i++)
		if(!T[i])
			a=std::min(a,slack[i]);
	for(int i=1;i<=n;i++){
		if(S[i])
			Lx[i]-=a;
		if(T[i])
			Ly[i]+=a;
		else
			slack[i]-=a;
	}
}

void KM(){
	for(int i=1;i<=n;i++){
		left[i]=Lx[i]=Ly[i]=0;
		for(int j=1;j<=n;j++)
			Lx[i]=std::max(Lx[i],w[i][j]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			slack[j]=INF;
		for(;;){
			for(int j=1;j<=n;j++)
				S[j]=T[j]=0;
			if(match(i))
				break;
			else
				update();
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&ants[i].x,&ants[i].y);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&apple[i].x,&apple[i].y);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			w[i][j]=-Distance(apple[i],ants[j]);
	KM();
	for(int i=1;i<=n;i++){
		printf("%d\n",left[i]);
	}
	return 0;
}
