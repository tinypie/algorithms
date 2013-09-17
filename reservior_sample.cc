#include <iostream>
#include <ctime>
#include <cstdlib>

#include <vector>

using namespace std;

int randint(int l, int u)
{
	return l + rand() % (u-l+1);
}

/*
 * selet one object when n is not known 
 */
bool reservior_sample(vector<int> &input, int &result)
{
	//srand(time(NULL));

	if (input.size() <= 0) 
		return false;
	
	vector<int>::iterator iter = input.begin();

	for (int i = 0; iter != input.end(); iter++, i++) {
		if (randint(0, i) < 1) 
			result = *iter;

	}

	return result;
}

int main()
{
	cout<<"fuck"<<endl;
	return 0;
}
