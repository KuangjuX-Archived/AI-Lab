// f(n) = g(n) + h(n)
#include <cstdio>
#include <queue>
#include <vector> 
#include "graph.h"

using namespace std;

void heuristic(graph *G) {

}


void astar(graph G) {
    priority_queue<graph> open_set;
    vector<graph> close_set;
    open_set.push(G);
    while(!open_set.empty()) {
        graph n = open_set.top();
        open_set.pop();
        if (judge(n)) {
            printf("success\n");
        }
        
        close_set.push_back(n);

        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if (n.nums[i][j] == 0) {
                    for(int k=0; k<4; k++) {
                        int cur_x = i + x[k];
                        int cur_y = j + y[k];
                        if (cur_x>=0 && cur_x <=2 && cur_y>=0 && cur_y<=2) {
                            graph G1;
                            for(int m=0; m<3; m++){
                                for(int s=0; s<3; s++){
                                    G1.nums[m][s] = n.nums[m][s];
                                }
                            }

                            G1.nums[cur_x][cur_y] = n.nums[i][j];
                            G1.nums[i][j] = 0;

                            if (!pruning(G1, close_set)) {
                                heuristic(&G1);
                                open_set.push(G1);
                            }
                        }
                    }
                }
            }
        }

    }
}