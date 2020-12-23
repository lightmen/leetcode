package stack

func isLeft(c int32) bool {
	if c == '[' || c == '(' || c == '{' {
		return true
	}

	return false
}

//isMatch
func isMatch(c1, c2 int32) bool {
	if getMatch(c1) == c2 || getMatch(c2) == c1 {
		return true
	}

	return false
}


func getMatch(left int32) int32 {
	if left == '[' {
		return']'
	}

	if left == '(' {
		return ')'
	}

	if left == '{'{
		return '}'
	}

	return 0
}

func isValid(s string) bool {
	st := New()

	for _, c1 := range s {
		if isLeft(c1) {
			st.Push(c1)
			continue
		}

		if st.IsEmpty() {
			return false
		}

		c2 := st.Top().(int32)
		if !isMatch(c1, c2) {
			return false
		}

		st.Pop()
	}

	if !st.IsEmpty() {
		return false
	}

	return true
}
