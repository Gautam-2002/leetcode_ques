class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // by default priority_queue in stl is maxheap means top element will be largest
        // so to create minheap(smallest element at top) we use below syntax
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto i:nums){
            pq.push(i);
            if(pq.size()>k){
                pq.pop();
            }
        }
        // while(pq.size()>0){
        //     cout<<pq.top()<<endl;
        //     pq.pop();
        // }
        return pq.top();
    }
};