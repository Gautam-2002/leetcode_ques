class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="")return 0;
        unordered_map<char,int> mp;
        int count=0,maxcount=INT_MIN;
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]>0){
                i=mp[s[i]];
                count=0;
                mp.clear();
            }
            
            
            mp[s[i]]=i+1;
            count++;
            maxcount=max(maxcount,count);
        }
        return maxcount;
    }
};
// BETTER approch 
// class Solution {
// public:
// 	int lengthOfLongestSubstring(string s) 
// 	{
// 		unordered_set<char> set;
    
// 		int i = 0, j = 0, n = s.size(), ans = 0;
    
// 		while( i<n && j<n)
// 		{
// 			if(set.find(s[j]) == set.end()) //If the character does not in the set
// 			{
// 				set.insert(s[j++]); //Insert the character in set and update the j counter
// 				ans = max(ans, j-i); //Check if the new distance is longer than the current answer
// 			}
// 			else
// 			{
// 				set.erase(s[i++]); 
// 				/*If character does exist in the set, ie. it is a repeated character, 
// 				we update the left side counter i, and continue with the checking for substring. */
// 			}
// 		}
    
// 		return ans;
// 	}
// };