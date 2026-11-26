#include <stdio.h>
 #define INF 999
 int main(){
int n, adj[20][20], dist[20], visited[20]={0}, u,min;
 printf("Enter number of vertices: "); 
scanf("%d",&n); 
printf("Enter adjacency matrix:\n");
for(int i=0;i<n;i++) for(int j=0;j<n;j++) 
scanf("%d",&adj[i][j]);
 int start;
 printf("Enter start vertex: ");
 scanf("%d",&start); 
for(int i=0;i<n;i++) dist[i]=INF;
 dist[start]=0;
for(int count=0;count<n;count++)
{ min=INF;
for(int i=0;i<n;i++)
 if(!visited[i] && dist[i]<min)
{ min=dist[i]; u=i;
 } 
visited[u]=1;
for(int i=0;i<n;i++)
if(adj[u][i] && !visited[i] && dist[u]+adj[u][i]<dist[i]) 
dist[i]=dist[u]+adj[u][i];
}
printf("Shortest distances from %d:\n",start);
for(int i=0;i<n;i++)
 printf("%d -> %d : %d\n",start,i,dist[i]);
 return 0;
}