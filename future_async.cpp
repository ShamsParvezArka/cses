#include <iostream>
#include <future>
#include <ranges>

bool is_prime(int x) {
	for (auto i: std::views::iota(2, x)) {
		if (x % i == 0)
			return false;
	}
	return true;
}

int main() 
{
	int x = 100823;

	std::future<bool> future = std::async(is_prime, x);
	bool return_type = future.get();

	if (return_type)
		printf("%d is a prime number\n", x);
	else 
		printf("%d is not a prime number\n", x);

	return 0;
}
