Brute Force Approach

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headA){
            ListNode* temp = headB;
            while(temp){
                if(temp == headA){
                    return temp;
                }
                temp = temp -> next;
            }
            headA = headA -> next;
        }
        return NULL;
    }
};


Better Approach

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp = headA;
        map<ListNode* , bool> mp;
        while(temp){
            mp[temp] = true;
            temp = temp -> next;
        }

        temp = headB;
        while(temp){
            if(mp[temp] == true){
                return temp;
            }
            temp = temp -> next;
        }
        return NULL;
    }
};


Optimal Approach

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      ListNode* d1 = headA;  
      ListNode* d2 = headB;

      while(d1 != d2){
          if(d1 == NULL){
              d1 = headB;
            }
          else{
              d1 = d1 -> next;
            }
          if(d2 == NULL){
              d2 = headA;

          }
          else{
              d2 = d2 -> next;
          }
      }  
      return d1;
    }
};
