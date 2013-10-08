#include <iostream>
#include <stack>

using namespace std;

// use two stack to implement a queue (as an template

template <typename T> class Cqueue {
public:
	Cqueue();
	~Cqueue();

	void append(const T &node);
	T delete_node();
private:
	stack<T> s1;
	stack<T> s2;
};

template<typename T> void Cqueue::append(const T &node)
{
	s1.push_back(node);
}

template <typename T> T cqueue::delete_node()
{
	if (s2.size() <= 0) {
		while (s1.size() > 0) {
			T &data = s1.top();
			s1.pop();
			s2.push_back(data);
		}
	}

	if (s2.size() == 0) {
		throw new exception("queue is empty");
	}

	T head = s2.top();
	s2.pop();

	return head;
}

