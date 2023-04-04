/*
 * Codeforces Round 863 (Div. 3)
 * Problem A: Insert Digit
 * Link: https://codeforces.com/contest/1811/problem/A
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	size_t test_case;
	std::cin >> test_case;
	size_t n, d;
	while (test_case--) {
		scanf("%ld %ld", &n, &d);
		std::string s;
		std::cin >> s;

		std::vector<int> vec;
		for (size_t i = 0; i < n; i++) {
			vec.push_back((int)(s[i] - '0'));
		}

		int max = *std::max_element(vec.begin(), vec.end());
		int min = *std::min_element(vec.begin(), vec.end());

		if (d >= max)
			vec.insert(vec.begin(), d);
		else if (d <= min)
			vec.insert(vec.end(), d);
		else {
			for (size_t i = 0; i < n; i++) {
				if (d > vec[i]) {
					vec.insert(vec.begin() + i, d);
					break;
				}
			}
		}

		for (auto i: vec)
			std::cout << i;
		printf("\n");
	}

	return 0;
}
