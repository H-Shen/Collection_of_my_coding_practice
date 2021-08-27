class SnakeGame {
private:
    deque<pair<int,int> > snake, foodpos;
    int width, height;
    
    bool hit() {
        // out of bounds
        if (snake.front().first < 0 || snake.front().first >= height || snake.front().second < 0 || snake.front().second >= width) {
            return true;
        }
        // hit its body
        int n = (int)snake.size();
        for (int i = 1; i < n; ++i) {
            if (snake.front().first == snake[i].first && snake.front().second == snake[i].second) {
                return true;
            }
        }
        return false;
    }
    
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        snake.push_back({0,0});
        this->width = width;
        this->height = height;
        for (const auto &i : food) {
            foodpos.push_back({i[0],i[1]});
        }
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        auto newPos = snake.front();
        switch (direction[0]) {
            case 'U':
                --newPos.first;
                break;
            case 'L':
                --newPos.second;
                break;
            case 'R':
                ++newPos.second;
                break;
            default:
                ++newPos.first;
                break;
        }
        if (!foodpos.empty() && newPos.first == foodpos.front().first && newPos.second == foodpos.front().second) {
            snake.push_front(newPos);
            foodpos.pop_front();
            return (int)snake.size() - 1;
        }
        // transform
        snake.push_front(newPos);
        snake.pop_back();
        // check hit
        return (hit()) ? -1 : (int)snake.size() - 1;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */