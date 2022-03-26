package generateparentheses

func generateParenthesis(n int) (arr []string) {
	if n == 0 {
		return
	}

	set := make(map[string]struct{})
	set["()"] = struct{}{}

	for i := 2; i <= n; i++ {
		newSet := make(map[string]struct{})
		for str := range set {
			for i := 0; i <= len(str); i++ {
				newStr := str[:i] + "()" + str[i:]
				newSet[newStr] = struct{}{}
			}
		}
		set = newSet
	}

	for str := range set {
		arr = append(arr, str)
	}

	return arr
}
