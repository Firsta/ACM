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

map<int,int> mx,block;
map<int,set<int> > ms;

int main(){
	string mode;
	int tri,item;
	while((cin>>mode)&&(mode!="#")){
		scanf("%d%d",&tri,&item);
		if(block[tri]){
			printf("IGNORED\n");
		}else if(mode=="S"){
			if(mx[item]==0){
				ms[item].insert(tri);
				printf("GRANTED\n");
			}else if(mx[item]==tri){
				printf("GRANTED\n");
			}else{
				printf("DENIED\n");
				block[tri]=1;
			}
		}else if(mode=="X"){
			if(mx[item]!=0){
				if(mx[item]==tri){
					printf("GRANTED\n");
				}else{
					printf("DENIED\n");
					block[tri]=1;
				}
			}else if(mx[item]==0){
				if(ms[item].size()!=0){
					if(ms[item].size()==1&&ms[item].count(tri)){
						printf("GRANTED\n");
						mx[item]=tri;
					}else{
						printf("DENIED\n");
						block[tri]=1;
					}
				}else{
					printf("GRANTED\n");
					mx[item]=tri;
				}
			}
		}
	}
	return 0;
}
