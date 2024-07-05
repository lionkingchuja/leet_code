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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next ==NULL) return vector<int>{-1,-1};
        ListNode* curr_prev=head;
        ListNode* curr=head->next;
        ListNode* curr_next=head->next->next;
        vector<int>v;
        int cnt=2;
        while(curr_next !=NULL){
            if(curr_prev->val < curr->val and curr->val > curr_next->val){
                v.push_back(cnt);
            }
            else if(curr_prev->val >curr->val and curr->val < curr_next->val){
                v.push_back(cnt);
            }
            cnt++;
            curr_prev=curr;
            curr=curr_next;
            curr_next=curr_next->next;
        }
        if(v.size() <=1) return vector<int>{-1,-1};
        sort(v.begin(),v.end());
        int min_diff=INT_MAX;
        for(int i=0;i<v.size()-1;i++){
            min_diff=min(min_diff,v[i+1]-v[i]);
        }
        return vector<int>{min_diff,v[v.size()-1]-v[0]};
    }
};