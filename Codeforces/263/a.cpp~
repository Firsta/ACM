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

char grid[105][105];

int n;

bool count(int x,int y){
	int cnt=0;
	if(x-1>=0&&grid[x-1][y]=='o')
		cnt++;
	if(x+1<n&&grid[x+1][y]=='o')
		cnt++;
	if(y-1>=0&&grid[x][y-1]=='o')
		cnt++;
	if(y+1<n&&grid[x][y+1]=='o')
		cnt++;
	if(cnt%2==0)
		return true;
	else
		return false;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		char tmp[105];
		scanf("%s",tmp);
		for(int j=0;j<n;j++)
			grid[i][j]=tmp[j];
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			if(!count(i,j)){
				cout<<"NO";
				return 0;
			}
		}
	cout<<"YES";
	return 0;
}
