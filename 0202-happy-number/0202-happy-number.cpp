class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> mp;
        int x = n;
        int a = 0; 
        while(mp.find(x)==mp.end() || mp[x]<=1){
            string s = to_string(x);
            for(auto i:s){
                int digit = (i-'0');
                a += (digit*digit);
            }
            if(a==1)
                return true;
            mp[a]++;
            x = a;
            a = 0;
        }
        return false;
        
    }
};