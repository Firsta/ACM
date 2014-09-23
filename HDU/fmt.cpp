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

typedef struct house
{
	double j;
	double f;
}house;
house h[1005];

bool cmp(const house &a,const house &b)
{
	if(a.j/a.f<b.j/b.f)
		return 0;
	else
		return 1;
}

int main()
{
	int m,n;
	while(cin>>m>>n&&(m!=-1&&n!=-1))
	{
		for(int i=0;i<n;i++)
			cin>>h[i].j>>h[i].f;
		sort(h,h+n,cmp);
		int i=0;
		double sum=0;
		while(1)
		{
			if(i==n)
				break;
			if(h[i].f<=m)
			{
				m-=h[i].f;
				sum+=h[i].j;
				i++;
			}
			else if(h[i].f>m&&m>0)
			{
				sum+=(h[i].j/h[i].f)*m;
				m=0;
			}
			else if(m<=0)
				break;
		}
		printf("%.3lf\n",sum);
	}
	return 0;
}
