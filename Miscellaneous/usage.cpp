#include <bits/extc++.h> // 万用头文件

// 编译
// g++ -std=c++17 -Wall -O2 usage.cpp -o usage
// 执行
// ./usage
// 调试的两种方法: 先把样例copy到in文件中
// 1. freopen("/home/ugd/haohu.shen/cpsc/in", "r", stdin);
// 2. 不用freopen 命令行下 ./usage < in

// 注意
// 1. 这里案例部分借鉴http://www.cplusplus.com/reference
// 2. 不考虑多线程
// 3. 建议把https://oi-wiki.org/lang/helloworld/ 语言基础部分过一遍

// using所有可能用到的命名空间
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

// 用ll作为long long类型的别名
using ll = long long;   // -2^63 to 2^63-1
// int: -2^31 to 2^31-1
// __int128 -2^127 to 2^127-1

// 类型
void type_demo() {
    int a;
    const int a_ = 1; // const前缀表示常量
    double b;   // 浮点数
    bool k; // 布尔变量 只有true和false
    int &a_ref = a; // 引用 可以当成C语言中的指针来理解
    struct Class {
        int a;
        int b;

        Class() {} // 默认构造函数 类似java
        Class(int a, int b) {
            this->a = a;
            this->b = b;
        } // 构造函数 类似java
        // 定义两个Class对象的大小比较方式 看哪个小
        bool operator<(const Class &other) {
            // 先比较成员a a小的则小
            if (a == other.a) {
                // 如果a相同则比较b b小的则小
                return (b < other.b);
            }
            return (a < other.a);
        }
    }; //定义一个名叫Class的类 里面有a b两个成员
    Class obj;
    obj.a = 12;
    string s = "abcd"; //字符串
    char ch = 'a'; // 字符
    vector<int> vec; //数组 里面放int
    vector<Class> vec_; //数组 里面放Class
    set<int> set_obj; // 有序集 里面放int
    set<Class> set_obj_class; // 有序集 里面放Class 因为我们定义了Class的比较方式 这里才能用
    map<int, Class> map_obj; // 有序集 有key也有value 只不过只根据key排序
    unordered_set<int> unset_obj; // 无序集 里面放int 和哈希一样 只不过只有key没有value
    unordered_map<int, Class> unmap_obj; // 哈希表 key是int value是Class
    gp_hash_table<int, Class> unmap_obj_; // 也是哈希 但是底层用的是探测法
    stack<Class> stack_obj; // 栈 里面放Class
    queue<Class> queue_obj; // 单向队列 里面放Class
    deque<int> deque_obj; // 双向队列 里面放Class
    forward_list<int> forwardList; // 单链表 里面放int
    list<int> list1; // 双链表
    std::priority_queue<int> pq; // 优先队列 谁小谁就在队列头 和set差不多 只不过set不能放重复值 这个可以
    bitset<32> Bitset; // 二进制数 最多存32位
    regex regex1("^abcd$"); // 正则表达式 编译会慢
}

// 针对不同类型的常用用法
void usage() {

    // vector
    vector<int> vec_;
    vec_.emplace_back(2);    // 数组添加元素
    int int0 = vec_.size(); // 数组长度
    bool bool0 = vec_.empty(); // 数组为空则true
    int int1 = vec_.front(); // 数组首元素
    int int2 = vec_.back(); // 数组尾元素
    int int3 = vec_.at(0); // 访问索引为0的元素 如果索引超出数组长程序会abort
    vector<int> vec_1;
    bool bool1 = (vec_ == vec_1); // 判断两个数组是否相同 同则true
    for (int i = 0; i < int0; ++i) {    // 遍历
        printf("%d\n", vec_.at(i));
    }
    vector<int>().swap(vec_); // 清空vec_

    // string
    string s = "abcd";
    string s2 = "ahq";
    bool bool__ = (s2 > s); // 判断s2和s谁大
    s.push_back('a'); // abcd + a = abcda
    s.pop_back(); // abcda - 尾巴 = abcd
    s.size(); // 字符串大小
    s += "AAA"; // abcd + AAA = abcdAAA
    bool bool_ = s.empty(); // 空则true
    string s_ = "abcd";
    bool bool2 = (s == s_); // 判断两个字符串是否相同 同则true
    printf("%s\n", s_.c_str()); // 打印字符串并换行
    string sub = s.substr(0, 2); // 取s的字串 从s的索引0开始取两个
    char ch2 = s.at(0); // 访问s的第0个字符

    // 如果在字符串s中找到字符d 则返回它的第一个出现的位置
    size_t position = s.find('d');
    if (position != string::npos) {
        printf("%d\n", (int) position); // size_t打印前转int 写法和java类似
    }
    s = ""; // 清空s

    // stack
    stack<int> stack1;
    int int4 = stack1.size();  // 栈大小
    bool bool3 = stack1.empty();  // 空则true
    stack1.push(12);    // 入栈
    int int5 = stack1.top(); // 把栈顶值赋给int5 栈空则报错
    stack1.pop(); // 弹出栈顶 栈空则报错
    // 栈没办法直接遍历 如果题目需要遍历自己另开个数组存数据 或者用两个栈相互push pop

    // set
    // set 因为它底层是红黑树 因此每个操作都是O(logn)
    set<int> set1;
    int int6 = set1.size(); // 集合大小
    bool bool4 = set1.empty(); // 空则true
    set1.insert(12); // 插入12
    bool bool5 = (set1.find(13) != set1.end()); // 在集合中查有没有13 有则true
    set1.clear(); // 清空set1

    set<int> set2;
    set2.insert(8);
    set2.insert(5);
    set2.insert(9);
    set2.insert(13);
    set2.insert(78);
    set2.insert(9);
    // 遍历
    for (const auto &i : set2) {
        printf("%d ", i);  // 5 8 9 13 78
    }
    set<int> myset;
    for (int i = 1; i < 10; i++) {
        myset.insert(i * 10); // 10 20 30 40 50 60 70 80 90
    }
    set<int>::iterator itlow, itup;  // set<int>的迭代器 类似C的指针 用*解引用取值
    itlow = myset.lower_bound(30); // itlow指向第一个大于等于30的位置 也就是30
    itup = myset.upper_bound(30); // itup指向第一个大于30的位置 也就是40
    // 如果迭代器 == myset.end() 说明没找到 直接指向set最后一个元素后边不存在的位置
    set<int>::iterator iter2 = myset.begin(); // 指向myset第一个元素 如果myset为空则指向myset.end()
    set<int>::reverse_iterator iter3 = myset.rbegin(); // 指向myset最后一个元素
    // 关于set的一道例题 https://ac.nowcoder.com/acm/problem/17508
    // asnwer: https://github.com/H-Shen/Collection_of_my_coding_practice/blob/master/Others/%E6%A0%A1%E6%8B%9BCollection/Others/%E6%8C%87%E7%BA%B9%E9%94%81.cpp

    // map
    // map 底层也是红黑树(默认顺序从小到大) 因此每个操作都是O(logn) 和set不同点就是可以存键值对
    // map<key, value> varname
    map<int, int> map0;
    map0[2] = 3; // insert(2, 3) to varname
    map0[2] = 4; // update(2, 3) to (2, 4)
    int int7 = map0.size(); // get the size of map
    map0.clear(); // 清空map0
    // 遍历map
    for (const auto &[key, value] : map0) {
        printf("%d %d\n", key, value);
    }
    bool bool6 = map0.empty(); // 空则true
    bool bool7 = (map0.find(2) != map0.end()); // 判断有没有2这个key
    // map也有lower_bound upper_bound方法 和set一样 只不过是针对key的二分 不针对value

    // unordered_map用法和map类似 但是它是哈希表因此无序 所以不能二分 复杂度O(1)

    // unordered_set用法和set类似 但是它是哈希表因此无序 所以不能二分 复杂度O(1)

    // 如果要往哈希表中放自定义类型 那得自己写哈希函数并重载== cpp自带的字符串不用写 比如
    struct Fuck {
        int a;
        int b;

        Fuck(int a_, int b_) : a(a_), b(b_) {}

        // 重载== 告诉程序怎么样情况下两个Fuck对象相同
        bool operator==(const Fuck &other) const {
            // 对应a, b相同则对象相等
            return (a == other.a && b == other.b);
        }
    };
    // 写哈希函数就按这个格式写
    struct Fuck_Hash_Function {
        // 哈希两个整数 最简单的一个办法的用他们的xor 反正不需要你处理哈希冲突
        size_t operator()(const Fuck &obj) const {
            return hash<int>()(obj.a) ^ hash<int>()(obj.b);
        }
    };
    // ok, 现在可以放了
    unordered_set<Fuck, Fuck_Hash_Function> set3;
    set3.insert(Fuck(2, 3));
    set3.insert(Fuck(2, 3));
    set3.insert(Fuck(7, 8));
    set3.insert(Fuck(11, 111));
    for (const auto &[key, value] : set3) {
        printf("%d %d\n", key, value);
    }
    unordered_map<Fuck, string, Fuck_Hash_Function> umap;
    umap[Fuck(1, 111)] = "1, 111";
    umap[Fuck(11, 1)] = "13, 111";
    umap[Fuck(11, 1)] = "13, 112";

    // 单向队列queue 先进先出O(1)
    queue<int> q;
    int q_length = q.size();
    q.push(12);
    q.push(13);
    int q_top = q.front();  // 把队列头的值给q_top 如果队列本来空则报错
    int q_back = q.back();  // 把队列尾的值给q_back 如果队列本来空则报错
    q.pop();    // 弹出队列头 如果队列本来空则报错
    bool q_is_empty = q.empty(); // 判空
    // queue不能直接遍历

    // 双向队列deque 左边右边能进出O(1)
    deque<int> deque1;
    deque1.clear(); // 清空
    bool deque1_is_empty = deque1.empty(); // 判空
    deque1.push_front(1); // push到左边
    deque1.push_back(2); // push到右边
    int deque1_val = deque1.front(); // 取队列左端
    int deque1_val2 = deque1.back(); // 取队列右端
    deque1.pop_front(); // 弹出左端
    deque1.pop_back(); // 弹出右端
    int length_deque1 = deque1.size(); // 队列长度
    // 遍历
    for (int i = 0; i < length_deque1; ++i) {
        printf("%d\n", deque1.at(i));   // 因此取某个索引值用deque.at(i) i非法则报错
    }

    // 优先队列 和set一样但是可存重复值
    std::priority_queue<int> pq; // set<int> pq;
    pq.push(1); // pq.insert(1)
    pq.push(1);
    int pq_length = pq.size();
    bool pq_is_empty = pq.empty();
    int pq_top = pq.top(); // *pq.begin()
    pq.pop(); // pq.erase(pq.begin())

    // 正则表达式
    regex r("^askd$");
    string s_test = "askd";
    bool bool8 = regex_match(s_test, r); // 如果s_test满足表达式r 则返回true

    // 堆heap
    // 建立堆之前先把堆内元素放在数组里
    vector<int> H = {8123, 1211, 111, 0, -12312};
    make_heap(H.begin(), H.end()); // 此时数组H已经变成一个堆了 默认是最大推 也就是堆顶元素最大
    int heap_top = H.front(); // 查看堆顶
    // 如何将堆顶推出堆 (首先保证堆不空 不然报错)
    pop_heap(H.begin(), H.end());
    H.pop_back();
    // 如何往堆内添加元素
    int new_element = 9;
    H.emplace_back(new_element);
    push_heap(H.begin(), H.end());
}

// 常用算法
// 定义一个学生类
struct Student {
    int grade;
    string name;
    Student(int _grade, string _name) : grade(_grade), name(std::move(_name)) {}    // 记住这个写法
};
// 定义如何比较两个学生对象大小: 成绩小的小 成绩相同字符串字典序小的小
bool cmp_func(const Student &left, const Student &right) {
    if (left.grade == right.grade) {
        return (left.name < right.name);
    }
    return (left.grade < right.grade);
}

// 常用的一些算法
void algorithm() {

    vector<int> v = {5, 8, 1, 3, 5, 7, 9, 3};
    vector<int> v_ = v; // 拷贝一份

    vector<Student> v_stu = {Student(98, "A"), Student(60, "B"), Student(0, "C")};
    vector<Student> v_stu_ = v_stu; // 拷贝一份

    // 不稳定排序 O(nlogn)
    sort(v_.begin(), v_.end());
    sort(v_stu_.begin(), v_stu_.end(), cmp_func);

    // 稳定排序 O(nlognlogn)
    stable_sort(v_.begin(), v_.end());
    stable_sort(v_stu_.begin(), v_stu_.end(), cmp_func);

    // 部分排序
    partial_sort(v_.begin(), v_.begin() + 3, v_.end()); // 保证第0到第3个元素有序

    // 求两个数的最大最小值
    int a = 123123;
    int b = 12391111;
    int max_of_a_and_b = max(a, b);
    int min_of_a_and_b = min(a, b);
    a = clamp(a, 133, 9012811);     // 限制a的数值在133和9012811之间

    // 堆排序
    vector<int> heap = {6, 2, 1, -1};
    make_heap(heap.begin(), heap.end());
    sort_heap(heap.begin(), heap.end());

    vector<int> p = {1, 2, 6, 1, 8, 0, 3};
    sort(p.begin(), p.end());
    // 二分法查8在不在数组中 如果在 打印它第一次出现的索引
    if (binary_search(p.begin(), p.end(), 8)) {
        printf("%d\n", (int)(lower_bound(p.begin(), p.end(), 8) - p.begin()));
    }

    bool bool0 = is_sorted(p.begin(), p.end());  // 判断p有没有从小到大排序 已经排序则返回true
    reverse(p.begin(), p.end()); // 反转p 类似Python中的p.reverse()
    swap(a, b); // 交换a b

    // O(n)求第k小的数
    vector<int> p_ = {5, 1, 8, 1, 2, 3};
    nth_element (p_.begin(), p_.begin()+5, p_.end()); //此时第5小的数是p_.at(4)
}

// 集合操作
// 求并 输出到v
void vector_union(vector <int> &v1, vector <int> &v2, vector <int> &v) {

  	set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v));
}
// 求交 输出到v
void vector_intersection(vector <int> &v1, vector <int> &v2, vector <int> &v) {

  set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v));
}
// 求差 输出到v
void vector_difference(vector <int> &v1, vector <int> &v2, vector <int> &v) {

  set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v));
}

// 集合测试
void set_operation_test() {

	vector <int> A = {5,4,3,1,2};
	vector <int> B = {1,4,3,1,2};
	vector <int> C;

	vector <int> ().swap(C);
	C.reserve(A.size() + B.size());
	
  // 先排序!!!
  sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	vector_union(A, B, C);

	unordered_set <int> res (C.begin(), C.end());

  // output
	for (auto i : res) {
		cout << i << endl;
	}
}
// 对拍
// 当你不确定当前算法是否准确的时候 可以再写一个另外一种解法 这种解法一般复杂度很高 但逻辑更为直接 比如用bruteforce
// 然后生成随机数据 用bruteforce程序求出一系列解 和你当前算法根据相同数据得出的解作比较
// 如果时间足够的情况下我们能用bruteforce遍历所有的情况并且对应你的算法得出的解都吻合
// 说明当前算法是对的 就算不能遍历所有情况 那么数据量足够多 准确率也更高 这样也能拿一部分分
// 随机数据生成到in文件中 两种算法分别输出out0 out1 然后命令行 diff out0 out1 检查是否相同
// a1 < in > out0
// a2 < in > out1
// diff a1 a2

// 主函数
int main() {

    // freopen("/home/ugd/haohu.shen/cpsc/in", "r", stdin);    // 读取in中的内容 调试用
    // freopen("/home/ugd/haohu.shen/cpsc/out", "w", stdout);  // 把程序运行结果输出至out 调试用
    usage();
    algorithm();

    return 0;
}
