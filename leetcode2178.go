package main

func maximumEvenSplit(finalSum int64) []int64 {
	var ans []int64
	if finalSum&1 == 1 {
		return []int64{}
	}
	if finalSum < 2 {
		return []int64{}
	}
	var sum int64
	var now int64 = 2
	for sum <= finalSum {
		if sum+now <= finalSum {
			ans = append(ans, now)
			sum += now
			now += 2
		} else {
			ans[len(ans)-1] = finalSum - sum + ans[len(ans)-1]
			break
		}
	}
	return ans
}

func main() {


}
