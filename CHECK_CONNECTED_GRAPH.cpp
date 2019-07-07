//akki
#include<bits/stdc++.h>
using namespace std;
vector<int> v;
void traverseviabfs(int**edges,bool*visited,int n,int sv)
{
 queue<int> q;
 q.push(sv);
 v.push_back(sv);
 visited[sv]=true;
 while(!q.empty())
 {
  for(int i=0;i<n;i++)
  {
   if(i!=q.front()&&edges[i][q.front()]==1&&!visited[i])
   {
   	q.push(i);
   	visited[i]=true;
   	v.push_back(i);
   }	
  }
  q.pop();
 }
 return;	
}
int main()
{
 int n,e;
 cin>>n>>e;
 int **edges=new int*[n];
 for(int i=0;i<n;i++)
 {
  edges[i]=new int[n];
  for(int j=0;j<n;j++)
   edges[i][j]=0;	
 }
  bool *visited=new bool[n];
 for(int i=0;i<n;i++)
   visited[i]=false;
 for(int i=0;i<e;i++)
 {
  int v1,v2;
  cin>>v1>>v2;
  edges[v1][v2]=1;
  edges[v2][v1]=1;	
 }
 traverseviabfs(edges,visited,n,0);
 if(v.size()==n)
  cout<<"true"<<endl;
 else
  cout<<"false"<<endl;
 for(int i=0;i<n;i++)
  delete edges[i];
 delete []edges;
 delete []visited;
 return 0; 	
}
