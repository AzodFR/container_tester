#include "global.hpp"
#include "Queue2.hpp"
#include <queue>
#include <deque>

template<typename T>
void queue_constructor_empty(std::string type)
{
	g_total = 0;
	g_suc = 0;

	ft::Queue<T> A;
	std::queue<T> B;
	ft::Queue<T> C;
	std::queue<T> D;
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

	RES("Queue::Empty constructor<\e[95m" +type+ "\e[0m>");
	std::cout << std::endl;
}

template<typename T>
void queue_contructor_from_deque(std::string type)
{
	g_total = 0;
	g_suc = 0;

	std::deque<T> example (3, 92);
	ft::Queue<T> A (example);
	std::queue<T> B (example);

	CHECK(".size()",A.size(), B.size());
	CHECK(".empty()", A.empty(), B.empty());
	CHECK(".front()", A.front(), B.front());
	CHECK(".back()", A.back(), B.back());
		std::cout << "---" << std::endl;
	A.pop();
	B.pop();
	CHECK(".size() after 1 pop",A.size(), B.size());
	CHECK(".empty() after 1 pop", A.empty(), B.empty());
	CHECK(".front() after 1 pop", A.front(), B.front());
	CHECK(".back() after 1 pop", A.back(), B.back());
		std::cout << "---" << std::endl;
	A.pop();
	B.pop();
	CHECK(".size() after 2 pop",A.size(), B.size());
	CHECK(".empty() after 2 pop", A.empty(), B.empty());
	CHECK(".front() after 2 pop", A.front(), B.front());
	CHECK(".back() after 2 pop", A.back(), B.back());
		std::cout << "---" << std::endl;
	A.pop();
	B.pop();
	CHECK(".size() after 3 pop",A.size(), B.size());
	CHECK(".empty() after 3 pop", A.empty(), B.empty());

	RES("Queue::Constructor from deque<\e[95m" +type+ "\e[0m>");
	std::cout << std::endl;
}

template<typename T>
void queue_contructor_by_copy(std::string type)
{
	g_total = 0;
	g_suc = 0;

	std::deque<T> example (3, 92);
	ft::Queue<T> A (example);
	std::queue<T> B (example);
	ft::Queue<T> C (A);
	std::queue<T> D (B);

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

	RES("Queue::Constructor by copy<\e[95m" +type+ "\e[0m>");
	std::cout << std::endl;
}

template<typename T>
void queue_contructor_by_assign(std::string type)
{
	g_total = 0;
	g_suc = 0;

	std::deque<T> example (3, 92);
	ft::Queue<T> A (example);
	std::queue<T> B (example);
	ft::Queue<T> C = A;
	std::queue<T> D = B;

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

	RES("Queue::Constructor by assignation<\e[95m" +type+ "\e[0m>");
	std::cout << std::endl;
}

template<typename T>
void queue_push(std::string type)
{
	g_total = 0;
	g_suc = 0;

	ft::Queue<T> A;
	std::queue<T> B;

	int i = 1;
	while ( i * 15 < 100)
	{
		if (i > 1)
			std::cout << "---" << std::endl;
		A.push(i * 15);
		B.push(i * 15);
		std::string text = ".front() after ";
		text += std::to_string(i);
		text += " push";
		std::string text2 = ".back() after ";
		text2 += std::to_string(i++);
		text2 += " push";
		CHECK(".size()",A.size(), B.size());
		CHECK(".empty()", A.empty(), B.empty());
		CHECK(text , A.front(), B.front());
		CHECK(text2 , A.back(), B.back());
	}

	RES("Queue::Push<\e[95m" +type+ "\e[0m>");
	std::cout << std::endl;
}

template<typename T>
void queue_all(std::string type)
{
	std::cout << "\e[91m=================== QUEUE ===================\e[0m" << std::endl;
	queue_constructor_empty<T>(type);
	queue_contructor_from_deque<T>(type);
	queue_contructor_by_copy<T>(type);
	queue_contructor_by_assign<T>(type);
	queue_push<T>(type);
}