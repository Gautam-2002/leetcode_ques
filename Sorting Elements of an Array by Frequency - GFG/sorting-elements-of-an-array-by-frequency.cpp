// class compare{
//     public:
//     bool operator()(pair<int,int> n1, pair<int,int> n2){
//         if(n1.second==n2.second){
//             return n1.first<n2.first;
//         }
//         return n1.second>n2.second;
//     }
// };

// class Solution {
// public:
//     vector<int> frequencySort(vector<int>& nums) {
//         vector<int> res;
//         unordered_map<int,int> m;
//         for(int i=0;i<nums.size();i++){
//             m[nums[i]]++;
//         }
        
//         priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
//         for(auto x: m){
//             pq.push({x.first, x.second});
//         }
        
//         while(!pq.empty()){
//             while(m[pq.top().first]>0){
//                 res.push_back(pq.top().first);
//                 m[pq.top().first]--;
//             }
//             pq.pop();
//         }
//         return res;
//     }
// };


#include <bits/stdc++.h>
using namespace std;

#define pi pair<int,int>
// class compare{
//     bool operator()(pi a,pi b){
//         if(a.first==b.first)
//             return a.first < b.first;
//         return a.first > b.first;
//     }
// };
vector<int> frequencySort(vector<int>& A) {
        unordered_map<int, int> count;
        for (int a: A)
            count[a]++;
        sort(begin(A), end(A), [&](int a, int b) {
            return count[a] == count[b] ? a < b : count[a] > count[b];
        });
        return A;
}
int main() {
	//code
	int t;cin>>t;
	while(t--){
	    int n;cin>>n;
	    vector<int> v(n);
	    for(int i=0;i<n;i++)
	    cin>>v[i];
	    frequencySort(v);
	   // reverse(v.begin(),v.end());
	    for(auto i: v){
	        cout<<i<<" ";
	    }
	    cout<<endl;
	   // unordered_map<int,int> mp;
	   // for(auto i:v){
	   //     mp[i]++;
	   // }
	   // priority_queue<pi,vector<pi>,compare> pq;
	    
	   // for(auto i:mp){
	   //     pq.push({i.second,i.first});
	   // }
	   // while(pq.size()>0){
	   //  int ele = pq.top().second;
	   //  int freq = pq.top().first;
	   //  for(int i=0;i<freq;i++){
	   //      cout<<ele<<" ";
	   //  }
	   //  pq.pop();
	   // }
	   // cout<<endl;
	}
	return 0;
}