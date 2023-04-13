//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<string> ans;
    void solve(string s,int last,int len){
        if(len==0){
            ans.push_back(s);
            return;
        }
        if(last==1){
            solve(s+"0",0,len-1);
        }
        else{
            solve(s+"0",0,len-1);
            solve(s+"1",1,len-1);
        }
    }
    void generateBinaryStrings(int num){
        //Write your code
        solve("0",0,num-1);
        solve("1",1,num-1);
        sort(ans.begin(),ans.end());
        for(auto i:ans){
            cout<<i<<" ";
        }
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends