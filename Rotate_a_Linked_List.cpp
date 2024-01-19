Solution 1

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        vector<int> v;
        ListNode* temp = head;
        while(temp){
            v.push_back(temp -> val);
            temp = temp -> next;
        }

        int n = v.size();
        vector<int> rotate(n,0);
        for(int i = 0; i < n; i++){
            rotate[(i + k) % n] = v[i];
        }

        ListNode* dummy = new ListNode(0);
        ListNode* t = dummy;
        for(int i = 0; i < n; i++){
            ListNode* node = new ListNode(rotate[i]);
            t -> next = node;
            t = t -> next;
        }
        return dummy -> next;

    }
};


Solution 2

node* rotateRight(node* head,int k) {
    if(head == NULL||head->next == NULL) return head;
    for(int i=0;i<k;i++) {
        node* temp = head;
        while(temp->next->next != NULL) temp = temp->next;
        node* end = temp->next;
        temp->next = NULL;
        end->next = head;
        head = end;
    }
    return head;
}


Solution 3

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL  ){
            return head;
        }
        ListNode* temp = head;
        int length = 1;
        while(temp -> next){
            length++;
            temp = temp -> next;
        }

        temp -> next = head;
        k = k % length;
        int end = length - k;
        while(end--){
            temp = temp -> next;
        }
        head = temp -> next;
        temp -> next = NULL;
        return head;
    }
};
