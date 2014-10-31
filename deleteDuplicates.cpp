#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
	 };

ListNode *deleteDuplicates(ListNode *head) {
	struct ListNode * current = head;
	struct ListNode * temp;

	if (current == NULL) return head;
	if (current -> next == NULL) return head;
	temp = current->next;

	while(temp->next != NULL)
	{
		if (temp->val == current->val)
		{
		//	struct ListNode *t = temp;
			current->next = temp->next;
			temp = current -> next;
		//	delete t;
//			cout << "duplicate"<<endl;
//			delete temp;  // c++ won't need this?!?!
//			cout << "deleted" <<endl;
		}
		else
		{
			current = current->next;
			temp = current->next;
		}
	
	}        
	
	if (temp->val == current->val)
		{//	struct ListNode *t = temp;
			current -> next = temp->next;
		//	delete t;
		}
	
	return head;
}

int printlist(struct ListNode *head){
	struct ListNode *cur = head;
	while(cur != NULL){
		cout << cur->val<<endl;
		cur = cur->next;		
	}
	cout<<"\n"<<endl;
	return 0;
}

int main(){
	//test regular case
	struct ListNode node1(1);
	struct ListNode node2(1);
	struct ListNode node3(2);
	struct ListNode node4(3);
	struct ListNode node5(3);

	node1.next = & node2;
	node2.next = & node3;
	node3.next = & node4;
	node4.next = & node5;

	printlist(& node1);
//	deleteDuplicates(& node1);
//	printlist(& node1);	  
	printlist(deleteDuplicates(& node1));	

	//test NULL
	printlist(deleteDuplicates(NULL));
	
	//test only one node case
	printlist(deleteDuplicates(& node5));
}
