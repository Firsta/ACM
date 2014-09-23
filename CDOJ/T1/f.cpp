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

int a[8][10];
string s0[5]={
	"***",
	"* *",
	"* *",
	"* *",
	"***"
};

string s1[5]={
	"  *",
	"  *",
	"  *",
	"  *",
	"  *"
};

string s2[5]={
	"***",
	"  *",
	"***",
	"*  ",
	"***"
};

string s3[5]={
	"***",
	"  *",
	"***",
	"  *",
	"***"
};

string s4[5]={
	"* *",
	"* *",
	"***",
	"  *",
	"  *",
};

string s5[5]={
	"***",
	"*  ",
	"***",
	"  *",
	"***"
};

string s6[5]={
	"***",
	"*  ",
	"***",
	"* *",
	"***"
};

string s7[5]={
	"***",
	"  *",
	"  *",
	"  *",
	"  *"
};

string s8[5]={
	"***",
	"* *",
	"***",
	"* *",
	"***"
};

string s9[5]={
	"***",
	"* *",
	"***",
	"  *",
	"***"
};

int main()
{
	string s;
	for(int i=0;i<8;i++)
		for(int j=0;j<10;j++)
			a[i][j]=1;
	for(int i=0;i<5;i++)
	{
		getline(cin,s);
		int len=s.size();
		for(int j=0;j+3<=len;j+=4)
		{
			string temp;
			temp=s.substr(j,3);
			if(temp!=s0[i])
				a[j/4][0]=0;
			if(temp!=s1[i])
				a[j/4][1]=0;
			if(temp!=s2[i])
				a[j/4][2]=0;
			if(temp!=s3[i])
				a[j/4][3]=0;
			if(temp!=s4[i])
				a[j/4][4]=0;
			if(temp!=s5[i])
				a[j/4][5]=0;
			if(temp!=s6[i])
				a[j/4][6]=0;
			if(temp!=s7[i])
				a[j/4][7]=0;
			if(temp!=s8[i])
				a[j/4][8]=0;
			if(temp!=s9[i])
				a[j/4][9]=0;
		}
	}
	int len=(s.size()+1)/4;
	int ans=0;
	for(int i=0;i<len;i++)
	{
		int t=0;
		int num;
		for(int j=0;j<=9;j++)
			if(a[i][j])
			{
				t++;
				num=j;
			}
		if(t!=1)
		{
			cout<<"BOOM!!";
			return 0;
		}
		ans=ans*10+num;
	}
	if(ans%6==0)
		cout<<"BEER!!";
	else
		cout<<"BOOM!!";
	return 0;
}
