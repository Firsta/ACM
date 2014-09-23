#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
class MinimumSquareEasy
{
	public:
		long long minArea(vector<int> x,vector<int> y)
		{
			long long area=LLONG_MAX;
			int xmin=INT_MAX,xmax=INT_MIN,ymin=INT_MAX,ymax=INT_MIN;
			for(int i=0;i<x.size();i++)
				for(int j=0;j<x.size() && i!=j;j++)
				{
					for(int k=0;k<x.size();k++)
					{
						if(k==i||k==j)
							continue;
						xmin=min(xmin,x[k]);
						xmax=max(xmax,x[k]);
						ymin=min(ymin,y[k]);
						ymax=max(ymax,y[k]);
					}
					long long l=max(xmax-xmin,ymax-ymin)+2;
					area=min(area,l*l);
				}
			return area;
		}
};
