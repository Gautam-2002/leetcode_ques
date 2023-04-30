class compare{
    public:
    bool operator()(pair<int,int> n1, pair<int,int> n2){
        if(n1.second==n2.second){
            return n1.first<n2.first;
        }
        return n1.second>n2.second;
    }
};

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> res;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
        for(auto x: m){
            pq.push({x.first, x.second});
        }
        
        while(!pq.empty()){
            while(m[pq.top().first]>0){
                res.push_back(pq.top().first);
                m[pq.top().first]--;
            }
            pq.pop();
        }
        return res;
    }
};