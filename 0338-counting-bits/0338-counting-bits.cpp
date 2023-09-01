class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=0;i<=n;i++){
            // string str = bitset<32>(i).to_string();
            // int x=0;
            // for(auto s:str){
            //     if(s=='1')
            //         x++;
            // }
            // ans[i] = x;
            
            // or :
            
            ans[i] = __builtin_popcount(i);
            
        }
        return ans;
    }
};