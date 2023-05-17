func haveConflict(event1 []string, event2 []string) bool {
	beh1, _ := strconv.Atoi(event1[0][0:2])
	bet1, _ := strconv.Atoi(event1[0][3:5])
	betim1 := beh1*60 + bet1
	endh1, _ := strconv.Atoi(event1[1][0:2])
	ent1, _ := strconv.Atoi(event1[1][3:5])
	end1 := endh1*60 + ent1
	beh2, _ := strconv.Atoi(event2[0][0:2])
	bet2, _ := strconv.Atoi(event2[0][3:5])
	betim2 := beh2*60 + bet2
	endh2, _ := strconv.Atoi(event2[1][0:2])
	ent2, _ := strconv.Atoi(event2[1][3:5])
	end2 := endh2*60 + ent2
	fmt.Println(betim1, betim2, end1, end2)
	if betim1 >= betim2 {
		if betim1 <= end2 {
			return true
		}
		return false
	} else {
		if end1 >= betim2 {
			return true
		}
		return false
	}
}