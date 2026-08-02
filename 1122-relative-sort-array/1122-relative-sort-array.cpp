class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        map<int,int> mpp;
        for(auto &it: arr1){
            mpp[it]++;
        }

        vector<int> ans;
        int m=arr2.size();
        for(int i=0;i<m;i++){
            int ele=arr2[i];
            int freq=mpp[ele];
            while(freq){
                ans.push_back(ele);
                freq--;
            }
            mpp.erase(ele);
        }
        while(!mpp.empty()){
            int ele=mpp.begin()->first;
            int freq=mpp.begin()->second;
            while(freq){
                ans.push_back(ele);
                freq--;
            }
            mpp.erase(ele);
        }

        return ans;
    }
};