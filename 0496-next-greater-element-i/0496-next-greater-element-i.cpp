class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& arr, vector<int>& nums) {
        int n=nums.size();
        int m=arr.size();
        vector<int> ans(m);
        stack<int> st;
        unordered_map<int,int> mpp;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top() <= nums[i]){
               st.pop();
            }
             
            if(st.empty()) mpp[nums[i]]=-1;
            else mpp[nums[i]]=st.top();

            st.push(nums[i]);
        }

        for(int i=0;i<m;i++){
            ans[i]=mpp[arr[i]];
        }

        return ans;
    }
};