class Solution {
public:
    int compareVersion(string v1, string v2) {
        // cout<<"ENTER : "<<v1<<" "<<v2<<endl;
        int a = stoi(v1), b = stoi(v2);
        if(a<b)return -1;
        else if(a>b) return 1;
        else{
            int i = 0,j=0;
            while(i<v1.size() && v1[i]!='.')i++;
            while(j<v2.size() && v2[j]!='.')j++;
            if(i==v1.size() && j < v2.size()){
                while(j < v2.size() ){
                    if(v2[j] != '0' && v2[j]!='.')return -1;
                    j++;
                }
                return 0;
            }
            else if(i < v1.size() && j == v2.size()){
                while(i < v1.size()){
                    if(v1[i] != '0' && v1[i]!='.')return 1;
                    i++;
                }
                return 0;
            }
            else if(i == v1.size() && j == v2.size()){
                return 0;
            }
            else{
                i++;j++;
                // cout<<i<<"*"<<j<<endl;
                string s1 = v1.substr(i,v1.size()-i);
                string s2 = v2.substr(j,v2.size()-j);
                return compareVersion(s1,s2);
            }
        }
    }
};
// class Solution {
// public:
//     static int compareVersion(string& v1, string& v2) {
//         const int n1=v1.size(), n2=v2.size();
//         int x1=0, x2=0;
//         for(int i=0, j=0; i<n1 || j<n2; i++, j++){
//             while(i<n1 && v1[i]!='.'){
//                 x1=10*x1+(v1[i++]-'0');
//             }
//             while(j<n2 && v2[j]!='.'){
//                 x2=10*x2+(v2[j++]-'0');
//             }
//             if (x1<x2) return -1;
//             else if (x1>x2) return 1;
//             x1=0;
//             x2=0;
//         }
//         return 0;
//     }
// };
