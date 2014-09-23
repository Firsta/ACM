#include<iostream>
#include<string>
using namespace std;
string s;
int main()
{
	int n;
	cin>>n;
	int ans=0;
	cin>>s;
	int p1,p2;
	for(;;)
	{
		p1=s.find('L');
		p2=s.find('R');
		if(p1==-1&&p2!=-1)
		{
			ans+=p2;
			break;
		}
		if(p1!=-1&&p2==-1)
		{
			ans+=s.size()-p1-1;
			break;
		}
		if(p1==-1&&p2==-1)
		{
			ans+=s.size();
			break;
		}
		if(p1<p2)
		{
			s=s.substr(p1+1);
		}
		else
		{
			ans+=(p1-p2-1)%2?1:0;
			ans+=p2;
			s=s.substr(p1+1);
		}
	}
	cout<<ans<<endl;
	return 0;
}
