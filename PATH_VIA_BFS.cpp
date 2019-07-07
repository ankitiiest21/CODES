//akki
#include<bits/stdc++.h>
using namespace std;
map<int, int> mp;
bool getpathviabfs(int**edges,bool*visited,int n,int v1,int v2)
{
 queue<int> q;
 q.push(v1);
 visited[v1]=true;
 while(!q.empty())
 {
  for(int i=0;i<n;i++)
  {
   if(q.front()==v2)
    return true;	
   if(i!=q.front()&&edges[i][q.front()]==1&&!visited[i])
   {
   	q.push(i);
   	mp[i]=q.front();
   	visited[i]=true;
   }	
  }
  q.pop();	
 }
 return false;
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
 bool chk=getpathviabfs(edges,visited,n,sv,ev);
 if(chk)
 {
  cout<<ev<<" ";	
  for(int i=ev;i!=sv;)
  {
  	cout<<mp[i]<<" ";
  	i=mp[i];
  }
  cout<<endl;	
 }
 for(int i=0;i<n;i++)
  delete edges[i];
 delete []edges;
 delete []visited;
 return 0; 	
}
