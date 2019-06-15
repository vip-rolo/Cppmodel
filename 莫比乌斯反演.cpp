#include<iostream>
#include<cstdio>
#define ll long long
#define N 10000000
using namespace std;
ll sum[N+1];
int f[N+1],mu[N+1],prime[N+1],cnt;
bool flag[N+1];
void getmu()
{
	mu[1]=1;
	for(int i=2;i<=N;i++)
	{
		if(!flag[i])prime[++cnt]=i,mu[i]=-1;
		for(int j=1;j<=cnt&&i*prime[j]<=N;j++)
		{
			flag[i*prime[j]]=1;
			if(i%prime[j]==0)break;
			mu[i*prime[j]]=-mu[i];
		}
	}
	for(int i=1;i<=cnt;i++)
		for(int j=1;prime[i]*j<=N;j++)
			f[j*prime[i]]+=mu[j];
	for(int i=1;i<=N;i++)
		sum[i]+=sum[i-1]+f[i];
}
ll solve(int a,int b)
{
	ll ans=0;
	if(a>b)swap(a,b);
	for(int l=1,r=0;l<=a;l=r+1)
	{
		r=min(a/(a/l),b/(b/l));
		ans+=(ll)(sum[r]-sum[l-1])*(ll)(a/l)*(ll)(b/l);
	}
	return ans;
}
int main()
{
	int T,n,m;
	getmu();
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		if(n>m)swap(n,m);
		printf("%lld\n",solve(n,m));
	}
	return 0;
} 
