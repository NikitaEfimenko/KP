#include <iostream>
#include <string>

template <class T>
class List{
public:
	List(){
		cnt = 0;
		head = NULL;
		std::cout << "create List\n";
	}
	~List(){
		std::cout << "delete List\n";
	}

	T search(int idx){

	}

	void insert(T elem, int& idx){
		if (gIdx(idx)){
			Node *n = new Node;
			n->elem = T;
			n->next = 
			cnt++;
		}
		else{
			std::cout <<"bad idx \n";
		}
	}
	void del(int & idx){
		if (gIdx(idx)){
			cnt--;

		}
		else{
			std::cout <<"bad idx \n";
		}
	}

private:
	int cnt = 0;
	struct Node{
		T elem;
		Node * next;
	}
	int gIdx(int i){
		return i > 0 && i < cnt;
	}
	Node * head;

}


int main(){
	List<std::string> list;
	list.insert("1", 0);
	list.insert("2", 0);
	list.insert("3", 1);
	list.insert("4", 1);

	list.print();

	list.del(1);
	list.del(0);

	list.print();
}