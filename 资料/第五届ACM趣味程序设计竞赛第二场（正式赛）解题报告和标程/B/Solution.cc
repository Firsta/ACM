//
//
//解题报告：
//
//该题可以用贪心考虑，若他此时能向某方向走且出口在当前位置的该方向上，他就应该走这一步，否则就不应该走。
//当当前位置就是出口时，输出当前时刻即可，若把所有时间用完依旧没有到达出口，则不可能到达出口，输出-1。
//
//
//标程：

#include <bits/stdc++.h>
using namespace std;

char a[100005];

int main()
{
	int T,t,x,y,i;
	freopen("b.in","r",stdin);
	scanf("%d",&T);
    assert(T > 0 && T <= 1000);
	while (T--)
	{
		scanf("%d%d%d%s",&x,&y,&t,a);
		assert(-100000 <= x && x <= 100000);
		assert(-100000 <= y && y <= 100000);
		assert(0 < t && t <= 100000);
		assert(strlen(a) == t);
		for(i=0;(x||y)&&i<t;i++)
		{
			switch(a[i])
			{
				case 'L':if(x<0)x++;break;
				case 'R':if(x>0)x--;break;
				case 'D':if(y<0)y++;break;
				case 'U':if(y>0)y--;break;
			}
		}
		printf("%d\n",x||y?-1:i);
	}

	return 0;
}
