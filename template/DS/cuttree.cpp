#define lc (o*2)
#define rc (o*2+1)

int fa[MAXN],son[MAXN],siz[MAXN],top[MAXN],w[MAXN],dep[MAXN];

//begin from 1
void dfs1(int u){
    siz[u]=1;son[u]=0;
    for(int e=head[u];e!=-1;e=edges[e].next){
        int v=edges[e].to;
        if(v!=fa[u]){
            fa[v]=u;
            dep[v]=dep[u]+1;
            dfs1(v);
            siz[u]+=siz[v];
            if(siz[v]>siz[son[u]])//siz[0]=0
                son[u]=v;
        }
    }
}

int ind;
void dfs2(int u,int tp){
    w[u]=++ind;top[u]=tp;
    if(son[u]!=0)
        cut(son[u],top[u]);
    for(int e=head[u];e!=-1;e=edges[e].next){
        int v=edges[e].to;
        if(v!=son[u]&&v!=fa[u])
            cut(v,v);
    }
}

int maxv[MAXN*4],addv[4*MAXN];

void maintain(int o,int L,int R){
    maxv[o]=0;
    if(R>L)
        maxv[o]=max(maxv[lc],maxv[rc]);
    maxv[o]+=addv[o];
}

void update(int o,int L,int R,int l,int r,int v){
    if(l<=L&&r>=R)
        addv[o]+=v;
    else{
        int M=L+(R-L)/2;
        if(L<=M)
            update(lc,L,M,l,r,v);
        if(R>M)
            update(rc,M+1,R,l,r,v);
    }
    maintain(o,L,R);
}

int query(int o,int L,int R,int l,int r,int add){
    if(l<=L&&r>=R)
        return maxv[o]+addv[o];
    else{
        int M=L+(R-L)/2,ret=0;
        if(L<=M)
            ret=max(ret,query(lc,L,M,l,r,add+addv[o]));
        if(R>M)
            ret=max(ret,query(rc,M+1,R,l,r,add+addv[o]));
        return ret;
    }
}

void cut(){
    fa[1]=dep[1]=ind=0;
    memset(siz,0,sizeof(siz));
    memset(maxv,0,sizeof(maxv));
    dfs1(1);
    dfs2(1,1);
    for(int i=0;i<m;i++){
        if(dep[edges[i].u]>dep[edges[i].v])
            swap(edges[i].u,edges[i].v);
        update(1,1,z,w[edges[i].v],edges[i].w);
    }
}
