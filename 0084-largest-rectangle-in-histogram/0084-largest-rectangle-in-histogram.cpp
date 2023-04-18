class Solution {
public:
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
};