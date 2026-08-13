class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m=tasks.size();
        unordered_map<char,int> mpp;
        int maxi=0;
        for(auto &it: tasks){
            mpp[it]++;
            maxi=max(maxi,mpp[it]);
        }

        int cnt=0;
        for(auto &it: mpp){
            if(it.second==maxi){
                cnt++;
            }
        }
        int ans=max(m,(maxi-1)*(n+1)+ cnt);
        return ans;


    }
};