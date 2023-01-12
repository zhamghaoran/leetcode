package main

import (
	"strings"
)

func evaluate(s string, knowledge [][]string) string {
	a := strings.Builder{}
	mapp := make(map[string]string)
	for _, i := range knowledge {
		mapp[i[0]] = i[1]
	}
	for i := 0; i < len(s); i++ {
		if s[i] != '(' {
			a.WriteByte(s[i])
		} else {
			b := strings.Builder{}
			i++
			for s[i] != ')' {
				b.WriteByte(s[i])
				i++
			}
			s2, err := mapp[b.String()]
			if err != false {
				a.WriteString(s2)
			} else {
				a.WriteByte('?')
			}
		}
	}
	return a.String()
}
func main() {
	s := "(name)is(age)yearsold"
	b := [][]string{{"name", "bob"}, {"age", "two"}}
	println(evaluate(s, b))
}
