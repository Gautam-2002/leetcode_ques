class Solution {
public:
    int maxSubarraySumCircular(vector<int>& arr) {
    int kmax=INT_MIN,currsum1=0;
    int totalsum=0,maxi=INT_MIN;
    int kmin=INT_MAX,currsum2=0;
    for (int i = 0; i < arr.size(); i++){
        totalsum+=arr[i];

        currsum1+=arr[i];
        if(currsum1<0)currsum1=0;
        kmax=max(kmax,currsum1);

        currsum2+=arr[i];
        if(currsum2>0)currsum2=0;
        kmin=min(kmin,currsum2);

        maxi=max(maxi,arr[i]);
    }
    int ans1=kmax;
    int ans2=totalsum-kmin;
    // cout<<kmin<<endl;
    // cout<<kmax<<endl;
    // cout<<totalsum<<endl;
    // cout<<ans2<<endl;
    if(ans1<=0 && ans2<=0)return maxi;
    else if(ans1 > ans2)return ans1;
    else return ans2;
    }
};