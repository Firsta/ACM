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

int a[7],b[7];

int main(){
	while(~scanf("%d%d%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6])){
		bool flag=false;
		for(int i=0;i<=6;i++)
			if(a[i]!=0){
				flag=true;
				break;
			}
		if(!flag)
			break;
	  	int ans=0;	
		ans+=a[0]/20;
		if(a[0]%20!=0){
			if(20-a[0]%20<=a[1])
				a[1]-=(20-a[0]%20);
			else
				a[1]=0;
			ans++;
		}
		ans+=a[1]/20;
		if(a[1]%20!=0){
			if(20-a[1]%20<=a[2])
				a[2]-=(20-a[1]%20);
			else
				a[2]=0;
			ans++;
		}
		ans+=a[2]/20;
		if(a[2]%20!=0){
			if(20-a[2]%20<=a[3])
				a[3]-=(20-a[2]%20);
			else
				a[3]=0;
			ans++;
		}
		ans+=a[3]/25;
		if(a[3]%25!=0){
			if(25-a[3]%25<=a[4])
				a[4]-=(25-a[3]%25);
			else
				a[4]=0;
			ans++;
		}
		ans+=a[4]/25;
		if(a[4]%25!=0){
			if(25-a[4]%25<=a[5])
				a[5]-=(25-a[4]%25);
			else
				a[5]=0;
			ans++;
		}
		ans+=a[5]/30;
		if(a[5]%30!=0){
			if(30-a[5]%30<=a[6])
				a[6]-=(30-a[5]%30);
			else
				a[6]=0;
			ans++;
		}
		ans+=a[6]/30;
		if(a[6]%30!=0){
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}

