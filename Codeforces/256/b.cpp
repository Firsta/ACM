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

int marka[26],markb[26];

int main(){
	string a,b;
	cin>>a>>b;
	for(int i=0;i<a.size();i++){
		marka[a[i]-'a']++;
	}
	for(int i=0;i<b.size();i++){
		markb[b[i]-'a']++;
	}
	for(int i=0;i<26;i++){
		if(markb[i]>marka[i]){
			cout<<"need tree"<<endl;
			return 0;
		}
	}
	bool flag=true;
	for(int i=0;i<26;i++){
		if(markb[i]!=marka[i]){
			flag=false;
			break;
		}
	}
	if(flag){
		cout<<"array"<<endl;
		return 0;
	}
	int cnt=0;
	for(int i=0;i<a.size();i++){
		if(a[i]==b[cnt]){
			cnt++;
		}
	}
	if(cnt==b.size()){
		cout<<"automaton"<<endl;
		return 0;
	}else
		cout<<"both"<<endl;
	return 0;
}
