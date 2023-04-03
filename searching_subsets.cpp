/*
 * Finding all the subsets of a set
 * Soln: Bit shifting
 */

#include <iostream>
#include <vector>

void search(size_t n) {
	for (int b = 0; b < (1 << n); b++) {
		std::vector<int> subset;
		for (int i = 0; i < n; i++) {
			if (b & (1 << i))
				subset.push_back(i);
		}
		for (auto i: subset)
			std::cout << i << ' ';
		std::cout << '\n';
	}
}

int main()
{
	search(3); // {}, {0}, {1}, {2}, {0, 1}, {0, 2}, {1, 2}, {1, 2, 3} 
	return 0;
}
