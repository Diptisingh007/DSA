class Solution {
public:
    // int uniqueXorTriplets(vector<int>& nums) {
    //     int n=nums.size();
    //     unordered_set<int> s1;
    //     for(int i=0;i<n;i++){
    //         for(int j=i;j<n;j++){
    //             s1.insert(nums[i]^nums[j]);
    //         }
    //     }

    //     unordered_set<int> s2;
    //     for(auto &it: s1){
    //         for(auto &num: nums){
    //             s2.insert(it^num);
    //         }
    //     }
    //     return s2.size();
    // }



    int uniqueXorTriplets(vector<int>& nums){
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());

        int T=1;
        while(T<=maxi){
          T=T*2;
        }

        vector<bool> s1(T,false);
        vector<bool> s2(T,false);

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                s1[nums[i]^nums[j]]=true;
            }
        }

        for(int i=0;i<T;i++){
            if(s1[i]==true){
                for(auto &it: nums){
                    s2[i^it]=true;
                }
            }
        }

        int ans=0;
        for(int i=0;i<T;i++){
            if(s2[i]) ans++;
        }

        return ans;
    }
};