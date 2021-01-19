package basic_calculator_ii

import (
	"strconv"
)

func calculate(s string) int {
	isOp := true
	isNeg := false
	numbers := make([]int, len(s))
	ntop := -1

	ops  := make([]int32, len(s))
	otop := -1

	for i := 0; i < len(s); i++ {
		c := int32(s[i])
		if c == ' ' {
			continue
		}

		if isNumber(c) {
			j := i + 1
			for  j < len(s){
				if !isNumber(int32(s[j])) {
					break
				}
				j++
			}

			tmp := s[i:j]
			val, _ := strconv.Atoi(tmp)
			if isNeg {
				val = -val
			}
			ntop++
			numbers[ntop] = val
			i = j-1
			isNeg = false
			isOp = false
			continue
		}

		if isOp {
			if c == '-' {
				isNeg = true
			}
			continue
		}

		if c == '(' {
			otop++
			ops[otop] = c
			continue
		}

		if c == ')' {
			for ops[otop] != '(' {
				ntop,otop = calc(numbers, ntop, ops, otop)
			}
			otop--
			continue
		}

		for otop > -1 && isHigh(ops[otop], c) {
			ntop,otop = calc(numbers, ntop, ops, otop)
		}

		otop++
		ops[otop] = c
		isOp = true
	}

	for otop > -1 {
		ntop,otop = calc(numbers, ntop, ops, otop)
	}

	return numbers[0]
}

func isNumber (c int32) bool {
	if c >= '0' && c <= '9' {
		return true
	}

	return false
}

func calc(nums []int, ntop int, ops []int32, otop int)(int, int) {
	op := ops[otop]
	otop--
	right := nums[ntop]
	ntop--
	left := nums[ntop]
	ntop--
	var val int
	switch  op {
	case '*':
		val = left * right
	case '/':
		val = left / right
	case '-':
		val = left - right
	case '+':
		val = left + right
	}

	ntop++
	nums[ntop] = val
	return ntop, otop
}

func isHigh(left, right int32) bool {
	if left == '*' || left == '/' {
		return true
	}

	if right == '+' || right == '-' {
		return true
	}
	return false
}