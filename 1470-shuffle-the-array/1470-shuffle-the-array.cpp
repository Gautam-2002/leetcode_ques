class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2*n);
        int j=1;
        for(int i=0;i<n;i++){
            ans[2*i]=nums[i];
            ans[j]=nums[i+n];
            j+=2;
        }
        return ans;
    }
};