#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

enum enumLnMove { kLeft = -1, kStill = 0, kRight = 1 };
enum enumColMove { kUp = -1, kDown = 1 };
int lnmove[] = { kLeft, kStill, kRight, kStill };
int colmove[] = { kStill, kUp, kStill, kDown };
int m, n;
char room[100][100];
bool visited[100][100];

void DFS(int curln, int curcol, int &counter) {

	for (int i = 0; i < 4; ++i) {

		int nextln = curln + lnmove[i];
		int nextcol = curcol + colmove[i];

		if (nextln > -1 && nextln < m && nextcol > -1 && nextcol < n) {
			if (room[nextln][nextcol] == '.' && visited[nextln][nextcol] == false) {
				visited[nextln][nextcol] = true;
				++counter;
				DFS(nextln, nextcol, counter);
			}
		}
	}
	return;
}

int main() {

	int curln, curcol;

	while (scanf("%d%d", &n, &m) != EOF) {
		int counter = 1;
		getchar();
		if (m > 0 || n > 0) {
			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < n; ++j) {
					char plot;
					scanf("%c", &plot);
					room[i][j] = plot;
					if (plot == '@') {
						curln = i;
						curcol = j;
					}
				}
				getchar();
			}

			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < n; ++j) {
					visited[i][j] = false;
				}
			}

			visited[curln][curcol] = true;

			DFS(curln, curcol, counter);
			printf("%d\n", counter);
		}
	}
	return 0;
}