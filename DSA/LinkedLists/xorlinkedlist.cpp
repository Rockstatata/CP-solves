
#include <iostream>

struct Node {
	int data;
	// XOR of next and prev
	Node* both;
};

class XORLinkedList {
private:
	Node* head;
	Node* tail;
	// XOR function for Node pointers
	Node* XOR(Node* a, Node* b);

public:
	// Constructor to initialize an empty
	// list
	XORLinkedList();

	// Insert a node at the head of the list
	void insert_at_head(int data);

	// Insert a node at the tail of the list
	void insert_at_tail(int data);

	// Delete a node from the head
	// of the list
	void delete_from_head();

	// Delete a node from the tail
	// of the list
	void delete_from_tail();

	//Delete a particular number
	void deleteoccurence(int data);

	// Print the elements of the list
	void print_list();
};

XORLinkedList::XORLinkedList()
{
	head = tail = nullptr; // Initialize head and tail to
						// nullptr for an empty list
}

Node* XORLinkedList::XOR(Node* a, Node* b)
{
	return (Node*)((long long)(a) ^ (long long)(b));
    		// XOR operation for Node pointers
}

void XORLinkedList::insert_at_head(int data)
{
	Node* new_node = new Node();
	new_node->data = data;
	new_node->both = XOR(nullptr, head);

	if (head) {
		head->both = XOR(new_node, XOR(head->both, nullptr));
	}
	else {
		// If the list was empty, the new
		// node is both the head and the
		// tail
		tail = new_node;
	}
	// Update the head to the new node
	head = new_node;
}

void XORLinkedList::insert_at_tail(int data)
{
	Node* new_node = new Node();
	new_node->data = data;
	new_node->both = XOR(tail, nullptr);

	if (tail) {
		tail->both = XOR(XOR(tail->both, nullptr), new_node);
	}
	else {
		// If the list was empty, the new
		// node is both the head and the
		// tail
		head = new_node;
	}
	// Update the tail to the new node
	tail = new_node;
}

void XORLinkedList::delete_from_head()
{
	if (head) {
		Node* temp = head;
		Node* next = XOR(head->both, nullptr);
		head = next;

		if (next) {
			next->both = XOR(next->both, temp);
		}
		else {
			// If the list becomes empty,
			// update the tail to nullptr
			tail = nullptr;
		}
		delete temp;
	}
}

void XORLinkedList::delete_from_tail()
{
	if (tail) {
		Node* temp = tail;
		Node* prev = XOR(tail->both, nullptr);
		tail = prev;

		if (prev) {
			prev->both = XOR(prev->both, temp);
		}
		else {
			// If the list becomes empty, update the head to
			// nullptr
			head = nullptr;
		}
		delete temp;
	}
}

void XORLinkedList::deleteoccurence(int data){
	Node* cur = head;
	Node* prev = nullptr,*next = nullptr;
	while(cur){
		if(cur->data == data){
			if(cur==tail){
				delete_from_tail();
				return;
			}
			else if(cur==head){
				delete_from_head();
				return;
			}
			Node* temp = cur;
			next = XOR(prev,cur->both);
			prev->both = XOR(cur,prev->both);
			prev->both = XOR(prev->both,next);
			next->both = XOR(next->both,cur);
			next->both = XOR(next->both,prev);
			cur = next;
			delete temp;
		}
		else{
			next = XOR(prev,cur->both);
			prev = cur;
			cur=next;
		}
	}
}

void XORLinkedList::print_list()
{
	Node* current = head;
	Node* prev = nullptr;
	while (current) {
		std::cout << current->data << " ";
		Node* next = XOR(prev, current->both);
		prev = current;
		current = next;
	}
	std::cout << std::endl;
}

int main()
{
	XORLinkedList list;
	list.insert_at_head(40);
	list.insert_at_tail(40);
	list.insert_at_head(10);
	list.insert_at_head(20);
	list.insert_at_tail(40);
	list.insert_at_tail(30);
	list.insert_at_tail(40);
	list.insert_at_tail(40);
	// prints 20 10 30 40
	list.print_list();
	list.deleteoccurence(40);
	list.print_list();
	//list.delete_from_head();
	// prints 10 30 40
	//list.print_list();
	//list.delete_from_tail();
	// prints 10 30
	//list.print_list();
	return 0;
}
