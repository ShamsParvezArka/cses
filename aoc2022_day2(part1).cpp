#include <iostream>
#include <fstream>
#include <string>

enum class Move {
	rock = 1,
	paper = 2,
	scissors = 3
};

Move filter_move(char ch) {
	switch (ch) {
		case 'A': return Move::rock;
		case 'B': return Move::paper;
		case 'C': return Move::scissors;

		case 'X': return Move::rock;
		case 'Y': return Move::paper;
		case 'Z': return Move::scissors;
	}
}

int main() {
	size_t score {};
	std::fstream file;
	std::string line;
	const char fname[] = "input.txt";

	file.open(fname, std::ios::in);
	if (file.is_open()) {
		while (getline(file, line)) {
			int opponent = static_cast<int>(filter_move(line[0]));
			int mine     = static_cast<int>(filter_move(line[2]));

			if (opponent > mine)
				score += (0 + mine);
			if (opponent < mine)
				score += (6 + mine);
			if (opponent == mine)
				score += (3 + mine);
		}
	}

	std::cout << score << '\n';

	return 0;
}
