#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=1e8;
int s[100000];
int main()
{
    int i,j,m,n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        vector<int>b;
        for(i=0;i<m;i++)
          {
              scanf("%d",&s[i]);
              b.push_back(MAXN);
          }
        b.push_back(MAXN);
        b[0]=-MAXN;
        b[1]=s[0];
        #define FIND(v)(lower_bound(b.begin(),b.end(),v)-b.begin())
        for(i=1;i<m;i++)
        {
               int tt=FIND(s[i]);
               b[FIND(s[i])]=s[i];
        }
        #undef FIND
        for(i=m;i>=1;i--)
        {
            if(b[i]!=MAXN)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
