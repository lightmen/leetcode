package main

import "fmt"

func main() {
	nums := []int{3, 2, 3, 1, 2, 4, 5, 5, 6}
	k := 4
	val := findKthLargest(nums, k)
	fmt.Printf("%d\n", val) //4
}
