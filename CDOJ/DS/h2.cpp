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
#define MAXN 600100

typedef long long ll;
using namespace std;

int h1[MAXN],s1=0;//small
int h2[MAXN],s2=0;//large

void push1(int x)
{
	int i=s1++;
	while(i>0)
	{
		int p=(i-1)/2;
		if(h1[p]<=x)
			break;
		h1[i]=h1[p];
		i=p;
	}
	h1[i]=x;
}

void push2(int x)
{
	int i=s2++;
	while(i>0)
	{
		int p=(i-1)/2;
		if(h2[p]>=x)
			break;
		h2[i]=h2[p];
		i=p;
	}
	h2[i]=x;
}

int pop1()
{
	int ret=h1[0];
	int x=h1[--s1];
	int i=0;
	while(i*2+1<s1)
	{
		int a=i*2+1,b=i*2+2;
		if(b<s1&&h1[b]<h1[a])
			a=b;
		if(h1[a]>=x)
			break;
		h1[i]=h1[a];
		i=a;
	}
	h1[i]=x;
	return ret;
}

int pop2()
{
	int ret=h2[0];
	int x=h2[--s2];
	int i=0;
	while(i*2+1<s2)
	{
		int a=i*2+1,b=i*2+2;
		if(b<s2&&h2[b]>h2[a])
			a=b;
		if(h2[a]<=x)
			break;
		h2[i]=h2[a];
		i=a;
	}
	h2[i]=x;
	return ret;
}

int main()
{
	char s[50];
	int m=0;
	while(~scanf("%s",s))
	{
		if(s[0]=='#')
		{
/*			for(int i=0;i<s1;i++)
				printf("%d ",h1[i]);
			printf("\n");
			for(int i=0;i<s2;i++)
				printf("%d ",h2[i]);
			printf("\n");*/
			printf("%d\n",m);
			if(s1||s2)
				if(s1>=s2)
				{
					m=h1[0];
					pop1();
				}
				else
				{
					m=h2[0];
					pop2();
				}
			else
				m=0;
		}
		else
		{
			int temp=0;
			int len=strlen(s);
			for(int i=0;i<len;i++)
			{
				temp*=10;
				temp+=s[i]-'0';
			}
			if(m==0)
			{
				m=temp;
				continue;
			}
			if(temp>=m)
				push1(temp);
			else
				push2(temp);
			if(s1-s2>=1)
			{
				push2(m);
				m=h1[0];
				pop1();
			}
			if(s2-s1>=2)
			{
				push1(m);
				m=h2[0];
				pop2();
			}
		}
	}
	return 0;
}
