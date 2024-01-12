Brute Force Approach


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return head;
        }

        stack<int> st;
        ListNode* temp = head;
        while(temp){
            st.push(temp -> val);
            temp = temp -> next;
        }
        temp = head;
        while(temp){
            temp -> val = st.top();
            st.pop();
            temp = temp -> next;
        }
        return head;
    }
};



Optimal Approach 1


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return head;
        }

        ListNode* current = head; 
        ListNode* previous = NULL; 
        ListNode* forward = NULL;

        while(current){
            forward = current -> next;
            current -> next = previous;
            previous = current;
            current = forward;
        } 
        return previous;
    }
};


Optimal Approach 2


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }

        ListNode* reverseHead = reverseList(head -> next);
        ListNode* front = head -> next;
        front -> next = head;
        head -> next = NULL;
        return reverseHead;
    }
};
