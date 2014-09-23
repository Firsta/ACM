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

int grid[50][50];
int mark[50][50];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&grid[i][j]);
	for(int i=1;i<=n;i++)
		grid[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(grid[i][k]+grid[k][j]>grid[i][j]&&grid[i][j]==1){
					mark[i][j]=1;
				}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout<<mark[i][j];
	}
	return 0;
}
