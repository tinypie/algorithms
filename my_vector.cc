/*
 * implement a vector like the STL
 * push, pop, size
 */
#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
struct tcontainer {
	virtual void push(const T&) = 0;
	virtual void pop() = 0;
	virtual const T& begin() = 0;
	virtual const T& end() = 0;
	virtual size_t size() = 0;
};

template <typename T>
struct mvector : public tcontainer<T> {
public:
	static const size_t step = 100;
	mvector()
	{
		msize = 0;
		cap = step;
		buf = NULL;
		re_capacity(cap);
	}

	~mvector()
	{
		free(buf);
	}

	void re_capacity(size_t cap) 
	{
		if (buf == NULL) {
			buf = (T *) malloc (sizeof(T) * cap);
		} else {
			buf = (T *) realloc(buf, sizeof(T) * cap);
		}
	}

	virtual void push(const T &v)
	{
		if (msize >= cap) {
			re_capacity(cap += msize);
		}
		buf[msize++] = v;
	}

	virtual void pop()
	{
		if (msize) 
			msize--;
	}

	virtual const T & begin()
	{
		return buf[0];
	}

	virtual const T & end()
	{
		if (msize) 
			return buf[msize-1];
		else 
			return NULL;
	}
	
	virtual size_t size()
	{
		return msize;
	}

	const T& operator[] (size_t i) 
	{
		if (i >= 0 && i < msize)
			return buf[i];
	}

private :
	size_t msize;	// number of element
	size_t cap;
	T* buf;
};
		

int main()
{
	mvector <int> v;

	for (int i = 0; i < 10; i++) {
		v.push(i);
	}

	for (int i = 0; i < 10; i++)
		cout << v[i] << " ";
	
	cout << endl;

	return 0;
}
