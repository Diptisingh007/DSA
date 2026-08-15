class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                int a=st.top();
                st.pop();
                int diff=i-a;
                ans[a]=diff;
            }
            st.push(i);
        }

        return ans;
    }
};