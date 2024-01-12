Brute Force Approach

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int n = 0;
        while(temp){
            n++;
            temp = temp -> next;
        }

        temp = head;
        for(int i = 0; i < (n/2); i++){
            temp = temp -> next;
        }
        return temp;
    }
};


Optimal Approach

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
};
