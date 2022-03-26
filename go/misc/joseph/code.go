package joseph

//约瑟夫环问题

//给定n个人，从1 到 n 编号，每隔m个人，删掉一个人，最后剩余一人为止，
// 求最后剩下的那个人的编号

//f(n,m) = (f(n-1, m) + m) % n
//参考： https://blog.csdn.net/u011500062/article/details/72855826
func Joseph(n, m int) int {
	idx := 0
	for i := 2; i <= n; i++ {
		idx = (idx + m) % i
	}

	//注意，由于编号从1开始的，所以这里加1
	return idx + 1
}
