class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n=patterns.size();
        int ans=0;
        for( auto &it: patterns){
            if(word.find(it)!=string::npos)
            ans++;
        }
        return ans;
    }
};