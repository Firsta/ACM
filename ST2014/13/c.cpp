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

string yuan[]={"h","he","li","be","b","c","n","o","f","ne","na","mg","al","si","p","s","cl","ar","k","ca","sc","ti","v","cr","mn","fe","co","ni","cu","zn","ga","ge","as","se","br","kr","rb","sr","y","zr","nb","mo","tc","ru","rh","pd","ag","cd","in","sn","sb","te","i","xe","cs","ba","hf","ta","w","re","os","ir","pt","au","hg","tl","pb","bi","po","at","rn","fr","ra","rf","db","sg","bh","hs","mt","ds","rg","cn","fl","lv","la","ce","pr","nd","pm","sm","eu","gd","tb","dy","ho","er","tm","yb","lu","ac","th","pa","u","np","pu","am","cm","bk","cf","es","fm","md","no","lr"};

int len;
string s;
map< string,int > mm;
int reach[50005];

int main(){
	//sum=114
	for(int i=0;i<114;i++)
		mm[yuan[i]]=1;
	int t;
	scanf("%d",&t);
	while(t--){
		cin>>s;
		string tmp;
		memset(reach,0,sizeof(reach));
		tmp=s.substr(0,2);
		if(mm[tmp])
			reach[2]=1;
		tmp=s.substr(0,1);
		if(mm[tmp])
			reach[1]=1;
		for(int i=1;i<s.size();i++){
			if(reach[i]){
				tmp=s.substr(i,2);
				if(mm[tmp])
					reach[i+2]=1;
				tmp=s.substr(i,1);
				if(mm[tmp])
					reach[i+1]=1;
			}
		}
		if(reach[s.size()])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
