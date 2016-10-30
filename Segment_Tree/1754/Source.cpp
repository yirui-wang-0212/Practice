#include<iostream>
#include<algorithm>
using namespace std;

#define lchild rt << 1, l, m
#define rchild rt << 1 | 1, m + 1, r

int tree[200020 << 2];

void push_up(int rt) {
	tree[rt] = max(tree[rt << 1], tree[rt << 1 | 1]);
}

void build(int rt, int l, int r) {

	if (l == r) {
		scanf("%d", &tree[rt]);
		return;
	}
	int m = (l + r) >> 1;
	build(lchild);
	build(rchild);
	push_up(rt);
}

void update(int p, int newdata, int rt, int l, int r) {

	if (l == r) {
		tree[rt] = newdata;
		return;
	}
	int m = (l + r) >> 1;
	if (p <= m) 
		update(p, newdata, lchild);
	else 
		update(p, newdata, rchild);
	push_up(rt);
}

int query(int a, int b, int rt, int l, int r) {

	int ans = 0;
	if (a <= l && b >= r) 
		return tree[rt];
	int m = (l + r) >> 1;
	if (a <= m)
		ans = max(ans, query(a, b, lchild));
	if (b > m)
		ans = max(ans, query(a, b, rchild));
	return ans;
}

int main() {

	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		build(1, 1, n);
		char s[2];
		int a, b;
		while (m--) {
			scanf("%s%d%d", s, &a, &b);
			if (s[0] == 'U')
				update(a, b, 1, 1, n);
			else
				printf("%d\n", query(a, b, 1, 1, n));
		}
	}

}