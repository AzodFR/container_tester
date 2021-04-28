#include "global.hpp"
#include "Stack.hpp"
#include <stack>

template<typename T>
void stack_constructor_empty(std::string type)
{
	g_total = 0;
	g_suc = 0;

	ft::Stack<T> A;
	std::stack<T> B;
	ft::Stack<T> C;
	std::stack<T> D;
	CHECK(".size()",A.size(), B.size());
	CHECK(".empty()", A.empty(), B.empty());
	bool oui = (A == C);
	CHECK(" == ", oui, 1);

	RES("Empty constructor<\e[95m" +type+ "\e[0m>");
	std::cout << std::endl;
}

template<typename T>
void stack_all(std::string type)
{
	std::cout << "\e[91m=================== STACK ===================\e[0m" << std::endl;
	stack_constructor_empty<T>(type);
}