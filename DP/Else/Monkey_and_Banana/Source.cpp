#include<iostream>
#include<algorithm>
using namespace std;

typedef struct {
	int x, y, z;
}t;

int n, cs;
int x, y, z;
t rs[95];
int dp[95];
int cnt;
int top, top_x, top_y;
int btm, btm_x, btm_y;

bool issmall(const t &a, const t &b) {

	return a.x < b.x;
}

int DP() {

	for (int i = 1; i <= cnt; ++i) {
		int maxh = 0;
		dp[i] = rs[i].z;
		for (int j = i - 1; j >= 1; --j)
			if (rs[j].x < rs[i].x && rs[j].y < rs[i].y)
				if (maxh < dp[j])
					maxh = dp[j];
		dp[i] += maxh;
	}

	int max = 0;
	for (int i = 1; i <= cnt; ++i)
		if (max < dp[i])
			max = dp[i];

	return max;
}

int main() {

	while (scanf("%d", &n), n) {
		getchar();
		++cs;
		cnt = 0;
		while (n--) {
			scanf("%d %d %d", &x, &y, &z);
			++cnt;
			int a = min(x, y);
			int b = max(x, y);
			rs[cnt].x = a;
			rs[cnt].y = b;
			rs[cnt].z = z;
			if (x != z) {
				++cnt;
				int a = min(y, z);
				int b = max(y, z);
				rs[cnt].x = a;
				rs[cnt].y = b;
				rs[cnt].z = x;
			}
			if (y != z) {
				++cnt;
				int a = min(x, z);
				int b = max(x, z);
				rs[cnt].x = a;
				rs[cnt].y = b;
				rs[cnt].z = y;
			}
			
		}
		sort(rs + 1, rs + cnt + 1, issmall);
		int max = DP();
		printf("Case %d: maximum height = %d\n", cs, max);
	}
	return 0;
}