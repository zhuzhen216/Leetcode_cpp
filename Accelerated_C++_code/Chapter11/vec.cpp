#include<memory>

template <class T> class Vec{
public:
	// these things are first to consider
	// define a class iterator
	// define a const_iterator
	// define size_typ
	// define value_type
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;

	//creator
	Vec(){create();}
	explicit Vec(size_type n, const T& val=T()){create(n,val);}

	//destructor
	~Vec(){uncreate();}

	// new operations: size and index
	size_type size() const {return limit-data;}
	T& operator[](size_type i) {return data[i];}
	const T& operator[](size_type i) const {return data[i];}
	
	// new functions to return iterators
	iterator begin() {return data;}
	const_iterator begin() const {return data;}
	
	iterator end() {return limit;}
	const_iterator end() const {return limit;}

	void push_back(const T& val){
		if (avail == limit) grow(); // get space if needed;
		unchecked_append(val);
	}
	
	// copy constructor
	Vec(const Vec& v) {create(v.begin(),v.end()); }

	// assignment
	Vec& operator=(const Vec&)
private:
	iterator data; //first element in the Vec
	iterator limit; // one past the last element in the Vec
	iterator avail; // pointer to (one past) the last constructed element;
}
Vec<T>& Vec<T>::operator=(const Vec& rhs){

if (&rhs != this){
uncreate();
create(rhs.begin(),rhs.end());
}
return *this;
}

Vec<int> v;
