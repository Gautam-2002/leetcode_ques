class RecentCounter {
public:
    unordered_map<int,int> mp;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        mp[t] = mp.size()+1;
        int ans=0;
        for(auto it:mp){
            if(it.first >= t-3000){
                ans++;
            }
        }
        return ans;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */