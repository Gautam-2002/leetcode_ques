class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        if(digits[n-1]==9){
            int i=n-1;
            while(digits[i]==9 && i>0){
            digits[i]=0;
            i--;
            }
            if(digits[i]==9){
            digits.push_back(0);
            digits[i]=1;
            }
            else{
            digits[i]++;    
            }
        }
        else{
            digits[n-1]++;
        }
        return digits;
    }
};