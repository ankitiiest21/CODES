int dp1(string a,string b)  #counting the occurence of string b in string a as a subsequence..
{
 int**dp=new int*[a.size()+1];
 for(int i=0;i<a.size()+1;i++){
  dp[i]=new int[b.size()+1];
  for(int j=0;j<b.size()+1;j++){
   dp[i][j]=0;
  }
 }
 for(int i=0;i<b.size()+1;i++)
  dp[0][i]=0;
 for(int i=0;i<a.size()+1;i++)
  dp[i][0]=1;
 for(int i=1;i<a.size()+1;i++){
  for(int j=1;j<b.size()+1;j++){
   if(a[i-1]==b[j-1])
    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
   else
    dp[i][j]=dp[i-1][j];
   }
  }
  return dp[a.size()][b.size()];
}
