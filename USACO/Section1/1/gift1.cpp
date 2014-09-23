/*
ID: firstaw1
PROG: gift1
LANG: C++
*/
#include<algorithm>
#include<iostream>
#include<fstream>
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

string  s[11];
int money[11];

int main()
{
	ofstream fout("gift1.out");
	ifstream fin("gift1.in");
	int np;
	fin>>np;
	for(int i=0;i<np;i++)
	{
		fin>>s[i];
	}
	for(int k=0;k<np;k++)
	{
		string ts;
		fin>>ts;
		int m,d;
		fin>>m>>d;
		if(d==0)
		{
			for(int i=0;i<np;i++)
				if(s[i]==ts)
				{
					money[i]+=m;
					break;
				}
			continue;
		}
		for(int i=0;i<np;i++)
			if(s[i]==ts)
			{
				money[i]+=m%d;
				money[i]-=m;
				break;
			}
		for(int j=0;j<d;j++)
		{
			string tts;
			fin>>tts;
			for(int i=0;i<np;i++)
				if(s[i]==tts)
				{
					money[i]+=m/d;
					break;
				}
		}
	}
	for(int i=0;i<np;i++)
	{
		fout<<s[i]<<' '<<money[i]<<endl;
	}
	return 0;
}
