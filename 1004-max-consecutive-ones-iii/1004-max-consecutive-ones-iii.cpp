class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int x = k;
        int curr = 0;
        int ans = INT_MIN;
        if(k==0){
            for(auto i:nums){
                if(i==1)curr++;
                else curr=0;
                ans = max(ans,curr);
            }
            return ans;
        }
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==1)curr++;
            else if(x > 0){
                curr++;
                x--;
            }
            else{
                int l = i-curr;
                while(x!=1 && l<i){
                    if(nums[l++]==0)
                        x=1;
                    curr--;
                }
                x--;
                curr++;
            }
            ans=max(ans,curr);
        }
        return ans;
    }
};