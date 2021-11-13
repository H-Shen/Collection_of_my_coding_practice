// 0: up 1: right 2: down 3: left

int turnLeft(int dir) {
    // 0->3 1->0 2->1 3->2
    if (dir == 0) return 3;
    return dir-1;
}

void nextMove(int cur_i, int cur_j, int dir, int& nxt_i, int& nxt_j) {
    nxt_i = cur_i;
    nxt_j = cur_j;
    switch (dir) {
        case 0:
            ++nxt_i;
            break;
        case 1:
            ++nxt_j;
            break;
        case 2:
            --nxt_i;
            break;
        case 3:
            --nxt_j;
            break;
    }
}

class Robot {
private:
    int width, height, dir, cur_i, cur_j, outer;
public:
    Robot(int width, int height) : width(width), height(height), dir(1), cur_i(0), cur_j(0) {
        outer = 2 * (width + height) - 4;
    }
    
    void move(int num) {
        int remainder = num % outer;
        // Corner case
        if (remainder == 0) {
            if (cur_i == 0 && cur_j == 0) {
                dir = 2;
            }
            else if (cur_i == 0 && cur_j == width-1) {
                dir = 1;
            }
            else if (cur_i == height-1 && cur_j == width-1) {
                dir = 0;
            }
            else if (cur_i == height-1 && cur_j == 0) {
                dir = 3;
            }
        }
        
        int nxt_i,nxt_j;
        for (int i = 0; i < remainder; ++i) {
            while (true) {
                nextMove(cur_i,cur_j,dir,nxt_i,nxt_j);
                if (nxt_i >= 0 && nxt_i < height && nxt_j >= 0 && nxt_j < width) {
                    cur_i = nxt_i;
                    cur_j = nxt_j;
                    break;
                } else {
                    dir = turnLeft(dir);
                }
            }
        }
    }
    
    vector<int> getPos() {
        return vector<int>{cur_j,cur_i};
    }
    
    string getDir() {
        switch (dir) {
            case 0:
                return "North";
            case 1:
                return "East";
            case 2:
                return "South";
            case 3:
                return "West";
        }
        return "";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->move(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */