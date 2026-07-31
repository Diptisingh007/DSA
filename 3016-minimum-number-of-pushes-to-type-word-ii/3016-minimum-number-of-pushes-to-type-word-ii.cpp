class Solution {
public:
    int minimumPushes(string word) {
        int n= word.size();
        unordered_map<char, int> mpp;
        for(auto &c: word){
            mpp[c]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto &it: mpp){
            pq.push({it.second,it.first});
        }
        int cnt=0;
        int mul=1;
        int cost=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            char c=it.second;
            int freq=it.first;
            cost=cost+(mul*freq);
            cnt++;
            if(cnt==8){
                cnt=0;
                mul++;
            }
        }

        return cost;
    }
};