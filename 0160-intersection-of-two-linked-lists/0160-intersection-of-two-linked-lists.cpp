/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<ListNode*>v;
        ListNode* curr=headA;

        while(curr !=NULL){
            v.push_back(curr);
            curr=curr->next;
        }
        curr=headB;
        while(curr !=NULL){
            for(int i=0;i<v.size();i++){
                if(curr==v[i]) return curr;
            }
            curr=curr->next;
        }
        return NULL;
    }
};