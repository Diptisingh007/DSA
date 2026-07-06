/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    typedef pair<int,ListNode*> node;
    ListNode* mergeKLists(vector<ListNode*>& nums) {
        int n=nums.size();
        priority_queue<node,vector<node>,greater<node>> pq;
        for(int i=0;i<n;i++){
            if(nums[i]){
                pq.push({nums[i]->val,nums[i]});
            }
        }

        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;
        while(!pq.empty()){
            auto node=pq.top();
            pq.pop();
            ListNode* newNode=node.second;
            temp->next=newNode;
            if(newNode->next){
                pq.push({newNode->next->val,newNode->next});
            }
            temp=temp->next;
        }

        return ans->next;
    }
};