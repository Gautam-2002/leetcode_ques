//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
    //Function to count number of ways to reach the nth stair.
    int fun(int n,int dp[]){
        if(n<=1)return 1;
        if(dp[n]!=0)return dp[n];
        dp[n] = (fun(n-1,dp)%1000000007+fun(n-2,dp)%1000000007)%1000000007;
        int ans = dp[n]%1000000007;
        return ans;
    }
    int countWays(int n)
    {
        // your code here
        int dp[n+1]={0};
        int ans = fun(n,dp);
        return ans;
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends