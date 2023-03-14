class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1=="0")return num2;
        if(num2=="0")return num1;
        int i = num1.size(),j=num2.size();
        int n = i>j?i+1:j+1;
        vector<int>num(n,0);
        i--;j--;
        int s = 0;
        int c = 0;
        int k = n-1;
        while(i>=0 && j>=0){
            s = (num1[i--]-'0')+(num2[j--]-'0')+c;
            num[k--]=s%10;
            c=s/10;
            s=0;
        }
        while(i>=0){
            s=(num1[i--]-'0')+c;
            num[k--]=s%10;
            c=s/10;
        }
        while(j>=0){
            s=(num2[j--]-'0')+c;
            num[k--]=s%10;
            c=s/10;
        }
        if(c>0)
            num[k]=c;
        string ans = "";
        while(num[k]==0 && k<n)k++;
        while(k<n){
            ans+=(num[k++]+'0');
        }
        return ans;
    }
};