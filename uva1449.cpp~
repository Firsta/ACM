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

const int maxnode=20000;
const int sigma_size=26;
const int maxn=155;

int n;

struct AC{
	int ch[maxnode][sigma_size];
	int f[maxnode],val[maxnode],last[maxnode];
	int sz,cnt[maxn];
	map<string,int> ms;
	void init(){
		sz=1;
		memset(ch[0],0,sizeof(ch[0]));
		memset(cnt,0,sizeof(cnt));
		val[0]=last[0]=0;
		ms.clear();
	}
	AC(){
		init();
	}
	int idx(char c){
		return c-'a';
	}
	void insert(string s,int v){
		int u=0,n=s.size();
		for(int i=0;i<n;i++){
			int c=idx(s[i]);
			if(!ch[u][c]){
				memset(ch[sz],0,sizeof(ch[sz]));
				val[sz]=0;
				ch[u][c]=sz++;
			}
			u=ch[u][c];
		}
		val[u]=v;
		ms[s]=v;
	}
	int getFail(){
		queue<int> q;
		f[0]=0;
		for(int c=0;c<sigma_size;c++){
			int u=ch[0][c];
			if(u){
				f[u]=last[u]=0;
				q.push(u);
			}
		}
		while(!q.empty()){
			int r=q.front();q.pop();
			for(int c=0;c<sigma_size;c++){
				int u=ch[r][c];
				if(!u)
					continue;
				q.push(u);
				int v=f[r];
				while(v&&!ch[v][c])
					v=f[v];
				f[u]=ch[v][c];
				last[u]=val[f[u]] ? f[u]:last[f[u]];
			}
		}
	}
	void find(string T){
		int n=T.size();
		int u=0;
		for(int i=0;i<n;i++){
			int c=idx(T[i]);
			while(u&&!ch[u][c])
				u=f[u];
			u=ch[u][c];
			if(val[u])
				print(u);
			else if(last[u])
				print(last[u]);
		}
	}
	void print(int j){
		if(j){
			cnt[val[j]]++;
			print(last[j]);
		}
	}
}ac;

string s[maxn],S;

int main(){
	while(~scanf("%d",&n)&&n){
		ac.init();
		for(int i=1;i<=n;i++){
			cin>>s[i];
			ac.insert(s[i],i);
		}
		cin>>S;
		ac.getFail();
		ac.find(S);
		int maxx=0;
		for(int i=1;i<=n;i++)
			maxx=max(maxx,ac.cnt[i]);
		printf("%d\n",maxx);
		for(int i=1;i<=n;i++)
			if(ac.cnt[ac.ms[s[i]]]==maxx)
				cout<<s[i]<<endl;
	}
	return 0;
}
