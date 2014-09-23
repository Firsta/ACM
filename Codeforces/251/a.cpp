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

int a[105];

int main()
{
	int n,d,sum=0;
	cin>>n>>d;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	if(sum+(n-1)*10>d)
		cout<<-1;
	else
		cout<<(d-sum)/5;
	return 0;
}
