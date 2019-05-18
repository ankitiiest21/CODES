#include<bits/stdc++.h>
using namespace std;
int subseq(string input,string output[])
{
 if(input.empty())
 {
  output[0]="";
  return 1;
 }
 string SmallString=input.substr(1);
 int count=subseq(SmallString,output);
 for(int i=0;i<count;i++)
  output[i+count]=input[0]+output[i];
 return 2*count; 
}
int main()
{
 string inp;
 cin>>inp;
 string*out=new string[(int)pow(2,inp.size())];
 int p=subseq(inp,out);
 for(int i=0;i<p;i++)
  cout<<out[i]<<endl;
 return 0;
}
