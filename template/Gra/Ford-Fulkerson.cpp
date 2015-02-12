bool used[MAX_V];

struct edge{
	int to,cap,next,rev;
}edges[MAX_E];

void addedge(int u,int v,int cap){
	edges[em].to=v;
	edges[em].next=head[u];
	edges[em].rev=em+1;
	edges[em].cap=cap;
	head[u]=em++;
	edges[em].to=u;
	edges[em].next=head[v];
	edges[em].cap=0;
	edges[em].rev=em-1;
	head[v]=em++;
}

int dfs(int u,int t,int f){
	if(u==t)
		return f;
	used[u]=true;
	for(int e=head[u];e!=-1;e=edges[e].next){
		int v=edges[e].to;
		if(!used[v]&&edges[e].cap>0){
			int d=dfs(v,t,min(f,edges[e].cap));
			if(d>0){
				edges[e].cap-=d;
				edges[edges[e].rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s,int t){
	int flow=0;
	for(;;){
		memset(used,0,sizeof(used));
		int f=dfs(s,t,INF);
		if(f==0)
			return flow;
		else
			flow+=f;
	}
}
