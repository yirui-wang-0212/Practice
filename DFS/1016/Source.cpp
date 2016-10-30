#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

#define MAXSUM 41
#define MAXN 21

bool iscomposite[MAXSUM];
int prime_ring[MAXN];
int isvisited[MAXN];
int n;

//mark the composite numbers
void setComposite() {

	for (int i = 2; i < MAXSUM; ++i) {
		for (int j = 2; i * j < MAXSUM; ++j)
			iscomposite[i * j] = true;
	}
}

void DFS(int pre, int counter) {

	int sum;

	if (counter == n - 1) {

		for (int i = 2; i <= n; ++i) {
			if (!isvisited[i]) {
				sum = pre + i;
				if (!iscomposite[sum] && !iscomposite[i + 1]) {
					prime_ring[n] = i;
					for (int i = 1; i <= n; ++i)
						printf(i == 1 ? "%d" : " %d", prime_ring[i]);
					putchar('\n');
					return;
				}
			}
		}
	}

	for (int i = 2; i <= n; ++i) {
		if (!isvisited[i]) {
			sum = pre + i;
			if (!iscomposite[sum]) {
				prime_ring[counter + 1] = i;
				isvisited[i] = true;
				DFS(i, counter + 1);
				//recall
				isvisited[i] = false;
			}
		}
	}
}

int main() {

	setComposite();
	prime_ring[1] = 1;
	int case_num = 1;
	
	while (scanf("%d", &n) != EOF) {
		memset(isvisited, 0, sizeof(isvisited));
		isvisited[1] = true;
		printf("Case %d:\n", case_num++);
		DFS(1, 1);
		putchar('\n');
	}
}
