#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int best[100005];
int need[505];
int value[505];

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		memset(best, 0, sizeof(best));
		for (int i = 1; i <= n; ++i)
			scanf("%d%d", &need[i], &value[i]);
		for (int i = 1; i <= n; ++i)
			for (int j = m; j >= need[i]; --j)
				best[j] = max(best[j], best[j - need[i]] + value[i]);
		printf("%d\n", best[m]);
	}
	return 0;
}