class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(auto i:nums1){
            mp1[i]++;
        }
        for(auto i:nums2){
            mp2[i]++;
        }
        int x=0,y=0;
        for(auto i:nums1){
            if(mp2.find(i)!=mp1.end()){
                x++;
            }
        }
        for(auto i:nums2){
            if(mp1.find(i)!=mp1.end()){
                y++;
            }
        }
        return {x,y};
    }
};