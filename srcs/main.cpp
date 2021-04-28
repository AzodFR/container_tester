#include <iostream>
#include "global.hpp"

#include "List_Tests.hpp"
#include "Stack_Tests.hpp"

int main()
{
	g_t = 0;
	g_s = 0;
	g_last = "";
	signal(SIGSEGV, sigs);
	signal(SIGABRT, sigs);
	signal(SIGBUS, sigs);

	list_all<int>("int");
	stack_all<int>("int");
	TOTAL();
	std::cout << "\e[0m";
	return (0);
}