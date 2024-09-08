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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int cnt=0;
        ListNode* curr=head;
        while(curr !=NULL){
            cnt++;
            curr=curr->next;
        }
        int a=cnt / k;
        int b=cnt % k;
        vector<ListNode*>ans;
        curr=head;
        while(curr!=NULL){
            ListNode* temp=curr;
            int len=a;
            if(b>0){
                len +=1;
                b--;
            }
            len--;
            while(len--){
                curr=curr->next;
            }
            ListNode* nextpart=NULL;
            nextpart=curr->next;
            curr->next=NULL;

            ans.push_back(temp);
            curr=nextpart;
        }
        while(ans.size() < k){
            ans.push_back(NULL);
        }
        return ans;
    }
};