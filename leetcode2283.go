
func digitCount(num string) bool {
	ans := make([]int, 0)
	for i, _ := range num {
		cnt := 0
		for _, j1 := range num {
			if int(j1-'0') == i {
				cnt++
			}
		}
		ans = append(ans, cnt)
	}
	for i := 0; i < len(num); i++ {
		if int(num[i]-'0') != ans[i] {
			return false
		}
	}
	return true
}
func main() {
	println(digitCount("030"))
}
