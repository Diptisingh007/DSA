class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        if(n==1) return 1;
        int odd_sum=n*n;
        int even_sum=n*(n+1);
        return even_sum % odd_sum;
    }
};