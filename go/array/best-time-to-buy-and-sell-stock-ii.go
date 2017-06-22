func maxProfit(prices []int) int {
    var ret int

    for i := 1; i < len(prices); i++ {
        if(prices[i] > prices[i-1]) {
            ret += prices[i] - prices[i-1]
        }
    }

    return ret
}
