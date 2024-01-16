Brute Force Approach

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        vector<int> v;
        while(temp){
            v.push_back(temp -> val);
            temp = temp -> next;
        }

        int s = 0;
        int e = v.size() - 1;
        while(s<=e){
            if(v[s] != v[e]){
                return false;
            }
            s++;
            e--;
        }
        return true;
    }
};



Optimal Approach

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

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast -> next && fast -> next -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* reverseHead = reverse(slow -> next);
        ListNode* temp = head;
        while(reverseHead){
            if(temp -> val != reverseHead -> val){
                return false;
            }
            temp = temp -> next;
            reverseHead = reverseHead -> next;
        }
        return true;
    }
};
