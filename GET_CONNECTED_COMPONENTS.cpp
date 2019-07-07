//akki
#include<bits/stdc++.h>
using namespace std;

bool visited[100]={false};
vector<int> traverseviabfs(int**edges,int n,int sv)
{
 queue<int> q;
 vector<int> v;
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
 sort(v.begin(),v.end());
 return v;	
}
vector<vector<int> > getconnectedcomponents(int**edges,int n)
{
 vector<vector<int> > ans;	
 for(int i=0;i<n;i++)
 {
  if(!visited[i])
  {
   vector<int> temp=traverseviabfs(edges,n,i);
   ans.push_back(temp);
  }	
 }
 return ans;
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
 for(int i=0;i<e;i++)
 {
  int v1,v2;
  cin>>v1>>v2;
  edges[v1][v2]=1;
  edges[v2][v1]=1;	
 }
 vector<vector<int> > ans=getconnectedcomponents(edges,n);
 for(int i=0;i<ans.size();i++)
 {
  for(int j=0;j<ans[i].size();j++)
   cout<<ans[i][j]<<" ";
  cout<<endl; 	
 } 
 for(int i=0;i<n;i++)
  delete edges[i];
 delete []edges;
 return 0; 	
}
