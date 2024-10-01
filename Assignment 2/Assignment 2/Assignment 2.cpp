#include <iostream>
#include <stdexcept>
using namespace std;

template <typename Item_Type>
class Node {
public:
	Item_Type data;
	Node* next;

	Node(const Item_Type& data) : data(data), next(nullptr) {

	}
};
//template for Node, for the next one

template <typename Item_Type>
class Single_Linked_List {
private:
	Node<Item_Type>* head;
	Node<Item_Type>* tail;
	size_t items_num;
	//private stuff of the node in the SLL
public:
	Single_Linked_List() : head(nullptr), tail(nullptr), items_num(0) {


	}
//SLL with no way back and forth, aka a new one
	~Single_Linked_List() {
		while (!empty()) {
			pop_front();
		}
	}
	//pops the front
	void push_front(const Item_Type& item) {
		Node<Item_Type>* new_node = new Node<Item_Type>(item);
		if (empty()) {
			tail = new_node;
		}
		else {
			new_node->next = head;
		}
		head = new_node;
		items_num++;
	}
	//if empty, the tail is the new node else the new node next becomes the head and the head is now the new node

	void push_back(const Item_Type& item) {
		Node<Item_Type>* new_node = new Node<Item_Type>(item);
		if (empty()) {
			head = new_node;
		}
		else {
			tail->next = new_node;
		}
		tail = new_node;
		items_num++;
	}
	//Always check for empty, as this one will make the new node the head. Else, the tail next is now the new node and the tail becomes the new node either way
	Item_Type pop_front() {
		if (empty()) {
			throw out_of_range("Empty list, pop!");
		}
		Item_Type rem_data = head->data;
		Node<Item_Type>* temp = head;
		head = head->next;
		delete temp;
		if (head == nullptr) {
			tail = nullptr;
		}
		items_num--;
		return rem_data;
	}
	//Checks empty and throws error as it's impossible to pop.
	//else it takes temporary data and head, as it adjust the real one before deleting the temporary one. It also checks if head is null so tail can be null too

	Item_Type pop_back() {
		if (empty()) {
			throw out_of_range("Empty list, pop!");
		}
		Item_Type rem_data = tail->data;
		if (head == tail) {		//one item
			delete tail;
			head = nullptr;
			tail = nullptr;
		}
		else {
			Node<Item_Type>* current = head;
			while (current->next != tail) {
				current = current->next;
			}
			delete tail;
			tail = current;
			tail->next = nullptr;
		}
		items_num--;
		return rem_data;
	}
	//Error incase it's empty too
	//takes data before checking if the head==tail, meaning there's 1 element/item left in the SLL. makes the head and tail null as the tail is deleted
	//Else, it changes the current node into the head and does a while command as long as the current next isn't the tail
	//it'll delete the tail and make that current the new tail as the next of it will be null

	Item_Type front()const {
		if (empty()) {
			throw out_of_range("Empty list!");
		}
		return head->data;
	}
	//throws error before returning the front/head of the data

	Item_Type back() const {
		if (empty()) {
			throw out_of_range("Empty list!");
		}
		return tail->data;
	}
	//throws error before retrieving the tail data

	bool empty() const {
		return items_num == 0;
	}

	//just checks if it's empty, returning if the items inside equal to 0 or nothing

	void insert(size_t index, const Item_Type& item) {
		if (index <= 0) {
			push_front(item);
		}
		else if (index >= items_num) {
			push_back(item);
		}
		else {
			Node<Item_Type>* new_node = new Node<Item_Type>(item);
			Node<Item_Type>* current = head;
			for (size_t i = 0; i < index - 1; i++) {
				current = current->next;
			}
			new_node->next = current->next;
			current->next = new_node;
			items_num++;
		}
	}
	//inserts a new item into the given index. It'll shift the necessary items and index of those items if needed 

	bool remove(size_t index) {
		if (index >= items_num) {
			return false;
		}
		if (index == 0) {
			pop_front();
		}
		else if (index == items_num - 1) {
			pop_back();
		}
		else {
			Node<Item_Type>* current = head;
			for (size_t i = 0; i < index - 1; i++) {
				current = current->next;
			}
			Node<Item_Type>* temp = current->next;
			current->next = temp->next;
			delete temp;
			items_num--;
		}
		return true;
	}
	//removes a certain index, rather than data. It'll check first if it's bigger than the SLL before going over front, back and elsewhere before finding and deleting the index.

	size_t find(const Item_Type& item) const {
		Node<Item_Type>* current = head;
		size_t index = 0;
		while (current) {
			if (current->data == item) {
				return index;
			}
			current = current->next;
			index++;
		}
		return items_num;
	}
	//just finds the current index given, scanning until found.
	size_t size() const {
		return items_num;
	}
	//returns size of the SLL
};
int main() {
	Single_Linked_List<int> sll;
	sll.push_back(10);
	sll.push_back(20);
	sll.push_front(5);
	sll.insert(1, 15);

	cout << "A number have been inserted for this test!" << endl;
	cout << "15 has been inserted into index 1, shifting 10 forward" << endl;
	cout << "Front: " << sll.front() << endl;
	cout << "Back: " << sll.back() << endl;  
	cout << "Size: " << sll.size() << endl;   
	cout << "Find 10 at index: " << sll.find(10) << endl;
	sll.remove(1); 
	cout << "Removed 1, size after removal!: " << sll.size() << endl; 

	return 0;
}