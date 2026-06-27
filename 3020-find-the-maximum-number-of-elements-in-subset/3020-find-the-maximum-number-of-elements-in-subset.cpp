class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        map<long long,int> mpp;
        for(auto &it: nums){
            mpp[it]++;
        }

        int ans=0;
        if(mpp.find(1)!=mpp.end()){
            int cnt=mpp[1];
            if(cnt%2==1){
                ans=max(ans,cnt);
            }
            else{
                ans=max(ans,cnt-1);
            }
        }

        for(auto &it: mpp){
            long long num=it.first;
            if(num==1) continue;

            int len=0;
            while(mpp.find(num)!=mpp.end() && mpp[num]>=2){
                len=len+2;
                if(num>1e9) break;
                num=num*num;
            }

            if(mpp.find(num)!=mpp.end()) len++;
            else len--;

            ans=max(ans,len);
        }

        return ans;
    }
};