//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int mostBalloons(int n, pair<int, int> points[]) {
        
        // Code here
        int ans = 2;
        if(n<2)return n;
        for(int i=0;i < n;i++){
            unordered_map<double,int> mp;
            int cnt =0;
            for(int j=0;j<n;j++){
                if(points[i].first==points[j].first &&points[i].second==points[j].second){
                    cnt++;
                }
                else{
                    double slope = (double)(points[j].second-points[i].second)/
                    (double)(points[j].first-points[i].first);
                    mp[slope]++;
                }
            }
            int temp=0;
            for(auto x: mp){
                temp = max(temp,x.second+cnt);
            }
            ans = max(ans,temp);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        pair<int, int> arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i].first;
        }
        for (int i = 0; i < N; i++) {
            cin >> arr[i].second;
        }
        Solution ob;
        cout << ob.mostBalloons(N, arr) << endl;
    }
}
// } Driver Code Ends