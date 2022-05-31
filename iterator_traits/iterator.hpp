#include "iterator_traits.hpp"

class MyIterator : public ft::iterator<std::input_iterator_tag, int>
{
	int		*p;

	public:
		MyIterator(int* x) :p(x) {}
		MyIterator(const MyIterator& mit) : p(mit.p) {}
		MyIterator& operator++() {++p;return *this;}
		MyIterator operator++(int) {MyIterator tmp(*this); operator++(); return tmp;}
		bool operator==(const MyIterator& rhs) const {return p==rhs.p;}
}; 
