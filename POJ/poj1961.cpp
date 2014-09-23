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

int n;
string s;

int f[1000005];

int main(){
	int cas=0;
	while(~scanf("%d",&n)&&n){
		cin>>s;
		int m=s.size();
		f[0]=f[1]=0;
		for(int i=1;i<m;i++){
			int j=f[i];
			while(j&&s[i]!=s[j])
				j=f[j];
			f[i+1]=(s[i]==s[j]?j+1:0);
		}
		printf("Test case #%d\n",++cas);
		for(int i=2;i<=m;i++)
			if(f[i]>0&&i%(i-f[i])==0)
				printf("%d %d\n",i,i/(i-f[i]));
		puts("");
	}
	return 0;
}
