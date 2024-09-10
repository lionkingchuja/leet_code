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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr1=head;
        ListNode* curr2=head;
        while(n--){
            curr2=curr2->next;
        }
        if(curr2==NULL) return head->next;
        while(curr2->next !=NULL){
            curr1=curr1->next;
            curr2=curr2->next;
        }
        ListNode* temp=curr1->next;
        curr1->next=temp->next;

        return head;
    }
};