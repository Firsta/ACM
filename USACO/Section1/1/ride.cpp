/*
ID: firstaw1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int solve(string s)
{
	int ret=1;
	for(int i=0;i<s.size();i++)
	{
		ret*=(s[i]-'A'+1);
		ret%=47;
	}
	return ret;
}

int main() 
{
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
	string s1,s2;
	fin>>s1>>s2;
	int a1=solve(s1);
	int a2=solve(s2);
	if(a1==a2)
		fout<<"GO"<<endl;
	else
		fout<<"STAY"<<endl;
    return 0;
}
