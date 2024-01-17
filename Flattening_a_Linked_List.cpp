Node* merge(Node* l1 , Node* l2){
	Node* dummy = new Node(0);
	Node* temp = dummy;
	while(l1 && l2){
		if(l1->data <= l2->data){
			temp -> child = l1;
			l1 = l1 -> child;
			temp = temp -> child;
		}
		else{
			temp -> child = l2;
			l2 = l2 -> child;
			temp = temp -> child;
		}
	}


	if(l1){
		temp -> child = l1;
	}
	if(l2){
		temp -> child = l2;
	}
	return dummy -> child;
}

Node* flattenLinkedList(Node* head) 
{
	if(head == NULL || head -> next == NULL){
		return head;
	}

	head -> next = flattenLinkedList(head -> next);
	head = merge(head , head -> next);
	return head;
}
