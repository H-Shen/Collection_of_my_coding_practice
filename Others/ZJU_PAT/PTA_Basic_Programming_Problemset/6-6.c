#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
struct Node {
  int Data;
  PtrToNode Next;
};
typedef PtrToNode List;

int FactorialSum(List L);

int main() {
  int N, i;
  List L, p;

  scanf("%d", &N);
  L = NULL;
  for (i = 0; i < N; i++) {
    p = (List)malloc(sizeof(struct Node));
    scanf("%d", &p->Data);
    p->Next = L;
    L = p;
  }
  printf("%d\n", FactorialSum(L));

  return 0;
}

/* Your code will be pasted here */
int FactorialSum(List L) {
  if (!L) {
    return 0;
  }
  PtrToNode ptr = L;
  int res = 0, tmp = 0;
  int i;

  while (ptr) {
    if (ptr->Data == 0) {
      tmp = 1;
    } else {
      tmp = 1;
      for (i = 1; i <= ptr->Data; ++i) {
        tmp *= i;
      }
    }
    res += tmp;
    ptr = ptr->Next;
  }
  return res;
}
