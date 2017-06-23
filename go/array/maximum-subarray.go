func maxSubArray(nums []int) int {
    var maxsum, cursum int

    maxsum = math.MinInt32
    for _, value := range nums {
        cursum += value
        if cursum > maxsum {
            maxsum = cursum
        }
        if cursum < 0 {
            cursum = 0
        }
    }

    return maxsum
}
