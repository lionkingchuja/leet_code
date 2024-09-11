class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = 0;

        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }

        int cnt2 = cnt / k;
        temp = head;
        vector<ListNode*> v;

        while (cnt2--) {
            int len = k;
            ListNode* prev = NULL;
            ListNode* curr = temp;
            ListNode* nxt = NULL;

            while (len-- && curr != NULL){
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }

            v.push_back(prev);

            temp = curr;  
        }
        while(temp!=NULL){
            v.push_back(temp);
            break;
        }
        ListNode* node=new ListNode(NULL);
        temp=node;
        cout<<v.size()<<endl;
        for(int i=0;i<v.size();i++){
            ListNode* it=v[i];
            while(it !=NULL){
                temp->next=it;
                temp=temp->next;
                it=it->next;
            }
        }
        return node->next;  
    }
};
