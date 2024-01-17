Brute Force Approach

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode* , bool> mp;
        ListNode* temp = head;
        while(temp){
            if(mp[temp ] == true){
                return temp;
            }
            mp[temp] = true;
            temp = temp -> next;
        }
        return NULL;
    }
};


Optimal Approach

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL){
            return NULL;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast -> next && fast -> next -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(fast == slow){
                fast = head;
                while(fast != slow){
                    fast = fast -> next;
                    slow = slow -> next;
                    
                }
                return slow;
            }
        }
        return NULL;
    }
};
