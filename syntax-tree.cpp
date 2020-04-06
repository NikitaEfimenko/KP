#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cctype>

using namespace std;

int down(string & c){
	return c == ")" || c == "+" || c == "-"|| c == "/"|| c == "*";
}


int prior(char c){
	switch(c){
		case '(': return 1;
		case ')': return 2;
		case '+': return 3;
		case '-': return 3;
		case '*': return 4;
		case '/': return 4;
	}
}

int op(char c){
	return c == '+' || c == '-' ||c == '*' ||c == '/';
}


int ratischauser_parse( string expr){
	int n = expr.size();
	vector<int> tmp(n, 0);
	int k = 0;
	int res = 0;
	for (int i = 0; i < n; ++i){
		auto c = expr[i];
		string str(1, c);
		tmp[i] = (down(str)) ? --k: ++k;
	}
	for (auto c:tmp) cout << c <<" ";
	cout<<endl;
	return res;
} 


vector<char> dijkstra_parse(string ss){
	stack<char> s;
	vector<char> res;
	for (auto c:ss){
		if (op(c)){
			while(!s.empty()){
				char c1 = s.top();
				if ( prior(c) <= prior(c1)){
					res.push_back(c1);
					s.pop();
				}
				else break;
			}
			s.push(c);

		}
		else if (c == '('){
			s.push(c);
		}
		else if (c == ')'){
			while(!s.empty()){
				char c1 = s.top();
				s.pop();
				if (c1 == '('){
					break;
				}
				else {
					res.push_back(c1);
				}
			}

		}
		else{
			res.push_back(c);
		}
	}
	while(!s.empty()){
		res.push_back(s.top());
		s.pop();
	}
	return res;	
}

int operation(char op, int a, int b){
	switch(op){
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return a / b;
	}
}

class syntax_tree{
private:
	struct node{
		char tcn;
		node * l;
		node * r;
	};
	node * root;
public:
	syntax_tree(){
		root = NULL;
	}
	void parse(vector<char> polskay){
		stack<node*> s;
		for (auto c : polskay){
			if (op(c)){
				node * rc = s.top();
				s.pop();
				node * lc = s.top();
				s.pop();
				auto n = new node;
				n->tcn = c;
				n->l = lc;
				n->r = rc;
				s.push(n);
			}
			else{
				auto n = new node;
				n->tcn = c;
				n->l = NULL;
				n->r = NULL;
				s.push(n);
			}
		}
		root = s.top();
		s.pop();
	}
	void infix(node * root){
		if (root == NULL) return;
		infix(root->l);
		cout << root->tcn;
		infix(root->r);
	}
	int eval(node * root){
		auto token = root->tcn;
		if (isdigit(token)){
			return static_cast<int>(token) - '0';
		}
		else {
			return  operation(token, eval(root->l), eval(root->r));
		}

	}
	int eval(){
		return eval(root);
	}
	void infix(){
		infix(this->root);
	}
	int task(node * root){
		if (root == NULL || root->r == NULL){
			return 0;
		}
		else {
			auto d = static_cast<int>(root->r->tcn) - '0';
			int count = (op(root->tcn) && d == 1)? 1: 0; 
			return count + task(root->l) + task(root->r);
		}
	}
	int task (){
		return task(root);
	}
};


int main(){
	string expr;
	cin >> expr;
	syntax_tree t;
	vector<char> polskay = dijkstra_parse(expr);
	for (auto k : polskay) cout << k;
	t.parse(polskay);
	cout << endl;
	t.infix();
	cout << endl;
	cout << t.eval() << endl;
	cout << t.task() << endl;
}
