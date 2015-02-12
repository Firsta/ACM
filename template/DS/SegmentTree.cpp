int ql,qr;//[ql,qr]
int query(int o,int L,int R){
	int M=L+(R-L)/2,ans=INF;
	if(ql<=L&&qr>=R)
		return minv[o];
	if(ql<=M)
		ans=min(ans,query(o*2,L,M));
	if(M<qr)
		ans=min(ans,query(o*2+1,M+1,R));
	return ans;
}

int p,v;//A[p]=v
void update(int o,int L,int R){
	int M=L+(R-L)/2;
	if(L==R)
		minv[o]=v;
	else{
		if(p<=M)
			update(o*2,L,M);
		else update(o*2+1,M+1,R);
		minv[o]=min(minv[o*2],minv[o*2+1]);
	}
}
//
int y1,y2;//[y1,y2]
void maintain(int o,int L,int R){
	int lc=o*2,rc=o*2+1;
	sumv[o]=minv[o]=maxv[o]=0;
	if(R>L){
		sumv[o]=sumv[lc]+sumv[rc];
		minv[o]=min(minv[lc],minv[rc]);
		maxv[o]=max(maxv[lc],maxv[rc]);
	}
	minv[o]+=addv[o];
	maxv[o]+=addv[o];
	sumv[o]+=addv[o]*(R-L+1);
}

void update(int o,int L,int R){
	int lc=o*2,rc=o*2+1;
	if(y1<=L&&R<=y2)
		addv[o]+=v;
	else{
		int M=L+(R-L)/2;
		if(y1<=M)
			update(lc,L,M);
		if(y2>M)
			update(rc,M+1,R);
	}
	maintain(o,L,R);
}

int _min,_max,_sum;
void query(int o,int L,int R,int add){
	if(y1<=L&&y2>=R){
		_sum+=sumv[o]+add*(R-L+1);
		_min=min(_min,minv[o]+add);
		_max=max(_max,maxv[o]+add);
	}else{
		int M=L+(R-L)/2;
		if(y1<=M)
			query(o*2,L,M,add+addv[o]);
		if(y2>M)
			query(o*2+1,M+1,R,add+addv[o]);
	}
}
