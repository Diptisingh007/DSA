class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end(), [](vector<int> &a, vector<int> &b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
        });
        int maxi=0;
        int cnt=0;
        for(auto &it: nums){
            int end=it[1];
            if(end>maxi) maxi=end;
            else cnt++;
        }
        return n-cnt;
    }
};