package removekdigits

import (
	"testing"
)

func TestNum(t *testing.T) {
	num := "1432219"
	k := 3
	t.Logf("%s", removeKdigits(num, k)) //1219

	num = "10200"
	k = 1
	t.Logf("%s", removeKdigits(num, k)) //200

	num = "10"
	k = 2
	t.Logf("%s", removeKdigits(num, k)) //0
}
