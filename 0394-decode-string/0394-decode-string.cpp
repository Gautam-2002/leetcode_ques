class Solution {
public:
    bool isnum(char x){
        if(x-'0'>=0 && x-'0'<=9){
            return true;
        }
        return false;
    }

    string decodeString(string s) {
        string ans = "";
        string curr = "";
        string num = "";
        stack<string> st;
        for(auto c:s){
            if(c=='['){
                st.push(ans);
                st.push(num);
                num="";
                ans="";
            }
            else if(c==']'){
                int x = stoi(st.top());
                st.pop();
                string prev = st.top();
                st.pop();
                curr = ans;
                ans = prev;
                while(x--)
                    ans+=curr;
            }
            else if(isnum(c)){
                num+=c;
            }
            else{
                ans+=c;
            }
        }
        return ans;
    }
};