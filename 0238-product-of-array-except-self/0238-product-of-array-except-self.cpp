class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int x = 0;
        long long temp = 1;
        int n = arr.size();
        long long w = 1;
        for(int i =0;i<n;i++){
            if(arr[i]==0){
                x++;
            }
            if(x<2 && arr[i]!=0){
                w*=arr[i];
            }
            temp*=arr[i];
        }
        vector<int>ans(n);
        if(x==1){
            for(int i =0;i<n;i++){
                if(arr[i]!=0){
                    ans[i]=0;
                }
                else{
                    ans[i]=w;
                }
            }
            return ans;
        }
        for(int i =0;i<n;i++){
            if(arr[i]==0)arr[i]=1;
            ans[i] = (temp/arr[i]);
        }
        return ans;        
    }
};