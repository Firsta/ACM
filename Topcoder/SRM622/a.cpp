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

int F[1000];

class FibonacciDiv2
{
	public:
		int find(int N)
		{
			F[0]=0;
			F[1]=1;
			for(int i=2;i<1000;i++)
				F[i]=F[i-1]+F[i-2];
			int last=N;
			for(int i=1;i<1000;i++)
			{
				int temp;
				if(N-F[i]>0)
					temp=N-F[i];
				else
					temp=F[i]-N;
				if(temp>last)
					break;
				else
					last=temp;
			}
			return last;
		}
};
