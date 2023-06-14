#include <iostream>
#include <fstream>
#include <string>

enum class Move {
	rock     = 1,
	paper    = 2,
	scissors = 3,
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

	size_t score {};
	std::string line {};
	if (file.is_open() == true) {
		while (std::getline(file, line)) {
			int opponent = static_cast<int>(game::filter(line[0]));
			int mine     = static_cast<int>(game::filter(line[2]));

			if (mine > opponent)
				score += (6 + mine);
			if (mine < opponent)
				score += (0 + mine);
			if (mine == opponent)
				score += (3 + mine);
		}
	}
	file.close();

	std::cout << score << '\n';

	return 0;
}
