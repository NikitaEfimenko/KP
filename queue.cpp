#include "stdio.h"
#include "stdlib.h"
#include <iostream>

template <class T>
class Queue{
public:
	Queue(){
		printf("Create Queue!\n");
		tail = NULL;
		head = NULL;
		count = 0;
	}
	~Queue(){
		printf("Delete Queue!\n");
	}
	void push(T elem){
		Node *n = new Node;
		n->data = elem;
		n->next = NULL;
		if (tail == NULL){
			head = n;
			tail = n;
		}
		else{
			tail->next = n;
		}
		tail = n;
		count++;
	}
	T pop(){
		Node * elem = head;
		head = head -> next;
		T res = elem->data;
		count--;
		delete elem;
		return res;
	}
	void print(){
		Node * elem = head;
		for (int i = 0; i < count; ++i){
			printf("%d -> ",elem->data);
			elem = elem->next;
		}
		printf("\n");

	}


private:
	struct Node{
		T data;
		Node * next;
	};
	Node *tail;
	Node *head;
	int count = 0;
};


int main(){
	Queue<int> q;
	q.push(1);
	
	q.push(2);
	q.push(-1);
	q.push(51);
	
	q.print();
	
	q.pop();
	q.pop();
	q.push(145);
	
	q.print();
	return 0;
}