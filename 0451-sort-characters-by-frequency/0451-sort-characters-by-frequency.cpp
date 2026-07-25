class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        unordered_map<char,int> mpp;
        for(auto &it: s){
            mpp[it]++;
        }

        priority_queue<pair<int,char>> pq;
        for(auto &it: mpp){
            pq.push({it.second,it.first});
        }

        string ans="";
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            char c=it.second;
            int freq=it.first;
            ans.append(freq,c);
        }

        return ans;
    }
};