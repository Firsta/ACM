#include<cstdio>
int main()
{
	char a;
	int cnt;
	while(1)
	{
		a=getchar();
		if(a=='\n')
			break;
		if(a==' ')
			break;
		if(a=='?')
			cnt++;
	}
	if(cnt%2==0)
		printf("No\n");
	else
		printf("Yes\n");
}
