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

int s[4][4],ans;

int lay0[4][4]={
	{1,1,2,2},
	{1,1,2,2},
	{4,4,3,3},
	{4,4,3,3},
};

int lay1[4][4]={
	{4,4,1,1},
	{4,4,1,1},
	{3,3,2,2},
	{3,3,2,2},
};

int lay2[4][4]={
	{3,3,4,4},
	{3,3,4,4},
	{2,2,1,1},
	{2,2,1,1},
};

int lay3[4][4]={
	{2,2,3,3},
	{2,2,3,3},
	{1,1,4,4},
	{1,1,4,4},
};

int lay[4][4][4];
void rotate90(int l){
	int tmp[4][4];
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			tmp[i][j]=s[i][j];
	if(l==0){
		tmp[0][1]=s[2][0];
		tmp[1][3]=s[0][1];
		tmp[3][2]=s[1][3];
		tmp[2][0]=s[3][2];
	}
	if(l==1){
		tmp[0][2]=s[1][0];
		tmp[1][0]=s[3][1];
		tmp[3][1]=s[2][3];
		tmp[2][3]=s[0][2];
	}
	if(l==2){
		tmp[1][1]=s[2][1];
		tmp[1][2]=s[1][1];
		tmp[2][2]=s[1][2];
		tmp[2][1]=s[2][2];
	}
	if(l==3){
		tmp[0][0]=s[3][0];
		tmp[0][3]=s[0][0];
		tmp[3][3]=s[0][3];
		tmp[3][0]=s[3][3];
	}
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			s[i][j]=tmp[i][j];
}

void dfs(int cnt,int l){
	if(l==4){
		bool yes=false;
		for(int i=0;i<4;i++){
			bool flag=true;
			for(int j=0;j<4;j++){
				if(!flag)
					break;
				for(int k=0;k<4;k++)
					if(s[j][k]!=lay[i][j][k]){
						flag=false;
						break;
					}
			}
			if(flag){
				yes=true;
				break;
			}
		}
		if(yes)
		{
			ans=min(ans,cnt);
//			cout<<"cnt:"<<cnt<<endl;
		}
		return;
	}
	for(int i=0;i<4;i++){
		rotate90(l);
		if(i==3)
			dfs(cnt+1,l+1);
		else
			dfs(cnt+i,l+1);
	}
	return;
}

int main(){
	for(int i=0;i<4;i++){
		if(i==0){
			for(int j=0;j<4;j++)
				for(int k=0;k<4;k++)
					lay[i][j][k]=lay0[j][k];
		}
		if(i==1){
			for(int j=0;j<4;j++)
				for(int k=0;k<4;k++)
					lay[i][j][k]=lay1[j][k];
		}
		if(i==2){
			for(int j=0;j<4;j++)
				for(int k=0;k<4;k++)
					lay[i][j][k]=lay2[j][k];
		}
		if(i==3){
			for(int j=0;j<4;j++)
				for(int k=0;k<4;k++)
					lay[i][j][k]=lay3[j][k];
		}
	}
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			scanf("%d",&s[i][j]);
	ans=4*4*4*4*4;
	dfs(0,0);
//	rotate(0,3);
//	for(int i=0;i<4;i++){
//		for(int j=0;j<4;j++)
//			cout<<s[i][j]<<' ';
//		cout<<endl;
//	}
	printf("%d\n",ans);
	return 0;
}
