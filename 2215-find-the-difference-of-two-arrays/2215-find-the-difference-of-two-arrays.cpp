class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        for(auto i:nums1){
            mp1[i]++;
        }
        for(auto i:nums2){
            mp2[i]++;
        }
        vector<int> tmp;
        for(auto i:mp1){
            if(mp2.find(i.first)==mp2.end())
                tmp.push_back(i.first);
        }
        ans.push_back(tmp);
        tmp = {};
        for(auto i:mp2){
            if(mp1.find(i.first)==mp1.end())
                tmp.push_back(i.first);
        }
        ans.push_back(tmp);
        return ans;
    }
};