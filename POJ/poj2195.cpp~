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

const int INF=INT_MAX;

char grid[105][105];
int w[105][105],Lx[105],Ly[105],left[105],slack[105],n,m;
bool S[105],T[105];

bool match(int i){
	S[i]=true;
	for(int j=1;j<=n;j++)
		if(!T[j]){
			if(Lx[i]+Ly[j]==w[i][j]){
				T[j]=true;
				if(!left[j]||match(left[j])){
					left[j]=i;
					return true;
				}
			}else
				slack[j]=std::min(slack[j],Lx[i]+Ly[j]-w[i][j]);
		}
	return false;
}

void update(){
	int a=INF;
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

void addEdge(int x,int y,int ind){
	int cnt=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(grid[i][j]=='H')
				w[ind][++cnt]=-(abs(i-x)+abs(j-y));
		}
}

int main(){
	while(~scanf("%d%d",&n,&m)&&(n||m)){
		char tmp[105];
		for(int i=0;i<n;i++){
			scanf("%s",tmp);
			for(int j=0;j<m;j++)
				grid[i][j]=tmp[j];
		}
		int cntm=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(grid[i][j]=='m'){
					addEdge(i,j,++cntm);
				}
		n=cntm;
		KM();
		int ans=0;
		for(int i=1;i<=n;i++)
			ans+=w[left[i]][i];
		printf("%d\n",-ans);
	}
	return 0;
}
