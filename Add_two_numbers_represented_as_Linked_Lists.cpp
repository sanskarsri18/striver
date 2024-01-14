class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* curr = dummyNode;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int carry = 0;
        while(t1 || t2){
            int sum = 0;
            if(t1){
                sum += (t1 -> val);
            }
            if(t2){
                sum += (t2 -> val);
            }
            sum += carry;
            ListNode* newNode = new ListNode(sum%10);
            curr -> next = newNode;
            curr = curr -> next;
            carry = sum / 10;

            if(t1){
                t1 = t1 -> next;
            }
            if(t2){
                t2 = t2 -> next;
            }
        }

        if(carry){
            ListNode* newNode = new ListNode(carry);
            curr -> next = newNode;
        }
        return dummyNode -> next;
    }
};
