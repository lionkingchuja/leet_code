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
    bool isPalindrome(ListNode* head) {
        stack<ListNode*>st;
        ListNode* curr=head;
        while(curr !=NULL){
            st.push(curr);
            curr=curr->next;
        }
        curr=head;
        while(curr !=NULL){
            if(curr->val==st.top()->val) st.pop();
            curr=curr->next;
        }
        if(st.empty()) return true;
        return false;

    }
};