#include<iostream>
#include<algorithm>
using namespace std;

int triangle[105][105];//记录数据
int calculate[105][105];//从下往上计算到这点的和

int main() {

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i; ++j) {
			scanf("%d", &triangle[i][j]);
			calculate[i][j] = triangle[i][j];
		}

	for (int i = n - 1; i >= 1; --i)//从倒数第二行开始
		for (int j = 1; j <= n - 1; ++j)
			calculate[i][j] += max(calculate[i + 1][j], calculate[i + 1][j + 1]);

	printf("%d\n", calculate[1][1]);

}