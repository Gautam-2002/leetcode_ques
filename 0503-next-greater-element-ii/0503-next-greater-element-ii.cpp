class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        int i= n-1;
        while(i>=0){
            // cout<<i<<" "<<nums[i]<<" * ";
            while(st.top() != -1 && nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(st.top()==-1){
                int x = 0;
                while(x<i && nums[x]<=nums[i]){
                    x++;
                }
                if(x!=i)
                st.push(x);
            }
            if(st.top()==-1)ans[i]=-1;
            else ans[i] = nums[st.top()];
            st.push(i);
            i--;
            // cout<<"* ";
        }
        return ans;
    }
};