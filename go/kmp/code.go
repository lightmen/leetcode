package kmp

//返回s1中，首次出现s2的下标，如果s1中不包含s2， 返回-1
func KMP(s1, s2 string) int{

	return -1
}

func getNext(s string) (arr []int) {
	if len(s) <= 1 {
		return []int{-1}
	}

	arr = make([]int, len(s))
	arr[0] = -1
	arr[1] = 1
	idx := 2
	prev := 0
	ch := []byte(s)
	for idx < len(s){
		if ch[idx] == ch[arr[prev]+1] {
			arr[idx] = arr[prev] + 1
			idx++
			prev = idx -1
		}else if arr[prev] == -1 {
			arr[idx] = 1
			idx++
		}else {
			idx = arr[prev]
		}
	}
	return
}