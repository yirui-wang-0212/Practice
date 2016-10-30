#include<iostream>
#include<queue>
#include <string.h>
using namespace std;

int xmove[] = { -1, 1, 0, 0 };
int ymove[] = { 0, 0, -1, 1 };

int labyrinthln, labyrinthcol;//迷宫规格
char labyrinth[105][105];//迷宫
bool visited[105][105];//是否访问过该位置

struct Element {

    int x_, y_;//位置坐标
    int time_;//此位置所需要的时间
    int route_[1000][2];//存放到此点的路线
    //运算符重载
    bool operator < (const Element &a)const {
        return a.time_ < time_;
    }
};

Element dad;
Element *BFS() {

    priority_queue<Element> q;

    //头元素
    dad.x_ = 0;
    dad.y_ = 0;
    dad.time_ = 0;
    dad.route_[0][0] = 0;
    dad.route_[0][1] = 0;
    visited[0][0] = true;
    q.push(dad);

    while (!q.empty()) {

        dad = q.top();
        q.pop();

        //到达终点
        if (dad.x_ == labyrinthln - 1 && dad.y_ == labyrinthcol - 1)
            return &dad;

        //未到达终点
        Element son = dad;
        for (int i = 0; i < 4; ++i) {
            son.x_ = dad.x_ + xmove[i];
            son.y_ = dad.y_ + ymove[i];
            int x = son.x_;
            int y = son.y_;
            if (x > -1 && x < labyrinthln && y > -1 && y < labyrinthcol) {
                //可到达的点
                if (labyrinth[x][y] != 'X' && !visited[x][y]) {
                    visited[x][y] = true;
                    son.time_ = dad.time_ + 1;
                    son.route_[son.time_][0] = x;
                    son.route_[son.time_][1] = y;//在路线中加入现位置
                    //有怪物的点
                    if (isdigit(labyrinth[x][y])) {
                        int time = labyrinth[x][y] - '0';
                        for (int i = 1; i <= time; ++i) {
                            son.route_[son.time_ + i][0] = son.route_[son.time_][0];
                            son.route_[son.time_ + i][1] = son.route_[son.time_][1];
                        }
                        son.time_ += time;
                    }
                    q.push(son);
                }
            }
        }
    }
    return NULL;
}

int main() {

    while (scanf("%d%d", &labyrinthln, &labyrinthcol) != EOF) {
        getchar();
        for (int i = 0; i < labyrinthln; ++i) {
            for (int j = 0; j < labyrinthcol; ++j)
                scanf("%c", &labyrinth[i][j]);
            getchar();
        }

        memset(visited, 0, sizeof(visited));

        Element *ans = BFS();

        if (ans == NULL)
            printf("God please help our poor hero.\nFINISH\n");
        else {
            int time = ans->time_;
            printf("It takes %d seconds to reach the target position, let me show you the way.\n", time);
            for (int i = 1; i <= time; ++i) {
                if (ans->route_[i][0] == ans->route_[i - 1][0] && ans->route_[i][1] == ans->route_[i - 1][1])
                    printf("%ds:FIGHT AT (%d,%d)\n", i, ans->route_[i][0], ans->route_[i][1]);
                else {
                    printf("%ds:(%d,%d)->(%d,%d)\n", i, ans->route_[i - 1][0], ans->route_[i - 1][1], ans->route_[i][0], ans->route_[i][1]);
                }
            }
            printf("FINISH\n");
        }

    }
}