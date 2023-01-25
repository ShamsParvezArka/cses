#include <stdio.h>

int main() {
	int tc;
	scanf("%d", &tc);
	
	long b, w, bc, wc, z, ans;
	while (tc--) {
		ans = 0;
		scanf("%ld %ld", &b, &w);
		scanf("%ld %ld %ld", &bc, &wc, &z);
		if (bc >= wc + z) {
			ans = w*wc + b*(wc + z);
		}
		else if (wc >= bc + z) {
			ans = b*bc + w*(bc + z);
		} else {
			ans = b*bc + w*wc;
		}
		printf("%ld\n", ans);
	}

	return 0;
}
