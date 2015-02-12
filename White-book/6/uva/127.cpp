#include<cstdio>
#include<cstring>
typedef struct card
{
	char rank;
	char suit;
}card;
int top[52];
bool cmp(card a,card b)
{
	if(a.rank==b.rank||a.suit==b.suit) return true;
	else return false;
}
int main()
{
	while(1)
	{
		memset(top,0,sizeof(top));
		char temp[2];
		card piles[52][52];
		scanf("%s",temp);
		if(temp[0]=='#') return 0;
		piles[0][top[0]].rank=temp[0];
		piles[0][top[0]++].suit=temp[1];
		for(int i=1;i<52;i++)
		{
			scanf("%s",temp);
			piles[i][top[i]].rank=temp[0];
			piles[i][top[i]++].suit=temp[1];
		}
		for(int i=1;i<52;)
		{
			if(top[i]==0)
			{
				i++;
				continue;
			}
			int j,c1=-1,c3=-1,t=0,flag=1;
			for(j=i-1;j>=0;j--)
			{
				if(top[j]>0) 
				{
					t++;
				}
				if(t==1&&flag)
				{
					c1=j;
					flag=0;
				}
				if(t==3)
				{
					c3=j;
					break;
				}
			}
			if(c3>=0&&cmp(piles[i][top[i]-1],piles[c3][top[c3]-1]))
			{
				top[c3]++;
				piles[c3][top[c3]-1]=piles[i][top[i]-1];
				top[i]--;
				i=c3;
				continue;
			}else if(c1>=0&&cmp(piles[i][top[i]-1],piles[c1][top[c1]-1]))
			{
				top[c1]++;
				piles[c1][top[c1]-1]=piles[i][top[i]-1];
				top[i]--;
				i=c1;
				continue;
			}else
			{
				i++;
				continue;
			}
		}
		int count=0;
		for(int i=0;i<52;i++)
		{
			if(top[i]) count++;
		}
		if(count==1)
		{
			printf("1 pile remain: 52\n");
		}else
		{
			printf("%d piles remain:",count);
			for(int i=0;i<52;i++)
			{
				if(top[i])
					printf(" %d",top[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
