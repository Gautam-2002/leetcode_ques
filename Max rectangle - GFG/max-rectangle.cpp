//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
    void next_sm(int *nums,int n,vector<int> &ans){
        stack<int> st;
        st.push(-1);
        for(int i=n-1; i>=0 ;i--){
            while(st.top() != -1 && nums[st.top()] >= nums[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
    }
    void prev_sm(int *nums,int n,vector<int> &ans){
        stack<int> st;
        st.push(-1);
        for(int i=0;i<n;i++){
            while(st.top() != -1 && nums[st.top()] >= nums[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
    }
    int largestRectangleArea(int *heights,int n) {
        // int n = heights.size();
        
        vector<int> next(n);
        next_sm(heights,n,next);
        
        vector<int> prev(n);
        prev_sm(heights,n,prev);
        
        int area = INT_MIN;
        
        for(int i=0;i<n;i++){
            int l = heights[i];
            
            if(next[i] == -1){
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            
            area = max(area,(l*b));
        }
        return area;
    }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int area = largestRectangleArea(M[0],m);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j] != 0){
                    M[i][j] = M[i][j] + M[i-1][j];
                }
            }
            int x = largestRectangleArea(M[i],m);
            area = max(area,x);
        }
        return area;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends