class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n=arr.size();
        for(int x:arr){
            mp[x]++;
        }
        set<int> st;
        for(auto it: mp){
            if(st.count(it.second)>0){
                return false;
            }
            else{
                st.insert(it.second);
            }
        }
        return true;
    }
};