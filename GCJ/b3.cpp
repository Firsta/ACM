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
	freopen("in.txt", "r", stdin);
	freopen("out3.txt", "w", stdout);
	int t;
	cin>>t;
	for(int cas=1;cas<=t;cas++)
	{
		double c,f,x;
		cin>>c>>f>>x;
		double a1,a2;
		a1=x/2.0;
		a2=x/(2.0+f)+c/2.0;
		int n=1;
		if(x/c>10)
			n=x/c-5;
		n++;
		while(a1>a2)
		{
			a1=a2;
			a2=0;
			for(int i=0;i<=n-1;i++)
				a2+=c/(2.0+i*f);
			a2+=x/(2.0+n*f);
			n++;
		}
//		cout<<n<<endl;
		printf("Case #%d: %.7lf\n",cas,a1);
	}
	return 0;
}
