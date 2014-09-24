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

int check(char c){
	if(c=='A'||c=='B'||c=='C')
		return 2;
	if(c=='D'||c=='E'||c=='F')
		return 3;
	if(c=='G'||c=='H'||c=='I')
		return 4;
	if(c=='J'||c=='K'||c=='L')
		return 5;
	if(c=='M'||c=='N'||c=='O')
		return 6;
	if(c=='P'||c=='R'||c=='S')
		return 7;
	if(c=='T'||c=='U'||c=='V')
		return 8;
	if(c=='W'||c=='X'||c=='Y')
		return 9;
	return 0;
}

map<int,int> m;
vector<int> ans;

int main(){
	int n;
	scanf("%d",&n);
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		int tmp=0;
		for(int j=0;j<s.size();j++){
			if(s[j]>='0'&&s[j]<='9')
				tmp=tmp*10+(s[j]-'0');
			else if(s[j]<='Z'&&s[j]>='A'&&s[j]!='Q'&&s[j]!='Z')
				tmp=tmp*10+check(s[j]);
		}
		m[tmp]++;
		if(m[tmp]==2)
			ans.push_back(tmp);
	}
	if(ans.size()==0){
		printf("No duplicates.\n");
		return 0;
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++){
		vector<int> s;
		int tmp=ans[i];
		for(int j=0;j<7;j++){
			s.push_back(tmp%10);
			tmp/=10;
		}
		for(int j=6;j>=0;j--){
			if(j==3)
				printf("-");
			printf("%c",'0'+s[j]);
		}
		printf(" %d\n",m[ans[i]]);
	}
	return 0;
}
