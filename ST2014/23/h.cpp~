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

int hash[100005];

int main(){
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		hash[i]=-1;
	int m;
	scanf("%d",&m);
	while(m--){
		int a;char c;
		scanf("%d %c",&a,&c);
		hash[a-1]=c-'a';
	}
	if(s.size()<7){
		printf("Goodbye, my love!");
		return 0;
	}
	if(s.find("desmond")!=-1){
		printf("I love you, Desmond!\n");
		printf("%d",0);
		return 0;
	}
	int cnt=0;
	string ex="desmond";
	for(int i=0;i<s.size();i++){
		string tmp;
		if(i>=6){
			tmp=s.substr(i-6,7);
			if(tmp==ex){
				printf("I love you, Desmond!\n");
				printf("%d",cnt);
				return 0;
			}
		}
		if(i<s.size()-6){
			tmp=s.substr(i,7);
			if(tmp==ex){
				printf("I love you, Desmond!\n");
	//			cout<<tmp<<endl;
				printf("%d",cnt);
				return 0;
			}
		}
		if(hash[i]!=-1){
			cnt++;
			s[i]='a'+hash[i];
		}
		if(i>=6){
			tmp=s.substr(i-6,7);
			if(tmp==ex){
				printf("I love you, Desmond!\n");
				printf("%d",cnt);
				return 0;
			}
		}
		if(i<s.size()-6){
			tmp=s.substr(i,7);
			if(tmp==ex){
				printf("I love you, Desmond!\n");
				printf("%d",cnt);
				return 0;
			}
		}
	}
	printf("Goodbye, my love!");
	return 0;
}
