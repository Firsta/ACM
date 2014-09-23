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

stack<int> val;
stack<char> op;
map<char,int> maps;

void opNot(int a)
{
	while(!op.empty()&&op.top()!="!")
	{
		op.pop();
		a=!a;
	}
	val.push(a);
}

int main()
{
	char ch;
	int a,b,t=0;
	maps['!']=3;maps['&']=2;maps['|']=1;
	while((ch=getchar())!=EOF)
	{
		t++;
		while(!val.empty())
			val.pop();
		while(!op.empty())
			op.pop();

	}
}
