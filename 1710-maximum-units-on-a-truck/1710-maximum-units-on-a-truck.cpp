class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){
        return a[1]<b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int ans = 0;
        int box = 0;
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        for(int i = boxTypes.size()-1;i>=0;i--){
            if(box==truckSize)break;
            while(box<truckSize && boxTypes[i][0]--){
                ans += boxTypes[i][1];
                box++;
            }
        }
        return ans;
    }
};