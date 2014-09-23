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
#define MAXN 200005

typedef long long ll;
using namespace std;

char cs[MAXN],c[MAXN],rc[MAXN];

int n,k;
int Rank[MAXN+1];
int tmp[MAXN+1];
int sa[MAXN+1],lcp[MAXN+1];

bool compare_sa(int i,int j){
	if(Rank[i]!=Rank[j])
		return Rank[i]<Rank[j];
	else{
		int ri=i+k<=n ? Rank[i+k]:-1;
		int rj=j+k<=n ? Rank[j+k]:-1;
		return ri<rj;
	}
}

void construct_sa(string S,int *sa){
	n=S.length();
	for(int i=0;i<=n;i++){
		sa[i]=i;
		Rank[i]=i<n ? S[i]:-1;
	}
	for(k=1;k<=n;k*=2){
		sort(sa,sa+n+1,compare_sa);
		tmp[sa[0]]=0;
		for(int i=1;i<=n;i++)
			tmp[sa[i]]=tmp[sa[i-1]]+(compare_sa(sa[i-1],sa[i]) ? 1:0);
		for(int i=0;i<=n;i++)
			Rank[i]=tmp[i];
	}
}


void construct_lcp(string S,int *sa,int *lcp){
	int n=S.length();
	for(int i=0;i<=n;i++)
		Rank[sa[i]]=i;
	int h=0;
	lcp[0]=0;
	for(int i=0;i<n;i++){
		int j=sa[Rank[i]-1];
		if(h>0)
			h--;
		for(;j+h<n&&i+h<n;h++){
			if(S[j+h]!=S[i+h])
				break;
		}
		lcp[Rank[i]-1]=h;
	}
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",cs);
		char last=cs[0];
		int cnt=0;
		for(int i=1;i<strlen(cs);i++){
			if(cs[i]!=last){
				c[cnt++]=last;
				last=cs[i];
			}
		}
		if(c[cnt-1]!=cs[strlen(cs)-1])
			c[cnt++]=cs[strlen(cs)-1];
		c[cnt]='\0';
		string s1(c);
		for(int i=0;i<cnt;i++)
			rc[i]=c[cnt-1-i];
		rc[cnt]='\0';
		string s2(rc);
		string s=s1+'\0'+s2;
		construct_sa(s,sa);
		construct_lcp(s,sa,lcp);
		int ans=0;
		for(int i=0;i<s.length();i++){
			if((sa[i]<cnt)!=(sa[i+1]<cnt)){
				ans=max(ans,lcp[i]);
			}
		}
		printf("%d\n",(ans+1)/2);
	}
	return 0;
}
