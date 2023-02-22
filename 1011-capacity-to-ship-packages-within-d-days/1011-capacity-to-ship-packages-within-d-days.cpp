class Solution {
public:
    pair<bool,int> isval(int lmt,vector<int>& arr, int x,int t){
        int i=0,j=arr.size()-1;
        int sum=0;
        int d = 0;
        int maxi = INT_MIN;
        while(i<=j){
            // cout<<i<<"~"<<j<<endl;
            if(arr[i]>lmt){
                return {false,-1};
            }
            while(i<=j && sum+arr[i]<=lmt){
                if(arr[i]>lmt){
                    return {false,-1};
                }
                sum+=arr[i++];
            }
            maxi = max(maxi,sum);
            // cout<<maxi<<endl;
            sum=0;
            d++;
        }
        if(d<=x)
            return {true,maxi};
        return {false,-1};
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int total = 0;
        for(auto i:weights){
            total+=i;
        }
        if(days==1)
            return total;
        int l = 1;
        int r = total;
        int mid;
        int ans = -1;
        while(l<r){
            // cout<<l<<"#"<<l + (r-l)/2<<"#"<<r<<endl;
            mid = l + (r-l)/2;
            pair<bool,int> val = isval(mid,weights,days,total);
            if(val.first){
                ans = mid;
                // cout<<l<<"^"<<mid<<"^"<<r<<endl;
                r = mid;
            }
            else{
                // cout<<l<<"*"<<mid<<"*"<<r<<endl;
                l= mid+1;
            }
        }
        return ans;
    }
};