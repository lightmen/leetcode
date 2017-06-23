func twoSum(numbers []int, target int) []int {
    var i, j int
    for i = 0; i < len(numbers); i++ {
        j = search(numbers, target - numbers[i], i + 1, len(numbers) - 1)
        if(j != -1){
            break
        }
    }

    return []int{i+1, j+1}
}

func search(numbers []int, target, start, end int) int {
    for start <= end {
        mid := (start + end) / 2
        if(numbers[mid] == target){
            return mid
        }else if(numbers[mid] > target){
            end = mid - 1
        }else{
            start = mid + 1
        }
    }

    return -1
}
