#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<sstream>
#include<vector>
#include<cstdio>
#include<string>
#include<stack>
#include<queue>
#include<cmath>
#include<map>
#include<set>

typedef long long ll;
using namespace std;

double Naomi[1001],Ken[1001];
bool visN[1001],visK[1001];

int main()
{
	freopen("in.txt","r", stdin);
 	freopen("out.txt", "w", stdout);
	int t;
	cin>>t;
	for(int cas=1;cas<=t;cas++)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>Naomi[i];
		for(int i=0;i<n;i++)
			cin>>Ken[i];
		sort(Naomi,Naomi+n);
		sort(Ken,Ken+n);
		int ans1=0,ans2=0;
		memset(visK,0,sizeof(visK));
		for(int i=0;i<n;i++)
		{
			bool flag=false;
			for(int j=0;j<n;j++)
			{
				if(Ken[j]>Naomi[i]&&!visK[j])
				{
					visK[j]=true;
					ans2++;
					flag=true;
					break;
				}
			}
			if(!flag)
			{
				for(int j=0;j<n;j++)
					if(!visK[j])
						visK[j]=true;
			}
		}
		memset(visN,0,sizeof(visN));
		for(int j=0;j<n;j++)
		{
			int flag=false;
			for(int i=0;i<n;i++)
				if(Naomi[i]>Ken[j]&&!visN[i])
				{
					ans1++;
					flag=true;
					visN[i]=true;
					break;
				}
			if(!flag)
				break;
		}
		printf("Case #%d: %d %d\n",cas,ans1,n-ans2);
	}
	return 0;
}
