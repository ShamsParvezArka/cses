#include <stdio.h>

int main() {
	int tc;
	scanf("%d", &tc);
	
	long b, w, bc, wc, z, ans;
	while (tc--) {
		ans = 0;
		scanf("%ld %ld", &b, &w);
		scanf("%ld %ld %ld", &bc, &wc, &z);
		if (bc == wc && wc == z) {
			ans = b*bc + w*wc;
		} 
		else if (bc < z && wc < z) {
			ans = b * bc + w*wc; 
		}
		else if (bc > wc+z) {
			ans = w*(wc+z) + w*wc;
		}
		else if (b == w && wc > bc) {
			ans = b*bc + w*(bc+z);
		} 
		else if (b == w && bc > wc) {
			ans = w*wc + b*(wc+z);
		}
		printf("%ld\n", ans);
	}

	return 0;
}
