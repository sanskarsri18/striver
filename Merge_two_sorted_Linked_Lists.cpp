Brute Force Approach

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* dummyhead = dummy;
        ListNode* head1 = list1;
        ListNode* head2 = list2;

        while(head1 != NULL && head2 != NULL){
            if(head1 -> val <= head2 -> val){
                ListNode* d = new ListNode(head1 -> val);
                dummy -> next = d;
                dummy = dummy -> next;
                head1 = head1 -> next;
            }
            else{
                ListNode* d = new ListNode(head2 -> val);
                dummy -> next = d;
                dummy = dummy -> next;
                head2 = head2 -> next;
            }

        }

        while(head1){
            ListNode* d = new ListNode(head1 -> val);
            dummy -> next = d;
            dummy = dummy -> next;
            head1 = head1 -> next;
        }

        while(head2){
            ListNode* d = new ListNode(head2 -> val);
            dummy -> next = d;
            dummy = dummy -> next;
            head2 = head2 -> next;
        }
        return dummyhead -> next;
    }
};



Optimal Approach

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }
        if(list1 -> val > list2 -> val){
            swap(list1 , list2);
        }
        ListNode* returnHead = list1;
        while(list1 && list2){

            ListNode* temp = NULL;
        while(list1 != NULL && list1 -> val <= list2 -> val){
            temp = list1;
            list1 = list1 -> next;
        }
            temp -> next = list2;
        swap(list1, list2);
        }
        return returnHead;
    }
};
