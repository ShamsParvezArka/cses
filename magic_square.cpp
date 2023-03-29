/*
 * matrix: Templatised matrix operation functions (i.e. refl, rot90, flat)
 * Author: Shams Parvez Arka <parvez6826@gmail.com>
 */

#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>

template<typename T> std::vector<std::vector<int>> refl(std::vector<std::vector<T>> &vec2D) {
	std::vector<std::vector<T>> vec(3);
	for (size_t i = 0; i < vec2D.size(); i++) {
		for (size_t j = 0; j < vec2D[i].size(); j++)
			vec[i].push_back(vec2D[j][i]);
	}
	vec2D = vec;
	vec.clear();
	return vec2D;
}

template<typename T> std::vector<std::vector<int>> rot90(std::vector<std::vector<T>> &vec2D) {
	refl<int> (vec2D);
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
	std::vector<int> input_square;
	int input;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cin >> input;
			input_square.push_back(input);
		}
	}
	std::vector<std::vector<int>> origin(3);
	origin = {
		{8, 1, 6},
		{3, 5, 7},
		{4, 9, 2}
	};
	
	std::vector<std::vector<int>> magic_squares(8);
	//generate first 4
	for (int i = 0; i < 4; i++) {
		magic_squares[i] = flat(origin);
		rot90(origin);
	}
	// Generate last 4
	for (int i = 4; i < 8; i++) {
		refl(origin);
		magic_squares[i] = flat(origin);
		refl(origin);
		rot90(origin);
	}

	std::vector<int> distences;
	std::vector<int> tmp;
	for (size_t i = 0; i < magic_squares.size(); i++) {
		for (size_t j = 0; j < magic_squares[i].size(); j++) {
			tmp.push_back(abs(input_square[j] - magic_squares[i][j]));
		}
		distences.push_back(std::accumulate(tmp.begin(), tmp.end(), 0));
		tmp.erase(tmp.begin(), tmp.end());
	}

	std::cout << *std::min_element(distences.begin(), distences.end());

	return 0;
}





