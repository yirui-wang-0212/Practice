#include<iostream>
#include<cstdlib>
#include <cstring>
#include<queue>
using namespace std;

class Node {
public:
	int x, y, z;
	int num;
};

int xmove[] = { -1, 1, 0, 0, 0, 0 };
int ymove[] = { 0, 0, -1, 1, 0, 0 };
int zmove[] = { 0, 0, 0, 0, -1, 1 };

int n;
char slicelist[10][10][10];
bool isvisited[10][10][10];
int startx, starty, startz;
int endx, endy, endz;

int BFS() {

	queue<Node> q;
	Node dad = { startx, starty, startz, 0 };
	isvisited[startx][starty][startz] = true;
	q.push(dad);

	while (!q.empty()) {

		dad = q.front();
		if (dad.x == endx && dad.y == endy && dad.z == endz)
			return dad.num;
		q.pop();

		Node son;
		son.num = dad.num + 1;

		for (int i = 0; i < 6; ++i) {
			son.x = dad.x + xmove[i];
			son.y = dad.y + ymove[i];
			son.z = dad.z + zmove[i];
			if (son.x > -1 && son.x < n && son.y > -1 && son.y < n && son.z > -1 && son.z < n) {
				if (slicelist[son.x][son.y][son.z]=='O' && !isvisited[son.x][son.y][son.z]) {
					isvisited[son.x][son.y][son.z] = true;
					q.push(son);
				}
			}
		}
	}
	return -1;
}

int main() {

	char str[6];

	while (scanf("%s%d",str,&n)!=EOF) {

		getchar();

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < n; ++k) {
					scanf("%c", &slicelist[k][j][i]);
				}
				getchar();
			}
		}
		scanf("%d%d%d%d%d%d%s", &startx, &starty, &startz, &endx, &endy, &endz, &str);

		int length = BFS();

		if (length == -1)
			printf("NO ROUTE\n");
		else
			printf("%d %d\n", n, length);
	}
	return 0;
}