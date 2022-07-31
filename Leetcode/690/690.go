/**
 * Definition for Employee.
 * type Employee struct {
 *     Id int
 *     Importance int
 *     Subordinates []int
 * }
 */

func dfs(id2employee *map[int]*Employee, id int, result *int) {
	temp := (*id2employee)[id]
	*result += temp.Importance
	for i := 0; i < len(temp.Subordinates); i++ {
		dfs(id2employee, temp.Subordinates[i], result)
	}
}

func getImportance(employees []*Employee, id int) int {
	id2employee := make(map[int]*Employee)
	for i := 0; i < len(employees); i++ {
		id2employee[employees[i].Id] = employees[i]
	}
	val, ok := id2employee[id]
	if !ok {
		return 0
	}
	result := val.Importance
	for i := 0; i < len(val.Subordinates); i++ {
		dfs(&id2employee, val.Subordinates[i], &result)
	}
	return result
}