// https://www.nowcoder.com/practice/ed85a09f0df047119e94fb3e5569855a

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/

class Plus {
public:
    ListNode *plusAB(ListNode *a, ListNode *b) {

        const int MAXN_ADD = 3000, GAP = 48;
        int numx[MAXN_ADD], numy[MAXN_ADD];

        auto Add = [&](string &x, string &y) {

            string res;
            memset(numx, 0, sizeof(numx));
            memset(numy, 0, sizeof(numy));
            int lenx = static_cast<int>(x.size()), leny = static_cast<int>(y.size());
            int maxlen = lenx > leny ? lenx : leny;

            for (int i = 0; i < lenx; i++)numx[lenx - i - 1] = x[i] - '0';
            for (int i = 0; i < leny; i++)numy[leny - i - 1] = y[i] - '0';

            for (int i = 0; i <= maxlen; i++) {
                numx[i] += numy[i];
                if (numx[i] > 9) {
                    numx[i + 1] += numx[i] / 10;
                    numx[i] %= 10;
                }
            }

            int i = maxlen + 2;
            for (; i > 0 && !numx[i];)
                i--;
            for (; i >= 0; i--)
                res += numx[i] + '0';
            return res;
        };


        if (!a && !b) {
            return a;
        } else if (!a) {
            return b;
        } else if (!b) {
            return a;
        }

        string A, B, C;

        ListNode *currentPtr = a;
        while (currentPtr) {
            A += to_string(currentPtr->val);
            currentPtr = currentPtr->next;
        }
        reverse(A.begin(), A.end());

        currentPtr = b;
        while (currentPtr) {
            B += to_string(currentPtr->val);
            currentPtr = currentPtr->next;
        }
        reverse(B.begin(), B.end());

        C = Add(A, B);
        reverse(C.begin(), C.end());
        int len = static_cast<int>(C.size());

        vector < ListNode * > res;
        int i;
        for (i = 0; i < len; i++) {
            auto newPtr = new ListNode(C[i] - GAP);
            res.push_back(newPtr);
        }
        for (i = 0; i < len - 1; i++) {
            res[i]->val = C[i] - GAP;
            res[i]->next = res[i + 1];
        }

        res[len - 1]->val = C[len - 1] - GAP;
        res[len - 1]->next = nullptr;

        return res[0];
    }
};