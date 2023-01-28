//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int solve(string str,int n){
        if(n==0)return 0;
        
        int digit = str[n-1]-'0';
        
        return solve(str,n-1)*10 + digit;
    }
    int atoi(string str) {
        //Your code here
        int ans = -1;
        int n = str.size();
        for(int i=0;i<n;i++){
            if((str[i]>='0' && str[i]<='9') || (str[i]=='-'&& i==0)){
                continue;
            }
            else
                return ans;
        }
        string s = "";
        if(str[0]=='-'){
            for(int i=1;i<n;i++)
                s+=str[i];
            ans = solve(s,n-1)*(-1);
        }
        else
            ans = solve(str,n);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends