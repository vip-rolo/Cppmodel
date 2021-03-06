#include<iostream>
#include<cstdio>
#define N 1000001 
using namespace std;
int tree[N],n,m;
int lowbit(int x){return x&-x;}
void add(int x,int y)
{
	while(x<=n)
	{
		tree[x]+=y;
		x+=lowbit(x);
	}
}
int ask(int x)
{
	int ans=0;
	while(x)
	{
		ans+=tree[x];
		x-=lowbit(x);
	}
	return ans;
}
int main()
{
	int i,x,y;int op;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		add(i,x);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&op,&x,&y);
		if(op==1)add(x,y);
		else printf("%d\n",ask(y)-ask(x-1));
	}
	return 0;
}
