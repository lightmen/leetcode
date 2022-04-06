package hammingdistance

import "testing"

func TestHammingDistance(t *testing.T) {
	cnt := hammingDistance(4, 1)
	t.Logf("%d\n", cnt) //2

	cnt = hammingDistance(3, 1)
	t.Logf("%d\n", cnt) //1
}
