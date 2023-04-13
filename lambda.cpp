#include <iostream>
#include <functional>

int main() 
{
	std::function<size_t(size_t)> factorial = [&factorial](size_t n) {
		return n > 1 ? n * factorial(n - 1) : 1;
	};

	printf("%lu\n", factorial(3));

	return 0;
}
