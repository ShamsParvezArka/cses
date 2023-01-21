#include <stdio.h>

int main() {
	int ts;
	scanf("%d", &ts);
	long n, c, m;
	while (ts--) {
		scanf("%ld %ld %ld", &n, &c, &m);
		long chocolate = n/c;
		long cwrapper = chocolate;
		if (cwrapper < m) {
			printf("%ld\n", cwrapper);
		} else {
			long ans = cwrapper;
			while (cwrapper >= m) {
				if (cwrapper % m == 0) {
					cwrapper = cwrapper / m;
					ans += cwrapper;
				} else {
					long reminder = cwrapper % m;
					ans += (cwrapper-reminder) / m;
					cwrapper = ((cwrapper-reminder) / m) + reminder;
				}
			}
			printf("%ld\n", ans);
		}		
	}
	return 0;
}
