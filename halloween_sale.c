#include <stdio.h>
#include <stdbool.h>

int main() {
	int p, d, m, s;
	scanf("%d %d %d %d", &p, &d, &m, &s);
	
	int ans = 0;
	
	if (s < p) {
		printf("%d\n", ans);
	}else {
		while (s >= m && s >= p) {
			s -= p;
			p -= d;
			if (p <= m) {
				p = m;
				ans++;
			} else {
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
