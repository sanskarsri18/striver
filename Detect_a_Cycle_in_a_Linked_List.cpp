Brute Force Approach

class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode* , bool> mp;
        ListNode* temp = head;
        while(temp){
            if(mp[temp] == true){
                return true;
            }
            mp[temp] = true;
            temp = temp -> next;
        }
        return false;
    }
};


Optimal Approach

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL){
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};
