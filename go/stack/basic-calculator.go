package stack

import (
	"strconv"
)

func isDigit(val int32) bool {
	if val >= '0' && val <= '9' {
		return true
	}

	return false
}
var opW = map[int32]int {
	'(': 0,
	'-': 1,
	'+': 1,
	'*': 2,
	'/':2,
}

func getResult(op1, op2 int, op int32)(val int) {
	switch op {
	case '-':
		val = op1 - op2
	case '+':
		val = op1 + op2
	case '*':
		val = op1 * op2
	case '/':
		val = op1/op2
	}

	return val
}

func calculate(s string) int {
	st := make([]int, len(s))
	top := -1

	opSt := make([]int32, len(s)/2)
	opTop := -1

	for i := 0; i < len(s); i++ {
		c := int32(s[i])
		if c == ' ' {
			continue
		}

		if isDigit(c) {
			j := i+1
			for j <len(s) {
				if !isDigit(int32(s[j])) {
					break
				}
				j++
			}
			tmp := s[i:j]
			val, _ := strconv.Atoi(tmp)
			top++
			st[top] = val
			i = j - 1
			continue
		}

		if c == '(' {
			opTop++
			opSt[opTop] = c
			continue
		}

		if c == ')' || (opTop > -1 && opW[opSt[opTop]] >= opW[c]) {
			for opTop > -1 {
				topC := opSt[opTop]
				if topC == '(' || opW[topC] < opW[c] {
					break
				}

				opTop--

				var result int
				if top >= 1 {
					op2 := st[top]
					top--
					op1 := st[top]
					top--

					result = getResult(op1, op2, topC)
				}else {
					result = st[top]
					top--
					if topC == '-' {
						result = -result
					}
				}


				top++
				st[top] = result
			}
		}

		if c == ')' {
			opTop--
			continue
		}



		opTop++
		opSt[opTop] = c
	}

	for opTop > -1 {
		topC := opSt[opTop]
		opTop--

		var result int
		if top >= 1 {
			op2 := st[top]
			top--
			op1 := st[top]
			top--

			result = getResult(op1, op2, topC)
		}else {
			result = st[top]
			top--
			if topC == '-' {
				result = -result
			}
		}

		top++
		st[top] = result
	}

	return st[0]
}
