Brute force Approach



class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node* , Node*> hash;
        Node* temp = head;
        while(temp){
            Node* copy = new Node(temp -> val);
            hash[temp] = copy;
            temp = temp -> next;
        }

        Node* it = head;
        while(it){
            Node* node = hash[it];
            node -> next = (it -> next) ? hash[it -> next] : NULL;
            node -> random = (it -> random) ? hash[it -> random] : NULL;
            it = it -> next;
        }
        return hash[head];
    }
};

Optimal Approach

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Step 1
        Node* temp = head;
        while(temp){
            Node* copy = new Node(temp -> val);{
                copy -> next = temp -> next;
                temp -> next = copy;
                temp = temp -> next -> next;
            }
        }

        // Step 2
        Node* it = head;
        while(it){
            if(it->random)
            it -> next -> random = it -> random -> next;
            it = it -> next -> next;
        }

        // Step 3
        Node* dummy = new Node(0);
        Node* a = dummy;
        Node* itr = head;
        Node* fast;
        while(itr){
            fast = itr -> next -> next;
            a -> next = itr -> next;
            itr -> next = fast;
            a = a -> next;
            itr = fast;
        }
        return dummy -> next;
    }
};
