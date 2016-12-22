#include <stdio.h>

typedef long long ll;

int main(int argc, char** argv) {
	ll arr[17];
	ll i;
	arr[0] = 0;
	arr[1] = arr[2] = 1;
	for (i = 3; i < 17; ++i) {
		if (i & 1) {
			arr[i] = arr[i-1]*arr[i-2];
		} else {
			arr[i] = arr[i-1] + arr[i-2];
		}
	}
	while (scanf("%lli", &i) == 1) {
		printf("%lli\n", arr[i-1]);
	}
	return 0;
}
