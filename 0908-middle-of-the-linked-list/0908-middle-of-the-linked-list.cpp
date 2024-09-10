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
    ListNode* middleNode(ListNode* head) {
        ListNode* curr=head;
        ListNode* curr1=head;

        while(curr1->next !=NULL and curr1->next->next !=NULL){
            curr=curr->next;
            curr1=curr1->next->next;
        }
        if(curr1->next==NULL) return curr;
        else return curr->next;
    }
};