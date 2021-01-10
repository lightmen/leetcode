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
	type node struct {
		id int
		time int
	}
	arr := make([]int, n)
	st := make([]*node, len(logs))

	top := -1

	for _, s := range logs {
		id, op, t := parseLog(s)
		if op == "start" {
			if top > -1 {
				arr[st[top].id] += t - st[top].time
				st[top].time = t
			}
			top++
			st[top] = &node{id:id, time:t}
			continue
		}

		node := st[top]
		top--
		arr[node.id] += t - node.time + 1
		if top > -1 {
			st[top].time = t + 1
		}
	}

	return arr
}
