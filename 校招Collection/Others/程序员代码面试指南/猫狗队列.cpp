// https://www.nowcoder.com/practice/8a7e04cff6a54b7095b94261d78108f5

#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 20;
char s[MAXN];

class Animal {
private:
    int number;
    string type;
public:
    Animal(int number, string type) : number(number), type(move(type)) {}
    int getNumber() const {
        return number;
    }
    string getType() const {
        return type;
    }
};

class Cat : public Animal {
public:
    explicit Cat(int number) : Animal(number, "cat") {}
};

class Dog : public Animal {
public:
    explicit Dog(int number) : Animal(number, "dog") {}
};

class DogAndCatQueue {
private:
    queue<pair<unsigned long long, Animal> > DogQueue;
    queue<pair<unsigned long long, Animal> > CatQueue;
    unsigned long long orderNumber{0};
public:
    void add(const Animal &animal) {
        if (animal.getType() == "cat") {
            CatQueue.push({orderNumber, animal});
        } else {
            DogQueue.push({orderNumber, animal});
        }
        ++orderNumber;
    }

    void pollAll() {
        while (!DogQueue.empty() && !CatQueue.empty()) {
            if (DogQueue.front().first < CatQueue.front().first) {
                printf("%s %d\n", DogQueue.front().second.getType().c_str(), DogQueue.front().second.getNumber());
                DogQueue.pop();
            } else {
                printf("%s %d\n", CatQueue.front().second.getType().c_str(), CatQueue.front().second.getNumber());
                CatQueue.pop();
            }
        }
        while (!DogQueue.empty()) {
            printf("%s %d\n", DogQueue.front().second.getType().c_str(), DogQueue.front().second.getNumber());
            DogQueue.pop();
        }
        while (!CatQueue.empty()) {
            printf("%s %d\n", CatQueue.front().second.getType().c_str(), CatQueue.front().second.getNumber());
            CatQueue.pop();
        }
        // Reset the order number
        orderNumber = 0;
    }

    void pollDog() {
        while (!DogQueue.empty()) {
            printf("%s %d\n", DogQueue.front().second.getType().c_str(), DogQueue.front().second.getNumber());
            DogQueue.pop();
        }
    }

    void pollCat() {
        while (!CatQueue.empty()) {
            printf("%s %d\n", CatQueue.front().second.getType().c_str(), CatQueue.front().second.getNumber());
            CatQueue.pop();
        }
    }

    bool isEmpty() const {
        return (DogQueue.empty() && CatQueue.empty());
    }

    bool isDogEmpty() const {
        return DogQueue.empty();
    }

    bool isCatEmpty() const {
        return CatQueue.empty();
    }
};

DogAndCatQueue A;

int main() {

    int n, number;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        if (!strcmp(s, "isEmpty")) {
            printf(A.isEmpty() ? "yes\n" : "no\n");
        } else if (!strcmp(s, "isDogEmpty")) {
            printf(A.isDogEmpty() ? "yes\n" : "no\n");
        } else if (!strcmp(s, "isCatEmpty")) {
            printf(A.isCatEmpty() ? "yes\n" : "no\n");
        } else if (!strcmp(s, "pollAll")) {
            A.pollAll();
        } else if (!strcmp(s, "pollDog")) {
            A.pollDog();
        } else if (!strcmp(s, "pollCat")) {
            A.pollCat();
        } else {
            scanf("%s %d", s, &number);
            if (!strcmp(s, "cat")) {
                A.add(Cat(number));
            } else {
                A.add(Dog(number));
            }
        }
    }

    return 0;
}