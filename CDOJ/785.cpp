#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int n;
	while(scanf("1/%d",&n)==1)
	{
		int cnt=0;
		for(int y=n+1;y<=2*n;y++)
		{
            		if((n*y)%(n-y)==0)
				cnt++;
		}
		printf("%d\n",cnt);
		getchar();
	}
	return 0;
}
