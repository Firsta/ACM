#include<cstdio>
int L;
int n;
int s[100];
int cnt=0;
int dfs(int cur)
{
	if(cnt++==n)
	{
		for(int i=0;i<cur;i++)
			printf("%c",'A'+s[i]);
		printf("\n");
		return 0;
	}
	for(int i=0;i<L;i++)
	{
		s[cur]=i;
		int ok=1;
		for(int j=1;j*2<=cur+1;j++)
		{
			int equal=1;
			for(int k=0;k<j;k++)
				if(s[cur-k]!=s[cur-k-j])
				{
					equal=0;
					break;
				}
			if(equal)
			{
				ok=0;
				break;
			}
		}
		if(ok) if(!dfs(cur+1)) return 0;
	}
	return 1;
}
int main()
{
	scanf("%d%d",&n,&L);
	dfs(0);
	return 0;
}
