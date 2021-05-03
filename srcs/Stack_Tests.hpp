#include "global.hpp"
#include "Stack.hpp"
#include <stack>
#include <deque>

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

	bool ft = (A == C);
	bool real = (B == D);
	CHECK(" == ", ft, real);

	ft = (A != C);
	real = (B != D);
	CHECK(" != ", ft, real);

	ft = (A > C);
	real = (B > D);
	CHECK(" > ", ft, real);

	ft = (A < C);
	real = (B < D);
	CHECK(" < ", ft, real);

	ft = (A >= C);
	real = (B >= D);
	CHECK(" >=", ft, real);

	ft = (A <= C);
	real = (B <= D);
	CHECK(" <= ", ft, real);

	RES("Stack::Empty constructor<\e[95m" +type+ "\e[0m>");
	std::cout << std::endl;
}

template<typename T>
void stack_contructor_from_deque(std::string type)
{
	g_total = 0;
	g_suc = 0;

	std::deque<T> example (3, 92);
	ft::Stack<T> A (example);
	std::stack<T> B (example);

	CHECK(".size()",A.size(), B.size());
	CHECK(".empty()", A.empty(), B.empty());
	CHECK(".top()", A.top(), B.top());
		std::cout << "---" << std::endl;
	A.pop();
	B.pop();
	CHECK(".size() after 1 pop",A.size(), B.size());
	CHECK(".empty() after 1 pop", A.empty(), B.empty());
	CHECK(".top() after 1 pop", A.top(), B.top());
		std::cout << "---" << std::endl;
	A.pop();
	B.pop();
	CHECK(".size() after 2 pop",A.size(), B.size());
	CHECK(".empty() after 2 pop", A.empty(), B.empty());
	CHECK(".top() after 2 pop", A.top(), B.top());
		std::cout << "---" << std::endl;
	A.pop();
	B.pop();
	CHECK(".size() after 3 pop",A.size(), B.size());
	CHECK(".empty() after 3 pop", A.empty(), B.empty());

	RES("Stack::Constructor from deque<\e[95m" +type+ "\e[0m>");
	std::cout << std::endl;
}

template<typename T>
void stack_contructor_by_copy(std::string type)
{
	g_total = 0;
	g_suc = 0;

	std::deque<T> example (3, 92);
	ft::Stack<T> A (example);
	std::stack<T> B (example);
	ft::Stack<T> C (A);
	std::stack<T> D (B);

	CHECK(".size() ft vs std",A.size(), B.size());
	CHECK(".empty() ft vs std ", A.empty(), B.empty());
	CHECK(".size() ft vs ft",A.size(), C.size());
	CHECK(".empty() ft vs ft ", A.empty(), C.empty());

	bool ft = (A == C);
	bool real = (B == D);
	CHECK(" == ", ft, real);

	ft = (A != C);
	real = (B != D);
	CHECK(" != ", ft, real);

	ft = (A > C);
	real = (B > D);
	CHECK(" > ", ft, real);

	ft = (A < C);
	real = (B < D);
	CHECK(" < ", ft, real);

	ft = (A >= C);
	real = (B >= D);
	CHECK(" >=", ft, real);

	ft = (A <= C);
	real = (B <= D);
	CHECK(" <= ", ft, real);

	RES("Stack::Constructor by copy<\e[95m" +type+ "\e[0m>");
	std::cout << std::endl;
}

template<typename T>
void stack_contructor_by_assign(std::string type)
{
	g_total = 0;
	g_suc = 0;

	std::deque<T> example (3, 92);
	ft::Stack<T> A (example);
	std::stack<T> B (example);
	ft::Stack<T> C = A;
	std::stack<T> D = B;

	CHECK(".size() ft vs std",A.size(), B.size());
	CHECK(".empty() ft vs std ", A.empty(), B.empty());
	CHECK(".size() ft vs ft",A.size(), C.size());
	CHECK(".empty() ft vs ft ", A.empty(), C.empty());
	bool ft = (A == C);
	bool real = (B == D);
	CHECK(" == ", ft, real);

	ft = (A != C);
	real = (B != D);
	CHECK(" != ", ft, real);

	ft = (A > C);
	real = (B > D);
	CHECK(" > ", ft, real);

	ft = (A < C);
	real = (B < D);
	CHECK(" < ", ft, real);

	ft = (A >= C);
	real = (B >= D);
	CHECK(" >=", ft, real);

	ft = (A <= C);
	real = (B <= D);
	CHECK(" <= ", ft, real);

	RES("Stack::Constructor by assignation<\e[95m" +type+ "\e[0m>");
	std::cout << std::endl;
}

template<typename T>
void stack_push(std::string type)
{
	g_total = 0;
	g_suc = 0;

	ft::Stack<T> A;
	std::stack<T> B;

	int i = 1;
	while ( i * 15 < 100)
	{
		if (i > 1)
			std::cout << "---" << std::endl;
		A.push(i * 15);
		B.push(i * 15);
		std::string text = ".top() after ";
		text += std::to_string(i++);
		text += " push";
		CHECK(".size()",A.size(), B.size());
		CHECK(".empty()", A.empty(), B.empty());
		CHECK(text , A.top(), B.top());
	}

	RES("Stack::Push<\e[95m" +type+ "\e[0m>");
	std::cout << std::endl;
}

template<typename T>
void stack_all(std::string type)
{
	std::cout << "\e[91m=================== STACK ===================\e[0m" << std::endl;
	stack_constructor_empty<T>(type);
	stack_contructor_from_deque<T>(type);
	stack_contructor_by_copy<T>(type);
	stack_contructor_by_assign<T>(type);
	stack_push<T>(type);
}
