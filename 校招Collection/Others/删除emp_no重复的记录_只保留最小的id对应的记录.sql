/*
https://www.nowcoder.com/practice/3d92551a6f6d4f1ebde272d20872cf05
*/
delete
from titles_test
where (titles_test.id, titles_test.emp_no) not in
      (
          select min(A.id), A.emp_no
          from titles_test as A
          group by A.emp_no
      )
;