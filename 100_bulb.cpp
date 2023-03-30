/*
 * The 100 Light Bulb problem | Finding the square numbers
 * Problem statement: https://www.youtube.com/watch?v=-UBDRX6bk-A
 * Shams Parvez Arka<parvez6826@gmail.com>
*/

#include <iostream>
#include <vector>

int main()
{
	long N;
	std::cin >> N;
	std::vector<bool> vec;
	for (int i = 0; i <= N; i++)
		vec.push_back(0);	

	long counter = 1;
	while (counter <= N) {
		for (long i = 1; i <= N; i++) {
			if (counter * i <= N)
				vec[counter * i] = !vec[counter * i];
		}
		counter++;
	}
	
	for (long i = 1; i <= N; i++) {
		if (vec.at(i) == true)
			std::cout << i << ' ';
	}
	
	return 0;
}