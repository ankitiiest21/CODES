#include<bits/stdc++.h> 
using namespace std; 
class Edge{
  public: int s,d,w;
};
int getparent(int v,int*parent){
  if(parent[v]==v)
    return v;
  return getparent(parent[v],parent);
}
bool sortby(Edge e1,Edge e2){
  return e1.w<e2.w;
}
Edge *kruskals(Edge *edges,int n,int e){
  sort(edges,edges+e,sortby);
  Edge *out=new Edge[n-1];
  int parent[n];
  for(int i=0;i<n;i++)
   parent[i]=i;
  int count=0,i=0;
  while(count<(n-1)){
    Edge cur=edges[i];
    int parent_src=getparent(cur.s,parent);
    int parent_dest=getparent(cur.d,parent);
    if(parent_dest!=parent_src){
      out[count]=edges[i];
      count+=1;
      parent[parent_src]=parent_dest;
    }
    i+=1; 
  }
  return out;
}
int main() 
{ 
 int n,e;
 cin>>n>>e;
 Edge *edges=new Edge[e];
 for(int i=0;i<e;i++){
  int src,dest,we;
  cin>>src>>dest>>we;
  edges[i].s=src;
  edges[i].d=dest;
  edges[i].w=we;
 }
 Edge *out=kruskals(edges,n,e); 
 for(int i=0;i<n-1;i++){
  cout<<min(out[i].s,out[i].d)<<" "<<max(out[i].s,out[i].d)<<" "<<out[i].w<<endl;
 }
 return 0; 
} 
