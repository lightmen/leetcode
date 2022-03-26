package largestnumber

import (
	"sort"
	"strconv"
)

type IntSlice []int

func (s IntSlice) Len() int {
	return len(s)
}

func (s IntSlice) Less(i, j int) bool {
	si := strconv.Itoa(s[i])
	sj := strconv.Itoa(s[j])

	return si+sj > sj+si
}

func (s IntSlice) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
}

func largestNumber(nums []int) string {
	sort.Sort(IntSlice(nums))
	s := ""
	for _, val := range nums {
		s += strconv.Itoa(val)
	}

	return s
}
