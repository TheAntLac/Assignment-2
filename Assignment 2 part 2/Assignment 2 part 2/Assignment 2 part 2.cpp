#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Stack {
private:
	vector<int> elements;	//made vector for elements

public:
	bool isEmpty()const {
		return elements.empty();	//checks if it's empty or not, doesn't display what's in it.
	}

	void push(int val) {
		elements.push_back(val);		//pushes the value into the stack 
	}

	void pop() {
		if (!isEmpty()) {
			elements.pop_back();
			cout << "Element has been popped" << endl;
		}
		else {
			cout << "Empty stack, can't pop!" << endl;		//Pops the back value and display message if it did or couldn't
		}
	}

	int top()const {
		if (!isEmpty()) {
			return elements.back();
		}
		else {
			cout << "Empty stack, can't return top!" << endl;		//returns the top element in the vector, or returns that no element is in the vector
			return -1;
		}
	}

	double avg()const {
		if (isEmpty()) {
			cout << "Empty stack, can't average nothing!" << endl;
			return 0.0;
		}
		return static_cast<double>(accumulate(elements.begin(), elements.end(), 0)) / elements.size();	//returns no average or adds all the elements inside dividedd by the size
	}
};

void Menu() {
	cout << "\nStack Operations Menu:" << endl;
	cout << "1. Check if the stack is empty" << endl;
	cout << "2. Push an integer onto the stack" << endl;
	cout << "3. Pop an integer from the stack" << endl;
	cout << "4. Get the top element of the stack" << endl;
	cout << "5. Calculate the average of the stack elements" << endl;
	cout << "6. Exit" << endl;

}			//a menu to show a quick preview. Must choose a number between 1 to 6

int main() {
	Stack stack;
	int choice, val;

	do {
		Menu();
		cout << "Choose a number or exit" << endl;
		cin >> choice;
		
		switch (choice) {	//takes the choice and goes by the case equalling to it
		case 1:
			cout << (stack.isEmpty() ? "Stack is empty" : "Stack is not empty.") << endl;
			break;
		case 2:
			cout << "Enter an int value to be pushed: ";
			cin >> val;
			stack.push(val);
			cout << val << " pushed into stack" << endl;
			break;
		case 3:
			stack.pop();
			break;
		case 4:
			val = stack.top();
			if (val != -1) {
				cout << "Top element is: " << val << endl;
			}
			break;
		case 5:
			cout << "Average of stack elements is : " << stack.avg() << endl;
			break;
		case 6:
			cout << "Exit." << endl;
			break;

		default:
			cout << "Invalid, please choose the numbers displayed on the left" << endl;
		}
	} while (choice != 6);	//exits out of the system.
	return 0;
}