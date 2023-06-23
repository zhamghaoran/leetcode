package main

import (
	"math"
	"strconv"
)

func maximumValue(strs []string) int {
	var ans = 0
	for _, j := range strs {
		num, err := strconv.Atoi(j)
		if err != nil {
			ans = int(math.Max(float64(ans), float64(len(j))))
		} else {
			ans = int(math.Max(float64(num), float64(ans)))
		}
	}
	return ans
}

func main() {

}
