class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int> ans(n,0);
        if(k==0) return ans;

        if(k>0){
            for(int i=0;i<n;i++){
                int sum=0;
                int j=i+1;
                for(int p=0;p<k;p++){
                    sum=sum+code[j%n];
                    j++;
                }
                ans[i]=sum;
            }
        }
        else{
            for(int i=0;i<n;i++){
                int sum=0;
                int j=i-1;
                for(int p=k;p<0;p++){
                    sum=sum+code[(j+n)%n];
                    j--;
                }
                ans[i]=sum;
            }
        }

        return ans;
    }
};