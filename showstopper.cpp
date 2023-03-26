/*
 * Codeforces Codeforces Round 860(Div.2)
 * Problem A: Showstopper
 * Link: https://codeforces.com/contest/1798/problem/A
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include <vector>
#include <map>
#include <cstdbool>

int main()
{
	int test_case;
	std::cin >> test_case;
	while (test_case--) {
		int N;
		bool is_possible = 0;
		std::cin >> N;
		std::vector<int> vec1;
		std::vector<int> vec2;
		for (int i = 0; i < N; i++) {
			int input;
			std::cin >> input;
			vec1.push_back(input);
		}
		for (int i = 0; i < N; i++) {
			int input;
			std::cin >> input;
			vec2.push_back(input);
		}
		int an = vec1.back();
		int bn = vec2.back();
		//std::cout << an << ' '<< bn << std::endl;

		for (int i = 0; i < N; i++) {
			std::swap(vec1[i], vec2[i]);
			int maxA = *std::max_element(vec1.begin(), vec1.end());
			int maxB = *std::max_element(vec2.begin(), vec2.end());
			if (maxA == an && maxB == bn) {
				is_possible = !is_possible;
				break;
			}
		}

		if (is_possible == true) {
			std::cout << "YES" << std::endl;
			is_possible = !is_possible;
		}
		else 
			std::cout << "NO" << std::endl;

		vec1.erase(vec1.begin(), vec1.end());
		vec2.erase(vec2.begin(), vec2.end());
	}

	return 0;
}
