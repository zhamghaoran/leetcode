func subtractProductAndSum(n int) int {
	var chen int = 1
	var sum int = 0
	for n > 0 {
		chen *= n % 10
		sum += n % 10
		n /= 10
	}
	return chen - sum
}
func main() {

}