func maxProfit(prices []int) int {
    ret := 0;
    cur := int(^uint(0) >> 1)

    for i := 0; i < len(prices); i++ {
        if prices[i] - cur > ret {
            ret = prices[i] - cur
        }
        if prices[i] < cur {
            cur = prices[i]
        }
    }

    return ret
}
