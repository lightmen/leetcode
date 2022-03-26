package sum

import "sort"

func threeSum(nums []int) [][]int {
	sort.Ints(nums)

	arr := make([][]int, 0)
	for i := 0; i < len(nums)-2; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}

		if nums[i] > 0 || nums[i]+nums[i+1] > 0 {
			break
		}

		l := i + 1
		r := len(nums) - 1
		for l < r {
			if l > i+1 && nums[l] == nums[l-1] {
				l++
				continue
			}

			sum := nums[i] + nums[l] + nums[r]
			if sum > 0 {
				r--
			} else if sum < 0 {
				l++
			} else {
				arr = append(arr, []int{nums[i], nums[l], nums[r]})
				l++
				r--
			}
		}
	}

	return arr
}
