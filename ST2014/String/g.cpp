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

int n,k;
int rank[MAXN+1];
int lcp[MAXN+1];
int tmp[MAXN+1];

bool compare_sa(int i,int j){
	if(rank[i]!=rank[j])
		return rank[i]<rank[j];
	else{
		int ri=i+k<=n ? rank[i+k] : -1;
		int rj=j+k<=n ? rank[j+k] : -1;
		return ri<rj;
	}
}

void construct_sa(string S,int *sa){
	n=S.length();
	for(int i=0;i<=n;i++){
		sa[i]=i;
		rank[i]=i<n ? S[i] : -1;
	}
	for(k=1;k<=n;k*=2){
		sort(sa,sa+n+1,compare_sa);
		tmp[sa[0]]=0;
		for(int i=1;i<=n;i++){
			tmp[sa[i]]=tmp[sa[i-1]]+(compare_sa(sa[i-1],sa[i]) ? 1:0);
		}
		for(int i=0;i<=n;i++)
			rank[i]=tmp[i];
	}
}

void construct_lcp(string S,int *sa,int *lcp){
	int n=S.length();
	for(int i=0;i<=n;i++)
		rank[sa[i]]=i;
	int h=0;
	lcp[0]=0;
	for(int i=0;i<n;i++){
		int j=sa[rank[i]-1];
		if(h>0)
			h--;
		for(;j+h<n&&i+h<n;h++){
			if(S[j+h]!=S[i+h])
				break;
		}
		lcp[rank[i]-1]=h;
	}
}

int sa[MAXN];

int main(){
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		int m;
		scanf("%d",&m);
		string s;
		while(m--)
		{
			string tmp;
			cin>>tmp;
			s+='\0'+tmp;
		}
		construct_sa(s,sa);
		construct_lcp(s,sa,lcp);
		for(int i=0;i<s.length();i++){
			bool flag=true;
			for(int j=0;j<m;j++){
				if(found(start[j],ending[j],i,i+j)!=1){
					flag=false;
				}
			}
			if(!flag)
				continue;
			else{
				for(int j=0;j<m-1;j++){
					if(lcp[j+i]!=lcp[j+i+1])
						continue;
					else
						ans=max(ans,lcp[i+j]);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
