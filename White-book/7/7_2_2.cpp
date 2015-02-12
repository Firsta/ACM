#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
void print_permutation(int n,int* P,int* A,int cur)
{
	int i,j;
	if(cur==n)
	{
		for(i=0;i<n;i++)
			printf("%d ",A[i]);
		printf("\n");
	}
	else for(i=0;i<n;i++)
		if(!i||P[i]!=P[i-1])
		{
			int c1=0,c2=0;
			for(j=0;j<cur;j++)
			{
				if(A[j]==P[i])
					c1++;
			}
			for(j=0;j<n;j++)
			{
				if(P[i]==P[j])
				c2++;
			}
			if(c1<c2)
			{
				A[cur]=P[i];
				print_permutation(n,P,A,cur+1);
			}
		}
}
int main()
{
	int n;
	int A[30];
	int P[30];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&P[i]);
	sort(P,P+n);
	print_permutation(n,P,A,0);
	return 0;
}
