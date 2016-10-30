#include<iostream>
using namespace std;

class UF {

public:
	UF(int n);
	int roadnum();
	int find(int p);
	void connect(int p,int q);

private:
	int id_[1001];
	int size_[1001];
	int roadnum_ = 0;
};

UF::UF(int n){

	for (int i = 1; i <= n; ++i) {
		id_[i] = i;
		size_[i] = 1;
	}
}

int UF::roadnum() {

	return roadnum_;
}

int UF::find(int p) {

	while (p != id_[p]) {
		id_[p] = id_[id_[p]];
		p = id_[p];
	}
	return p;
}

void UF::connect(int p, int q) {

	int i = find(p);
	int j = find(q);

	if (i == j)
		return;

	++roadnum_;
	if (size_[i] < size_[j]) {
		id_[i] = j;
		size_[j] += size_[i];
	}
	else {
		id_[j] = i;
		size_[i] += size_[j];
	}
}

int main() {

	int townnum, roadnum;
	while (true)
	{
		scanf("%d%d", &townnum, &roadnum);
		if (!townnum)
			return 0;

		UF uf(townnum);
		getchar();
		for (int i = 0; i < roadnum; ++i) {
			int p, q;
			scanf("%d%d", &p, &q);
			getchar();
			uf.connect(p, q);
		}

		int ans = townnum - uf.roadnum() - 1;
		printf("%d\n", ans);
	}

}