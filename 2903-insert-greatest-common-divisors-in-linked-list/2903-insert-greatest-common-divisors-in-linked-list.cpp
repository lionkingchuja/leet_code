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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL) return NULL;
        vector<int>v,ans;
        ListNode* curr=head;
        while(curr !=NULL){
            v.push_back(curr->val);
            curr=curr->next;
        }

        for(int i=0;i<v.size()-1;i++){
            ans.push_back(v[i]);
            ans.push_back(__gcd(v[i],v[i+1]));
        }
        ans.push_back(v[v.size()-1]);

        ListNode* mundi=new ListNode(ans[0]);
        curr=mundi;

        for(int i=1;i<ans.size();i++){
            curr->next=new ListNode(ans[i]);
            curr=curr->next;
        }

        return mundi;
    }
};