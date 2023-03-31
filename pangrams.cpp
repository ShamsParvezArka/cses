#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <numeric>
#include <set>

char lower_case(char &ch);

int main()
{
	std::string message;
	std::getline(std::cin, message);
	std::for_each(message.begin(), message.end(), lower_case);
	
	std::set<char> filter;
	for (auto i: message)
		filter.insert(i);

	int letters = filter.size() - 1;		
	if (letters == 26)
		std::cout << "pangram" << std::endl;
	else 
		std::cout << "not pangram" << std::endl;

	return 0;
}

char lower_case(char &ch) {
	return ch = tolower(ch);
}
