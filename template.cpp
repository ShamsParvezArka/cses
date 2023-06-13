#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
#include <string>
#include <map>

template<typename T>
std::vector<T> slice_vector(std::vector<T>& vec, T a, T b) {
	auto start = vec.begin() + a;
	auto end = vec.begin() + b + 1;
	std::vector<T> sliced_vec(end - start);
	std::copy(start, end, sliced_vec.begin());

	return sliced_vec;
}

template<typename T> 
std::vector<std::vector<T>> refl(std::vector<std::vector<T>> &vec2D) {
	std::vector<std::vector<T>> vec(3);
	for (size_t i = 0; i < vec2D.size(); i++) {
		for (size_t j = 0; j < vec2D[i].size(); j++)
			vec[i].push_back(vec2D[j][i]);
	}
	vec2D = vec;
	vec.clear();

	return vec2D;
}

template<typename T> 
std::vector<std::vector<T>> rot90(std::vector<std::vector<T>> &vec2D) {
	refl<int> (vec2D);
	for (size_t i = 0; i < vec2D.size(); i++) {
		std::reverse(vec2D[i].begin(), vec2D[i].end());
	}

	return vec2D;
}

template<typename T> 
std::vector<T> flat(std::vector<std::vector<T>> vec2D) {
	std::vector<T> vec;
	for (auto row: vec2D) {
		for (auto col: row)
			vec.push_back(col);
	}

	return vec;
}

std::vector<std::string> split(std::string& raw, std::string delimiter)
{
	std::vector<std::string> vec {};

	std::string token;
	size_t pos = 0;

	while ((pos = raw.find(delimiter)) != std::string::npos) {
		token = raw.substr(0, pos);
		vec.push_back(token);
		raw.erase(0, pos + delimiter.length());
	}
	vec.push_back(raw);

	return vec;
}
