//Bellman-Ford
struct edge{
	int to,cap,rev,cost,next;
}edges[MAXE];
int em;

void addedge(int u,int v,int cap,int cost){
	edges[em].next=head[u];
	edges[em].to=v;
	edges[em].cap=cap;
	edges[em].cost=cost;
	edges[em].rev=em+1;
	head[u]=em++;
	edges[em].next=head[v];
	edges[em].to=u;
	edges[em].cap=0;
	edges[em].cost=-cost;
	edges[em].rev=em-1;
	head[v]=em++;
}

int min_cost_flow(int s,int t,int f){
	int res=0;
	while(f>0){
		fill(dist,dist+V,INF);
		dist[s]=0;
		bool update=true;
		while(update){
			update=false;
			for(int u=0;u<V;u++){
				if(dist[u]==INF)
					continue;
				for(int e=head[u];e!=-1;e=edges[e].next){
					int v=edges[e].to;
					if(edges[e].cap>0&&dist[v]>dist[u]+edges[e].cost){
						dist[v]=dist[u]+edges[e].cost;
						prevv[v]=u;
						preve[v]=e;
						update=true;
					}
				}
			}
		}
		if(dist[t]==INF)
			return -1;
		int d=f;
		for(int v=t;v!=s;v=prevv[v]){
			d=min(d,edges[preve[v]].cap);
		}
		f-=d;
		res+=d*dist[t];
		for(int v=t;v!=s;v=prevv[v]){
			edges[preve[v]].cap-=d;
			edges[edges[preve[v]].rev]+=d;
		}
	}
	return res;
}

//Dijkstra
typedef pair<int,int> P;

struct edge{
	int to,cap,cost,rev,next;
}edges[MAXV];
int em;

int V;
int h[MAXV],dist[MAXV],prevv[MAXV],preve[MAXV];

void addedge(int u,int v,int cap,int cost){
	edges[em].next=head[u];
	edges[em].to=v;
	edges[em].cap=cap;
	edges[em].cost=cost;
	edges[em].rev=em+1;
	head[u]=em++;
	edges[em].next=head[v];
	edges[em].to=u;
	edges[em].cap=0;
	edges[em].cost=-cost;
	edges[em].rev=em-1;
	head[v]=em++;
}

int min_cost_flow(int s,int t,int f){
	int res=0;
	fill(h,h+V,0);
	while(f>0){
		priority_queue< P,vector<P>,greater<P> > que;
		fill(dist,dist+V,INF);
		dist[s]=0;
		que.push(P(0,s));
		while(!que.empty()){
			P p=que.top();que.pop();
			int u=p.second;
			if(dist[u]<p.first)
				continue;
			for(int e=head[u];e!=-1;e=edges[e].next){
				int v=edges[e].to;
				if(edges[e].cap>0&&dist[v]>dist[u]+edges[e].cost+h[u]-h[v]){
					dist[v]=dist[u]+edges[e].cost+h[u]-h[v];
					prevv[v]=u;
					preve[v]=e;
					que.push(P(dist[v],v));
				}
			}
		}
		if(dist[t]==INF)
			return -1;
		for(int i=0;i<V;i++)
			h[i]+=dist[i];
		int d=f;
		for(int v=t;v!=s;v=prevv[v])
			d=min(d,edges[preve[v]].cap);
		f-=d;
		res+=d*h[t];
		for(int v=t;v!=s;v=prevv[v]){
			edges[preve[v]].cap-=d;
			edges[edges[preve[v]].rev].cap+=d;
		}
	}
	return res;
}
