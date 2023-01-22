//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string p, string s) {
	    // code here
	    int ans=0;
        vector<int> mp1(26,0);vector<int> mp2(26,0);
        if(s.size()<p.size()){return ans;}
        int window = p.size();
        int len = s.size();
        int l = 0,r=0;
        while(r<window){
            mp1[p[r]-'a']++;
            mp2[s[r]-'a']++;
            r++;
        }r--;
        while(r<len){
            if(mp1 == mp2)ans++;
            r++;
            if(r!=len)mp2[s[r]-'a']++;
            mp2[s[l]-'a']--;
            l++;
        }
        return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends