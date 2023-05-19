class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int x = 1;
        int idx = 0;
        int curr = 0;
        int ans = 0;
        int s = 0;
        for(int i = 0;i<nums.size();i++){
            int ele = nums[i];
            if(ele==1){
                curr++;
            }
            else if(ele==0 && x==1){
                x=0;
                idx = i;
            }
            else{
                x==1;
                curr=curr-(idx-s);
                s = idx+1;
                idx = i;
            }
            ans = max(ans,curr);                
        }
        if(x==1)ans-=1;
        return ans;
    }
};