//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int nums[], int n)
    {
      //Your code here
      unordered_map<int,bool> mp;
        for(int i=0;i<n;i++){
            int it=nums[i];
            if(mp.find(it-1)!=mp.end()){
                mp[it]=false;
            }
            else{
                mp[it]=true;
            }
            if(mp.find(it+1)!=mp.end()){
                mp[it+1]=false;
            }
        }
        int ans=0;
        for(auto i:mp){
            int curr=0;
            if(i.second==true){
                int x = i.first;
                while(mp.find(x)!=mp.end()){
                    curr++;
                    x++;
                }
                ans=max(ans,curr);
            }
                        
        }
        return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends