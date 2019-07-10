/* https://www.nowcoder.com/practice/be806d482bb14b07b58091817042b42e */

/* Initializtion */
CREATE TABLE "Employee" (
	"Id"	INTEGER NOT NULL PRIMARY KEY UNIQUE,
	"Name"	TEXT NOT NULL,
	"Salary"	INTEGER NOT NULL,
	"DepartmentId"	INTEGER NOT NULL
);

INSERT INTO "Employee" VALUES (1, "Mandy", 10000, 1);
INSERT INTO "Employee" VALUES (2, "Henry", 21000, 2);
INSERT INTO "Employee" VALUES (3, "Tom", 15000, 2);
INSERT INTO "Employee" VALUES (4, "Mike", 20000, 1);

CREATE TABLE "Department" (
	"Id"	INTEGER NOT NULL UNIQUE,
	"Name"	TEXT NOT NULL,
	PRIMARY KEY("Id")
);

INSERT INTO "Department" VALUES (1, "Sale A");
INSERT INTO "Department" VALUES (2, "Sale B");

/* Find the name of the employee, the salary and the DepartmentId  with the second max salary in their department */
SELECT * FROM
(
SELECT b.Name, a.Name, a.Salary
FROM Employee AS a, Department AS b
WHERE a.DepartmentId = b.Id
) WHERE Name = "Sale A"
ORDER BY
Salary DESC
LIMIT 1 OFFSET 1;

SELECT * FROM
(
SELECT b.Name, a.Name, a.Salary
FROM Employee AS a, Department AS b
WHERE a.DepartmentId = b.Id
) WHERE Name = "Sale B"
ORDER BY
Salary DESC
LIMIT 1 OFFSET 1;

