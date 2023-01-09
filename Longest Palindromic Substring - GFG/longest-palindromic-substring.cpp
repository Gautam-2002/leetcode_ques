//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string s){
        // code here 
        if(s.size()<=1)return s;
        
        int n=s.size();
        int ans = 1;
        int st = 0,en = 0;
        
        for(int i=0;i<n-1;++i){
            int l = i,r = i;
            while(l>=0 && r<n){
                if(s[l] == s[r]){
                    l--;r++;
                }
                else
                    break;
            }
            int len = r-l-1;
            if(len > ans){
                ans = len;
                st = l+1;
                en = r-1;
            }
        }

        for(int i=0;i<n-1;++i){
            int l = i,r = i+1;
            while(l>=0 && r<n){
                if(s[l] == s[r]){
                    l--;r++;
                }
                else
                    break;
            }
            int len = r-l-1;
            if(len > ans){
                ans = len;
                st = l+1;
                en = r-1;
            }
        }
        return s.substr(st,ans);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends