#include<iostream>
using namespace std;

struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
//	cout << (*head).val << endl;
	if (head == NULL) { // empty list
		return false;
	}
	
	if (head->next == NULL) { // list with one node
		return false;
	}

	if (head->next == head) {
		return true;
	}

	if (head->next->next == head || head->next->next == head->next) {
		return true;
	} 
	if (head->next->next == NULL) {
		return false;
	}

	ListNode *fast, *slow;
	fast = head->next->next;
	slow = head->next;
	//cout<<fast->val<<"  "<<slow->val<<endl;
	//cout<<fast->next->val<<endl;
	
	//while(!(fast->next->next==NULL || fast->next==NULL)){
	while(fast->next!=NULL && fast->next->next !=NULL){	
		if (fast == slow) return true;
		fast = fast->next->next;
		slow = slow->next;
        }
	return false;       

}

int main(){
	ListNode node1 = ListNode(1);
	ListNode node2 = ListNode(2);
	ListNode node3 = ListNode(3);
	ListNode node4 = ListNode(4);

	// create connection	
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node2;

	
	bool b = hasCycle(&node1);
	if (b==false) 
		cout<<"no cycle"<<endl;
	else
		cout<<"has cycle"<<endl;

	ListNode *node5 = NULL;
	cout << hasCycle(node5) << endl; 
/*   	b = hasCycle(node5);
	if (b) {
		cout << b << endl;
	} else {
		cout << b << endl;
	}	
*/
	ListNode node6 = ListNode(6);
	node6.next = &node6;
  	cout << hasCycle(&node6) << endl;


	ListNode node7 = ListNode(7);
	ListNode node8 = ListNode(8);

	node7.next = &node8;
	node8.next = &node8;

	cout<< hasCycle(&node7)<<endl;



	return 0;
}


