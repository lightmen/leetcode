package yuan_quan_zhong_zui_hou_sheng_xia_de_shu_zi_lcof

import "testing"

func TestLastRemaining(t *testing.T) {
	var result int
	result = lastRemaining(5, 3)
	if  result != 3 {
		t.Fatalf("test failed: %d", result)
	}

	result = lastRemaining(10, 17)
	if  result != 2 {
		t.Fatalf("test failed: %d", result)
	}
}
