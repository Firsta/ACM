#include<iostream>
using namespace std;
#define MAXN 10100
int rad[MAXN];
char s[MAXN];
char r1[MAXN/2],r[MAXN];
int sa[MAXN];
int wa[MAXN],wb[MAXN],wv[MAXN],ws[MAXN];
int height[MAXN],rank[MAXN];
int ans,start;
inline bool cmp(int *r,int a,int b,int len){
	return r[a]==r[b]&&r[a+len]==r[b+len];
}
void SA(int n,int m){
	int i,j,p,*x=wa,*y=wb,*t;
	for(i=0;i
			ws[i]=0;
			for(i=0;i
				ws[x[i]=r[i]]++;
				for(i=1;i
					ws[i]+=ws[i-1];
					for(i=n-1;i>=0;i--)
					sa[--ws[x[i]]]=i;
					for(j=p=1;p
						for(p=0,i=n-j;i
							y[p++]=i;
							for(i=0;i
								if(sa[i]>=j)
								y[p++]=sa[i]-j;
								}
								for(i=0;i
									ws[i]=0;
									for(i=0;i
										ws[wv[i]=x[y[i]]]++;
										for(i=1;i
											ws[i]+=ws[i-1];
											for(i=n-1;i>=0;i--)
											sa[--ws[wv[i]]]=y[i];
											for(t=x,x=y,y=t,x[sa[0]]=0,p=i=1;i
												x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
												}
												}
												void Height(int n){
												int i,j,k=0;
												for(i=1;i<=n;i++)
												rank[sa[i]]=i;
												for(i=0;i
													for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
													}
													void Manacher(char str[],int n){
													int i,mx=0,id;
													for(i=1;i
														if(mx>i) rad[i]=min(rad[2*id-i],mx-i);
														else rad[i]=0;
														for(;str[i+rad[i]]==str[i-rad[i]];rad[i]++)
														;
														rad[i]--;
														if(mx
															mx=rad[i]+i;
															id=i;
															}
															}
															}
															int make_string(int mid){
															strcpy(r,r1);
															r[mid]='#';
															scanf("%s",r+mid+1);
															return strlen(r);
															}
															void cal_str(int from,int len){
															int i;
															s[0]='$';
															for(i=0;i
																s[2*i+1]='#';
																s[2*i+2]=r1[i+from];
																}
																s[2*len+1]='#';
																s[2*len+2]='@';
																Manacher(s,2*len+2);
																int t=0;
																for(i=1;i<=2*len+1;i++){
																if(rad[i]>ans){
																ans=rad[i];
																start=from+t-rad[i]/2;
																}
																if(s[i]!='#')
																t++;
																}
																}
																int main(){
																int n,mid;
																memset(height,0,sizeof(height));
																scanf("%s",r1);
																mid=strlen(r1);
																n=make_string(mid);
																SA(n+1,130);
																Height(n);
																ans=0;
																for(int i=2;i<=n;i++){
																	if(sa[i-1]mid)
																		cal_str(sa[i-1],height[i]);
																	else if(sa[i]mid)
																		cal_str(sa[i],height[i]);
																}
																for(int i=0;i
																		printf("%c",r1[start+i]);
																		printf("\n");
																		}
