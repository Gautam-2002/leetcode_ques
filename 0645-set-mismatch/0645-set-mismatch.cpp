class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i:nums){
            mp[i]++;
        }
        int x,y;
        for(int i=0;i<nums.size();i++){
            if(mp.find(i+1)==mp.end())y=i+1;
            else{
                if(mp[i+1]==2)x=i+1;
            }
        }
        return {x,y};
    }
};