package spiralmatrix

func spiralOrder(matrix [][]int) (result []int) {
	if len(matrix) <= 0 {
		return
	}

	mode := 1
	rows := len(matrix)
	cols := len(matrix[0])
	flag := make([][]bool, rows)
	for i := 0; i < rows; i++ {
		flag[i] = make([]bool, cols)
	}

	isVisited := func(i, j int) bool {
		if i < 0 || i >= rows || j < 0 || j >= cols {
			return true
		}

		if flag[i][j] {
			return true
		}

		return false
	}

	i := 0
	j := 0
	for {
		if isVisited(i, j) {
			break
		}

		result = append(result, matrix[i][j])
		flag[i][j] = true

		switch mode {
		case 1:
			j++
			if isVisited(i, j) {
				mode = 2
				j--
				i++
			}
		case 2:
			i++
			if isVisited(i, j) {
				mode = 3
				i--
				j--
			}
		case 3:
			j--
			if isVisited(i, j) {
				mode = 4
				j++
				i--
			}
		case 4:
			i--
			if isVisited(i, j) {
				mode = 1
				i++
				j++
			}

		}
	}

	return
}
