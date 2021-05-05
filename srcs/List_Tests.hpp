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

	RES("List::Explicit Size Constructor<\e[95m" +type+ "\e[0m>");
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

	RES("List::Explicit Fill Constructor<\e[95m" +type+ "\e[0m>");
	std::cout << std::endl;
}

template<typename T>
void list_explicit_range_constructor(std::string type)
{
	g_total = 0;
	g_suc = 0;

	ft::List<T> C(6, 100);
	std::list<T> D(6, 100);
	ft::List<T> Ar(C.begin(), C.end());
	std::list<T> Br(D.begin(), D.end());

std::cout << C.size() << std::endl;
std::cout <<Ar.size() << std::endl;

	CHECK(".size()",Ar.size(), Br.size());
	CHECK(".max_size()", Ar.max_size(), Br.max_size());
	CHECK(".begin() value", *Ar.begin(), *Br.begin());
	CHECK(".end() value", *Ar.end(), *Br.end());
	CHECK(".empty()", Ar.empty(), Br.empty());
	CHECK("total value", get_total(Ar.begin(), Ar.end()), get_total(Br.begin(), Br.end()));

	RES("List::Explicit Range Constructor<\e[95m" +type+ "\e[0m>");
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

	RES("List::Copy Constructor<\e[95m" +type+ "\e[0m>");	
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

	RES("List::Pop & Push<\e[95m" +type+ "\e[0m>");
	std::cout << std::endl;
}

template <typename T>
void list_front_back(std::string type)
{
	g_total = 0;
	g_suc = 0;
	ft::List<T> A(1, 9);
	std::list<T> B(1, 9);

	A.push_back(1);
	B.push_back(1);
	CHECK(".front()", A.front(), B.front());
	CHECK(".back()", A.back(), B.back());
	RES("List::Front & Back<\e[95m" +type+ "\e[0m>");
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
	RES("List::Insert<\e[95m" +type+ "\e[0m>");
	std::cout << std::endl;
}

template<typename T>
void list_adv_int(ft::List<T> A, std::list<T> B)
{
	std::cout << "---" << std::endl;


	typename ft::List<T>::iterator A_end = A.end();
	typename std::list<T>::iterator B_end = B.end();
	A.push_front(-5);
	B.push_front(-5);
	typename ft::List<T>::iterator A_begin = A.begin();
	typename std::list<T>::iterator B_begin = B.begin();
	A.unique(abs_equ);
	B.unique(abs_equ);
	CHECK(".unique(Predicate)", A.size(), B.size());
	CHECK(".unique(Predicate) total size", get_total(A.begin(), A.end()), get_total(B.begin(), B.end()));
	std::cout << "---" << std::endl;
	CHECK("iterator still valid", *A_begin, *B_begin);
	CHECK("iterator still valid total size", get_total(A_begin, A_end), get_total(B_begin, B_end));

	std::cout << "---" << std::endl;

	A_begin = A.begin();
	B_begin = B.begin();
	A.remove_if(is_even);
	B.remove_if(is_even);
	CHECK(".remove_if(Predicate)", A.size(), B.size());
	CHECK(".remove_if(Predicate) total size", get_total(A.begin(), A.end()), get_total(B.begin(), B.end()));
	std::cout << "---" << std::endl;
	CHECK("iterator still valid", *A_begin, *B_begin);
	CHECK("iterator still valid total size", get_total(A_begin, A_end), get_total(B_begin, B_end));

	std::cout << "---" << std::endl;

	A.push_back(99);
	B.push_back(99);
	A.push_front(12);
	B.push_front(12);
	A.push_back(0);
	B.push_back(0);
	A_begin = A.begin();
	B_begin = B.begin();
	A.sort(is_sup);
	B.sort(is_sup);
	CHECK(".sort(Compare)", A.size(), B.size());
	CHECK(".sort(Compare) total size", get_total(A.begin(), A.end()), get_total(B.begin(), B.end()));
	CHECK(".begin() value", *A.begin(), *B.begin());
	CHECK("last value", *(--A.end()), *(--B.end()));
	CHECK(".end() value", *A.end(), *B.end());
	std::cout << "---" << std::endl;
	CHECK("iterator still valid", *A_begin, *B_begin);
	CHECK("iterator still valid total size", get_total(A_begin, A_end), get_total(B_begin, B_end));
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
	RES("List::Resize<\e[95m" +type+ "\e[0m>");
	std::cout << std::endl;
}

template<typename T>
void list_advanced(std::string type)
{
	g_total = 0;
	g_suc = 0;
	ft::List<T> A(40, 200);
	std::list<T> B(40, 200);

	typename ft::List<T>::iterator A_end = A.end();
	typename std::list<T>::iterator B_end = B.end();
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

	typename ft::List<T>::iterator A_begin = A.begin();
	typename std::list<T>::iterator B_begin = B.begin();
	A.reverse();
	B.reverse();
	CHECK(".reverse() -- begin", *(A.begin()), *(B.begin()));
	CHECK(".reverse() -- end", *(--A.end()), *(--B.end()));
	std::cout << "---" << std::endl;
	CHECK("iterator still valid", *A_begin, *B_begin);
	CHECK("iterator still valid total size", get_total(A_begin, A_end), get_total(B_begin, B_end));

	std::cout << "---" << std::endl;

	A.push_front(6);
	A.push_front(6);
	B.push_front(6);
	B.push_front(6);
	A_begin = A.begin();
	B_begin = B.begin();
	A.unique();
	B.unique();
	CHECK(".unique()", get_total(A.begin(), A.end()), get_total(B.begin(), B.end()));
	std::cout << "---" << std::endl;
	CHECK("iterator still valid", *A_begin, *B_begin);
	CHECK("iterator still valid total size", get_total(A_begin, A_end), get_total(B_begin, B_end));

	std::cout << "---" << std::endl;

	A_begin = A.begin();
	B_begin = B.begin();
	A.sort();
	B.sort();
	CHECK(".sort() -- begin", *(A.begin()), *(B.begin()));
	CHECK(".sort() -- mid", *(++A.begin()), *(++B.begin()));
	CHECK(".sort() -- end", *(--A.end()), *(--B.end()));
	std::cout << "---" << std::endl;
	CHECK("iterator still valid", *A_begin, *B_begin);
	CHECK("iterator still valid total size", get_total(A_begin, A_end), get_total(B_begin, B_end));

	CHECK(".size()", A.size(), B.size());
	CHECK(".rbegin()", *(A.rbegin()), *(B.rbegin()));
	CHECK(".rend()", *(--A.rend()), *(--B.rend()));

//Please comment the line just under if the List type is not int, or edit the 3 bool funciton in global.hpp
	list_adv_int(A, B);

	RES("List::Advanced<\e[95m" +type+ "\e[0m>");
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
	typename ft::List<T>::iterator A_begin = A2.begin();
	typename std::list<T>::iterator B_begin = B2.begin();
	typename ft::List<T>::iterator A_end = --A2.end();
	typename std::list<T>::iterator B_end = --B2.end();

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
		std::cout << "---" << std::endl;
	CHECK("iterator still valid", *A_begin, *B_begin);
	CHECK("iterator still valid total size", get_total(A_begin, A_end), get_total(B_begin, B_end));

	RES("List::Assign<\e[95m" +type+ "\e[0m>");
	std::cout << std::endl;
}

template<typename T>
void list_splice(std::string type)
{
	g_total = 0;
	g_suc = 0;
	ft::List<T> A(40, 333);
	std::list<T> B(40, 333);
	ft::List<T> A2(60, 999);
	std::list<T> B2(60, 999);
	ft::List<T> A3(20, 666);
	std::list<T> B3(20, 666);
	ft::List<T> A4(80, 369);
	std::list<T> B4(80, 369);
	typename ft::List<T>::iterator A_begin = A2.begin();
	typename std::list<T>::iterator B_begin = B2.begin();
	typename ft::List<T>::iterator A_end = --A2.end();
	typename std::list<T>::iterator B_end = --B2.end();

	A.splice(--A.end(), A2);
	B.splice(--B.end(), B2);
	CHECK(".splice(iterator pos, other list) -- size (list 1)", A.size(), B.size());
	CHECK(".splice(iterator pos, other list) total size (list 1)", get_total(A.begin(), A.end()), get_total(B.begin(), B.end()));
	CHECK(".splice(iterator pos, other list) -- .begin() value (list 1)", *A.begin(), *B.begin());
	CHECK(".splice(iterator pos, other list) -- last value (list 1)", *(--A.end()), *(--B.end()));
	CHECK(".splice(iterator pos, other list) .end() value (list 1)", *A.end(), *B.end());
		std::cout << "---" << std::endl;
	CHECK(".splice(iterator pos, other list) -- size (list 2)", A2.size(), B2.size());
	CHECK(".splice(iterator pos, other list) total size (list 2)", get_total(A2.begin(), A2.end()), get_total(B2.begin(), B2.end()));
	CHECK(".splice(iterator pos, other list) -- .begin() value (list 2)", *A2.begin(), *B2.begin());
	CHECK(".splice(iterator pos, other list) -- last value (list 2)", *(--A2.end()), *(--B2.end()));
	CHECK(".splice(iterator pos, other list) .end() value (list 2)", *A2.end(), *B2.end());
		std::cout << "---" << std::endl;
	CHECK("iterator still valid", *A_begin, *B_begin);
	CHECK("iterator still valid total size", get_total(A_begin, A_end), get_total(B_begin, B_end));

		std::cout << "---" << std::endl;
	A_begin = A.begin();
	B_begin = B.begin();
	A.splice(++A.begin(), A3, --A3.end());
	B.splice(++B.begin(), B3, --B3.end());
	CHECK(".splice(iterator pos, other list, iterator elem) -- size (list 1)", A.size(), B.size());
	CHECK(".splice(iterator pos, other list, iterator elem) total size (list 1)", get_total(A.begin(), A.end()), get_total(B.begin(), B.end()));
	CHECK(".splice(iterator pos, other list, iterator elem) -- .begin() value (list 1)", *A.begin(), *B.begin());
	CHECK(".splice(iterator pos, other list, iterator elem) -- last value (list 1)", *(--A.end()), *(--B.end()));
	CHECK(".splice(iterator pos, other list, iterator elem) .end() value (list 1)", *A.end(), *B.end());
		std::cout << "---" << std::endl;
	CHECK(".splice(iterator pos, other list, iterator elem) -- size (list 2)", A3.size(), B3.size());
	CHECK(".splice(iterator pos, other list, iterator elem) total size (list 2)", get_total(A3.begin(), A3.end()), get_total(B3.begin(), B3.end()));
	CHECK(".splice(iterator pos, other list, iterator elem) -- .begin() value (list 2)", *A3.begin(), *B3.begin());
	CHECK(".splice(iterator pos, other list, iterator elem) -- last value (list 2)", *(--A3.end()), *(--B3.end()));
	CHECK(".splice(iterator pos, other list, iterator elem) .end() value (list 2)", *A3.end(), *B3.end());
		std::cout << "---" << std::endl;
	CHECK("iterator still valid", *A_begin, *B_begin);
	CHECK("iterator still valid total size", get_total(A_begin, A_end), get_total(B_begin, B_end));

		std::cout << "---" << std::endl;
	A.splice(--(--(A.end())), A4, ++A4.begin(), A4.end());
	B.splice(--(--(B.end())), B4, ++B4.begin(), B4.end());
	CHECK(".splice(iterator pos, other list, iterator start, iterator end) -- size (list 1)", A.size(), B.size());
	CHECK(".splice(iterator pos, other list, iterator start, iterator end) total size (list 1)", get_total(A.begin(), A.end()), get_total(B.begin(), B.end()));
	CHECK(".splice(iterator pos, other list, iterator start, iterator end) -- .begin() value (list 1)", *A.begin(), *B.begin());
	CHECK(".splice(iterator pos, other list, iterator start, iterator end) -- last value (list 1)", *(--A.end()), *(--B.end()));
	CHECK(".splice(iterator pos, other list, iterator start, iterator end) .end() value (list 1)", *A.end(), *B.end());
		std::cout << "---" << std::endl;
	CHECK(".splice(iterator pos, other list, iterator start, iterator end) -- size (list 2)", A4.size(), B4.size());
	CHECK(".splice(iterator pos, other list, iterator start, iterator end) total size (list 2)", get_total(A4.begin(), A4.end()), get_total(B4.begin(), B4.end()));
	CHECK(".splice(iterator pos, other list, iterator start, iterator end) -- .begin() value (list 2)", *A4.begin(), *B4.begin());
	CHECK(".splice(iterator pos, other list, iterator start, iterator end) -- last value (list 2)", *(--A4.end()), *(--B4.end()));
	CHECK(".splice(iterator pos, other list, iterator start, iterator end) .end() value (list 2)", *A4.end(), *B4.end());
		std::cout << "---" << std::endl;
	CHECK("iterator still valid", *A_begin, *B_begin);
	CHECK("iterator still valid total size", get_total(A_begin, A_end), get_total(B_begin, B_end));

	RES("List::Splice<\e[95m" +type+ "\e[0m>");
	std::cout << std::endl;
}

template<typename T>
void list_erase(std::string type)
{
	g_total = 0;
	g_suc = 0;
	ft::List<T> A(50, 106);
	std::list<T> B(50, 106);
	ft::List<T> A2(106, 50);
	std::list<T> B2(106, 50);
	typename ft::List<T>::iterator A_begin = A.begin();
	typename std::list<T>::iterator B_begin = B.begin();
	typename ft::List<T>::iterator A_end = A.end();
	typename std::list<T>::iterator B_end = B.end();


	A.erase(++A.begin());
	B.erase(++B.begin());
	CHECK(".erase(from 2nd element) -- size", A.size(), B.size());
	CHECK(".erase(from 2nd element) total size", get_total(A.begin(), A.end()), get_total(B.begin(), B.end()));
	CHECK(".erase(from 2nd element) -- .begin() value", *A.begin(), *B.begin());
	CHECK(".erase(from 2nd element) -- last value", *(--A.end()), *(--B.end()));
	CHECK(".erase(from 2nd element) .end() value", *A.end(), *B.end());
		std::cout << "---" << std::endl;
	CHECK("iterator still valid", *A_begin, *B_begin);
	CHECK("iterator still valid total size", get_total(A_begin, A_end), get_total(B_begin, B_end));
		std::cout << "---" << std::endl;
	A2.erase(A2.begin(), ++A2.begin());
	B2.erase(B2.begin(), ++B2.begin());
	typename ft::List<T>::reverse_iterator rA_begin = A2.rbegin();
	typename ft::List<T>::reverse_iterator rA_end = A2.rend();
	typename std::list<T>::reverse_iterator rB_end = B2.rend();
	typename std::list<T>::reverse_iterator rB_begin = B2.rbegin();
	CHECK(".erase(2 firsts elements) -- size", A2.size(), B2.size());
	CHECK(".erase(2 firsts elements) total size", get_total(A2.begin(), A2.end()), get_total(B2.begin(), B2.end()));
	CHECK(".erase(2 firsts elements) -- .begin() value", *A2.begin(), *B2.begin());
	CHECK(".erase(2 firsts elements) -- last value", *(--A2.end()), *(--B2.end()));
	CHECK(".erase(2 firsts elements) .end() value", *A2.end(), *B2.end());
			std::cout << "---" << std::endl;
	CHECK("reverse iterator still valid", *++rA_begin, *++rB_begin);
	CHECK("reverse iterator still valid total size", get_total(rA_begin, rA_end), get_total(rB_begin, rB_end));

	RES("List::Erase<\e[95m" +type+ "\e[0m>");
	std::cout << std::endl;
}

template<typename T>
void list_clear(std::string type)
{
	g_total = 0;
	g_suc = 0;
	ft::List<T> A(50, 106);
	std::list<T> B(50, 106);

	A.clear();
	B.clear();
	CHECK(".size()",A.size(), B.size());
	CHECK(".max_size()", A.max_size(), B.max_size());
	CHECK(".begin() value", *A.begin(), *B.begin());
	CHECK(".end() value", *A.end(), *B.end());
	CHECK(".empty()", A.empty(), B.empty());
	CHECK("total value", get_total(A.begin(), A.end()), get_total(B.begin(), B.end()));
	RES("List::Clear<\e[95m" +type+ "\e[0m>");
	std::cout << std::endl;
}

template<typename T>
void list_merge(std::string type)
{
	g_total = 0;
	g_suc = 0;
	ft::List<T> A;
	std::list<T> B;
	ft::List<T> C;
	std::list<T> D;

	A.push_front(8);
	B.push_front(8);
	A.push_back(6);
	B.push_back(6);
	A.insert(++A.begin(), 27);
	B.insert(++B.begin(), 27);

	C.push_back(2);
	D.push_back(2);
	C.push_front(5);
	D.push_front(5);
	C.insert(++C.begin(), 10);
	D.insert(++D.begin(), 10);

	A.sort();
	B.sort();
	C.sort();
	D.sort();

	CHECK(".size() after sort",A.size(), B.size());
	CHECK(".sort() begin",*A.begin(), *B.begin());
	CHECK(".sort() mid",*++A.begin(), *++B.begin());
	CHECK(".sort() end",*--A.end(), *--B.end());
	A.merge(C);
	B.merge(D);
	typename ft::List<T>::iterator C_begin = A.begin();
	typename ft::List<T>::iterator C_end = A.end();
	typename std::list<T>::iterator D_begin = B.begin();
	typename std::list<T>::iterator D_end = B.end();
	CHECK(".size()",A.size(), B.size());
	int i = 0;
	while (C_begin != C_end && D_begin != D_end)	
	{
		std::string text = ".merge() element [";
		text += std::to_string(i++);
		text += "]";
		CHECK(text, *C_begin, *D_begin);
		C_begin++;
		D_begin++;
	}
	CHECK(".end() value", *A.end(), *B.end());
	CHECK("total value", get_total(A.begin(), A.end()), get_total(B.begin(), B.end()));

		std::cout << "---" << std::endl;
	A.clear();
	B.clear();
	C.clear();
	D.clear();
	A.push_front(-5);
	A.push_back(6);
	A.insert(++A.begin(), 29);

	B.push_front(-5);
	B.push_back(6);
	B.insert(++B.begin(), 29);

	C.push_front(5);
	C.push_back(-9);
	D.push_front(5);
	D.push_back(-9);

	A.sort(abs_sort);
	B.sort(abs_sort);
	C.sort(abs_sort);
	D.sort(abs_sort);
	CHECK(".size() after sort",A.size(), B.size());
	CHECK(".sort(absolute) begin",*A.begin(), *B.begin());
	CHECK(".sort(absolute) mid",*++A.begin(), *++B.begin());
	CHECK(".sort(absolute) end",*--A.end(), *--B.end());
	A.merge(C, abs_sort);
	B.merge(D, abs_sort);
	C_begin = A.begin();
	C_end = A.end();
	D_begin = B.begin();
	D_end = B.end();
	CHECK(".size()",A.size(), B.size());
	i = 0;
	while (C_begin != C_end && D_begin != D_end)	
	{
		std::string text = ".merge(absolute) element [";
		text += std::to_string(i++);
		text += "]";
		CHECK(text, *C_begin, *D_begin);
		C_begin++;
		D_begin++;
	}
	CHECK(".end() value", *A.end(), *B.end());
	CHECK("total value", get_total(A.begin(), A.end()), get_total(B.begin(), B.end()));
	RES("List::Merge<\e[95m" +type+ "\e[0m>");
	std::cout << std::endl;
}

template<typename T>
void list_all(std::string type)
{
	std::cout << "\e[91m=================== LIST ===================\e[0m" << std::endl;
	list_explicit_size_constructor<T>(type);
	list_explicit_fill_constructor<T>(type);
	list_explicit_range_constructor<T>(type);
	list_copy_constructor<T>(type);
	list_pop_push<T>(type);
	list_front_back<T>(type);
	list_insert<T>(type);
	list_resize<T>(type);
	list_assign<T>(type);
	list_splice<T>(type);
	list_erase<T>(type);
	list_clear<T>(type);
	list_advanced<T>(type);
	list_merge<T>(type);
}