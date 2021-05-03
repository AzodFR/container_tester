#include "global.hpp"
#include "Vector.hpp"
#include <vector>


template <typename T>
void vector_constructor_empty(std::string type)
{
	g_total = 0;
	g_suc = 0;

	ft::Vector<T> A;
	std::vector<T> B;

	CHECK(".size()",A.size(), B.size());
	CHECK(".empty()", A.empty(), B.empty());
	CHECK(".max_size()",A.max_size(), B.max_size());
	CHECK(".capacity()", A.capacity(), B.capacity());

	RES("Vector::Empty constructor<\e[95m" +type+ "\e[0m>");
	std::cout << std::endl;
}

template<typename T>
void vector_constructor_range(std::string type)
{
	g_total = 0;
	g_suc = 0;

	ft::Vector<T> A(T(), ++T());
	std::vector<T> B(T(), ++T());


	RES("Vector::Range constructor<\e[95m" +type+ "\e[0m>");
	std::cout << std::endl;
}

template <typename T>
void vector_all(std::string type)
{
	vector_constructor_empty<T>(type);
}