class Solution {
public:

    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward = NULL;

        while(curr){
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    ListNode* findnode(ListNode* temp , int k){
        k--;
        while(temp != NULL && k > 0){
            k--;
            temp = temp -> next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* nextnode = NULL;
        ListNode* prevnode = NULL;

        while(temp != NULL){
            ListNode* knode = findnode(temp , k);
            if(knode == NULL){
                if(prevnode){

                prevnode -> next = temp;
                }
                break;
            }
            nextnode = knode -> next;
            knode -> next = NULL;
            reverse(temp);
            if(temp == head){
                head = knode;
            }
            else{
                prevnode -> next = knode;
            }
            prevnode = temp;
            temp = nextnode;
        }
        return head;
    }
};
