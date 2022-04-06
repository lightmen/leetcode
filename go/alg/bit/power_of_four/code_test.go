package poweroffour

import (
	"testing"
)

func TestIsPowerOfFour(t *testing.T) {
	if isPowerOfFour(0) != false {
		t.Fatal("test failed")
	}

	if isPowerOfFour(16) != true {
		t.Fatal("test failed")
	}

	if isPowerOfFour(5) != false {
		t.Fatal("test failed")
	}

	if isPowerOfFour(1) != true {
		t.Fatal("test failed")
	}
}
