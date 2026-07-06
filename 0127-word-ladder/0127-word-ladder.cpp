class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            string s=it.first;
            int a=it.second;
            if(s==endWord) return a;
            for(int i=0;i<s.size();i++){
                char o=s[i];
                for(char c='a';c<='z';c++){
                    s[i]=c;
                    if(st.find(s)!=st.end()){
                        q.push({s,a+1});
                        st.erase(s);
                    }
                }
                s[i]=o;
            }
        }
        return 0;
    }
};