class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<long long,long long> mp;
        long long day = 0;
        for(int i=0;i<tasks.size();i++){
            if(mp.find(tasks[i])==mp.end()){
                mp[tasks[i]]=1+space+day;
                day++;
            }
            else{
                if(mp[tasks[i]] > day){
                    day = mp[tasks[i]];
                }
                mp[tasks[i]] = 1+space+day;
                day++;
            }
        }
        return day;
    }
};