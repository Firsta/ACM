//T:待测文本 P:匹配文本 f:失配函数
void find(char *T,char *P,int *f){
	int n=strlen(T),m=strlen(P);
	getFail(P,f);
	int j=0;
	for(int i=0;i<n;i++){
		while(j&&P[j]!=T[i])
			j=f[j];
		if(P[j]==T[i])
			j++;
		if(j==m){
			//cnt++;
			//j=f[j];
		}
	}
}

void getFail(char *P,int *f){
	int m=strlen(P);
	f[0]=0;f[1]=0;
	for(int i=1;i<m;i++){
		int j=f[i];
		while(j&&P[i]!=P[j])
			j=f[j];
		f[i+1]=(P[i]==P[j] ? j+1:0);
	}
}
