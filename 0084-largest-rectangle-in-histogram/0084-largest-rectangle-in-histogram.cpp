class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        int nse=n;
        int pse=-1;
        int ans=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                int ind=st.top();
                st.pop();

                nse=i;
                if(st.empty()) pse=-1;
                else pse=st.top();
                ans=max(ans,(nse-pse-1)*nums[ind]);
            }     
            st.push(i);      
        }

        while(!st.empty()){
            int ind=st.top();
            st.pop();

            nse=n;
            if(st.empty()) pse=-1;
            else pse=st.top();

            ans=max(ans,(nse-pse-1)*nums[ind]);
        }

        return ans;
    }
};