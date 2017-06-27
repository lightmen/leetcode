func plusOne(digits []int) []int {
    var carry = 1
    var arr = make([]int, len(digits) + 1)

    for i := len(digits); i > 0; i-- {
        arr[i] = (digits[i-1] + carry) % 10
        carry = (digits[i-1] + carry) / 10
    }

    if carry == 1 {
        arr[0] = carry
        return arr
    }
    return arr[1:]
}
