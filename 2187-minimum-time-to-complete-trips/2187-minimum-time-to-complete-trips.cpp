class Solution {
public:
    bool ispos(vector<int>& time, int x,long long m){
        long long a = 0;
        for(auto i:time){
            if(i<=m)
                a+=(m/i);
        }
        if(a<x)return false;
        return true;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        if(time.size()==1)return 1LL*time[0]*totalTrips;
        int maxi = INT_MIN;
        for(auto i:time){
            maxi = max(maxi,i);
        }
        long long l = 1;
        long long r = 1LL*maxi*totalTrips;
        long long mid;
        long long ans = -1;
        while(l<r){
            mid = l+(r-l)/2;
            if(ispos(time,totalTrips,mid)){
                ans = mid;
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};