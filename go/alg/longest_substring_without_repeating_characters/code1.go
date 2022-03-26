package longest_substring

func lengthOfLongestSubstring1(s string) int {
	var index [256]int
	for i := 0; i < len(index); i++ {
		index[i] = -1
	}

	lastIndex := -1
	maxSub := 0
	for i := 0; i < len(s); i++ {
		ch := int(s[i])
		if index[ch] >= lastIndex {
			lastIndex = index[ch] + 1
		}

		index[ch] = i
		if i-lastIndex+1 > maxSub {
			maxSub = i - lastIndex + 1
		}
	}

	return maxSub
}
