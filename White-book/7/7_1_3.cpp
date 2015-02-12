#include<cstdio>
int main()
{
	int k,x,y,count=0;
	scanf("%d",&k);
	for(y=k+1;y<=2*k;y++)
	{
		if((k*y)%(y-k)==0)
		{
			count++;
		}
	}
	printf("%d\n",count);
	for(y=k+1;y<=2*k;y++)
	{
		if((k*y)%(y-k)==0)
		{
			x=(k*y)/(y-k);
			printf("1/%d=1/%d+1/%d\n",k,x,y);
		}
	}
	return 0;
}
