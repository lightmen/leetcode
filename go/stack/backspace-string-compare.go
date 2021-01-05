package stack

func toStack(s string) (st []int32, top int) {
	top = -1
	st = make([]int32, len(s))
	for _, val := range s {
		if val != '#' {
			top++
			st[top] = val
		}else if top > -1{
			top--
		}
	}

	return
}

func backspaceCompare(S string, T string) bool {
	st1, top1 := toStack(S)
	st2, top2 := toStack(T)

	if top1 != top2 {
		return false
	}

	for idx := 0; idx <= top1; idx++ {
		if st1[idx] != st2[idx] {
			return false
		}
	}
	return true
}
