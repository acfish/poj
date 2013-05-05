#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN(a,b) (a)<(b)?(a):(b)
#define N 999999
using namespace std;
int s[12000];
int mark[12000];
int num[100100];
int mm[12000];
int main()
{
    int i,j,n,m;
    while(scanf("%d",&n)!=EOF)
    {
        memset(mark,0,sizeof(mark));
        memset(num,0,sizeof(num));
        __int64 sum=0;
        __int64 mmin=N;
        __int64 mmax=-N;
        for(i=1;i<=n;i++)
        {
            int r;
            scanf("%d",&r);
            mm[i]=r;
            num[r]=1;
            mmin=MIN(r,mmin);
            mmax=MAX(r,mmax);
            sum+=r;
        }
        int top=1;
        for(i=1;i<=mmax;i++)
        if(num[i])
        {
            num[i]=top;
            s[top++]=i;
        }
        for(i=1;i<=n;i++)
        {
            if(!mark[i])
            {
                __int64 len=0;
                __int64 getmin=N;
                int kk=i;
                while(!mark[kk])
                {
                    mark[kk]=1;
                    getmin=MIN(getmin,s[kk]);
                    len++;
                    kk=num[mm[kk]];
                }
                sum+=MIN((len-2)*getmin,(len+1)*mmin+getmin);
            }
        }
        printf("%I64d\n",sum);
    }
    return 0;
}
