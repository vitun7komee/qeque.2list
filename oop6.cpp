#include <iostream>
using T = int;
template<typename T>
class queue 
{
	
public:
	queue();
	~queue();
	void pushback(T data);
	int getsize() { return size; }
	void popfront();
	void clear();
	void pushfront(T data);
	void popback();
	void insert(T value, int infex);
	void removeat(int index);
	void print();
	bool empty();
	T front();
	T back();
	T& operator[](const int index);

private:
	template<typename T>
	class Node {
	public:
		Node *pnext;
		Node* pprev;
		T data;
		Node(T data = T(), Node* pnext = nullptr, Node* pprev = nullptr) {
			this->data = data;
			this->pnext = pnext;
			this->pprev = pprev;
		}
	};
	Node<T>* head;
	Node<T>* end;
	int size;
};
template<typename T>
queue<T>::queue() {
	size = 0;
	head = nullptr;
	end = nullptr;
}
template<typename T>
queue<T>::~queue() {
	clear();
}
template<typename T>
void queue<T>::pushback(T data) {
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T>* current = this->head;
		while (current->pnext != nullptr) { current = current->pnext; }
		current->pnext = new Node<T>(data);

	}
	size++;
}
template<typename T>
T& queue<T>::operator[](const int index) {
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr) {
		if (counter == index) { return current->data; }
		current = current->pnext;
		counter++;
	}
}
template<typename T>
void queue<T>::popfront() {
	Node<T> *temp = this->head;
	head = head->pnext;
	delete temp;
	size--;
}
template<typename T>
void queue<T>::clear() {
	while (size) {
		popfront();
	}
}
template<typename T>
void queue<T>::pushfront(T data) {
	head = new Node<T>(data,head);
	size++;
}
template<typename T>
void queue<T>::insert(T value, int index) {
	if (index == 0) { pushfront(value); }
	else {
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++) {
			previous = previous->pnext;
		}
		Node<T>* newNode = new Node<T>(value, previous->pnext);
		previous->pnext = newNode;
		size++;
	}
}
template<typename T>
void queue<T>::removeat(int index) {
	if (index == 0) { popfront(); }
	else {
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++) {
			previous = previous->pnext;
		}
		Node<T>* toDelete = previous->pnext;
		previous->pnext = toDelete->pnext;
		delete toDelete;
		size--;
	
	}
}
template<typename T>
void queue<T>::popback() {
	removeat(size - 1);
}
template<typename T>
void queue<T>::print() {

	Node<T>* current = this->head;
	while (current) {
		std::cout << current->data << "  ";
		current = current->pnext;
	}
}
template<typename T>
bool queue<T>::empty() {
	return head == nullptr;
}
template<typename T>
T queue<T>::front() {
	return head->data;
}
template<typename T>
T queue<T>::back() {
	Node<T>* temp = this->head;
	while (temp->pnext) { temp = temp->pnext; }
	end = temp;
	return end->data;
}
int main() {

	enum actions {
		pushback, getsize, popfront, clear, pushfront, popback, insert, removeat, print, endsession
	};

	bool stop = false;
	int choice;

	queue<int>lst;
	std::cout << "Enter size of queue :\n";
	int numberscount;
	std::cin >> numberscount;
	for (int i = 0; i < numberscount; i++) {
		lst.pushback(rand() % 10);
	}
	std::cout << " queue created!\n";

	std::cout << " 0 - pushback  1 - getsize  2 - popfront  3 - clear  4 - pushfront  " << std::endl;
	std::cout << " 5 - popback  6 - insert  7 - removeat  8 - print  9 - endsession  " << std::endl;
	while (!stop) {
		std::cout << "\nselect action : ";
		std::cin >> choice;
		switch (choice) {
		case actions::print:
			lst.print();
			std::cout << std::endl;
			break;
		case actions::getsize:
			std::cout << "size of queue = " << lst.getsize() << std::endl;
			break;
		case actions::pushback:
			int elemb;
			std::cout << "enter element which you want to add :";
			std::cin >> elemb;
			lst.pushback(elemb);
			break;
		case actions::pushfront:
			int elemf;
			std::cout << "enter element which you want to add :";
			std::cin >> elemf;
			lst.pushfront(elemf);
			break;
		case actions::popback:
			lst.popback();
			std::cout << "last element has been removed\n";
			break;
		case actions::popfront:
			lst.popfront();
			std::cout << "first element has been removed\n";
			break;
		case actions::insert:
			int index1;
			double value;
			std::cout << "enter index : ";
			std::cin >> index1;
			std::cout << "\nenter value : ";
			std::cin >> value;
			std::cout << std::endl;
			lst.insert(value, index1);
			break;
		case actions::removeat:
			int index2;
			std::cout << "enter index : ";
			std::cin >> index2;
			lst.removeat(index2);
			break;
		case actions::clear:
			lst.clear();
			std::cout << "the queue has been removed\n";
			break;
		case actions::endsession:
			std::cout << "cya!";
			stop = true;
			break;
		}	
	}
}



