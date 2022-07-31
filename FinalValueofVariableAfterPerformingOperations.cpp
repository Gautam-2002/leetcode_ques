class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans=0;
        int len=operations.size();
        for(int i=0;i<len;i++){
            if(operations[i]=="--X" || operations[i]=="X--")
                ans--;
            else
                ans++;
        }
        return ans;
    }
};