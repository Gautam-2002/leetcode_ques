//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<vector<string>> allPalindromicPerms(string s) {
        // code here
        vector<vector<string>> ans;
        vector<string> path;
        solve(0,s,path,ans);
        return ans;
    }
    void solve(int idx,string s,vector<string>path,vector<vector<string>>&ans){
        if(idx == s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=idx;i<s.size();++i){
            if(isPal(s,idx,i)){
                path.push_back(s.substr(idx,i-idx+1));
                solve(i+1,s,path,ans);
                path.pop_back();
            }
        }
    }
    bool isPal(string s,int l,int r){
        while(l<=r){
            if(s[l++]!=s[r--]){
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends