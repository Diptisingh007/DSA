class Solution {
public:
    // int leastInterval(vector<char>& tasks, int n) {
    //     int m=tasks.size();
    //     unordered_map<char,int> mpp;
    //     for(auto &it: tasks){
    //         mpp[it]++;
    //     }

    //     priority_queue<int> pq;
    //     for(auto &it: mpp) pq.push(it.second);
        
    //     int ans=0;
    //     while(!pq.empty()){
    //         vector<int> temp;
    //         for(int i=0;i<n+1;i++){
    //             if(!pq.empty()){
    //                 int freq=pq.top();
    //                 pq.pop();
    //                 freq--;
    //                 temp.push_back(freq);
    //             }
    //         }

    //         for(auto &it: temp){
    //             if(it>0) pq.push(it);
    //         }

    //         if(!pq.empty()){
    //             ans+=(n+1);
    //         }
    //         else{
    //             ans+=temp.size();
    //         }
    //     }
    //     return ans;
    // }



    int leastInterval(vector<char>& tasks, int n) {
        int m=tasks.size();
        vector<int> freq(26,0);
        int maxi=0;
        for(int i=0;i<m;i++){
            freq[tasks[i]-'A']++;
            maxi=max(maxi,freq[tasks[i]-'A']);
        }
         
        int temp=0;
        for(auto &it:freq){
            if(it==maxi) temp++;
        } 

        int ans=max(m,(maxi-1)*(n+1)+temp);
        
        return ans;
    }
};