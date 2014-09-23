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

int a[1000005];
int b[1000005];

int main()
{
	stack<int> s;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];
	int ia=0,ib=0;
	bool flag=true;
	while(ib<n)
	{
		if(a[ia]==b[ib])
		{
			ia++;ib++;
		}
		else if(!s.empty()&&s.top()==b[ib])
		{
			s.pop();
			ib++;
		}
		else if(ia<n)
			s.push(a[ia++]);
		else
		{
			flag=false;
			break;
		}
	}
	if(flag)
		cout<<"Yes"<<endl;
	else 
		cout<<"No"<<endl;
	return 0;
}
