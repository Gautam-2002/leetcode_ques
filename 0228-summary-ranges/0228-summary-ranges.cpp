class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        if(nums.size()==0)
            return ans;
        if(nums.size()==1){
            return {to_string(nums[0])};
        }
        int s = nums[0];
        int e = nums[0];
        int i = 0;
        bool f = false;
        while(i+1<nums.size()){
            if(nums[i]+1==nums[i+1]){
                if(i+1==nums.size()-1)
                    f=true;
            }
            else{
                e = nums[i];
                if(s==e){
                    ans.push_back(to_string(s));
                }
                else{
                    ans.push_back(to_string(s)+"->"+to_string(e));
                }
                if(i+1==nums.size()-1){
                    f=true;
                }
                s = nums[i+1];
            }
            i++;
        }
        if(f){
            e = nums[i];
            if(s==e){
                ans.push_back(to_string(s));
            }
            else{
                ans.push_back(to_string(s)+"->"+to_string(e));
            }
        }
        return ans;
    }
};