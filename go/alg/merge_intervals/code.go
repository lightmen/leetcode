package mergeintervals

import "sort"

type intSet [][]int

func (s intSet) Len() int {
	return len(s)
}

func (s intSet) Less(i, j int) bool {
	return s[i][0] < s[j][0]
}

func (s intSet) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
}

func merge(intervals [][]int) (result [][]int) {
	if len(intervals) == 0 {
		return
	}
	sort.Sort(intSet(intervals))
	result = append(result, intervals[0])

	idx := 0
	for i := 1; i < len(intervals); i++ {
		arr := intervals[i]
		if result[idx][1] >= arr[0] {
			if arr[1] > result[idx][1] {
				result[idx][1] = arr[1]
			}
		} else {
			idx++
			result = append(result, arr)
		}
	}

	return
}
