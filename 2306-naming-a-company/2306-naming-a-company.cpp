class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long ans = 0;
        // array of sets
        unordered_set<string> st[26];
        for(auto i:ideas){
            st[i[0]-'a'].insert(i.substr(1));
        }
        // for(auto i:st){
        //     for(auto j:i)
        //         cout<<j<<"*";
        //     cout<<endl;
        // }
        for(int i = 0; i<25; i++){
            for(int j = i+1; j<26; j++){
                int x = 0; //to count no. of mutuals
                for( auto &it:st[i]){
                    if(st[j].count(it)){
                        x++;
                    }
                }
                ans += (2 * (st[i].size() - x) * (st[j].size() - x));
            }
        }
        return ans;
    }
};