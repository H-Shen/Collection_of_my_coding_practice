// https://www.nowcoder.com/practice/6235a76b1e404f748f7c820583125c50
class CatDogAsylum {
public:
    vector<int> asylum(vector <vector<int>> ope) {
        // write code here
        list<int> asylum;
        queue<int> dog, cat;
        vector<int> res;
        int tmp;

        for (auto &i : ope) {
            // input
            if (i.at(0) == 1) {
                asylum.push_back(i.at(1));
                if (i.at(1) > 0) {
                    dog.push(i.at(1));
                } else {
                    cat.push(i.at(1));
                }
            }
                // output
            else {
                //out by time
                if (i.at(1) == 0 && !asylum.empty()) {
                    tmp = asylum.front();
                    asylum.pop_front();
                    if (tmp > 0) {
                        dog.pop();
                    } else {
                        cat.pop();
                    }
                    res.push_back(tmp);
                }
                    // output a dog
                else if (i.at(1) == 1 && !dog.empty()) {
                    tmp = dog.front();
                    dog.pop();
                    for (auto it = asylum.begin(); it != asylum.end(); ++it) {
                        if (*it == tmp) {
                            asylum.erase(it);
                            break;
                        }
                    }
                    res.push_back(tmp);
                }
                    // output a cat
                else if (i.at(1) == -1 && !cat.empty()) {
                    tmp = cat.front();
                    cat.pop();
                    for (auto it = asylum.begin(); it != asylum.end(); ++it) {
                        if (*it == tmp) {
                            asylum.erase(it);
                            break;
                        }
                    }
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
};