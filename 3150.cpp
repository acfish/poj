#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
__int64 s[600];
__int64 gg[600];
__int64 ans[600][600];
__int64 sum[600];
__int64 matrix[600][600];
void init(int nn,int dd)
{
    memset(matrix,0,sizeof(matrix));
    for(int ii=0;ii<nn;ii++)
    {
        for(int jj=0;jj<=dd;jj++)
        {
            matrix[ii][(ii+jj)%nn]=1;
            matrix[ii][(ii+nn-jj)%nn]=1;
        }
        for(int jj=0;jj<nn;jj++)
        ans[ii][jj]=0;

        ans[ii][ii]=1;
        gg[ii]=0;
    }
    return ;
}
void binary(int nn,int kk,int mm)
{
    while(kk)
    {
            if(kk&1)
            {
               for(int ii=0;ii<nn;ii++)
               {
                    sum[ii]=0;
                    for(int jj=0;jj<nn;jj++)
                    sum[ii]=(sum[ii]+(ans[0][jj]%mm)*(matrix[jj][ii]%mm))%mm;
               }
               for(int ii=0;ii<nn;ii++)
               {
                    ans[0][ii]=sum[ii]%mm;
                    for(int jj=0;jj<nn;jj++)
                    ans[ii][jj]=sum[(nn+ii-jj)%nn]%mm;
               }
            }
            kk=kk>>1;
            for(int ii=0;ii<nn;ii++)
            {
                sum[ii]=0;
                for(int jj=0;jj<nn;jj++)
                sum[ii]=((sum[ii]%mm)+(matrix[0][jj]%mm)*(matrix[jj][ii]%mm)%mm)%mm;
            }
            for(int ii=0;ii<nn;ii++)
            {
                matrix[0][ii]=sum[ii]%mm;
                for(int jj=0;jj<nn;jj++)
                    matrix[ii][jj]=sum[(jj+ii)%nn]%mm;
            }
    }
    return ;
}
void get_ans(int nn,int mm)
{
    /*for(int ii=0;ii<nn;ii++)
       {
            for(int jj=0;jj<nn;jj++)
            {
               cout<<ans[ii][jj]<<' ';
            }
            cout<<endl;
       }*/
    for(int ii=0;ii<nn;ii++)
    {
        for(int jj=0;jj<nn;jj++)
            gg[ii]=(gg[ii]+s[jj]*ans[ii][jj])%mm;
    }
    return ;
}
int main()
{
    int i,j,n,m;
    int d,k;
    char w[3][100];
    int sta=1;
    while(scanf("%d%d%d%d",&n,&m,&d,&k)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%I64d",&s[i]);
        //printf("sample output #%d\n",sta++);
        init(n,d);
        binary(n,k,m);
        get_ans(n,m);
        printf("%I64d",gg[0]%m);
        for(i=1;i<n;i++)
            printf(" %I64d",gg[i]%m);
        printf("\n");
    }
    return 0;
}
/*
把不该输入的和输出的input or output也自己输入输出了
*/
