package stack

func max(v1, v2 int) int {
	if v1 > v2 {
		return v1
	}

	return v2
}

func scoreOfParentheses(S string) int {
	st := make([]int, len(S))
	top := 0
	st[top] = 0

	for _, s := range S {
		if s == '(' {
			top++
			st[top] = 0
			continue
		}

		cur := st[top]
		top--
		st[top] += max(cur*2, 1)

	}

	return st[top]
}

func scoreOfParentheses1(S string) int {
	 dep := 0
	 score := 0

	for i := 0; i < len(S); i++ {
		if S[i] == '(' {
			dep++
			continue
		}

		dep--
		if S[i-1] == '(' {
			score += (1 << dep)
		}
	}

	return score
}
