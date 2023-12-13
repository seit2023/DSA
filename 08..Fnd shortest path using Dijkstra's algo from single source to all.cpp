
#define infinity 9999
#define MAX 20
#include<iostream>

using namespace std;
class graph
{
	int G[MAX][MAX];
	int n;

	public:
		graph()
		{
			n=0;
		}
		void readgraph();
		//MAX=100;
		void printgraph();
		void dijk(int startnode);
};
void graph::readgraph()
{
	int i,j;
	cout<<"\n Enter no of vertices: ";
	cin>>n;
	cout<<"\n Enter the adjacency matrix: ";
	for(i=0;i<n;i++)


	for(j=0;j<n;j++)

	cin>>G[i][j];


}
void graph::printgraph()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		cout<<"\n";
		for(j=0;j<n;j++)

		cout<<" "<<G[i][j];

	}
}
void graph::dijk(int startnode)
{
	int cost[MAX][MAX],distance[MAX],pred[MAX];
	int visited[MAX],i,j,mindistance,nextnode,count;
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	{
		if(G[i][j]==0)
			cost[i][j]=infinity;
		else
			cost[i][j]=G[i][j];
	}
	for(i=0;i<n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	while(count<n-1)
	{
		mindistance=infinity;
		for(i=0;i<n;i++)
		  if(distance[i]<mindistance&&!visited[i])
		    {
			mindistance=distance[i];
			nextnode=i;
		    }
		visited[nextnode]=1;
		for(i=0;i<n;i++)
		  if(!visited[i])
		    if(mindistance+cost[nextnode][i]<distance[i])
			{
				distance[i]=mindistance+cost[nextnode][i];
				pred[i]=nextnode;
			}
		count++;
	}
	for(i=0;i<n;i++)
	if(i!=startnode)
	{
		cout<<" \n Distance of node : " <<i<<"="<<distance[i];
		cout<<"\n Path= "<<i;
		j=i;
		do
		{
			j=pred[j];
			cout<<"<-"<<j;
		}while(j!=startnode);
	}
}
// int dijk(int startnode,int n,int G[MAX][MAX]);

int main()
{
	graph g;
	int x;
	g.readgraph();
	cout<<"\n Enter the satrtnode :  ";
	cin>>x;
	g.dijk(x);
	return(0);
}
