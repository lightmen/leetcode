package yuan_quan_zhong_zui_hou_sheng_xia_de_shu_zi_lcof

//see https://blog.csdn.net/u011500062/article/details/72855826
func lastRemaining(n int, m int) int {
	p := 0
	for i := 2; i <= n; i++ {
		p = (p + m) % i
	}
	return p
}
