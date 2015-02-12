#include<cstdio>
#include<cstring>
const int MAXN=10000;
char s1[MAXN],s2[MAXN];
void build(int n,char* s1,char* s2)
{
	if(n<=0) return;
	int p=strchr(s2,s1[0])-s2;
	build(p,s1+1,s2);
	build(n-p-1,s1+p+1,s2+p+1);
	printf("%c",s1[0]);
}
int main()
{
	while(scanf("%s%s",s1,s2)==2)
	{
		int n=strlen(s1);
		build(n,s1,s2);
		putchar('\n');
	}
	return 0;
}
