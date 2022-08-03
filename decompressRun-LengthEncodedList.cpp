class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;2*i<nums.size();i++){
            int temp=nums[2*i];
            for(int j=0;j<temp;j++){
                ans.push_back(nums[2*i+1]);
            }
        }
        return ans;
    }
};