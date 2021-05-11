#include <vector>
using namespace std;
int x[4] = {0, 1, 0, -1};
int y[4] = {1, 0, -1, 0};



struct Graph {
    int nums[3][3];
    int priproty;
    int weight;

    bool operator<(const Graph& other) const {
        return priproty > other.priproty;
    }

    Graph(): nums(), priproty(), weight(){
       for(int i=0; i<3; i++){
           for(int j=3; j<3; j++){
               this->nums[i][j] = 0;
           }
       }

       this->priproty = 0;
       this->weight = 0;
    }
};

static Graph GS;

void Static_Init() {
    GS.nums[0][0] = 1;
    GS.nums[0][1] = 2;
    GS.nums[0][2] = 3;
    GS.nums[1][0] = 8;
    GS.nums[1][1] = 0;
    GS.nums[1][2] = 4;
    GS.nums[2][0] = 7;
    GS.nums[2][1] = 6;
    GS.nums[2][2] = 5;
}


bool is_ok(Graph G) {
    if(G.nums[0][0] == 1 && G.nums[0][1] == 2 && G.nums[0][2] == 3 
    && G.nums[1][0] == 8 && G.nums[1][1] == 0 && G.nums[1][2] == 4
    && G.nums[2][0] == 7 && G.nums[2][1] == 6 && G.nums[2][2] == 5){
        return true;
    }

    return false;
}

void print_graph(Graph* G) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++){
            if (G->nums[i][j] == 0){
                printf("  ");
            }else{
                printf("%d ", G->nums[i][j]);
            } 
        }
        printf("\n");
    }
    printf("\n\n");
}


bool pruning(Graph G, vector<Graph> close_set) {
    for(auto& x: close_set) {
        int ok = 1;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++){
               if(x.nums[i][j] == G.nums[i][j]){
                   ok &= 1;
               }else{
                   ok = 0;
               } 
            }
        }
        if (ok){
            return true;
        }
    }

    return false;
}

// This function is used to judge if the solution can be solved.
bool is_solved(Graph G) {
    int inverse = 0;
    vector<int> tmp;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            tmp.push_back(G.nums[i][j]);
        }
    }

    for(int i=0; i<tmp.size(); i++) {
        for(int j=i+1; j<tmp.size(); j++) {
            if(tmp[j] < tmp[i]) {
                inverse++;
            }
        }
    }

    if(inverse%2 == 1){
        return true;
    }
    return false;
}