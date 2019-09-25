#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class trieNode
{
    public:
        trieNode* left;
        trieNode* right;
};

void insert(ll x,trieNode *head)
{
    trieNode *curr=head;
    for(int i=31;i>=0;i--)
    {
        ll b=((1<<i)&x);
        if(b==0)
        {
            if(curr->left==0){
                curr->left=new trieNode();
            }
            curr=curr->left;
        }
        else{
            if(curr->right==0){
                curr->right=new trieNode();
            }
            curr=curr->right;
        }
    }
}

ll maximum(ll x,trieNode *head)
{
    trieNode *curr=head;
    ll val=0;
    for(int i=31;i>=0;i--)
    {
        ll b=((1<<i)&x);
        if(b==0)
        {
            if(curr->right){
                curr=curr->right;
                val+=(1<<i);
            }
            else{
                curr=curr->left;
            }
        }
        else{
            if(curr->left){
                curr=curr->left;
                val+=(1<<i);
            }
            else{
                curr=curr->right;
            }
        }
    }
    return val;
}

int main() {
    ll n;
    cin>>n;
    ll *arr=new ll[n+1];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    trieNode *head=new trieNode();
    ll x=0;
    for(ll i=0;i<n;i++){
        x=x^arr[i];
        insert(x,head);
    }
    x=0;
    ll maxi=maximum(x,head);
    for(int i=0;i<n;i++){
        x=x^arr[i];
        maxi=max(maxi,maximum(x,head));
    }
    cout<<maxi<<endl;
	return 0;
}
