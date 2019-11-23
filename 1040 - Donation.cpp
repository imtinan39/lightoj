#include<bits/stdc++.h>
using namespace std;

struct edge
{
    int p,k,d;
};
int par[501];
int makeset(int h)
{
    par[h]=h;
}

int fin(int a)
{
    if(par[a]==a)
    {
        return a;
    }
    else
    {
        par[a]=fin(par[a]);
        return par[a];
    }
}

int uni(int a,int b)
{
    int u=fin(a);
    int v=fin(b);
    if(u==v)
    {
        return 0;
    }
    else
    {
        par[u]=v;
        return 1;
    }
}

int main()
{
    int t;
    cin>>t;
    for(int s=0;s<t;s++)
    {
        int donate=0,cnt=0,cost=0,cost1=0,edge_count=0;
 int n,x;
 cin>>n;
        struct edge edges[n*n];



   for(int i=0;i<n+1;i++)
   {
       makeset(i);
   }


        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>x;

                if(i==j)
                {
                    donate=donate+x;
                }

                else if(i!=j&&x>0)
                {
                    edges[cnt].p=i;
                    edges[cnt].k=j;
                    edges[cnt].d=x;
                    cost=cost+x;
                    cnt=cnt+1;


                }
                else
                {
                    continue;
                }
            }
        }

        for(int i=0;i<cnt;i++)
        {
            for(int j=0;j<cnt-1;j++)
            {
                if(edges[j].d>edges[j+1].d)
                {
                    swap(edges[j],edges[j+1]);
                }
            }
        }



      for(int i=0;i<cnt;i++)
      {
          if(uni(edges[i].p,edges[i].k)==1)
          {
              cost1=cost1+edges[i].d;
              edge_count=edge_count+1;

          }
      }
        int result=0;
           result=donate+(cost-cost1);
          if(edge_count!=n-1)
          {
              cout<<"Case "<<s+1<<": "<<"-1"<<endl;
          }
          else
          {
             cout<<"Case "<<s+1<<": "<<result<<endl;
          }

    }
}

