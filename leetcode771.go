package main

func numJewelsInStones(jewels string, stones string) int {
	ans := 0
	for _, v := range stones {
		for _, vv := range jewels {
			if v == vv {
				ans += 1
				break
			}
		}
	}
	return ans
}
func main() {

}
