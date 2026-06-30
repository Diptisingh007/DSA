class Solution {
public:
    int LH(vector<int> &nums){
        int n=nums.size();
        int ans=0;
        int nse=n;
        int pse=-1;
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                int ind=st.top();
                st.pop();

                nse=i;
                pse=st.empty() ? -1: st.top();
                ans=max(ans,(nse-pse-1)*nums[ind]);
            }
            st.push(i);
        }

        while(!st.empty()){
            int ind=st.top();
            st.pop();
            nse=n;
            pse=st.empty() ? -1:st.top();
            ans=max(ans,(nse-pse-1)*nums[ind]);
        }

        return ans;
    }
    int maximalRectangle(vector<vector<char>>& nums) {
        int n=nums.size();
        int m=nums[0].size();
        vector<vector<int>> arr(n,vector<int>(m,0));
        int ans=0;
        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                sum=(nums[i][j]=='0') ? 0 : sum+1;
                arr[i][j]=sum;
            }
        }

        for(int i=0;i<n;i++){
            int res=LH(arr[i]);
            ans=max(ans,res);
        }

        return ans;
    }
};