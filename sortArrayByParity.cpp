class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        if(nums.size()==1 ||nums.size()==0)return nums;
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            if(nums[i]%2==0){
                i++;
            }
            else if(nums[i]%2==1 && nums[j]%2==0){
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
            else{
                j--;
            }
        }
        return nums;
    }
};