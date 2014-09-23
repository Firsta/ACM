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

int to(char c){
	if(c>='3'&&c<='9')
		return c-'0';
	if(c=='T')
		return 10;
	if(c=='J')
		return 11;
	if(c=='Q')
		return 12;
	if(c=='K')
		return 13;
	if(c=='A')
		return 14;
	if(c=='2')
		return 15;
	if(c=='X')
		return 16;
	if(c=='Y')
		return 17;
	return 0;
}

int a[20],b[20];
int cnta[18],cntb[18];

int main(){
	int t;
	scanf("%d",&t);
	string s;
	while(t--){
		memset(cnta,0,sizeof(cnta));
		memset(cntb,0,sizeof(cntb));
		cin>>s;
		int lena=s.size();
		for(int i=0;i<s.size();i++){
			a[i]=to(s[i]);
			cnta[a[i]]++;
		}
		cin>>s;
		int lenb=s.size();
		for(int i=0;i<s.size();i++){
			b[i]=to(s[i]);
			cntb[b[i]]++;
		}
		sort(a,a+lena);
		sort(b,b+lenb);
		//出光
		if(lena==1){
			printf("Yes\n");
			continue;
		}
		if(lena==2&&a[0]==a[1]){
			printf("Yes\n");
			continue;
		}
		if(lena==3&&a[0]==a[1]&&a[1]==a[2]){
			printf("Yes\n");
			continue;
		}
		if(lena==4){
			if(a[0]==a[1]&&a[1]==a[2]){
				printf("Yes\n");
				continue;
			}else if(a[1]==a[2]&&a[2]==a[3]){
				printf("Yes\n");
				continue;
			}
		}
		if(lena==5){
			if(a[0]==a[1]&&a[1]==a[2]&&a[3]==a[4]){
				printf("Yes\n");
				continue;
			}else if(a[2]==a[3]&&a[3]==a[4]&&a[0]==a[1]){
				printf("Yes\n");
				continue;
			}
		}
		if(lena==6){
			if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3]){
				printf("Yes\n");
				continue;
			}else if(a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4]){
				printf("Yes\n");
				continue;
			}else if(a[2]==a[3]&&a[3]==a[4]&&a[4]==a[5]){
				printf("Yes\n");
				continue;
			}
		}
		//X-Y
		bool findx=false,findy=false;
		for(int i=0;i<lena;i++){
			if(a[i]==to('X'))
				findx=true;
			if(a[i]==to('Y'))
				findy=true;
		}
		if(findx&&findy){
			printf("Yes\n");
			continue;
		}
		findx=false,findy=false;
		for(int i=0;i<lenb;i++){
			if(b[i]==to('X'))
				findx=true;
			if(b[i]==to('Y'))
				findy=true;
		}
		if(findx&&findy){
			printf("No\n");
			continue;
		}
		//炸弹
		int maxa=0,maxb=0;
		for(int i=17;i>=3;i--){
			if(cnta[i]==4){
				maxa=i;
				break;
			}
		}
		for(int i=17;i>=3;i--){
			if(cntb[i]==4){
				maxb=i;
				break;
			}
		}
		if(maxa!=maxb){
			if(maxa>maxb){
				printf("Yes\n");
				continue;
			}
			else{
				printf("No\n");
				continue;
			}
		}
		//1个
		if(a[lena-1]>b[lenb-1]){
			printf("Yes\n");
			continue;
		}
		//1 pair
		maxa=0,maxb=0;
		for(int i=17;i>=3;i--){
			if(cnta[i]>=2){
				maxa=i;
				break;
			}
		}
		for(int i=17;i>=3;i--){
			if(cntb[i]>=2){
				maxb=i;
				break;
			}
		}
		if(maxa>maxb){
			printf("Yes\n");
			continue;
		}
		//1 trio
		maxa=0,maxb=0;
		for(int i=17;i>=3;i--){
			if(cnta[i]>=3){
				maxa=i;
				break;
			}
		}
		for(int i=17;i>=3;i--){
			if(cntb[i]>=3){
				maxb=i;
				break;
			}
		}
		if(maxa>maxb){
			printf("Yes\n");
			continue;
		}
		//Trio-Solo
		maxa=0,maxb=0;
		for(int i=17;i>=3;i--){
			if(cnta[i]>=3&&lena-cnta[i]>0){
				maxa=i;
				break;
			}
		}
		for(int i=17;i>=3;i--){
			if(cntb[i]>=3&&lenb-cntb[i]>0){
				maxb=i;
				break;
			}
		}
		if(maxa>maxb){
			printf("Yes\n");
			continue;
		}
		//Trio-Pair
		maxa=0,maxb=0;
		for(int i=17;i>=3;i--){
			if(cnta[i]>=3){
				bool flag=false;
				for(int j=3;j<=17;j++){
					if(cnta[j]>=2&&j!=i){
						flag=true;
					}
				}
				if(flag){
					maxa=i;
					break;
				}
			}
		}
		for(int i=17;i>=3;i--){
			if(cntb[i]>=3){
				bool flag=false;
				for(int j=3;j<=17;j++){
					if(cntb[j]>=2&&j!=i){
						flag=true;
					}
				}
				if(flag){
					maxb=i;
					break;
				}
			}
		}
		if(maxa>maxb){
			printf("Yes\n");
			continue;
		}
		//Four-Dual
		maxa=0,maxb=0;
		for(int i=17;i>=3;i--){
			if(cnta[i]==4&&lena-cnta[i]>=2){
				maxa=i;
				break;
			}
		}
		for(int i=17;i>=3;i--){
			if(cntb[i]==4&&lenb-cntb[i]>=2){
				maxb=i;
				break;
			}
		}
		if(maxa>maxb){
			printf("Yes\n");
			continue;
		}
		printf("No\n");
		continue;
	}
	return 0;
}
