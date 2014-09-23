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
#define MAXN 100100

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main(){
	string s1,s2;
	cin>>s1>>s2;
	int lena=s1.size(),lenb=s2.size();
	while(1){
		bool find=false;
		for(int i=0;i<lena-2;i++){
				if(s1[i]=='1'&&s1[i+1]=='0'&&s1[i+2]=='0'){
					s1[i]='0';
					s1[i+1]='1';
					s1[i+2]='1';
					find=true;
				}
		}
		for(int i=lena-1;i>=2;i--){
			if(s1[i]=='0'&&s1[i-1]=='0'&&s1[i-2]=='1'){
				s1[i]='1';
				s1[i-1]='1';
				s1[i-2]='0';
				find=true;
			}
		}
		if(!find)
			break;
	}
	while(1){
		bool find=false;
		for(int i=0;i<lenb-2;i++){
				if(s2[i]=='1'&&s2[i+1]=='0'&&s2[i+2]=='0'){
					s2[i]='0';
					s2[i+1]='1';
					s2[i+2]='1';
					find=true;
				}
		}
		for(int i=lenb-1;i>=2;i--){
			if(s2[i]=='0'&&s2[i-1]=='0'&&s2[i-2]=='1'){
				s2[i]='1';
				s2[i-1]='1';
				s2[i-2]='0';
				find=true;
			}
		}
		if(!find)
			break;
	}
	int b1,b2,len1,len2;
	b1=0;
	while(s1[b1]=='0'&&b1<lena)
		b1++;
	b2=0;
	while(s2[b2]=='0'&&b2<lenb)
		b2++;
	len1=lena-b1;
	len2=lenb-b2;
	if(len1>len2)
		cout<<'>';
	else if(len1<len2)
		cout<<'<';
	else{
		for(;b1<lena&&b2<lenb;b1++,b2++){
			if(s1[b1]=='1'&&s2[b2]=='0'){
				cout<<'>';
				return 0;
			}else if(s1[b1]=='0'&&s2[b2]=='1'){
				cout<<'<';
				return 0;
			}
		}
		cout<<'=';
	}
//	cout<<s1<<endl<<s2<<endl;
	return 0;
}
