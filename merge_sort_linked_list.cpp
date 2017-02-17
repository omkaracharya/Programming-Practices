#include <iostream>
using namespace std;

struct node{
	node *next;
	int val;
	node(int v){
		next = NULL;
		val = v;
	}
};

class List{
	node *head;
public:
	List(){
		head = NULL;
	}
	node* make_list(int[], int);
	void print_list();
	void merge_sort_helper();
	void merge_sort(node**);
	void split(node*, node**, node**);
	node* merge(node*, node*);
};

node* List::make_list(int arr[], int size){
	for(int i = 0; i < size; ++i) {
		node *temp = new node(arr[i]);
		if(i == 0){
			head = temp;
		} else {
			node *p = head;
			while(p->next) {
				p = p->next;
			}
			p->next = temp;
		}
	}
	return head;
}

void List::print_list() {
	node *p = head;
	while(p){
		cout << p->val << "->";
		p = p->next;
	}
	cout << endl;
}

void List::merge_sort_helper(){
	merge_sort(&head);
}

void List::merge_sort(node **head){
	node *temphead = *head;
	if(!temphead || !temphead->next)
		return;
	node *first, *second;
	split(temphead, &first, &second);
	merge_sort(&first);
	merge_sort(&second);
	*head = merge(first, second);
}

void List::split(node *head, node **first, node **second){
	node *slow, *fast;
	if(!head || !head->next){
		*first = head;
		*second = NULL;
		return;
	} else {
		slow = head;
		fast = head->next;
		while(fast){
			fast = fast->next;
			if(fast){
				fast = fast->next;
				slow = slow->next;
			}
		}

		*first = head;
		*second = slow->next;
		slow->next = NULL;
	}
}

node* List::merge(node *first, node *second){
	if(!first)
		return second;
	if(!second)
		return first;

	node *temp;
	if(first->val <= second->val){
		temp = first;
		temp->next = merge(first->next, second);
	} else {
		temp = second;
		temp->next = merge(first, second->next);
	}
	return temp;
}

int main(){
	int arr[] = {10,9,8,7,6,5,4,3,2,1};
	int size = sizeof(arr) / sizeof(arr[0]);
	List l;
	l.make_list(arr, size);
	l.print_list();
	l.merge_sort_helper();
	l.print_list();
	return 0;
}