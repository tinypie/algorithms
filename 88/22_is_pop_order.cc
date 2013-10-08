#include <iostream>
#include <stack>
using namespace std;

bool is_pop_order(int *push, int *pop, int len)
{
	bool ret = false;

	if (push == NULL || pop == NULL || len <= 0)
		return false;
	
	const int *next_push = push;
	const int *next_pop = pop;

	stack <int> st;

	while(next_pop - pop < len) {
		while (st.empty() || st.top() != *next_pop) {
			if (next_push - push == len)
				break;

			st.push(*next_push);
			next_push++;
		}

		if (st.top() != *next_pop)
			break;
		
		st.pop();
		next_pop++;
	}

	if (st.empty() && next_pop - pop == len)
		ret = true;
	
	return ret;
}

int main() 
{
	int push[5] = {1, 2, 3, 4, 5};
	int pop[5] = {4, 3, 5, 1, 2};

	if (is_pop_order(push, pop, 5))
		cout << "yes" << endl;
	else 
		cout <<"no" << endl;
	
	return 0;
}
