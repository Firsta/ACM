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

int maxx[100005];
int vis[100005];

map<int,int> mapp;

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	bool flag=true;
	mapp.clear();
	for(int i=0;i<n;i++){
		int k,c;
		scanf("%d%d",&k,&c);
		bool update=false;
		while(k--){
			int p;
			scanf("%d",&p);
			if(maxx[p]==0){
				mapp[c]++;
				update=true;
				maxx[p]=c;
			}else if(maxx[p]>c){
				if(mapp[maxx[p]]==1)
					flag=false;
				else if(mapp[maxx[p]]>1){
					mapp[maxx[p]]--;
					maxx[p]=c;
					update=true;
					mapp[c]++;
				}
			}
			else if(maxx[p]<c)
				continue;
			else if(maxx[p]==c){
				update=true;
				continue;
			}
		}
		if(!update){
			flag=false;
		}
//		for(int i=1;i<=m;i++)
//			cout<<maxx[i]<<' ';
//		cout<<endl;
//		cout<<mapp[7]<<'!'<<endl;
	}
//	for(int i=1;i<=n;i++)
//		cout<<re[i]<<' ';
//	cout<<endl;
	if(!flag){
		cout<<"Poor memory"<<endl;
		return 0;
	}
	cout<<"Good memory"<<endl;
	if(maxx[1]==0)
		cout<<1;
	else
		cout<<maxx[1];
	for(int i=2;i<=m;i++){
		if(maxx[i]==0)
			cout<<' '<<1;
		else
			cout<<' '<<maxx[i];
	}
	return 0;
}
