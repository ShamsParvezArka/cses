#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <cstdbool>

std::vector<int> itovector(int n) {
	std::vector<int> vec;
	int number_length = floor(log10(n)) + 1;
	for (int i = 0; i < number_length; i++) {
		vec.insert(vec.begin(), n % 10);
		n = n / 10;
	}
	return vec;
}

int vectortoi(std::vector<int> vec) {
	std::string str;
	for (size_t i = 0; i < vec.size(); i++) {
		str += std::to_string(vec[i]);
	}
	return std::stoi(str);
}

int main()
{
	int x;
	scanf("%d", &x);
	int kap = 6174;
	int counter = 0;

	while (true) {
		std::vector<int> minV = itovector(x);
		std::sort(minV.begin(), minV.end());
		int min = vectortoi(minV);

		std::vector<int> maxV = minV;
		std::reverse(maxV.begin(), maxV.end());
		int max = vectortoi(maxV);
		
		if (max - min == kap) {
			std::cout << counter << std::endl;
			break;
		}
		else {
			x = max - min;
			counter++;
		}
	}
	
	return 0;
}


/*
 * A: 
 * 2342 --> max: 4322
 * 2342 --> min: 2234
 * -------------------
 *     subtract: 2088 --> ?isKaprikar (false --> goto A) (true --> return 0)
 */
