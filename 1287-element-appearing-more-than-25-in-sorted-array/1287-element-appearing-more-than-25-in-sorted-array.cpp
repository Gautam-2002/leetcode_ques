class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int x = arr[0];
        int freq = 0;
        for(int i:arr){
            if(i==x)
                freq++;
            else
                x = i,freq = 1;
            if(freq>(n/4))
                return x;
            else
                continue;
        }
        return -1;
    }
};