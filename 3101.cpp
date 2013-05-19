#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

#define MAX(a,b)((a)>(b)?(a):(b))
using namespace std;

struct node
{
    int fz;
    int fm;
}w[10100];
int s[10100];
int prime[10100];
int mark[10100];
int ma[1500];
int ans[1100];

int abb(int nn)
{
    if(nn<0)return -nn;
    return nn;
}
void get_prime()
{
    prime[1]=2;
    int uu=2;
    for(int ii=3;ii<=10000;ii+=2)
    {
        int mm=0;
        for(int jj=1;prime[jj]*prime[jj]<=ii&&jj<uu;jj++)
        {
            if(ii%prime[jj]==0){mm=1;break;}
        }
        if(!mm)
            prime[uu++]=ii;
    }
   // cout<<prime[1229]<<endl;
    return ;
}//get the prime table
int gcd(int aa,int bb)
{
     while(bb)
     {
         int tt=bb;
         bb=aa%bb;
         aa=tt;
     }
     return aa;
}


int main()
{
    int i,j,m,n;
   // cout<<50004999/9999<<endl;
    get_prime();
    while(scanf("%d",&n)!=EOF)
    {
        memset(mark,0,sizeof(mark));
        memset(ma,0,sizeof(ma));
        memset(ans,0,sizeof(ans));
        int top=0;
        for(i=1;i<=n;i++)
          {
            int pp;
            scanf("%d",&pp);
            if(!mark[pp])
            {
                mark[pp]=1;
                s[++top]=pp;
            }
          }
        for(i=1;i<top;i++)
        {
            int rr=gcd(s[i]*s[i+1],2*abb(s[i]-s[i+1]));
            w[i].fz=s[i]*s[i+1]/rr;
            //cout<<w[i].fz<<' '<<rr<<endl;
            w[i].fm=2*abb(s[i]-s[i+1])/rr;
        }
        //cout<<w[1].fz<<endl;
        int gcd1=w[1].fm;
        for(i=1;i<top;i++)
        {
            gcd1=gcd(gcd1,w[i].fm);
            int sta=1;
            while(w[i].fz!=1)
            {
                int ee=0;
                while(w[i].fz%prime[sta]==0)
                {
                    w[i].fz/=prime[sta];
                    ee++;
                }
                ma[sta]=MAX(ma[sta],ee);
                sta++;
            }
        }
        ans[1]=1;
        for(i=1;i<1230;i++)
        {
            for(j=1;j<=ma[i];j++)
            {
                int temp=0;
                for(int k=1;k<=1001;k++)
                {
                    ans[k]=ans[k]*prime[i]+temp;
                    int yy=ans[k];
                    ans[k]%=10000;
                    temp=yy/10000;
                }
            }
        }
        for(i=1001;;i--)
        {
            if(ans[i]>0)
                    break;
        }
        printf("%d",ans[i]);
        for(j=i-1;j>=1;j--)
            printf("%04d",ans[j]);
        printf(" %d\n",gcd1);
    }
    return 0;
}
/*
用求素因子的方法来最小公倍数，取每个数的每个素因子的max值，他们的乘积就是其最小公倍数
然后用大数的乘法来算得最小公倍数，其中用大数的乘法不需要用字符串，而只是每个int类型的数组取4—5位（这个不定）。
最后输出的时候要注意顺序，我在顺序问题上wa了几次。从左到右依次是高位到低位。
*/
