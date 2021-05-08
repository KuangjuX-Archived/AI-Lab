#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include "graph.h"


using namespace std;


void bfs(graph G) {
    using namespace std;
    queue<graph> q;
    vector<graph> close_set;
    q.push(G);
    while(!q.empty()) {
        graph n = q.front();
        q.pop();
        print_graph(&n);
        close_set.push_back(n);
        // judge the graph is correct
        if (judge(n)) {
            printf("success\n");
            return;
        }

        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                // search the point which is empty
                if (n.nums[i][j] == 0) {
                    for(int k=0; k<4; k++) {
                        int cur_x = i + x[k];
                        int cur_y = j + y[k];
                        if (cur_x>=0 && cur_x <=2 && cur_y>=0 && cur_y<=2){
                            graph G1;

                            for(int m=0; m<3; m++) {
                                for(int s=0; s<3; s++) {
                                    G1.nums[m][s] = n.nums[m][s];
                                }
                            }

                            G1.nums[i][j] = n.nums[cur_x][cur_y];
                            G1.nums[cur_x][cur_y] = 0;
                            if (!pruning(G1, close_set)) {
                                q.push(G1);
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
    graph G;
    G.nums[0][0] = 2;
    G.nums[0][1] = 3;
    G.nums[0][2] = 5;
    G.nums[1][0] = 4;
    G.nums[1][1] = 0;
    G.nums[1][2] = 6;
    G.nums[2][0] = 7;
    G.nums[2][1] = 8;
    G.nums[2][2] = 1;

    // g.nums[0][0] = 1;
    // g.nums[0][1] = 2;
    // g.nums[0][2] = 3;
    // g.nums[1][0] = 8;
    // g.nums[1][1] = 0;
    // g.nums[1][2] = 4;
    // g.nums[2][0] = 7;
    // g.nums[2][1] = 5;
    // g.nums[2][2] = 6;

    bfs(G);
}