class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        int a=INT_MIN,b=INT_MIN,c=INT_MIN;
        int p=0,q=0;
        for(int i=0;i<n;i++){
            if(nums[i]>=a){
                c=b;
                b=a;
                a=nums[i];
            }
            else if(nums[i]>=b){
                c=b;
                b=nums[i];
            }
            else if(nums[i]>=c){
                c=nums[i];
            }

            if(p>=nums[i]){
                q=p;
                p=nums[i];
            }
            else if(q>=nums[i]){
                q=nums[i];
            }
        }

        int ans1=a*b*c;
        int ans2=p*q*a;
        return max(ans1,ans2);
    }
};