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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1=l1;
        ListNode* curr2=l2;
        ListNode* head=new ListNode(NULL);
        ListNode* curr=head;
        int carry=0;
        while(curr1 !=NULL and curr2 !=NULL){
            curr->next=new ListNode((curr1->val+curr2->val+carry)%10);
            curr=curr->next;
            carry=(curr1->val+curr2->val+carry)/10;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        while(curr1 !=NULL){
            curr->next=new ListNode((curr1->val+carry)%10);
            curr=curr->next;
            carry=(curr1->val+carry)/ 10;
            curr1=curr1->next;
        }
        while(curr2 !=NULL){
            curr->next=new ListNode((curr2->val+carry)%10);
            curr=curr->next;
            carry=(curr2->val+carry)/ 10;
            curr2=curr2->next;
        }
        if(carry>0) curr->next=new ListNode(carry);
        return head->next;
    }
};