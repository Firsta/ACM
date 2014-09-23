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
#define inf 100005.0

typedef long long ll;
using namespace std;

double cable[10005];
int n,k;

bool judge(double mid)
{
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=floor(cable[i]/mid);
	return sum>=k;
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%lf",&cable[i]);
	double lb,ub;
	lb=0,ub=inf;
	for(int i=0;i<100;i++)
	{
		double mid=(lb+ub)/2;
		if(judge(mid))
			lb=mid;
		else
			ub=mid;
	}
	printf("%.2lf",floor(lb*100)/100);
	return 0;
}
