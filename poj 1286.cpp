#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int gcd(int aa,int bb)
{
    int tt;
    while(bb)
    {
        tt=bb;
        bb=aa%bb;
        aa=tt;
    }
    return aa;
}
__int64 poww(int nn,int mm)
{
    __int64 num=1;
    for(int ii=1;ii<=mm;ii++)
        num*=nn;
    return num;
}
int main()
{
    int i,j,m,n;
    while(scanf("%d",&m),m!=-1)
    {
        if(m==0){printf("0\n");continue;}
        n=3;
        __int64 nu=0;
        __int64 sum=0;
        for(i=1;i<=m;i++)
        {
           int u=gcd(m,i);
            sum+=poww(n,u);
        }
        nu+=m;
        if(m%2)
        {
            int u=m/2+1;
            sum+=m*poww(n,u);
            nu+=m;
        }
        else
        {
            int u=m/2+1;
            sum+=(m/2)*poww(n,u);
            u=m/2;
            sum+=u*poww(n,u);
            nu+=m;
        }
        printf("%I64d\n",sum/nu);
    }
    return 0;
}
