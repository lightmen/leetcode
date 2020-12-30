package stack

import "strconv"

func calPoints(ops []string) int {
	st := make([]int, len(ops))
	top := -1

	for _, s := range ops {
		switch s {
		case "C":
			top--
		case "D":
			val := st[top] * 2
			top++
			st[top] = val
		case "+":
			val := st[top-1] + st[top]
			top++
			st[top] = val
		default:
			val,_ := strconv.ParseInt(s, 10, 64)
			top++
			st[top] = int(val)
		}
	}

	var sum int
	for idx := 0; idx <= top; idx++ {
		sum += st[idx]
	}

	return sum
}
