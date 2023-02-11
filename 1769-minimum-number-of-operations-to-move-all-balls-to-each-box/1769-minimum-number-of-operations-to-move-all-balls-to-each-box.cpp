class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n);
        for(int i = 0;i < n;i++){
            int l = 0;
            int r = n-1;
            int x = 0;
            while(l < i){
                if(boxes[l]=='1')
                    x+=(i-l);
                l++;
            }
            int y = 0;
            while(r > i){
                if(boxes[r]=='1')
                    y+=(r-i);
                r--;
            }
            ans[i] = (x+y);
        }
        return ans;
    }
};