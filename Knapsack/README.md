# Knapsack-Problem
Different knapsack problems

the problem links:

01pack: http://hihocoder.com/problemset/problem/1038

completepack: http://hihocoder.com/problemset/problem/1043

完全背包问题的代码与01背包问题的代码只有第二层的循环次序不同而已。

P01中要按照v=V..0的逆序来循环是因为要保证第i次循环中的状态f[i][v]是由状态f[i-1][v-c[i]]递推而来。换句话说，这正是为了保证每件物品只选一次，保证在考虑“选入第i件物品”这件策略时，依据的是一个绝无已经选入第i件物品的子结果f[i-1][v-c[i]]。

而现在完全背包的特点恰是每种物品可选无限件，所以在考虑“加选一件第i种物品”这种策略时，却正需要一个可能已选入第i种物品的子结果f[i][v-c[i]]，所以就可以并且必须采用v=0..V的顺序循环。
