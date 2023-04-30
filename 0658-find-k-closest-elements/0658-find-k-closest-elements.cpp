#define pi pair<int,int>
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pi> pq;
        for(int i=0;i<k;i++){
            pq.push({abs(arr[i]-x),arr[i]});
        }
        for(int i=k;i<arr.size();i++){
            pq.push({abs(arr[i]-x),arr[i]});
            pq.pop();
        }
        vector<int> ans;
        while(pq.size() > 0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};