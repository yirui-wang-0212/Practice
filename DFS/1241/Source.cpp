#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

enum enumLnMove { kLeft = -1, kStill = 0, kRight = 1 };
enum enumColMove { kUp = -1, kDown = 1 };
//for searching adjacent 8 ceils
int lnmove[] = { kLeft, kStill, kRight, kStill, kLeft, kLeft, kRight, kRight };
int colmove[] = { kStill, kUp, kStill, kDown, kUp, kDown, kUp, kDown };
int m, n;
char grid[100][100];//store square plots
bool visited[100][100];//if is visited, set true

void Dig(int curln, int curcol) {

	//search adjacent 8 ceils
	for (int i = 0; i < 8; ++i) {

		int nextln = curln + lnmove[i];
		int nextcol = curcol + colmove[i];

		if (nextln > -1 && nextln < m && nextcol > -1 && nextcol < n) {
			if (grid[nextln][nextcol] == '@'&&visited[nextln][nextcol] == false) {
				visited[nextln][nextcol] = true;
				Dig(nextln, nextcol);
			}
		}
	}
	return;
}

int DFS() {

	int count = 0;

	//traverse all ceils
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] == '@' && visited[i][j] == false) {
				visited[i][j] = true;
				++count;
				Dig(i, j);
			}
		}
	}

	return count;
}

int main() {

	int count;

	while (scanf("%d%d", &m, &n) != EOF) {
		getchar();
		if (m > 0 || n > 0) {
			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < n; ++j) {
					char plot;
					scanf("%c", &plot);
					grid[i][j] = plot;
				}
				getchar();
			}

			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < n; ++j) {
					visited[i][j] = false;
				}
			}

			count = DFS();
			printf("%d\n", count);
		}
	}
	return 0;
}