class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int cnt = 0;
        int x = 1;
        int idx = 0;
        int q = 1;
        while(x<=arr[arr.size()-1]+k){
            int i ;
            if(idx==arr.size()){
                cnt++;
                i = arr[arr.size()-1]+q;
                q++;
            }
            else
                i = arr[idx++];
            while(x<i){
                cnt++;
                cout<<x<<"*"<<cnt<<"^";
                if(cnt==k){
                    return x;
                }
                x++;
            }
            if(cnt==k){
                return x;
            }
            x++;            
        }
        return x;
    }
};