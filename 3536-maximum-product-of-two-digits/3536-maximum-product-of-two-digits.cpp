class Solution {
public:
    int maxProduct(int n) {
        vector<int> arr;
        while(n){
            int digit=n%10;
            arr.push_back(digit);
            n=n/10;
        }
        sort(arr.begin(),arr.end());
        int m=arr.size();
        int ans=arr[m-1]*arr[m-2];

        return ans;
    }
};