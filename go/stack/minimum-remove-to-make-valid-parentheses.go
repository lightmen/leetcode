package stack

func minRemoveToMakeValid(s string) string {
	st := make([]int32, len(s))
	top := -1

	idSt := make([]int, len(s))
	idTop := -1

	for idx, v := range s {
		if v == '(' || (v == ')' && (top == -1 || st[top] != '(') ){
			top++
			st[top] = v

			idTop++
			idSt[idTop] = idx
			continue
		}else if v == ')' {
			top--
			idTop--
		}
	}

	for idTop > -1 {
		idx := idSt[idTop]
		idTop--

		s = s[:idx] + s[idx+1:]
	}

	return s
}
