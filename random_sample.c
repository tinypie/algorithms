#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * There are three solution to the problem of random sample
 * 1):random selection
 * 2):STL set
 * 3): random order
 * 4): genfloid (worse carse is m) good
 * wanted distinct integers in random order ==> use 3)(not sorted)
 * wanted distinct integers in increament order ==> 1) or 2)
 * wanted duplicate integers in random order 
 * 	for i=[0,m)
 * 		rand() % n
 * wanted duplicate integers in increament order 
 */

/*
 * 使用rand() 产生bigrand()和randint()的方法
 * 因为C库是rand()返回的是15位的随机数，至少返回30位的随机数的bigrand()
 */
int bigrand() 
{
	return RAND_MAX * rand() + rand();
}

int randint(int l, int u)
{
	int tmp;
	if (l > u) {
		tmp = l;
		l = u;
		u = tmp;
	}

	return l + bigrand() % (u - l + 1);
}

/* 
 * random select
 * increament and distinct
 * When n is very large, however, this code can be very slow.
 * */
int random_select(int m, int n)
{
	int i;
	time_t t;
	srand(time(&t));
	//srand(time(NULL));

	for (i = 0; i < n; i++) {
		/* select i with probability m/(n-i) */
		if (rand() % (n-i) < m) {
			printf("%d ", i);
			m--;
		}
	}
	return 0;
}

/* 
 * STL SET, when m is near n, the algorithm generates many random numbers
 * that are discarded because they are already present in the set.
 * O(mlgm)
 */
#if 0
int rand_set(int m, int n)
{
	set<int> s;
	while(s.size() < m) {
		s.insert(rand()%n);
	}

	set<int>::iterator i;
	for (i = s.begin(); i!= s.end(); i++) {
		cout << *i << endl;
	}
	return 0;
}

void genfloyd(int m, int n)
{
	set<int> s;
	set<int>::iterator i;
	for (int j = n-m; j < n; j++) {
		int t = rand()%(j+1);
		if (s.find(t) == s.end()) 	
			s.insert(t);
		else
			s.insert(j);
	}

}
	
/* rand order */

int rand_shuffer(int m, int n)
{
	int i, j;
	int *x = new int[n];

	for (i = 0; i < n; i++) 
		x[i] = i;
	for (i = 0; i < m; i++) {
//		j = i + rand()%(n-i)
		j = randin(i, n-1);
		int t = x[i];
		x[i] = x[j];
		x[j] = t;
	}

	sort(x, x+m);

	for (i = 0; i < m; i++) {
		cout << x[i];
	}
	return 0;
}

#endif
int random_recursive(int m, int n)
{
	int i;
	if (m > 0) {
		i = rand()%n;
		if (i < m) {
			printf("%d ", n-1);
			random_recursive(m-1, n-1);
		} else
			random_recursive(m, n-1);
		
	}

	return 0;
}
			
/* if n is very large, then the space is too expensive */
int rand_rand(int m, int n)
{
	int i, j, *a;
	a = (int *) malloc(n*sizeof(int));

	if (a == NULL) {
		fprintf(stderr, "malloc error\n");
		exit(0);
	}

	for (i = 0; i < n; i++) {
		a[i] = i;
	}

	while (m > 0) {
		j = rand() % n;

		printf("%d ", a[j]);
		if (j < n-1) {
			a[j] = a[n-1];
		}
		m--;
		n--;
	}
	free(a);
	return 0;
}

int main()
{
//	int i = randint(0, 10);
//	printf("%d\n", i);
//	random_select(2, 10);
	random_recursive(2, 10);
//	good(10, 500);

	return 0;
}
