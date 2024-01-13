Brute Force Approach

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;
        while(temp){
            count++;
            temp = temp -> next;
        }

        if(count == n){
            ListNode* nextHead = head -> next;
            delete(head);
            return nextHead;
        }

        int res = count - n;
        temp = head;
        while(temp){
            res--;
            if(res == 0){
                break;
            }
            temp = temp -> next;
        }

        ListNode* del = temp -> next;
        temp -> next = temp -> next -> next;
        delete(del);
        return head;
    }
};


Optimal Approach


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(n--){
            fast = fast -> next;

        }
        if(fast == NULL){
            return head -> next;
        }

        while(fast -> next){
            fast = fast -> next;
            slow = slow -> next;
        }
        ListNode* del = slow -> next;
        slow -> next = slow -> next -> next;
        delete(del);
        return head;
    }
};
