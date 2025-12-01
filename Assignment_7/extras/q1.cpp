class Solution {
  public:
    string countSort(string s) {
        // code here
        vector<int>rec(26);
        for(char c:s) rec[c-'a']++;
        string ans="";
        for(int i=0 ; i<26 ; i++){
            ans.append(rec[i] , i+'a');
        }
        return ans;
    }
};