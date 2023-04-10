class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i=0;
        while(i<s.size()){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                st.push(s[i]);
            }
            else if((s[i]==')'||s[i]==']'||s[i]=='}')&&st.empty()){
                return false;
            }

            else if(s[i]==')'&&st.top()!='('||s[i]==']'&&st.top()!='['||s[i]=='}'&&st.top()!='{'){
                return false;
            }
            else if(s[i]==')'&&st.top()=='('||s[i]==']'&&st.top()=='['||s[i]=='}'&&st.top()=='{'){
                st.pop();
            }
            i++;
        }
        if(!st.empty())return false;
        return true;
    }
};