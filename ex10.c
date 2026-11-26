#include <stdio.h> 
#define INF 999 
int main(){
int n, cost[10][10], selected[10]={0};
printf("Enter number of vertices: ");
 scanf("%d",&n); 
printf("Enter cost adjacency matrix:\n");
for(int i=0;i<n;i++) 
for(int j=0;j<n;j++)
 scanf("%d",&cost[i][j]);
selected[0]=1;
 printf("Edges in MST:\n");
for(int count=0;count<n-1;count++)
{
 int min=INF,u=-1,v=-1;
for(int i=0;i<n;i++) 
if(selected[i])
for(int j=0;j<n;j++)
if(!selected[j] && cost[i][j]<min)
{ 
min=cost[i][j]; u=i; v=j;
}
printf("%d-%d (%d)\n",u,v,min); selected[v]=1;
}
return 0;
}