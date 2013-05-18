#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int ext_gcd(int aa,int bb,int &x,int &y)
{
    if(bb==0)
    {
        x=1;
        y=0;
        return aa;
    }
    int nn=ext_gcd(bb,aa%bb,x,y);
    int t=x;
    x=y;
    y=t-aa/bb*y;
    return nn;
}
int up(int nn,int mm)
{
    while(nn<0)
    {
        nn+=mm;
    }
    return nn;
}
int main()
{
    int i,j,m,n;
    int a,b,c,d;
    int kk=1;
    while(scanf("%d%d%d%d",&a,&b,&c,&d),a!=-1||b!=-1||c!=-1||d!=-1)
    {
        __int64 sum=0;
        int x[3],y[3];
        ext_gcd(28*33,23,x[0],y[0]);
        x[0]=up(x[0],23);
        //cout<<x[0]<<endl;
        ext_gcd(23*33,28,x[1],y[1]);
        x[1]=up(x[1],28);
      //  cout<<x[1]<<endl;
        ext_gcd(23*28,33,x[2],y[2]);
        x[2]=up(x[2],33);
       // cout<<x[2]<<endl;
        sum=x[0]*28*33*a+x[1]*33*23*b+x[2]*23*28*c;
       // cout<<sum<<endl;
        __int64 rr=((sum%(23*28*33))+(23*28*33))%(23*28*33);
        //cout<<"rr = "<<rr<<endl;
        //if(rr==0)rr=23*28*33;
        while(rr<=d)
            rr+=23*28*33;
        //else
          //  rr-=d;
        printf("Case %d: the next triple peak occurs in %d days.\n",kk++,rr-d);
        //printf("%I64d\n",rr-d);
    }
    return 0;
}
/*
ex_gcd问题+中国剩余定理
wa了几次的原因，没有处理好rr的原因和取模。
*/
