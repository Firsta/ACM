
int head[MAXN],em;

struct edges
{
	int to,w,next;
}edges[MAXM];

void addedge(int u,int v,int w)
{
	edges[em].next=head[u];
	edges[em].w=w;
	edges[em].to=v;
	head[u]=em++;
}

int main()
{
	em=0;
	memset(head,-1,sizeof(head));
}
