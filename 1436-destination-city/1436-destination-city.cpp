class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int> mp1,mp2;
        for(auto i:paths){
            mp1[i[0]]++;
            mp2[i[1]]++;
        }
        for(auto it:mp2){
            if(mp1.find(it.first)==mp1.end())
                return it.first;
        }
        return "";
    }
};