#include<cstdio>
int a[100];
int maxsum(int *A,int x,int y)
{
	int i,m,v,L,R,max;
	if(y-x==1)
		return A[x];
	m=x+(y-x)/2;
	if(maxsum(A,x,m)>maxsum(A,m,y))
		max=maxsum(A,x,m);
	else 
		max=maxsum(A,m,y);
	v=0;L=A[m-1];
	for(int i=m-1;i>=x;i--)
	{
		v+=A[i];
		if(v>L)
			L=v;
	}
	v=0;L=A[m];
	for(int i=m;i<y;i++)
	{
		v+=A[i];
		if(v>R)
			R=v;
	}
	if(max>(R+L))
		return max;
	else return R+L;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	printf("%d",maxsum(a,1,n+1));
	return 0;
}
