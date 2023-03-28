/*
 * matrix: Templatised matrix operation functions (i.e. transpose, rotate90, flat)
 * Author: Shams Parvez Arka <parvez6826@gmail.com>
 */

#include <iostream>
#include <algorithm>
#include <vector>

template<typename T> std::vector<std::vector<int>> transpose(std::vector<std::vector<T>> &vec2D) {
	std::vector<std::vector<T>> vec(3);
	for (size_t i = 0; i < vec2D.size(); i++) {
		for (size_t j = 0; j < vec2D[i].size(); j++)
			vec[i].push_back(vec2D[j][i]);
	}
	vec2D = vec;
	vec.clear();
	return vec2D;
}

template<typename T> std::vector<std::vector<int>> rotate90(std::vector<std::vector<T>> &vec2D) {
	for (size_t i = 0; i < vec2D.size(); i++) {
		std::reverse(vec2D[i].begin(), vec2D[i].end());
	}
	return vec2D;
}

template<typename T> std::vector<T> flat(std::vector<std::vector<T>> vec2D) {
	std::vector<T> vec;
	for (auto row: vec2D) {
		for (auto col: row)
			vec.push_back(col);
	}
	return vec;
}

int main()
{
	std::vector<std::vector<int>> vec2D(3);
	int input;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cin >> input;
			vec2D[i].push_back(input);
		}
	}

	transpose<int> (vec2D);
	rotate90<int> (vec2D);
	std::vector<int> vec = flat<int> (vec2D);

	for (auto i: vec)
		std::cout << i;

	return 0;
}
