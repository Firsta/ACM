//
//
//���ⱨ�棺
//
//���������̰�Ŀ��ǣ�������ʱ����ĳ�������ҳ����ڵ�ǰλ�õĸ÷����ϣ�����Ӧ������һ��������Ͳ�Ӧ���ߡ�
//����ǰλ�þ��ǳ���ʱ�������ǰʱ�̼��ɣ���������ʱ����������û�е�����ڣ��򲻿��ܵ�����ڣ����-1��
//
//
//��̣�

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
