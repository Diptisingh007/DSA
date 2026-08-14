// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int n=nums.size();
//         sort(nums.begin(),nums.end());
//         for(int i=1;i<n;i++){
//             if(nums[i]==nums[i-1]){
//                 return nums[i];
//             }
//         }return 0;
        
//     }
// };



class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];

            if (slow == fast) {
                break;
            }
        }

        int slow2 = nums[0];

        while (slow != slow2) {
            slow = nums[slow];
            slow2 = nums[slow2];
        }

        return slow;        
    }
};