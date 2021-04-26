#include <iostream>
#include "global.hpp"

#include "List_Tests.hpp"

int main()
{
	g_t = 0;
	g_s = 0;
	list_all<int>("int");
	TOTAL();
	std::cout << "\e[0m";
	return (0);
}