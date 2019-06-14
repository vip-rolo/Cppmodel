#include<cstdio>
#define N 100100
using namespace std;
struct node
{
    int val,tag;
} tree[N*4];
int n,m;
inline void pushup(int root)
{
	tree[root].val=tree[root<<1].val+tree[root<<1|1].val;
}
inline void Pushdown(int root,int x,int y,int tag)
{
    tree[root].val+=(y-x+1)*tag;
    tree[root].tag+=tag;
}
inline void pushdown(int root,int x,int y)
{
    if(tree[root].tag==0) return;
    int mid=(x+y)>>1;
    Pushdown(root<<1,x,mid,tree[root].tag);
    Pushdown(root<<1|1,mid+1,y,tree[root].tag);
    tree[root].tag=0;
}
inline void build(int root,int x,int l,int r,int val)
{
	if(l==r&&l==x)
	{
		tree[root].val+=val;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid) build(root<<1,x,l,mid,val);
	else if(mid<r) build(root<<1|1,x,mid+1,r,val);
	pushup(root);
}
inline void add(int root,int x,int y,int l,int r,int val)
{
    if(x<=l&&r<=y)
    {
        tree[root].val+=(r-l+1)*val;
        tree[root].tag+=val;
        return;
    }
	pushdown(root,l,r);
    int mid=(l+r)>>1;
    if(x<=mid) add(root<<1,x,y,l,mid,val);
    if(mid<y) add(root<<1|1,x,y,mid+1,r,val);
    pushup(root);
}
int query(int root,int x,int y,int l,int r)
{
    if(x<=l&&r<=y) return tree[root].val;
    pushdown(root,l,r);
    int mid=(l+r)>>1,ans=0;
    if(x<=mid) ans+=query(root<<1,x,y,l,mid);
    if(mid<y) ans+=query(root<<1|1,x,y,mid+1,r);
    return ans;
}
int main()
{
    int i,x,y,ans;
    char op;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        build(1,i,1,n,x);
    }
    while(m--)
    {
        scanf("%s",&op);
        if(op=='1')
        {
            scanf("%d%d%d",&x,&y,&i);
            add(1,x,y,1,n,i);
        }
        else
        {
            scanf("%d%d",&x,&y);
            ans=query(1,x,y,1,n);
            printf("%d\n",ans);
        }
    }
    return 0;
}
