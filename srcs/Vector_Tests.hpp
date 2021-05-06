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
	ft::Vector<T> A(C.begin(), --C.end());
	std::vector<T> B(D.begin(), --D.end());

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

	ft::Vector<T> A(5, 200);
	std::vector<T> B(5, 200);

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

	CHECK(".size()",A.size(), B.size());
	int i = 0;
	typename ft::Vector<T>::iterator a_beg = A.begin();
	typename std::vector<T>::iterator beg = B.begin();
	for (; beg != B.end() && a_beg != A.end(); beg++)
	{
		std::string text = ".insert(begin, begin, end) element [";
		text += std::to_string(i++);
		text += "]";
		CHECK(text, *a_beg, *beg);
		a_beg++;
	}

	RES("Vector::Insert()<\e[95m" +type+ "\e[0m>");
	std::cout << std::endl;
}

template<typename T>
void vector_erase_function(std::string type)
{
	g_total = 0;
	g_suc = 0;
	ft::Vector<T> A(50, 24);
	std::vector<T> B(50, 24);

	A.erase(++A.begin(), --A.end());
	B.erase(++B.begin(), --B.end());
	CHECK(".size()",A.size(), B.size());
	CHECK(".empty()", A.empty(), B.empty());
	CHECK(".max_size()",A.max_size(), B.max_size());
	CHECK(".capacity()", A.capacity(), B.capacity());
	CHECK(".front()", A.front(), B.front());

std::cout << "---" << std::endl;

	A.erase(A.begin());
	B.erase(B.begin());
	CHECK(".size()",A.size(), B.size());
	CHECK(".empty()", A.empty(), B.empty());
	CHECK(".capacity()", A.capacity(), B.capacity());
	RES("Vector:Erase()<\e[95m" +type+ "\e[0m>");
	std::cout << std::endl;
}

template<typename T>
void vector_change_size(std::string type)
{
	g_total = 0;
	g_suc = 0;
	ft::Vector<T> A;
	std::vector<T> B;

std::cout << "--- .resize(20)" << std::endl;
	A.resize(20);
	B.resize(20);
	CHECK(".size()",A.size(), B.size());
	CHECK(".empty()", A.empty(), B.empty());
	CHECK(".max_size()",A.max_size(), B.max_size());
	CHECK(".capacity()", A.capacity(), B.capacity());
	CHECK("last value", *A.rbegin(), *B.rbegin());

std::cout << std::endl << "--- .resize(10)" << std::endl;

	A.resize(10);
	B.resize(10);
	CHECK(".size()",A.size(), B.size());
	CHECK(".empty()", A.empty(), B.empty());
	CHECK(".max_size()",A.max_size(), B.max_size());
	CHECK(".capacity()", A.capacity(), B.capacity());
	CHECK("last value", *A.rbegin(), *B.rbegin());

std::cout << std::endl << "--- .reserve(100)" << std::endl;

	A.reserve(100);
	B.reserve(100);
	CHECK(".size()",A.size(), B.size());
	CHECK(".empty()", A.empty(), B.empty());
	CHECK(".max_size()",A.max_size(), B.max_size());
	CHECK(".capacity()", A.capacity(), B.capacity());
	CHECK("last value", *A.rbegin(), *B.rbegin());

std::cout << std::endl << "--- .reserve(15)" << std::endl;
	A.reserve(15);
	B.reserve(15);
	CHECK(".size()",A.size(), B.size());
	CHECK(".empty()", A.empty(), B.empty());
	CHECK(".max_size()",A.max_size(), B.max_size());
	CHECK(".capacity()", A.capacity(), B.capacity());
	CHECK("last value", *A.rbegin(), *B.rbegin());

std::cout << std::endl << "--- .reserve(1)" << std::endl;
	A.reserve(1);
	B.reserve(1);
	CHECK(".size()",A.size(), B.size());
	CHECK(".empty()", A.empty(), B.empty());
	CHECK(".max_size()",A.max_size(), B.max_size());
	CHECK(".capacity()", A.capacity(), B.capacity());
	CHECK("last value", *A.rbegin(), *B.rbegin());
std::cout  << std::endl << "--- .reserve(100) then .resize(1000)" << std::endl;
	A.reserve(100);
	B.reserve(100);
	A.resize(1000);
	B.resize(1000);
	CHECK(".size()",A.size(), B.size());
	CHECK(".empty()", A.empty(), B.empty());
	CHECK(".max_size()",A.max_size(), B.max_size());
	CHECK(".capacity()", A.capacity(), B.capacity());
	CHECK("last value", *A.rbegin(), *B.rbegin());

	RES("Vector::Resize/Reserve()<\e[95m" +type+ "\e[0m>");
	std::cout << std::endl;
}

template<typename T>
void vector_push_pop_back_function(std::string type)
{
	g_total = 0;
	g_suc = 0;
	ft::Vector<T> A;
	std::vector<T> B;

	T i = 0;
	A.push_back(i);
	B.push_back(i);
	typename ft::Vector<T>::reverse_iterator 	a_begin = A.rbegin();
	typename std::vector<T>::reverse_iterator	b_begin = B.rbegin();



	while (i < 10)
	{
		std::string text = ".push_back(";
		text += std::to_string(i++);
		text += ")";
		CHECK(text, *a_begin, *b_begin);
		A.push_back(i);
		B.push_back(i);
		a_begin = A.rbegin();
		b_begin = B.rbegin();
	}
	while (--i)
	{
		std::string text = ".pop_back(";
		text += std::to_string(i);
		text += ")";
		CHECK(text, *a_begin, *b_begin);
		A.pop_back();
		B.pop_back();
		a_begin = A.rbegin();
		b_begin = B.rbegin();
	}

	RES("Vector::Push_back()<\e[95m" +type+ "\e[0m>");
	std::cout << std::endl;
}

template<typename T>
void vector_swap(std::string type)
{
	g_total = 0;
	g_suc = 0;
	ft::Vector<T> A(5, 1);
	std::vector<T> B(5, 1);
	ft::Vector<T> C(10, 2);
	std::vector<T> D(10, 2);

	A.swap(C);
	B.swap(D);
	CHECK(".size() -- First",A.size(), B.size());
	CHECK(".empty() -- First", A.empty(), B.empty());
	CHECK(".max_size() -- First",A.max_size(), B.max_size());
	CHECK(".capacity() -- First", A.capacity(), B.capacity());
	CHECK("last value -- First", *A.rbegin(), *B.rbegin());
		std::cout  << std::endl << "---" << std::endl;
		CHECK(".size() -- Second",C.size(), D.size());
	CHECK(".empty() -- Second", C.empty(), D.empty());
	CHECK(".max_size() -- Second",C.max_size(), D.max_size());
	CHECK(".capacity() -- Second", C.capacity(), D.capacity());
	CHECK("last value -- Second", *C.rbegin(), *D.rbegin());
		std::cout  << std::endl << "---" << std::endl;
	unsigned long i = 0;
	typename ft::Vector<T>::iterator a = A.begin();
	typename std::vector<T>::iterator b = B.begin();
	while (i < 10)
	{
		std::string text = ".swap() -- First -- element[";
		text += std::to_string(i);
		text += "]";
		CHECK(text, *a, *b);
		a++;
		b++;
		i++;
	}
	std::cout  << std::endl << "---" << std::endl;
	i = 0;
	typename ft::Vector<T>::iterator c = C.begin();
	typename std::vector<T>::iterator d = D.begin();
	while (i < 5)
	{
		std::string text = ".swap() -- Second -- element[";
		text += std::to_string(i);
		text += "]";
		CHECK(text, *c, *d);
		c++;
		d++;
		i++;
	}
	std::cout  << std::endl << "--- Hardcore" << std::endl;
	A.erase(A.begin(), A.end());
	C.swap(A);
	B.erase(B.begin(), B.end());
	D.swap(B);
	CHECK(".size() -- First",A.size(), B.size());
	CHECK(".empty() -- First", A.empty(), B.empty());
	CHECK(".max_size() -- First",A.max_size(), B.max_size());
	CHECK(".capacity() -- First", A.capacity(), B.capacity());
	CHECK("last value -- First", *A.rbegin(), *B.rbegin());
		std::cout  << std::endl << "---" << std::endl;
		CHECK(".size() -- Second",C.size(), D.size());
	CHECK(".empty() -- Second", C.empty(), D.empty());
	CHECK(".max_size() -- Second",C.max_size(), D.max_size());
	CHECK(".capacity() -- Second", C.capacity(), D.capacity());
		std::cout  << std::endl << "---" << std::endl;
	i = 0;
	a = A.begin();
	b = B.begin();
	while (i < 5)
	{
		std::string text = ".swap() -- First -- element[";
		text += std::to_string(i);
		text += "]";
		CHECK(text, *a, *b);
		a++;
		b++;
		i++;
	}
	RES("Vector::Swap()<\e[95m" +type+ "\e[0m>");
	std::cout << std::endl;
}

template <typename T>
void vector_all(std::string type)
{
		std::cout << "\e[91m=================== VECTOR ===================\e[0m" << std::endl;
	vector_constructor_empty<T>(type);
	vector_constructor_fill<T>(type);
	vector_constructor_range<T>(type);
	vector_insert_function<T>(type);
	vector_erase_function<T>(type);
	vector_change_size<T>(type);
	vector_push_pop_back_function<T>(type);
	vector_swap<T>(type);
}