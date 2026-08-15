class Solution {
public:
    int evalRPN(vector<string>& nums) {
        int n=nums.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(nums[i]=="+" || nums[i]=="-" || nums[i]=="/" || nums[i]=="*"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int c;
                if(nums[i]=="+") c=b+a;
                else if(nums[i]=="-") c=b-a;
                else if(nums[i]=="/") c=b/a;
                else if(nums[i]=="*") c=b*c;

                st.push(c);
            }
            else{
                int a=stoi(nums[i]);
                st.push(a);
            }
        }

        return st.top();
    }
};