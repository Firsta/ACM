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

int a[1005];

int main(){
	int n,p;
	scanf("%d%d",&n,&p);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
		a[i]=s[i]-'a';
	for(int i=len-1;i>=0;i--){
		bool find=false;
		for(int j=a[i]+1;j<p;j++)
			if((i==0||(i>0&&j!=a[i-1]))&&(i<=1||(i>1&&j!=a[i-2]))){
				a[i]=j;
		//		cout<<i<<' '<<j<<endl;
				find=true;
				break;
			}
		if(find){
			for(int j=i+1;j<len;j++)
				for(int k=0;k<p;k++)
					if((j==0||(j>0&&k!=a[j-1]))&&(j<=1||(j>1&&k!=a[j-2]))){
						a[j]=k;
						break;
					}
			for(int j=0;j<len;j++)
				printf("%c",'a'+a[j]);
			return 0;
		}
	}
	printf("NO");
	return 0;
}
