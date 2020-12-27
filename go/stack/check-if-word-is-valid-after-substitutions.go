package stack

func isValid1(s string) bool {
	st := New()
	for _, c := range s {
		if c < 'c' {
			st.Push(c)
			continue
		}

		if st.Len() < 2 {
			return false
		}

		b := st.Pop()
		if b.(int32) != 'b' {
			return false
		}

		a := st.Pop()
		if a.(int32) != 'a' {
			return false
		}
	}

	return st.Len() == 0
}
