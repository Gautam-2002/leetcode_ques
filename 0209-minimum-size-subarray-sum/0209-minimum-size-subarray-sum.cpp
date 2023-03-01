class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        int ans = INT_MAX;
        int i = 0;
        int j = 0;
        int t = 0;
        int n = arr.size();
        int k = target;
        bool f = true;
        while(j<n){
          // if(t<k)
               // if(t==k){j++;break;}
               t+=arr[j++];

          // cout<<i<<"*"<<j<<endl;
          // if(t>=k)

          while(t>=k && i<j){
               f = false;
               ans=min(ans,j-i);
               t-=arr[i++];
          }
          // j++;
        }
        if(f)return 0;

        return ans;
    }
};