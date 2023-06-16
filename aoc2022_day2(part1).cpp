#include <iostream>
#include <fstream>
#include <string>
#include <array>

enum class Move {
	rock     = 0,
	paper    = 1,
	scissors = 2,
};

namespace game {
	constexpr Move filter(char ch) {
		switch (ch) {
			case 'A': return Move::rock;
			case 'B': return Move::paper;
			case 'C': return Move::scissors;

			case 'X': return Move::rock;
			case 'Y': return Move::paper;
			case 'Z': return Move::scissors;
		}
	}
}

int main() {
	const char fname[] = "input.txt";
	std::fstream file;
	file.open(fname, std::ios::in);

	std::array<std::array<int, 3>, 3> score_map = {{
		{4, 1, 7},
		{8, 5, 2},
		{3, 9, 6}
	}};

	size_t score {};
	std::string line {};
	if (file.is_open() == true) {
		while (std::getline(file, line)) {
			int opponent = static_cast<int>(game::filter(line[0]));
			int mine     = static_cast<int>(game::filter(line[2]));
			score += score_map.at(opponent).at(mine);
		}
	}
	file.close();

	std::cout << score << '\n';

	return 0;
}

