#include<cstdio>
#include<cstdlib>
int vis[2][100];
int c[100];
int tot=0;
int n;
void search(int cur)
{
	/*
	int i,j;
	if(cur==n)
		tot++;
	else for(i=0;i<n;i++)
	{
		int ok=1;
		c[cur]=i;
		for(j=0;j<cur;j++)
			if(c[cur]==c[j]||cur-c[cur]==j-c[j]||cur+c[cur]==j+c[j])
			{
				ok=0;
				break;
			}
	        if(ok==1)
			search(cur+1);
	}
	*/
	if(cur==n)
		tot++;
	else for(int i=0;i<n;i++)
		if(!vis[0][i]&&!vis[1][cur-i+n]&&!vis[2][cur+i])
		{
			vis[0][i]=vis[1][cur-i+n]=vis[2][cur+i]=1;
			search(cur+1);
			vis[0][i]=vis[1][cur-i+n]=vis[2][cur+i]=0;
		}
}
int main()
{
	scanf("%d",&n);
	search(0);
	printf("%d",tot);
	return 0;
}
