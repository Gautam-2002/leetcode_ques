class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        long long res = 0;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"){
                long long op1 = st.top();st.pop();
                long long op2 = st.top();st.pop();
                res = op1 + op2;
                // cout<<res<<endl;
                st.push(res);
            }
            else if(tokens[i]=="-"){
                long long op1 = st.top();st.pop();
                long long op2 = st.top();st.pop();
                res = op2 - op1;
                // cout<<res<<endl;
                st.push(res);
            }
            else if(tokens[i]=="*"){
                long long op1 = st.top();st.pop();
                long long op2 = st.top();st.pop();
                res = op1 * op2;
                // cout<<res<<endl;
                st.push(res);
            }
            else if(tokens[i]=="/"){
                long long op1 = st.top();st.pop();
                long long op2 = st.top();st.pop();
                res = op2 / op1;
                // cout<<res<<endl;
                st.push(res);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        
        return (int)st.top();
    }
};