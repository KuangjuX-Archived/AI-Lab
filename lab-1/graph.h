#include <vector>
using namespace std;
int x[4] = {0, 1, 0, -1};
int y[4] = {1, 0, -1, 0};


struct graph {
    int nums[3][3];
    int priproty;

    bool operator<(const graph& other) const {
        return priproty < other.priproty;
    }
};

void init(graph* g) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            g->nums[i][j] = 0;
        }
    }

    g->priproty = 0;
}

bool judge(graph g) {
    if(g.nums[0][0] == 1 && g.nums[0][1] == 2 && g.nums[0][2] == 3 
    && g.nums[1][0] == 8 && g.nums[1][1] == 0 && g.nums[1][2] == 4
    && g.nums[2][0] == 7 && g.nums[2][1] == 6 && g.nums[2][2] == 5){
        return true;
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


bool pruning(graph G, vector<graph> close_set) {
    for (int i=0; i<close_set.size(); i++) {
        graph m = close_set[i];
        if(G.nums[0][0] == m.nums[0][0] && G.nums[0][1] == m.nums[0][1] && G.nums[0][2] == m.nums[0][2] 
        && G.nums[1][0] == m.nums[1][0] && G.nums[1][1] == m.nums[1][1] && G.nums[1][2] == m.nums[1][2]
        && G.nums[2][0] == m.nums[2][0] && G.nums[2][1] == m.nums[2][1] && G.nums[2][2] == m.nums[2][2]){
            return true;
        }
    }
    return false;
}