package permutationinstring

func checkInclusion(s1 string, s2 string) bool {
	if len(s2) < len(s1) {
		return false
	}

	cnt1 := [26]int{}
	cnt2 := [26]int{}
	for i, v := range s1 {
		cnt1[v-'a']++
		cnt2[s2[i]-'a']++
	}

	if cnt1 == cnt2 {
		return true
	}

	for i := len(s1); i < len(s2); i++ {
		cnt2[s2[i]-'a']++
		cnt2[s2[i-len(s1)]-'a']--
		if cnt1 == cnt2 {
			return true
		}
	}

	return false
}
