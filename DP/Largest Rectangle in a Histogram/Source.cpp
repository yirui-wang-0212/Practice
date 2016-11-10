#include<iostream>
using namespace std;

long long int h[100005], l[100005], r[100005];
long long int n, max;

void dp() {

	l[0] = 1;
	r[n - 1] = 1;
	int j;

	//从左开始计算
	for (int i = 1; i < n; ++i) {
		l[i] = 1;
		//若前一个比自己低, 从自己开始算
		//若前一个比自己高, 加上前面的数并跳到前一组, 再跳到前一组进行比较
		if (h[i] <= h[i - 1]) {
			j = i - 1;
			while (j >= 0 && h[i] <= h[j]) {
				l[i] += l[j];
				j -= l[j];
			}
		}
	}

	//从右开始计算
	for (int i = n - 2; i >= 0; --i) {
		r[i] = 1;
		if (h[i] <= h[i + 1]) {
			j = i + 1;
			while (j < n && h[i] <= h[j]) {
				r[i] += r[j];
				j += r[j];
			}
		}
	}

	long long int sum;
	max = 0;
	for (int i = 0; i < n; ++i) {
		//总长度 = 左 + 右 - 1
		//面积 = 总长度 * 高
		sum = (r[i] + l[i] - 1)*h[i];
		//寻找最大面积
		if (sum > max)
			max = sum;
	}

}

int main() {

	while (scanf("%lld", &n), n) {

		getchar();
		for (int i = 0; i < n; ++i) {
			scanf("%lld", h + i);
			getchar();
		}
		dp();
		printf("%lld\n", max);
	}
	return 0;
}