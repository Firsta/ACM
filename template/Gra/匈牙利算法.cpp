int vis[MAXN];
int linked[MAXN];
vector<int> G[MAXN];
//vis:点是否在增广路上 linked:j所在增广路的起点
bool find(int u){
	for(int i=0;i<G[u].size();i++){
		int temp=G[u][i];
		if(!vis[temp]){
			vis[temp]=1;
			if(!linked[temp]||find(linked[temp])){
				linked[temp]=u;
				return true;
			}
		}
	}
	return false;
}

int count(){
	int ans=0;
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		if(find(i))
			ans++;
	}
	return ans;
}
//
bool dfs(int u){
	used[u]=true;
	for(int e=head[u];e!=-1;e=edges[e].next){
		int v=edges[e].to,w=match[v];
		if(w<0||!used[w]&&dfs(w)){
			match[u]=v;
			match[v]=u;
			return true;
		}
	}
	return false;
}

int bipartite_matching(){
	int res=0;
	memset(match,-1.sizeof(match));
	for(int v=0;v<V;v++){
		if(match[v]<0){
			memset(used,0,sizeof(used));
			if(dfs(v)){
				res++;
			}
		}
	}
	return res;
}
