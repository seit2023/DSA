
#include<iostream>
#include<stdlib.h>
using namespace std;


class kru
{
   public :
        int u,v,ne;
        int min,total,cost[50][50],parent[50]; //parent[i] array maintain the egde coming from u
        int find(int i);
        int uni(int i,int j);
        kru()
        {
                ne=1;
                total=0;
        }
};

main()
{
        kru k;
        int i,j,a,b,n;

        cout<<"\nEnter the no. of vertices : ";
        cin>>n;

        cout<<"\nEnter the cost adjacency matrix : ";
        for(i=1;i<=n;i++)
        {
                for(j=1;j<=n;j++)
                {
                        cin>>k.cost[i][j];
                        if(k.cost[i][j]==0) //Replace 0 i.e. absent edge by 999 to find proper min value
                                k.cost[i][j]=999;
                }
        }

        cout<<"\nThe edges of Minimum Cost Spanning Tree are : \n";
        while(k.ne<n)
        {
		k.min=999;
                for(i=1;i<=n;i++)
                {
                        for(j=1;j<=n;j++)
                        {
                                if(k.cost[i][j]<k.min)
                                {
                                        k.min=k.cost[i][j];
                                        a=k.u=i;
                                        b=k.v=j;
                                }
                        }
                }
                 if(k.uni(k.u,k.v)) //To avoid cycle
                {
                        k.ne++;
			cout<<"\n"<<k.ne<<" edge ("<<a<<","<<b<<") : "<<k.min;
                        k.total=k.total+k.min;
                }
                k.cost[a][b]=k.cost[b][a]=999; //After getting min value set position with 999
        }
        cout<<"\nMinimum cost : "<<k.total;
}

int kru::uni(int i,int j)
{
        if(i!=j)
        {
                parent[j]=i;
                        return 1;
        }
}

