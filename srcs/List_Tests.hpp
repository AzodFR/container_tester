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

	ft::List<T> A(6, 100);
	std::list<T> B(6, 100);

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
void list_copy_constructor(std::string type)
{
	g_total = 0;
	g_suc = 0;

	ft::List<T> B(5, 100);
	ft::List<T> A(B);
	CHECK(".size()",A.size(), B.size());
	CHECK(".max_size()", A.max_size(), B.max_size());
	CHECK(".begin() value", *A.begin(), *B.begin());
	CHECK(".end() value", *A.end(), *B.end());
	CHECK(".empty()", A.empty(), B.empty());
	CHECK("total value", get_total(A.begin(), A.end()), get_total(B.begin(), B.end()));

	RES("Copy Constructor<" +type+ ">");	
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
void list_adv_int(ft::List<T> A, std::list<T> B)
{
	std::cout << "---" << std::endl;

	A.push_front(-5);
	B.push_front(-5);
	A.unique(abs_equ);
	B.unique(abs_equ);
	CHECK(".unique(Predicate)", A.size(), B.size());
	CHECK(".unique(Predicate) total size", get_total(A.begin(), A.end()), get_total(B.begin(), B.end()));

	std::cout << "---" << std::endl;

	A.remove_if(is_even);
	B.remove_if(is_even);
	CHECK(".remove_if(Predicate)", A.size(), B.size());
	CHECK(".remove_if(Predicate) total size", get_total(A.begin(), A.end()), get_total(B.begin(), B.end()));

	std::cout << "---" << std::endl;

	A.push_back(99);
	B.push_back(99);
	A.push_front(12);
	B.push_front(12);
	A.push_front(0);
	B.push_front(0);
	A.sort(is_sup);
	B.sort(is_sup);
	CHECK(".sort(Compare)", A.size(), B.size());
	CHECK(".sort(Compare) total size", get_total(A.begin(), A.end()), get_total(B.begin(), B.end()));
	CHECK(".begin() value", *A.begin(), *B.begin());
	CHECK("last value", *(--A.end()), *(--B.end()));
	CHECK(".end() value", *A.end(), *B.end());
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
void list_advanced(std::string type)
{
	g_total = 0;
	g_suc = 0;
	ft::List<T> A(40, 200);
	std::list<T> B(40, 200);
	CHECK(".size()", A.size(), B.size());

	A.push_back(5);
	A.push_front(10);
	B.push_back(5);
	B.push_front(10);
	CHECK(".push_front()", *(A.begin()), *(B.begin()));
	CHECK(".push_back()", *(--A.end()), *(--B.end()));

	std::cout << "---" << std::endl;

	A.remove(200);
	B.remove(200);
	CHECK(".remove()", get_total(A.begin(), A.end()), get_total(B.begin(), B.end()));

	std::cout << "---" << std::endl;

	A.reverse();
	B.reverse();
	CHECK(".reverse() -- begin", *(A.begin()), *(B.begin()));
	CHECK(".reverse() -- end", *(--A.end()), *(--B.end()));

	std::cout << "---" << std::endl;

	A.push_front(6);
	A.push_front(6);
	B.push_front(6);
	B.push_front(6);
	A.unique();
	B.unique();
	CHECK(".unique()", get_total(A.begin(), A.end()), get_total(B.begin(), B.end()));

	std::cout << "---" << std::endl;

	A.sort();
	B.sort();
	CHECK(".sort() -- begin", *(A.begin()), *(B.begin()));
	CHECK(".sort() -- mid", *(++A.begin()), *(++B.begin()));
	CHECK(".sort() -- end", *(--A.end()), *(--B.end()));

	CHECK(".size()", A.size(), B.size());
	CHECK(".rbegin()", *(A.rbegin()), *(B.rbegin()));
	CHECK(".rend()", *(--A.rend()), *(--B.rend()));

//Please comment the line just under if the List type is not int, or edit the 3 bool funciton in global.hpp
	list_adv_int(A, B);

	RES("Advanced<" +type+ ">");
	std::cout << std::endl;
}

template<typename T>
void list_assign(std::string type)
{
	g_total = 0;
	g_suc = 0;
	ft::List<T> A(40, 200);
	std::list<T> B(40, 200);
	ft::List<T> A2(60, 999);
	std::list<T> B2(60, 999);

	B.assign(20, 100);
	A.assign(20, 100);
	CHECK(".assign() -- size", A.size(), B.size());
	CHECK(".assign() total size", get_total(A.begin(), A.end()), get_total(B.begin(), B.end()));
	CHECK(".assign() -- .begin() value", *A.begin(), *B.begin());
	CHECK(".assign() -- last value", *(--A.end()), *(--B.end()));
	CHECK(".assign() .end() value", *A.end(), *B.end());

	std::cout << "---" << std::endl;

	A.assign((++(++(++A2.begin()))), (--(--(--A2.end()))));
	B.assign((++(++(++B2.begin()))), (--(--(--B2.end()))));
	CHECK(".assign(iterator) -- size", A.size(), B.size());
	CHECK(".assign(iterator) total size", get_total(A.begin(), A.end()), get_total(B.begin(), B.end()));
	CHECK(".assign(iterator) -- .begin() value", *A.begin(), *B.begin());
	CHECK(".assign(iterator) -- last value", *(--A.end()), *(--B.end()));
	CHECK(".assign(iterator) .end() value", *A.end(), *B.end());

	RES("Assign<" +type+ ">");
	std::cout << std::endl;
}

template<typename T>
void list_splice(std::string type)
{
	g_total = 0;
	g_suc = 0;
	ft::List<T> A(40, 200);
	std::list<T> B(40, 200);
	ft::List<T> A2(60, 999);
	std::list<T> B2(60, 999);

	A.splice(--A.end(), A2);
	B.splice(--B.end(), B2);
	CHECK(".splice(List 1) -- size", A.size(), B.size());
	CHECK(".splice(List 1) total size", get_total(A.begin(), A.end()), get_total(B.begin(), B.end()));
	CHECK(".splice(List 1) -- .begin() value", *A.begin(), *B.begin());
	CHECK(".splice(List 1) -- last value", *(--A.end()), *(--B.end()));
	CHECK(".splice(List 1) .end() value", *A.end(), *B.end());
	std::cout << "---" << std::endl;
	CHECK(".splice(List 2) -- size", A2.size(), B2.size());
	CHECK(".splice(List 2) total size", get_total(A2.begin(), A2.end()), get_total(B2.begin(), B2.end()));
	CHECK(".splice(List 2) -- .begin() value", *A2.begin(), *B2.begin());
	CHECK(".splice(List 2) -- last value", *(--A2.end()), *(--B2.end()));
	CHECK(".splice(List 2) .end() value", *A2.end(), *B2.end());
	RES("Splice<" +type+ ">");
	std::cout << std::endl;
}

template<typename T>
void list_all(std::string type)
{
	list_explicit_size_constructor<T>(type);
	list_explicit_fill_constructor<T>(type);
	list_copy_constructor<T>(type);
	list_pop_push<T>(type);
	list_insert<T>(type);
	list_resize<T>(type);
	list_advanced<T>(type);
	list_assign<T>(type);
	list_splice<T>(type);
}