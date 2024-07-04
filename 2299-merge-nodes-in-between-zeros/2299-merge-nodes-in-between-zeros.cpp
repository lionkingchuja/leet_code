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
    ListNode* mergeNodes(ListNode* head) {
        vector<int>v;
        int temp=0;
        ListNode* curr=head;
        while(curr !=NULL){
            if(curr->val==0){
                v.push_back(temp);
                temp=0;
            }
            else temp +=curr->val;
            curr=curr->next;
        }
        ListNode* new_head=new ListNode(v[1]);
        curr=new_head;
        for(int i=2;i<v.size();i++){
            curr->next=new ListNode(v[i]);
            curr=curr->next;
        }
        return new_head;
    }
};