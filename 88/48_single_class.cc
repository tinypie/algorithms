// 不能被继承的类

class Single {
public:
	static Single *get_single()
	{
		return new Single();
	}

	static void delete_single(Single *instance)
	{
		delete instance;
	}

private:
	Single(){}
	~Single() {}
};


template <typename T> class Make_single {
public:
	friend T;
private:
	Make_single() {}
	~Make_single() {}
};

class Single_beater : virtual public Make_single<Single_beater> {
public:
	Single_beater() {}
	~Single_beater() {}
};
