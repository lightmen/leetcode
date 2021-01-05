package stack

import "strings"

type node struct {
	left bool
	right bool
}
func isValidSerialization(preorder string) bool {
	arrs := strings.Split(preorder, ",")

	st := make([]*node, len(arrs))
	top := -1

	if len(arrs) == 1 && arrs[0] == "#" {
		return true
	}

	for idx, val := range arrs {
		if val == "#" {
			if top < 0 {
				return false
			}

			for top >= 0{
				node := st[top]
				if !node.left {
					node.left = true
					break
				}
				if !node.right {
					top--
				}
			}
			
			if top < 0 && idx < len(arrs)-1 {
				return false
			}
		}else {
			top++
			st[top] = &node{}
		}
	}

	if top >= 0 {
		return false
	}

	return true
}

