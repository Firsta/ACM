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

int even[100005];
int odd[100005];
int cnte=0;
int cnto=0;

int main()
{
	int n,k,p;
	cin>>n>>k>>p;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		if(temp%2)
		{
			odd[cnto++]=temp;
		}
		else
		{
			even[cnte++]=temp;
		}
	}
	int e=cnte,o=cnto;
	if(k-p>cnto)
	{
		cout<<"NO";
		return 0;
	}
	else if((cnto-(k-p))%2==0)
	{
		int temp=(cnto-(k-p))/2+cnte;
		if(temp>=p)
		{
			cout<<"YES"<<endl;
			if(p==0)
			{
				for(int i=0;i<k-p-1;i++)
				{
					int temp=odd[--cnto];
					cout<<1;
					cout<<' '<<temp<<endl;
				}
				cout<<n-(k-p-1);
				while(cnte>0)
				{
					int temp=even[--cnte];
					cout<<' '<<temp;
				}
				while(cnto>0)
				{
					int temp=odd[--cnto];
					cout<<' '<<temp;
				}
				cout<<endl;
			}
			else
			{
				int i;
				for(i = 0; i < k - p; i ++) printf("1 %i\n",odd[i]);
				while(i < cnto && p > 1)
				{
					printf("2 %d %d\n",odd[i],odd[i+1]);
					i += 2;
					p --;
				}
				while(p > 1)
				{
					printf("1 %d\n",even[--cnte]);
					p --;
				}
				printf("%d ",cnte + cnto - i);
				while(i != cnto) printf("%d ",odd[i ++]);
				while(cnte) printf("%d ",even[-- cnte]);
			}
		}
		else
			cout<<"NO";
	}
	else
		cout<<"NO";
	return 0;
}
