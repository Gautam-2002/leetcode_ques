class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        if(nums.size()==1)return nums;
        vector<int> target(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            for(int j=target.size()-1;j>index[i];j--){
                target[j]=target[j-1];
            }
            target[index[i]]=nums[i];
            
        }
        return target;
    }
};
// using inbuilt function insert
// class Solution {
// public:
//     vector<int> createTargetArray(vector<int>& nums, vector<int>& index) 
//     {
//         vector<int> result;
//         for(int i=0;i<index.size();++i)
//             result.insert(result.begin()+index[i],nums[i]);
//         return result;
//     }
// };