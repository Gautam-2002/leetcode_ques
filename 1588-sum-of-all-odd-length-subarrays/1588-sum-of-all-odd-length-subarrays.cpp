class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int len = 1;
        int ans = 0;
        while(len <= arr.size()){
            int sum = 0;
            for(int i=0;i<len;i++){
                sum += arr[i];
            }
            ans+=sum;
            int x = 0;
            for(int i=len;i<arr.size();i++){
                sum-=arr[x++];
                sum+=arr[i];
                ans+=sum;
            }
            len+=2;
        }
        return ans;
    }
};