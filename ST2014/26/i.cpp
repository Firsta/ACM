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

string line1[]={
	".*","*.","*.","**","**","*.","**","**","*.",".*"
};

string line2[]={
	"**","..","*.","..",".*",".*","*.","**","**","*."
};

string line3[]={
	"..","..","..","..","..","..","..","..","..",".."
};

int hash[105][10];

int main(){
	int d;
	while(~scanf("%d",&d)&&d){
		string s;
		cin>>s;
		if(s=="S"){
			cin>>s;
			cout<<line1[s[0]-'0'];
			for(int i=1;i<s.size();i++)
				cout<<' '<<line1[s[i]-'0'];
			printf("\n");
			cout<<line2[s[0]-'0'];
			for(int i=1;i<s.size();i++)
				cout<<' '<<line2[s[i]-'0'];
			printf("\n");
			cout<<line3[s[0]-'0'];
			for(int i=1;i<s.size();i++)
				cout<<' '<<line3[s[i]-'0'];
			printf("\n");
		}else if(s=="B"){
			memset(hash,0,sizeof(hash));
			string tmp;
			getchar();
			for(int i=1;i<=3;i++){
				getline(cin,s);
				if(s[s.size()-1]!=' ')
					s=s+' ';
				for(int j=0;j<s.size();j++)
					if(s[j]==' '){
						tmp=s.substr(j-2,2);
						for(int k=0;k<=9;k++){
							if(i==1){
								if(line1[k]==tmp){
									if(hash[(j+1)/3][k]==0)
										hash[(j+1)/3][k]=1;
								}else
									hash[(j+1)/3][k]=-1;
							}
							if(i==2){
								if(line2[k]==tmp){
									if(hash[(j+1)/3][k]==0)
										hash[(j+1)/3][k]=1;
								}else
									hash[(j+1)/3][k]=-1;
							}
							if(i==3){
								if(line3[k]==tmp){
									if(hash[(j+1)/3][k]==0)
										hash[(j+1)/3][k]=1;
								}else
									hash[(j+1)/3][k]=-1;
							}
						}
					}
			}
			for(int i=1;i<=d;i++)
				for(int j=0;j<=9;j++)
					if(hash[i][j]==1){
						printf("%d",j);
						break;
					}
			printf("\n");
		}
	}
	return 0;
}
