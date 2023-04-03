/*
 * HackerRank: Climbing the Leaderboard
 * Difficulty: Medium
 * Soln: Bruteforce
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
#include <set>

using namespace std;

int bruteforce() {
	size_t n, m;
	cin >> n;
	vector<size_t> ranked {};
	int input;
	for (size_t i = 0; i < n; i++) {
		cin >> input;
		ranked.push_back(input);
	}
	cin >> m;
	vector<size_t> player;
	for (size_t i = 0; i < m; i++) {
		cin >> input;
		player.push_back(input);
	}

	sort(ranked.begin(), ranked.end(), greater<int>());
	ranked.erase(unique(ranked.begin(), ranked.end()), ranked.end());

	for (size_t i = 0; i < player.size(); i++) {
		if (player.at(i) < ranked.back())
			cout << ranked.size() + 1 << endl;
		else if (player.at(i) > ranked.front())
			cout << 1 << endl;
		else {
			for (size_t j = 0; j < ranked.size(); j++) {
				if (player.at(i) >= ranked.at(j)) {
					cout << j + 1 << endl;
					break;
				}
			}
		}
	}

	return 0;
}

// An idiot admires complexity, a genius admires simplicity
