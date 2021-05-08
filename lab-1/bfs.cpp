#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include "graph.h"

std::vector<graph> list;

bool pruning(graph g) {
    for (int i=0; i<list.size(); i++) {
        graph m = list[i];
        if(g.nums[0][0] == m.nums[0][0] && g.nums[0][1] == m.nums[0][1] && g.nums[0][2] == m.nums[0][2] 
        && g.nums[1][0] == m.nums[1][0] && g.nums[1][1] == m.nums[1][1] && g.nums[1][2] == m.nums[1][2]
        && g.nums[2][0] == m.nums[2][0] && g.nums[2][1] == m.nums[2][1] && g.nums[2][2] == m.nums[2][2]){
            return true;
        }
    }
    return false;
}

void print_graph(graph* g) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++){
            if (g->nums[i][j] == 0){
                printf("  ");
            }else{
                printf("%d ", g->nums[i][j]);
            } 
        }
        printf("\n");
    }
    printf("\n\n");
}

void bfs(graph g) {
    using namespace std;
    queue<graph> q;
    q.push(g);
    while(!q.empty()) {
        graph cur_g = q.front();
        q.pop();
        print_graph(&cur_g);
        list.push_back(cur_g);
        // judge the graph is correct
        if (judge(cur_g)) {
            printf("success\n");
            return;
        }

        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                // search the point which is empty
                if (cur_g.nums[i][j] == 0) {
                    for(int k=0; k<4; k++) {
                        int cur_x = i + x[k];
                        int cur_y = j + y[k];
                        if (cur_x>=0 && cur_x <=2 && cur_y>=0 && cur_y<=2){
                            int tmp = cur_g.nums[i][j];
                            cur_g.nums[i][j] = cur_g.nums[cur_x][cur_y];
                            cur_g.nums[cur_x][cur_y] = tmp;
                            if (!pruning(cur_g)) {
                                q.push(cur_g);
                            }else{
                                continue;
                            }
                        }
                    }
                }
            }
        }
    }

    printf("queue empty");
}

int main() {
    using namespace std;
    graph g;
    // g.nums[0][0] = 2;
    // g.nums[0][1] = 3;
    // g.nums[0][2] = 5;
    // g.nums[1][0] = 4;
    // g.nums[1][1] = 0;
    // g.nums[1][2] = 6;
    // g.nums[2][0] = 7;
    // g.nums[2][1] = 8;
    // g.nums[2][2] = 1;

    g.nums[0][0] = 1;
    g.nums[0][1] = 2;
    g.nums[0][2] = 3;
    g.nums[1][0] = 8;
    g.nums[1][1] = 0;
    g.nums[1][2] = 4;
    g.nums[2][0] = 7;
    g.nums[2][1] = 5;
    g.nums[2][2] = 6;

    bfs(g);
}