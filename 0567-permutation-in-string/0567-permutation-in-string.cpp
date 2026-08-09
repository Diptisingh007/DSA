class Solution {
public:
    bool all_zero(vector<int> &nums){
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=0) return false;
        }

        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<int> freq(26,0);

        for(auto &it: s1){
            freq[it-'a']++;
        }

        int i=0,j=0;
        while(j<m){
            freq[s2[j]-'a']--;

            if(j-i+1==n){
                if(all_zero(freq)){
                    return true;
                }

                freq[s2[i]-'a']++;
                i++;
            }
            j++;
        }

        return false;
    }
};