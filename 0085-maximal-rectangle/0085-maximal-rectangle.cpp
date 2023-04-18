class Solution {
    void next_sm(vector<int>& nums,int n,vector<int> &ans){
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
    void prev_sm(vector<int>& nums,int n,vector<int> &ans){
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
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> M(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j = 0; j<m;j++){
                if(matrix[i][j]=='1'){
                    M[i][j]=1;
                }
            }
        }
        int area = largestRectangleArea(M[0]);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j] != 0){
                    M[i][j] = M[i][j] + M[i-1][j];
                }
            }
            int x = largestRectangleArea(M[i]);
            area = max(area,x);
        }
        return area;
    }
};