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
void vector_constructor_fill(std::string type)
{
	g_total = 0;
	g_suc = 0;

	ft::Vector<T> A(5, 255);
	std::vector<T> B(5, 255);

	CHECK(".size()",A.size(), B.size());
	CHECK(".empty()", A.empty(), B.empty());
	CHECK(".max_size()",A.max_size(), B.max_size());
	CHECK(".capacity()", A.capacity(), B.capacity());
	CHECK(".front()", A.front(), B.front());
	
	RES("Vector::Fill constructor<\e[95m" +type+ "\e[0m>");
	std::cout << std::endl;
}

template<typename T>
void vector_constructor_range(std::string type)
{
	g_total = 0;
	g_suc = 0;

	ft::Vector<T> C(5, 255);
	std::vector<T> D(5, 255);
	ft::Vector<T> A(++(++C.begin()), --(--(--C.end())));
	std::vector<T> B(++(++D.begin()), --(--(--D.end())));

	CHECK(".size()",A.size(), B.size());
	CHECK(".empty()", A.empty(), B.empty());
	CHECK(".max_size()",A.max_size(), B.max_size());
	CHECK(".capacity()", A.capacity(), B.capacity());
	CHECK(".front()", A.front(), B.front());
	
	RES("Vector::Range constructor<\e[95m" +type+ "\e[0m>");
	std::cout << std::endl;
}

template <typename T>
void vector_insert_function(std::string type)
{
	g_total = 0;
	g_suc = 0;

	ft::Vector<T> A;
	std::vector<T> B;

	A.insert(A.begin(), 5);
	B.insert(B.begin(), 5);

	CHECK(".insert(begin , 5)", A.front(), B.front());

std::cout << "---" << std::endl;

	A.insert(A.begin(), 10);
	B.insert(B.begin(), 10);

	CHECK(".insert(begin , 10)", A.front(), B.front());

std::cout << "---" << std::endl;

	A.insert(A.begin(), 2, 25);
	B.insert(B.begin(), 2, 25);

	CHECK(".insert(begin , 2, 25) -- 1", A.front(), B.front());
	CHECK(".insert(begin , 2, 25) -- 2", *(++A.begin()), *(++B.begin()));
	CHECK(".size()",A.size(), B.size());

std::cout << "---" << std::endl;

	A.insert(A.begin(), A.begin(), A.end());
	B.insert(B.begin(), B.begin(), B.end());
	int i = 0;
	typename ft::Vector<T>::iterator a_beg = A.begin();
	typename std::vector<T>::iterator beg;
	for (beg = B.begin(); beg != B.end(); beg++)
	{
		std::string text = ".insert(begin, begin, end) element [";
		text += std::to_string(i++);
		text += "]";
		CHECK(text, *a_beg, *beg);
		a_beg++;
	}
	CHECK(".size()",A.size(), B.size());
	RES("Vector::Range constructor<\e[95m" +type+ "\e[0m>");
	std::cout << std::endl;
}

template <typename T>
void vector_all(std::string type)
{
	vector_constructor_empty<T>(type);
	vector_constructor_fill<T>(type);
	vector_constructor_range<T>(type);
	vector_insert_function<T>(type);
}