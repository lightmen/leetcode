package stack

import "strings"

func isValidSerialization(preorder string) bool {
	arrs := strings.Split(preorder, ",")
	slots := 1

	for _, val := range arrs {
		slots--
		if slots < 0 {
			return false
		}

		if val != "#" {
			slots += 2
		}
	}

	return slots == 0
}

