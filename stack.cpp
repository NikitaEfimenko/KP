#include <iostream>

template<class T>
class Stack{
public:
	Stack(){
		head = NULL;
		tail = NULL;
		std::cout << "create Stack\n";
	}
	~Stack(){
		std::cout << "delete Stack\n";
	}

	void push(T elem){
		Node * n = new Node;
		n->elem = elem;
		n->next = NULL;
		cnt++;
		if (head == NULL){
			tail = n;
			head = n;
		}
		else{
			n->next = head;
			head = n;  
		}		
	}
	T pop(){
		Node * del = head;
		if (del == NULL){
			return -1;
		}
		head = head->next;
		cnt --;
		T res = del->elem;
		delete del;
		return res;
	}
	void print(){
		Node * el = head;
		for (int i = 0; i < cnt; ++i){
			std::cout<< el->elem << "<- ";
			el = el->next;
		}
		std::cout << std::endl;
	}

private:
	struct Node{
		T elem;
		Node * next;
	};
	Node * head;
	Node * tail;
	int cnt = 0;
};


int main(){
	Stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.print();

	st.pop();
	st.pop();
	st.pop();
	st.pop();
	st.pop();
	st.print();
}