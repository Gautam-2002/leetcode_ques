class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        
 
        
        for(int i=0;i<indices.size();i++)
        {
            
              while(indices[i]!=i)
              {
                  swap(s[i],s[indices[i]]);
                  swap(indices[i],indices[indices[i]]);
                       
              }
        }
        
       
        return s;
    }
};
// class Solution {
// public:
//     string restoreString(string s, vector<int>& indices) {
//         unordered_map<int,char> mp;
//         for(int i=0;i<indices.size();i++){
//             mp[indices[i]]=s[i];
//         }
//         string ans="";
//         for(int i=0;i<indices.size();i++){
//             ans+=mp[i];
//         }
//         return ans;
//     }
// };