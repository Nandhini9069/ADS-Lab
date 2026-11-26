#include <stdio.h> 
#define INF 999 
int main(){
int n, dist[20][20];
printf("Enter number of vertices: "); 
scanf("%d",&n); 
printf("Enter adjacency matrix (use %d for no edge):\n",INF);
 for(int i=0;i<n;i++) 
for(int j=0;j<n;j++) 
scanf("%d",&dist[i][j]);
for(int k=0;k<n;k++)
 for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
if(dist[i][k]+dist[k][j]<dist[i][j]) 
dist[i][j]=dist[i][k]+dist[k][j];
printf("All-pairs shortest distances:\n");
 for(int i=0;i<n;i++){
for(int j=0;j<n;j++)
 printf("%d\t",dist[i][j]); 
printf("\n");
}
return 0;
}