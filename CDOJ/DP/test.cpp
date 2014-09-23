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

int main()
{
	int myints[] = {10,20,30,30,20,10,10,40};
  	vector<int> v(myints,myints+8);	
	vector<int>::iterator it=lower_bound(v.begin(),v.end(),40);
	int ans=it-v.begin();
	cout<<ans<<endl;
	return 0;
}
