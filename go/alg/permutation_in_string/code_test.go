package permutationinstring

import "testing"

func TestCheckInclusion(t *testing.T) {
	s1 := "adc"
	s2 := "dcda"
	ok := checkInclusion(s1, s2)
	t.Logf("%v", ok)
}
