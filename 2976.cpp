#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const double eps=1e-8;

struct node
{
    __int64 xx;
    __int64 yy;
}s[1200];

struct node1
{
    double num;
    int sta;
}d[1200];

int cmp(node1 a,node1 b)
{
    return a.num>b.num;
}

int main()
{
    int i,j,m,n;
    while(scanf("%d%d",&m,&n),m||n)
    {
        for(i=0;i<m;i++)
        scanf("%I64d",&s[i].xx);
        for(i=0;i<m;i++)
        scanf("%I64d",&s[i].yy);
        double r=1.0;
        while(1)
        {
            for(i=0;i<m;i++)
            {
                d[i].num=s[i].xx-r*s[i].yy;
                d[i].sta=i;
            }
            sort(d,d+m,cmp);
            double p,q;
            p=0.0;
            q=0.0;
            for(i=0;i<m-n;i++)
            {
                p+=s[d[i].sta].xx;
                q+=s[d[i].sta].yy;
            }
            if(fabs(p/q-r)<eps)break;
            r=p/q;
        }
        printf("%.0f\n",(r+eps)*100);
    }
    return 0;
}
