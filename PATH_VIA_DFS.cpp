//akki
#include<bits/stdc++.h>

using namespace std;
vector<int> haspathviadfs(int**edges,bool*visited,int n,int v1,int v2)
{
 if(v1==v2)
 {
  vector<int> m;
  m.push_back(v1);
  return m;	
 }
 visited[v1]=true;
 for(int i=0;i<n;i++)
 {
  if(edges[v1][i]==1&&!visited[i])
  {
   vector<int> m=haspathviadfs(edges,visited,n,i,v2);
   if(m.size()>0)
   {
    m.push_back(v1);
    return m;
   }	
  }
 }
 vector<int> m;
 return m;
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
 int sv,ev;
 cin>>sv>>ev;
 vector<int> ans=haspathviadfs(edges,visited,n,sv,ev);
 for(int i=0;i<ans.size();i++)
  cout<<ans[i]<<" ";
 cout<<endl;
 for(int i=0;i<n;i++)
  delete edges[i];
 delete []edges;
 delete []visited;
 return 0; 	
}
