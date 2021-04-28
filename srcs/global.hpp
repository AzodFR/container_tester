#ifndef GLOBAL_HPP
# define GLOBAL_HPP

int g_total;
int g_suc;
int g_t;
int g_s;
std::string g_last;

# define CHECK(str, x, y) g_last = str; if (x == y) print(str, 1); else {print(str, 0); std::cout << "\e[90m[Excepted: "<< y << " | You: " << x << "]\e[0m" << std::endl;}
# define RES(str) std::cout << str << ": "; if (g_suc == g_total) std::cout << "\e[92m"; else std::cout << "\e[91m"; std::cout << g_suc << "/" << g_total << "\e[0m" << std::endl;
# define TOTAL() std::cout << "Total: "; if (g_s == g_t) std::cout << "\e[92m"; else std::cout << "\e[91m"; std::cout << g_s << "/" << g_t << "\e[0m" << std::endl;

void print(std::string str, int res)
{
	g_total++;
	std::cout << "\e[93m" << str << "\e[0m => ";
	if (res && ++g_suc && ++g_s)
		std::cout << "\e[92mOK !\e[0m" << std::endl;
	else
		std::cout << "\e[91mKO !\e[0m" << std::endl;
	g_t++;
}


void sigs(int signal)
{
	int list[] = {SIGSEGV, SIGABRT, SIGBUS};
	std::string msg [] = {"SEGV", "ABRT", "BUS"};
	
	for (size_t i = 0; i < 3; i++)
		if (list[i] == signal)
			std::cout << "[\e[93m" << msg[i] << "\e[0m] \e[90m//Last test -> " << g_last << "\e[0m" << std::endl;

	exit(1);
}


bool is_even(int x){return (x% 2 == 0);}


bool abs_equ(int x, int y){return (x == y ? true : x == -y ? true : false);}

bool abs_sort(int x, int y){ if (x < 0) x = -x; if (y < 0) y = -y; return (x < y);}
bool is_sup(int x, int y){return (x > y);}
#endif