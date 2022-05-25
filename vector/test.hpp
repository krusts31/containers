#include <iostream>
namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		//explicit make sure that the constructor will be invoked by maching the type you pass it
		//inplicit would mean that if I pass H(11) or h("HAHA") then the comppiler could try to just
		//convert the "haha" to a integer hence implicite
		public:
			explicit vector(const Alloc& alloc = Alloc())
			{
				std::cout << "HELLLO" << std::endl;
				(void)alloc;
				;
			}
			explicit vector(size_t n, const T& val = T(),
					 const Alloc& alloc = Alloc());
			template <class InputIterator>
			vector (InputIterator first, InputIterator last,
				const Alloc& alloc = Alloc());
			vector (const vector& x);
		private:
			T	*t;
	};
}
