package longest_palindromic_substring

import "testing"

func TestLongestPalindrome(t *testing.T) {
	s := "babad"
	result := longestPalindrome(s)
	if result != "bab" && result != "aba" {
		t.Fatalf("test failed:%s", result)
	}

	s = ""
	result = longestPalindrome(s)
	if result != "" {
		t.Fatalf("test failed:%s", result)
	}

	s = "a"
	result = longestPalindrome(s)
	if result != "a" {
		t.Fatalf("test failed:%s", result)
	}
}
