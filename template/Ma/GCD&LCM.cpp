int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

int lcm(int a,int b){
	return a*b/gcd(a,b);
}

int extgcd(int a,int b,int &x,int &y){
	int d=a;
	if(b!=0){
		d=extgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}else{
		x=1;y=0;
	}
	return d;
}

//ax=1(mod m)=>ax-mk=1
int mod_inverse(int a,int m){
	int x,y;
	extgcd(a,m,x,y);
	return (m+x%m)%m;
}

//n!mod p(0<=n<p)
int fact[MAX_P];

int mod_fact(int n,int p,int &e){
	e=0;
	if(n==0)
		return 1;
	int res=mod_fact(n/p,p,e);
	e+=n/p;
	if(n/p%2!=0)
		return res*(p-fact[n%p])%p;
	return res*fact[n%p]%p;
}

int mod_comb(int n,int k,int p){
	if(n<0||k<0||n<k)
		return 0;
	int e1,e2,e3;
	int a1=mod_fact(n,p,e1),a2=mod_fact(k,p,e2),a3=mod_fact(n-k,p,e3);
	if(e1>e2+e3)
		return 0;
	return a1*mod_inverse(a2*a3%p,p)%p;
}
