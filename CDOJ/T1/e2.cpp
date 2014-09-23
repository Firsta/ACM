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

int main()
{
	string a,b;
	cin>>a;cin>>b;
	int lena=a.size(),lenb=b.size();
	int l,r;
	int flag=0;
	for(int i=0;i<min(lena,lenb);i++)
		if(a[i]!=b[i])
		{
			flag=1;
			l=i;
			break;
		}
	if(!flag)
		l=min(lena,lenb);
	flag=0;
	for(int i=lena,j=lenb;i>=0&&j>=0;j--,i--)
		if(a[i]!=b[j])
		{
			flag=1;
			r=j;
			break;
		}
	if(!flag)
		r=max(lena,lenb)-min(lena,lenb)-1;
	if(l>r)
	{
		cout<<max(lena,lenb)-min(lena,lenb);
	}
	else
		cout<<min(l-r+1,max(lena,lenb)-min(lena,lenb));
	return 0;
}
