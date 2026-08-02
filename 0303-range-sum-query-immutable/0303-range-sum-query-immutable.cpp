class NumArray {
    vector<int> pre;
public:
    NumArray(vector<int>& nums) {
        pre=nums;
        int n=nums.size();
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+pre[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0) return pre[right];
        int ans=pre[right]-pre[left-1];
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */