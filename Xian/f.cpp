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

int a[6],b[6],t[6],vis[1000000],ans;

bool judge(){
	bool flag=true;
	for(int i=0;i<6;i++)
		if(a[i]!=t[i])
			flag=false;
	return flag;
}

void rCD(){
	int tmp=t[4];
	t[4]=t[0];
	t[0]=t[5];
	t[5]=t[1];
	t[1]=tmp;
}

void rCG(){
	int tmp=b[2];
	t[2]=t[0];
	t[0]=t[3];
	t[3]=t[1];
	t[1]=tmp;
}

void rDH(){
	int tmp=b[3];
	t[3]=t[0];
	t[0]=t[2];
	t[2]=t[1];
	t[1]=tmp;
}

void rGH(){
	int tmp=b[4];
	t[4]=t[1];
	t[1]=t[5];
	t[5]=t[0];
	t[0]=tmp;
}

struct node{
	int hash,step;
	node(int hash,int step):hash(hash),step(step){

	}
};

int bfs(int hash){
	queue<node> q;
	q.push(node(hash,0));
	vis[hash]=1;
	while(!q.empty()){
		node nn=q.front();q.pop();
		int now=nn.hash;
		int cnt=5;
		while(now){
			t[cnt--]=now%10;
			now/=10;
		}
		rCD();
		int ha=0;
		for(int i=0;i<5;i++)
			ha=ha*10+t[i];
		if(ha==th)
			return nn.step+1;
		if(!vis[ha]){
			vis[ha]=1;
			q.push(node(ha,nn.step+1));
		}
		rGH();
		rGH();
		ha=0;
		for(int i=0;i<5;i++)
			ha=ha*10+t[i];
		if(ha==th)
			return nn.step+1;
		if(!vis[ha]){
			vis[ha]=1;
			q.push(node(ha,nn.step+1));
		}
		rCD();
		rCG();
		ha=0;
		for(int i=0;i<5;i++)
			ha=ha*10+t[i];
		if(ha==th)
			return nn.step+1;
		if(!vis[ha]){
			vis[ha]=1;
			q.push(node(ha,nn.step+1));
		}
		rDH();
		rDH();
		ha=0;
		for(int i=0;i<5;i++)
			ha=ha*10+t[i];
		if(ha==th)
			return nn.step+1;
		if(!vis[ha]){
			vis[ha]=1;
			q.push(node(ha,nn.step+1));
		}
	}
	return -1;
}

int main(){
	while(~scanf("%d",&a[0])){
		memset(vis,0,sizeof(vis));
		for(int i=1;i<6;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<6;i++)
			scanf("%d",&b[i]);
		int hash=0;
		bool find=true;
		for(int i=0;i<6;i++)
			if(a[i]!=b[i])
				find=false;
		if(find){
			printf("0\n");
			continue;
		}
		for(int i=0;i<6;i++)
			hash=hash*10+b[i];
		printf("%d\n",bfs(hash));
	}
	return 0;
}
