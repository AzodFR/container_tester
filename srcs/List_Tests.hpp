#include "global.hpp"
#include "List.hpp"
#include <list>

template <typename T>
int get_total(T it, T end)
{
	int total = 0;
	while (it != end)
	{
		total += *it;
		it++;
	}
	return (total);
}


template<typename T>
void list_explicit_size_constructor(std::string type)
{
	ft::List<T> A(5);
	std::list<T> B(5);

	g_total = 0;
	g_suc = 0;

	CHECK(".size()",A.size(), B.size());
	CHECK(".max_size()", A.max_size(), B.max_size());
	CHECK(".begin() value", *A.begin(), *B.begin());
	CHECK(".end() value", *A.end(), *B.end());
	CHECK(".empty()", A.empty(), B.empty());
	CHECK("total value", get_total(A.begin(), A.end()), get_total(B.begin(), B.end()));

	RES("Explicit Size Constructor<" +type+ ">");
	std::cout << std::endl;
}

template<typename T>
void list_explicit_fill_constructor(std::string type)
{
	g_total = 0;
	g_suc = 0;

	ft::List<T> A(5, 100);
	std::list<T> B(5, 100);

	CHECK(".size()",A.size(), B.size());
	CHECK(".max_size()", A.max_size(), B.max_size());
	CHECK(".begin() value", *A.begin(), *B.begin());
	CHECK(".end() value", *A.end(), *B.end());
	CHECK(".empty()", A.empty(), B.empty());
	CHECK("total value", get_total(A.begin(), A.end()), get_total(B.begin(), B.end()));

	RES("Explicit Fill Constructor<" +type+ ">");
	std::cout << std::endl;
}

template<typename T>
void list_pop_push(std::string type)
{
	g_total = 0;
	g_suc = 0;
	ft::List<T> A(1);
	std::list<T> B(1);

	A.push_front(2);
	A.push_front(1);
	A.push_back(9);
	B.push_front(2);
	B.push_front(1);
	B.push_back(9);

	CHECK(".push_front()", *(A.begin()), *(B.begin()));
	CHECK(".push_back()", *(--A.end()), *(--B.end()));
	A.pop_front();
	B.pop_front();
	CHECK(".pop_front()", *(A.begin()), *(B.begin()));
	A.pop_back();
	B.pop_back();
	CHECK(".pop_back()", *(A.begin()), *(B.begin()));

	RES("Pop & Push<" +type+ ">");
	std::cout << std::endl;
}

template<typename T>
void list_insert(std::string type)
{
	g_total = 0;
	g_suc = 0;
	ft::List<T> A(1);
	std::list<T> B(1);

	A.insert(A.begin(), 42);
	B.insert(B.begin(), 42);
	CHECK(".insert() - begin", *(A.begin()), *(B.begin()));
	A.insert(++A.begin(), 21);
	B.insert(++B.begin(), 21);
	CHECK(".insert() - begin + 1", *(++A.begin()), *(++B.begin()));
	CHECK(".size()", A.size(), B.size());
	RES("Insert<" +type+ ">");
	std::cout << std::endl;
}

template<typename T>
void list_resize(std::string type)
{
	g_total = 0;
	g_suc = 0;
	ft::List<T> A(1);
	std::list<T> B(1);
	A.resize(500);
	B.resize(500);
	CHECK(".resize()", A.size(), B.size());
	RES("Resize<" +type+ ">");
	std::cout << std::endl;
}

template<typename T>
void list_all(std::string type)
{
	list_explicit_size_constructor<T>(type);
	list_explicit_fill_constructor<T>(type);
	list_pop_push<T>(type);
	list_insert<T>(type);
	list_resize<T>(type);
}