
#include <iostream>
#include <algorithm>
#include <vector>

template<class T>
class binTree{
private:
	struct Node{
		T val;
		Node * l;
		Node * r;
	};
	Node * _createNode(T v){
		Node * n = new Node;
		n->val = v;
		n->l = NULL;
		n->r = NULL;
		return n;
	}
	Node* root;
	Node ** search(T v, Node * (&root)){
		if (root != NULL){
			if (root->val == v){
				return &root;
			}
			else if(root->val > v){
			 	 search(v, root->l);
			}
			else{
				 search(v, root->r);
			}
		}
		else{
			return NULL;
		}
	}
public:
	binTree(){
		std::cout<<"create!\n";
		root = NULL;
	}
	~binTree(){
		std::cout<<"delete!\n";
	}

	Node ** search(T v){
		return search(v, root);
	}

	void del(T v, Node * (&root)){
		Node ** target = search(v, root);
		if (target != NULL){
			Node * toDel = *target;
			if ((*target)->l == NULL && (*target)->r == NULL){
				delete *target;
				*target = NULL;
				std::cout<<"\n(1)\n";
			}
			else if((*target)->l != NULL && (*target)->r == NULL){
				*target = toDel->l;
				std::cout<<"\n(2)\n";
				delete toDel;
			}
			else if((*target)->l == NULL && (*target)->r != NULL){
				*target = toDel->r;
				std::cout<<"\n(3)\n";
				delete toDel;	
			}
			else {
				Node * mx = max(toDel->l);
				T dV = toDel->val;
				toDel->val = mx->val;
				std::cout<<"\n###############\n";
				del(mx->val, toDel->l);
			}
		}
		else{
			std::cout<<"\n(10)\n";
		}
	}
	void del(T v){
		del(v, root);
	}
	void insert(T v, Node * (&root)){
		if(root !=NULL){
			if (root->val < v){
				insert(v, root->r);
			}
			else{
				insert(v, root->l);
			}
		}
		else{
			root = _createNode(v);
		}
	}
	void print(Node * root, int l){
		if(root != NULL){
			print(root->r, l + 1);
			printf("%*s%d\n", 4 * l, " ", root->val);
			print(root->l, l + 1);
		}
		else{
			printf("%*sNULL\n", 4 * l, " ");

		}
	}
	void insert(T v){
		insert(v, this->root);
	}
	void print(){
		print(this->root, 0);
	}

	Node * max(Node * root){
		Node * st = root;
		while(st->r != NULL){
			st = st->r;
		}
		return st;
	}
	T max(){
		return max(root)->val;
	}

	void levelsHeight(Node * root, std::vector<int> &levelSize, int lvl){
		if (root != NULL) {
			levelSize[lvl]++;
			levelsHeight(root->l,levelSize, lvl + 1);
			levelsHeight(root->r,levelSize, lvl + 1);
		}
		else return;
	}

	int height(){
		std::vector<int> levelSize(maxDepth(), 0);
		levelsHeight(root, levelSize, 0);
		return *std::max_element(levelSize.begin(), levelSize.end());
		
	}

	int maxDepth(Node * root){
		if (root != NULL){
			return std::max(maxDepth(root->l), maxDepth(root->r)) + 1;
		}
		return 0;
	}
	int maxDepth(){
		maxDepth(root);
	}


	int minDepth(Node * root){
		if (root != NULL){
			return std::min(minDepth(root->l), minDepth(root->r)) + 1;
		}
		return 0;
	}
	int minDepth(){
		minDepth(root);
	}
	int isAVL(){
		return maxDepth() - minDepth() <= 1  ;
	}
};

int main(){
	binTree<int> tree;
	
	tree.insert(10);
	tree.insert(2);
	tree.insert(30);
	tree.insert(3);
	tree.insert(1);
	tree.insert(40);
	tree.insert(25);
	tree.insert(-15);
	//tree.insert(-16);
	//tree.insert(-18);
	tree.print();

	std::cout << tree.maxDepth()<<std::endl;
	std::cout << tree.isAVL()<<std::endl;

	return 1;
}