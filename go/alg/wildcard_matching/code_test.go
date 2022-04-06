package wildcardmatching

import "testing"

func TestIsMatch(t *testing.T) {
	s := "aab"
	p := "c*a*b"

	ok := isMatch(s, p)

	t.Logf("ok: %v\n", ok)
}
