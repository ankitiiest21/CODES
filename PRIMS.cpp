//akki
#include<bits/stdc++.h> 
using namespace std; 
int getminVertex(int*weight,bool*visited,int n){
  int minVertex=-1;
  for(int i=0;i<n;i++){
   if(!visited[i]&&((minVertex==-1)||(weight[minVertex]>weight[i])))
     minVertex=i;
  }
  return minVertex;
}
void prims(int**edges,int n,int e){
  bool*visited=new bool[n];
  int*parent=new int[n];
  int*weight=new int[n];
  for(int i=0;i<n;i++){
    visited[i]=false;
    weight[i]=INT_MAX;
  }
  parent[0]=-1;
  weight[0]=0;
  for(int i=0;i<n-1;i++){
    int minVertex=getminVertex(weight,visited,n);
    visited[minVertex]=true;
    for(int j=0;j<n;j++){
      if(edges[minVertex][j]!=0&&!visited[j]){
        if(weight[j]>edges[minVertex][j]){
          weight[j]=edges[minVertex][j];
          parent[j]=minVertex;
        }
      }
    }
  }
  for(int i=1;i<n;i++){
    cout<<min(parent[i],i)<<" "<<max(parent[i],i)<<" "<<weight[i]<<endl;
  }
  delete []visited;
  delete []weight;
  delete []parent;
}
int main() 
{ 
 int n,e;
 cin>>n>>e;
 int**edges=new int*[n];
 for(int i=0;i<n;i++){
  edges[i]=new int[n];
  for(int j=0;j<n;j++)
    edges[i][j]=0;
 }
 for(int i=0;i<e;i++){
  int sv,ev,w;
  cin>>sv>>ev>>w;
  edges[sv][ev]=w;
  edges[ev][sv]=w;
 }
 prims(edges,n,e);
 for(int i=0;i<n;i++)
  delete []edges[i];
 delete []edges;
 return 0; 
} 
