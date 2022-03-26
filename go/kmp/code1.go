package kmp

import "fmt"

func buildNext(s string) (next []int) {
	if len(s) <= 1 {
		return []int{-1}
	}

	next = make([]int, len(s))
	next[0] = -1
	next[1] = 0

	idx := 2
	cn := 0
	for idx < len(s) {
		if s[idx-1] == s[cn] {
			next[idx] = cn + 1
			cn++
			idx++
		} else if cn > 0 {
			cn = next[cn]
		} else {
			next[idx] = 0
			idx++
		}
	}

	// for i := 2; i < len(s); i++ {
	// 	j := i - 1
	// 	for j >= 0 {
	// 		if j > 0 && s[i-1] == s[next[j]] {
	// 			next[i] = next[j] + 1
	// 			break
	// 		} else if j > 0 {
	// 			j = next[j]
	// 		} else if j == 0 {
	// 			next[i] = 0
	// 			break
	// 		}
	// 	}
	// }
	return
}

func Kmp(s string, pattern string) int {
	if len(pattern) == 0 || len(s) < len(pattern) {
		return -1
	}

	next := buildNext(pattern)
	fmt.Println(pattern)
	fmt.Println(next)
	i, j := 0, 0
	for i < len(s) && j < len(pattern) {
		if s[i] == pattern[j] {
			i++
			j++
		} else if j == 0 {
			i++
		} else {
			j = next[j]
		}
	}

	if j == len(pattern) {
		return i - j
	}

	return -1
}
