#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int matrix[3][3];
int ans[3][3];
int mm[3][3];
int binary(int nn)
{
    while(nn)
    {
        if(nn&1)
        {
            for(int ii=1;ii<=2;ii++)
                for(int jj=1;jj<=2;jj++)
                mm[ii][jj]=(ans[ii][1]*matrix[1][jj]+ans[ii][2]*matrix[2][jj])%10000;
            for(int ii=1;ii<=2;ii++)
                for(int jj=1;jj<=2;jj++)
                ans[ii][jj]=mm[ii][jj];
        }
        nn/=2;
        for(int ii=1;ii<=2;ii++)
            for(int jj=1;jj<=2;jj++)
            mm[ii][jj]=(matrix[ii][1]*matrix[1][jj]+matrix[ii][2]*matrix[2][jj])%10000;
        for(int ii=1;ii<=2;ii++)
            for(int jj=1;jj<=2;jj++)
            matrix[ii][jj]=mm[ii][jj];
    }
    return ans[1][1]%10000;
}
void init()
{
    ans[1][1]=1;
    ans[2][2]=1;
    ans[1][2]=0;
    ans[2][1]=0;
    matrix[1][1]=1;
    matrix[1][2]=1;
    matrix[2][1]=1;
    matrix[2][2]=0;
    return ;
}
int main()
{
    int i,j,m,n;
    while(scanf("%d",&n),n!=-1)
    {
        init();
        if(n==0){printf("0\n");continue;}
        int tt=binary(n-1);
        printf("%d\n",tt);
    }
    return 0;
}
