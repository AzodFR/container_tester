#include "global.hpp"
#include "Map.hpp"
#include <map>


template<typename T>
void map_empty_constructor(std::string type)
{
	g_total = 0;
	g_suc = 0;
	
	ft::Map<std::string, T> A;
	std::map<std::string, T> B;

	CHECK(".size()", A.size(), B.size());
	CHECK(".max_size()", A.max_size(), B.max_size());
	CHECK(".empty()", A.empty(), B.empty());


	RES("Map::Empty Constructor<\e[95mstd::string, " +type+ "\e[0m>");
	std::cout << std::endl;
}

template<typename T>
void map_range_constructor(std::string type)
{
	g_total = 0;
	g_suc = 0;

	ft::Map<std::string, T> C;
	std::map<std::string, T> D;
	for(int i = 0; i < 8; i++)
	{
			ft::pair<std::string, T> C2("test n" + std::to_string(i), i);
			std::pair<std::string, T> D2("test n"+ std::to_string(i), i);
			C.insert(C2);
			D.insert(D2);
	}

	ft::Map<std::string, T> A(C.begin(), C.end());
	std::map<std::string, T> B(D.begin(), D.end());
	CHECK(".size()", A.size(), B.size());
	CHECK(".max_size()", A.max_size(), B.max_size());
	CHECK(".empty()", A.empty(), B.empty());
	for(int i = 0; i < 8; i++)
	{
			CHECK(".count() " + std::to_string(i) + " in A && C", A.count("test n" + std::to_string(i)), C.count("test n" + std::to_string(i)))
			CHECK(".count() " + std::to_string(i) + " in A && D (real)", A.count("test n" + std::to_string(i)), B.count("test n" + std::to_string(i)))
	}
	
	RES("Map::Range Constructor<\e[95mstd::string, " +type+ "\e[0m>");
	std::cout << std::endl;
}

template<typename T>
void map_insert(std::string type)
{
	g_total = 0;
	g_suc = 0;
	
	ft::Map<std::string, T> A;
	std::map<std::string, T> B;

	std::cout<< std::endl << "--- check simple insert" << std::endl;
	ft::pair<std::string, T> C("test", 10);
	std::pair<std::string, T> D("test", 10);
	A.insert(C);
	B.insert(D);
	CHECK(".size()", A.size(), B.size());
	CHECK(".max_size()", A.max_size(), B.max_size());
	CHECK(".empty()", A.empty(), B.empty());
	

		std::cout  << std::endl << "--- check duplicate key"<< std::endl;
	A.insert(C);
	B.insert(D);
	CHECK(".size()", A.size(), B.size());
	CHECK(".max_size()", A.max_size(), B.max_size());
	CHECK(".empty()", A.empty(), B.empty());


		std::cout << std::endl << "--- check lot of key" << std::endl;
	for(int i = 0; i < 500; i++)
	{
			ft::pair<std::string, T> C2("test n" + std::to_string(i), i);
			std::pair<std::string, T> D2("test n"+ std::to_string(i), i);
			A.insert(C);
			B.insert(D);
	}
	CHECK(".size()", A.size(), B.size());
	CHECK(".max_size()", A.max_size(), B.max_size());
	CHECK(".empty()", A.empty(), B.empty());

		std::cout << std::endl << "--- check same key but negative" << std::endl;
	for(int i = 0; i < 500; i++)
	{
			ft::pair<std::string, T> C2("test n" + std::to_string(-i), -i);
			std::pair<std::string, T> D2("test n"+ std::to_string(-i), -i);
			A.insert(C);
			B.insert(D);
	}
	CHECK(".size()", A.size(), B.size());
	CHECK(".max_size()", A.max_size(), B.max_size());
	CHECK(".empty()", A.empty(), B.empty());


		std::cout << std::endl << "--- check duplicate (silent) " << std::endl;
	for(int i = -500; i < 500; i++)
	{
		S_CHECK(".count()", A.count("test n" + std::to_string(i)), B.count("test n" + std::to_string(i)));
	}
	CHECK(".count()", A.count(std::to_string(999999)), B.count(std::to_string(999999)));


	std::cout << std::endl << "--- check insert (iterator first, iterator last) (silent) " << std::endl;
	ft::Map<std::string, T> A2;
	std::map<std::string, T> B2;
	A2.insert(A.begin(), A.end());
	B2.insert(B.begin(), B.end());
	typename std::map<std::string, T>::iterator b_beg = B2.begin();
	typename ft::Map<std::string, T>::iterator a_beg = A2.begin();
	CHECK(".size()", A.size(), B.size());
	CHECK(".max_size()", A.max_size(), B.max_size());
	CHECK(".empty()", A.empty(), B.empty());
	while (a_beg != A2.end() && b_beg != B2.end())
	{
		S_CHECK("check_element ->first", a_beg->first, b_beg->first);
		S_CHECK("check_element ->second", a_beg->second, b_beg->second);
		a_beg++;
		b_beg++;
	}
	

	std::cout << std::endl << "--- check insert (iterator pos, pair) (silent) " << std::endl;
		a_beg = A.begin();
		b_beg = B.begin();
	for (int i = 600; i != 610; i++)
	{
		ft::pair<std::string, T> C3("at pos " + std::to_string(i), i);
		std::pair<std::string, T> D3("at pos "+ std::to_string(i), i);
		A.insert(a_beg, C3);
		B.insert(b_beg, D3);
		a_beg = A.begin();
		b_beg = B.begin();
		CHECK("count_element ["+ std::to_string(i) +"]", A.count("at pos " + std::to_string(i)), B.count("at pos " + std::to_string(i)));
	}

	RES("Map::Insert<\e[95mstd::string, " +type+ "\e[0m>");
	std::cout << std::endl;
}

template<typename T>
void map_erase(std::string type)
{
	g_total = 0;
	g_suc = 0;

	ft::Map<std::string, T> A;
	std::map<std::string, T> B;
	std::cout << std::endl << "--- check output of .erase(key)" << std::endl;
	for(int i = 0; i < 8; i++)
	{
		ft::pair<std::string, T> A2("test n" + std::to_string(i), i);
		std::pair<std::string, T> B2("test n"+ std::to_string(i), i);
		A.insert(A2);
		B.insert(B2);
	}
	for(int i = 2; i < 5; i++)
	{
		CHECK(".erase(key)", A.erase("test n" + std::to_string(i)), B.erase("test n" + std::to_string(i)));
	}
	CHECK(".size()", A.size(), B.size());
	CHECK(".max_size()", A.max_size(), B.max_size());
	CHECK(".empty()", A.empty(), B.empty());

		std::cout << std::endl << "--- check .erase(position)" << std::endl;
	A.erase(A.begin());
	B.erase(B.begin());
	CHECK(".size()", A.size(), B.size());
	CHECK(".max_size()", A.max_size(), B.max_size());
	CHECK(".empty()", A.empty(), B.empty());

		std::cout << std::endl << "--- check .erase(start, last)" << std::endl;
	A.erase(A.begin(), A.end());
	B.erase(B.begin(), B.end());
	CHECK(".size()", A.size(), B.size());
	CHECK(".max_size()", A.max_size(), B.max_size());
	CHECK(".empty()", A.empty(), B.empty());


	RES("Map::Erase<\e[95mstd::string, " +type+ "\e[0m>");
	std::cout << std::endl;
}

template<typename T>
void map_clear(std::string type)
{
	g_total = 0;
	g_suc = 0;

	ft::Map<std::string, T> A;
	std::map<std::string, T> B;

		std::cout << std::endl << "--- clear empty map" << std::endl;
	A.clear();
	B.clear();
	CHECK(".size()", A.size(), B.size());
	CHECK(".max_size()", A.max_size(), B.max_size());
	CHECK(".empty()", A.empty(), B.empty());

		std::cout << std::endl << "--- clear filled map" << std::endl;
	for(int i = 0; i < 498; i++)
	{
		ft::pair<std::string, T> A2("test n" + std::to_string(i), i);
		std::pair<std::string, T> B2("test n"+ std::to_string(i), i);
		A.insert(A2);
		B.insert(B2);
	}
	A.clear();
	B.clear();
	CHECK(".size()", A.size(), B.size());
	CHECK(".max_size()", A.max_size(), B.max_size());
	CHECK(".empty()", A.empty(), B.empty());

	RES("Map::Clear<\e[95mstd::string, " +type+ "\e[0m>");
	std::cout << std::endl;
}

template<typename T>
void map_swap(std::string type)
{
	g_total = 0;
	g_suc = 0;

	ft::Map<std::string, T> A;
	std::map<std::string, T> B;
	for(int i = 0; i < 498; i++)
	{
		ft::pair<std::string, T> A2("first n" + std::to_string(i), i);
		std::pair<std::string, T> B2("first n"+ std::to_string(i), i);
		A.insert(A2);
		B.insert(B2);
	}
	ft::Map<std::string, T> C;
	std::map<std::string, T> D;
	for(int i = 0; i < 498; i++)
	{
		ft::pair<std::string, T> A2("second n" + std::to_string(i), i);
		std::pair<std::string, T> B2("second n"+ std::to_string(i), i);
		C.insert(A2);
		D.insert(B2);
	}
	A.swap(C);
	B.swap(D);
		std::cout << std::endl << "--- swap check A" << std::endl;
	CHECK(".size()", A.size(), B.size());
	CHECK(".max_size()", A.max_size(), B.max_size());
	CHECK(".empty()", A.empty(), B.empty());
	CHECK(".count() second in  A", A.count("second n" + std::to_string(245)),B.count("second n" + std::to_string(245)));
	CHECK(".count() first in A", A.count("first n" + std::to_string(245)),B.count("first n" + std::to_string(245)));

		std::cout << std::endl << "--- swap check B" << std::endl;
	CHECK(".size()", C.size(), D.size());
	CHECK(".max_size()", C.max_size(), D.max_size());
	CHECK(".empty()", C.empty(), D.empty());
	CHECK(".count() second in  B", C.count("second n" + std::to_string(245)),D.count("second n" + std::to_string(245)));
	CHECK(".count() first in B", C.count("first n" + std::to_string(245)),D.count("first n" + std::to_string(245)));

	std::cout << std::endl << "--- Hardcore	" << std::endl;
	A.clear();
	B.clear();
	A.swap(C);
	B.swap(D);
	std::cout << std::endl << "--- swap check A" << std::endl;
	CHECK(".size()", A.size(), B.size());
	CHECK(".max_size()", A.max_size(), B.max_size());
	CHECK(".empty()", A.empty(), B.empty());
	CHECK(".count() second in  A", A.count("second n" + std::to_string(245)),B.count("second n" + std::to_string(245)));
	CHECK(".count() first in A", A.count("first n" + std::to_string(245)),B.count("first n" + std::to_string(245)));

		std::cout << std::endl << "--- swap check B (must be clear)" << std::endl;
	CHECK(".size()", C.size(), D.size());
	CHECK(".max_size()", C.max_size(), D.max_size());
	CHECK(".empty()", C.empty(), D.empty());
	CHECK(".count() second in  B", C.count("second n" + std::to_string(245)),D.count("second n" + std::to_string(245)));
	CHECK(".count() first in B", C.count("first n" + std::to_string(245)),D.count("first n" + std::to_string(245)));


	RES("Map::Swap<\e[95mstd::string, " +type+ "\e[0m>");
	std::cout << std::endl;
}

template<typename T>
void map_bound(std::string type)
{
	g_total = 0;
	g_suc = 0;
	std::string str[] = {"zero", "one", "two", "three"};
	ft::Map<std::string, T> A;
	std::map<std::string, T> B;

	for (int i = 0; i < 4; i++)
	{
		ft::pair<std::string, T> A2(str[i], i);
		std::pair<std::string, T> B2(str[i], i);
		A.insert(A2);
		B.insert(B2);
	}
	for (int i = 0; i < 4; i++)
	{
		CHECK(".lower_bound(" + str[i] +")", A.lower_bound(str[i])->first, B.lower_bound(str[i])->first);
		CHECK(".upper_bound(" + str[i]+")", A.upper_bound(str[i])->first, B.upper_bound(str[i])->first);
		CHECK(".lower_bound(" + str[i] +")", A.lower_bound(str[i])->second, B.lower_bound(str[i])->second);
		CHECK(".upper_bound(" + str[i]+")", A.upper_bound(str[i])->second, B.upper_bound(str[i])->second);
	}

	RES("Map::Upper/Lower Bound<\e[95mstd::string, " +type+ "\e[0m>");
	std::cout << std::endl;
}

template<typename T>
void map_all(std::string type)
{
		std::cout << "\e[91m=================== MAP ===================\e[0m" << std::endl;
	map_empty_constructor<T>(type);
	map_range_constructor<T>(type);
	map_insert<T>(type);
	map_erase<T>(type);
	map_swap<T>(type);
	map_bound<T>(type);
}