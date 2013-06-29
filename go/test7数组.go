package main

import (
  "fmt"
)

func main() {
	var a [2]int
	var b [2]int
	var c [3]string
	d := [20]int{19: 1}
	e := [...]int{1, 2, 3, 4, 5}
	f := [...]int{0: 1, 1: 2, 2: 3}
	g := [...]int{100: 1}
	fmt.Println(a)
	fmt.Println(b)
	fmt.Println(c)
	fmt.Println(d)
	fmt.Println(e)
	fmt.Println(f)
	fmt.Println(g)
	h := [...]int{99: 1}
	var p *[100]int = &h
	fmt.Println(p)
	fmt.Println(*p)
	x, y := 1, 2
	z := [...]*int{&x, &y}
	fmt.Println(z)

	j := [2]int{1, 2}
	k := [2]int{1, 2}
	fmt.Println(j == k)

	m := [10]int{}
	m[1] = 2
	fmt.Println(m)
	n := new([10]int)
	n[1] = 2
	fmt.Println(n)
	//2个长度为3的数组
	u := [2][3]int{
		{1, 1, 1},
		{2, 2, 2}}
	fmt.Println(u)
	//冒号排序
	v := [...]int{5, 2, 6, 3, 9}
	fmt.Println(v)

	num := len(v)
	for i := 0; i < num; i++ {
		for j := i + 1; j < num; j++ {
			if v[i] < v[j] {
				temp := v[i]
				v[i] = v[j]
				v[j] = temp
			}

		}
	}
	fmt.Println(v)
}
