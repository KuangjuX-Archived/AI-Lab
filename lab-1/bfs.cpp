#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include "graph.h"


using namespace std;


void bfs(Graph G) {
    queue<Graph> open_set;
    vector<Graph> close_set;
    open_set.push(G);
    while(!open_set.empty()) {
        Graph n = open_set.front();
        open_set.pop();
        printf("The graph on the top of queue:\n");
        print_graph(&n);
        // judge the graph is correct
        if (is_ok(n)) {
            printf("success\n");
            return;
        }

        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                // search the point which is empty
                if (n.nums[i][j] == 0) {
                    for(int k=0; k<4; k++) {
                        int xi = i + x[k];
                        int yi = j + y[k];
                        if (xi>=0 && xi <=2 && yi>=0 && yi<=2){
                            Graph G1;

                            for(int m=0; m<3; m++) {
                                for(int s=0; s<3; s++) {
                                    G1.nums[m][s] = n.nums[m][s];
                                }
                            }

                            G1.nums[i][j] = n.nums[xi][yi];
                            G1.nums[xi][yi] = 0;
                            if (!pruning(G1, close_set)) {
                                printf("push graph:\n");
                                print_graph(&G1);
                                close_set.push_back(G1);
                                open_set.push(G1);
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
    Graph G;
    // G.nums[0][0] = 2;
    // G.nums[0][1] = 3;
    // G.nums[0][2] = 5;
    // G.nums[1][0] = 4;
    // G.nums[1][1] = 0;
    // G.nums[1][2] = 6;
    // G.nums[2][0] = 7;
    // G.nums[2][1] = 8;
    // G.nums[2][2] = 1;

    G.nums[0][0] = 2;
    G.nums[0][1] = 8;
    G.nums[0][2] = 3;
    G.nums[1][0] = 1;
    G.nums[1][1] = 0;
    G.nums[1][2] = 4;
    G.nums[2][0] = 7;
    G.nums[2][1] = 6;
    G.nums[2][2] = 5;

    bfs(G);
}