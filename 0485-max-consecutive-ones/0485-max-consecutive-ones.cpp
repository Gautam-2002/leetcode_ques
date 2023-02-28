class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int i = 0,j = 0,ans=INT_MIN;
        while(j<n){
            while(j<n && nums[j]==1){
                j++;
            }
            // if(j==n)--j;
            ans = max(ans,j-i);
            j++;i=j;
        }
        return ans;
    }
};