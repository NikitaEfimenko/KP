#include <iostream>
#include <vector>
#include <string>
#include <iterator>

template<class T>
class priorityQueue{
private:
	std::vector<std::pair<int, T>> q;
	void _heapify(int i){
		int sz = q.size();
		int l = (i << 1) + 1;
		int r = (i << 1) + 2;
		int mx = (l < sz && q[l].first > q[i].first)? l: i;
		mx = (r < sz && q[r].first > q[mx].first)? r: mx;
		if (mx != i){
			std::swap(q[i], q[mx]);
			_heapify(mx);
		}
	}
	void _toHeap(){
		int size = q.size();
		for (int i = size >> 1; i >=0; --i){
			_heapify(i);
		}
	}	
public:
	priorityQueue(){
		std::cout << "create priorityQueue\n";
	
	}
	priorityQueue(std::vector<int, T>data){
		this->q.clear();
		this->q = data;
		_toHeap();
	
	}
	~priorityQueue(){
		std::cout << "delete priorityQueue\n";
	}
	void insert(T val, int priority){
		int idx = q.size();
		q.push_back(std::pair<int, T>(priority, val));
		while(idx > 0 && q[idx] > q[idx >> 1]){
			std::swap(q[idx], q[idx >> 1]);
			idx = idx >> 1;
		}
	}
	auto extract(){
		auto val = q.front().second;
		std::swap(q[0], q[q.size()-1]);
		q.pop_back();
		std::cout <<"\n_______________\n";
		_heapify(0);
		return val;

	}
	void print(){
		for (auto el : q){
			std::cout<<" ->("<<el.first<<","<<el.second<<")";
		}
		std::cout<<std::endl;
	}
};


int main(){
	priorityQueue<std::string> q;
	q.insert("hello", 1);
	q.insert("my", 3);
	q.insert("dear", 14);
	q.insert("friend", 16);
	q.insert("fucking", 5);
	q.insert("or", 2);
	q.insert("=)", 0);

	std::cout<<q.extract()<<std::endl;
	std::cout<<q.extract()<<std::endl;
	std::cout<<q.extract()<<std::endl;
	std::cout<<q.extract()<<std::endl;
	std::cout<<q.extract()<<std::endl;
	std::cout<<q.extract()<<std::endl;
	q.print();
}