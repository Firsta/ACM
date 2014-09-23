#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<cmath>
#include<sstream>
#include<string>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

struct node{
	int m,s,cnt;
};

bool cmp(const node &a,const node &b){
	if(a.m==b.m)
		return a.s<b.s;
	else
		return a.m<b.m;
}

node make_node(int m,int s,int cnt){
	node tmp;
	tmp.m=m;
	tmp.s=s;
	tmp.cnt=cnt;
	return tmp;
}

vector<node> a,b,c;

int main(){
	int m,s;
	while(~scanf("%d:%d",&m,&s)&&(m||s)){
		int mid=m*60+s;
		int l,r;
		if(mid%10==0){
			l=mid-mid/10+1;
			r=mid+mid/10-1;
		}
		else{
			int tmp=mid*10+mid;
			tmp-=tmp%10;
			r=tmp/10;
			tmp=mid*10-mid;
			tmp+=(10-tmp%10);
			l=tmp/10;
		}
		a.clear();b.clear();c.clear();
		int maxx=0;
	//	cout<<l<<' '<<r<<endl;
		for(int i=l;i<=r;i++){
			int tm,ts,cnt,ttm,tts;
			if(i<100){
				tm=0;ts=i;
				cnt=0;tts=i;
				while(tts){
					if(tts%10==9)
						cnt++;
					tts/=10;
				}
				maxx=max(maxx,cnt);
				if(cnt==maxx)
					a.push_back(make_node(tm,ts,cnt));
			}
			if(i>=60){
				ttm=tm=i/60;tts=ts=i%60;
				cnt=0;
				while(ttm){
					if(ttm%10==9)
						cnt++;
					ttm/=10;
				}
				while(tts){
					if(tts%10==9)
						cnt++;
					tts/=10;
				}
				maxx=max(maxx,cnt);
				if(cnt==maxx)
					a.push_back(make_node(tm,ts,cnt));
				if(i%60<40){
					ttm=tm=i/60-1;tts=ts=i%60+60;
					cnt=0;
					while(ttm){
						if(ttm%10==9)
							cnt++;
						ttm/=10;
					}
					while(tts){
						if(tts%10==9)
							cnt++;
						tts/=10;
					}
					maxx=max(maxx,cnt);
					if(cnt==maxx)
						a.push_back(make_node(tm,ts,cnt));
				}
			}
		}
		if(maxx==0){
			if(m<10)
				printf("0");
			printf("%d:",m);
			if(s<10)
				printf("0");
			printf("%d\n",s);
			continue;
		}
		int minn=100000;
		for(int i=0;i<a.size();i++)
			if(a[i].cnt==maxx)
				b.push_back(a[i]);
		for(int i=0;i<b.size();i++)
			if(abs(b[i].m*60+b[i].s-mid)<minn)
				minn=abs(b[i].m*60+b[i].s-mid);
		for(int i=0;i<b.size();i++)
			if(abs(b[i].m*60+b[i].s-mid)==minn)
				c.push_back(b[i]);
		sort(c.begin(),c.end(),cmp);
		if(c[0].m<10)
			printf("0");
		printf("%d:",c[0].m);
		if(c[0].s<10)
			printf("0");
		printf("%d\n",c[0].s);
	}
	return 0;
}
