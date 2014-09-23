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

vector<int> a;
int vis[201];
int n,k,ans=-200001;

int maxsequence(vector<int> a, int len)
{
    int maxsum, maxhere;
    maxsum = maxhere = a[0];
    for (int i=1; i<len; i++) {
        if (maxhere <= 0)
            maxhere = a[i];
        else
            maxhere += a[i];
        if (maxhere > maxsum) {
            maxsum = maxhere;
        }
    }
    return maxsum;
}

void dfs(int x)
{
	int tm=maxsequence(a,n);
	if(tm>ans)
		ans=tm;
	if(x=k)
		return;
	else
	{
		for(int i=0;i<n-1;i++)
			for(int j=i+1;j<n;j++)
			{
				int t;
				if(!vis[i]||!vis[j])
				{
					vis[i]=vis[j]=1;
					t=a[j];
					a[j]=a[i];
					a[i]=t;
					dfs(x+1);
					vis[i]=vis[j]=0;
					a[i]=a[j];
					a[j]=t;
				}
			}
	}
}

int main()
{
	cin>>n>>k;
	int temp;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		a.push_back(temp);
	}
	dfs(0);
	cout<<ans;
	return 0;
}
