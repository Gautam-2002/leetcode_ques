class Solution {
    public boolean ispos(int[] time, int x,long m){
        long a = 0;
        for(int i:time){
            if(i<=m)
                a+=(m/i);
        }
        if(a<x)return false;
        return true;
    }
    public long minimumTime(int[] time, int totalTrips) {
        if(time.length==1)return (long)time[0]*totalTrips;
        int maxi = -1;
        for(int i:time){
            maxi = Math.max(maxi,i);
        }
        long l = 1;
        long r = (long)maxi*totalTrips;
        long mid;
        long ans = -1;
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
}