/*
ID: firstaw1
PROG: namenum
LANG: C++
*/
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
#include<fstream>

typedef long long ll;
using namespace std;

vector<string> v;

int num(char x)
{
	if(x=='A'||x=='B'||x=='C')
		return 2;
	if(x=='D'||x=='E'||x=='F')
		return 3;
	if(x=='G'||x=='H'||x=='I')
		return 4;
	if(x=='J'||x=='K'||x=='L')
		return 5;
	if(x=='M'||x=='N'||x=='O')
		return 6;
	if(x=='P'||x=='R'||x=='S')
		return 7;
	if(x=='T'||x=='U'||x=='V')
		return 8;
	if(x=='W'||x=='X'||x=='Y')
		return 9;
	else
		return 1;
}

int main()
{
//  freopen("test.in","w","stdin")
//  freopen("test.out","r","stdout")
	ifstream icin;
	ifstream fin("namenum.in");
	ofstream fout("namenum.out");
	icin.open("dict.txt");
	string s;
	while(icin>>s)
		v.push_back(s);
	ll n;
	fin>>n;
	bool find=false;
	for(int i=0;i<v.size();i++)
	{
		string t=v[i];
		ll nt=0;
		for(int j=0;j<t.size();j++)
			nt=nt*10+num(t[j]);
		if(nt==n)
		{
			find=true;
			fout<<t<<endl;
		}
	}
	if(!find)
		fout<<"NONE"<<endl;
	return 0;
}
