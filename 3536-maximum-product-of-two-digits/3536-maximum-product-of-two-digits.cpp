class Solution {
public:
    // int maxProduct(int n) {
    //     vector<int> arr;
    //     while(n){
    //         int digit=n%10;
    //         arr.push_back(digit);
    //         n=n/10;
    //     }
    //     sort(arr.begin(),arr.end());
    //     int m=arr.size();
    //     int ans=arr[m-1]*arr[m-2];

    //     return ans;
    // }
    int maxProduct(int n) {
        int a=0;
        int b=0;
        while(n){
            int digit=n%10;
            if(a <= digit){
                b = a;
                a = digit;
            }
            else if(b < digit){
                b = digit;
            }
            n=n/10;
        }
        return a*b;
    }
};