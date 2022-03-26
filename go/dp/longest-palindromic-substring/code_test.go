package dp

import "testing"

func TestLongestPalindrome(t *testing.T) {
	s := "aba"
	rs := longestPalindrome(s)
	if rs != "aba" {
		t.Fatalf("test failed: %s", rs)
	}

	s = "cbbd"
	rs = longestPalindrome(s)
	if rs != "bb" {
		t.Fatalf("test failed: %s", rs)
	}
}
