package wildcardmatregularexpressionmatchingching

import "testing"

func TestIsMatch(t *testing.T) {
	s := "aa"
	p := ".*"

	ok := isMatch(s, p)
	t.Logf("%v\n", ok)
}
