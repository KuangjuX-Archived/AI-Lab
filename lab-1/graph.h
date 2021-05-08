int x[4] = {0, 1, 0, -1};
int y[4] = {1, 0, -1, 0};


struct graph {
    int nums[3][3];
};

void init(graph* g) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            g->nums[i][j] = 0;
        }
    }
}

bool judge(graph g) {
    if(g.nums[0][0] == 1 && g.nums[0][1] == 2 && g.nums[0][2] == 3 
    && g.nums[1][0] == 8 && g.nums[1][1] == 0 && g.nums[1][2] == 4
    && g.nums[2][0] == 7 && g.nums[2][1] == 6 && g.nums[2][2] == 5){
        return true;
    }

    return false;
}