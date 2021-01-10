package stack

import (
	"strconv"
	"strings"
)

func parseLog(str string)(id int, op string, t int) {
	arr := strings.Split(str, ":")
	id, _ = strconv.Atoi(arr[0])
	op = arr[1]
	t, _ = strconv.Atoi(arr[2])

	return
}

func exclusiveTime(n int, logs []string) []int {
	arr := make([]int, n)
	st := make([]int, len(logs))
	top := -1
	prev := 0

	for _, s := range logs {
		id, op, t := parseLog(s)
		if op == "start" {
			if top > -1 {
				arr[st[top]] += t - prev
			}
			top++
			st[top] = id
			prev = t
			continue
		}

		arr[st[top]] += t - prev + 1
		top--
		prev = t + 1
	}

	return arr
}
