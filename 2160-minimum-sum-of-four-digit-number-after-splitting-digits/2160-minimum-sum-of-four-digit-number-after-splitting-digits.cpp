class Solution {
public:
    int minimumSum(int num) {
        vector<int> arr;
        int x = num;
        while(x>0){
            int r = x%10;
            arr.push_back(r);
            x/=10;
        }
        sort(arr.begin(),arr.end());
        int a = (arr[0]*10)+arr[3];
        int b = (arr[1]*10)+arr[2];
        return a+b;
    }
};