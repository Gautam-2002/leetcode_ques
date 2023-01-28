class Solution {
public:
    int solve(string &str,int n){
        if(n==0)return 0;
        // cout<< str[n-1]<<endl;
        long long digit = str[n-1]-'0';
        // cout<< str[n-1]<<" dig "<<digit<<endl;
        long long t = (solve(str,n-1));
        long long ans = t*10 + digit;
        // cout<<ans<<endl;
        if(ans > INT_MAX){
            return INT_MAX;
            // cout<<ans<<endl;
        }
        
        return ans;
    }
    int myAtoi(string s) {
        if(s=="-2147483647")return -2147483647;
        string a="";
        bool n = false;
        bool f = false;
        for(int i=0;i<s.size();i++){
            if((s[i]>='0' && s[i]<='9') || (((s[i]=='-'||s[i]=='+')&&n==false) && f==false)){
                a+=s[i];
                n=true;
                f=true;
            }
            else if((s[i]=='-'||s[i]=='+')&& f==true && n==false)return 0;
            else if(n==false && s[i] == ' '){
                continue;
            }
            else if(n==true)
                break;
            else
                return 0;
        }
        // cout<<a<<endl;
        if(a.size()==1 && (a[0]=='+'||a[0]=='-'))return 0;
        int ans = 0;
        int n1 = a.size();
        string str = "";
        if(a[0]=='-'){
            for(int i=1;i<n1;i++)
                str+=a[i];
            n1 = str.size();
            ans = solve(str,n1);
            if(ans == INT_MAX)ans = INT_MIN;
            else ans = ans*(-1);
        }
        else if(a[0]=='+'){
            // cout<<a<<" "<<a.size();
            for(int i=1;i<n1;i++)
                str+=a[i];
            n1 = str.size();
            // cout<<str<<endl;
            ans = solve(str,n1);
        }
        else
            ans = solve(a,n1);
        return ans;       
    }
};