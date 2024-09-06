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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        map<int,bool>m;
        for(auto i:nums) m[i]=true;

        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr!=NULL){
            if(m.find(curr->val) != m.end() and head!=curr){
                prev->next=curr->next;
                curr=curr->next;
            }
            else {
                prev=curr;
                curr=curr->next;
            }
        }
        if(m.find(head->val)!=m.end()) return head->next;
        else return head;
    }
};