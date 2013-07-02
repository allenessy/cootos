package main

import (
	"fmt"
)

func main() {
	for i := 0; i < 3; i++ {
		v := 1
		fmt.Println(&v)
	}
	//声明slice
	var s1 []int
	fmt.Println(s1)

	a := [10]int{1, 2, 3, 4, 5, 6, 7, 8, 9}
	fmt.Println(a)
	s2 := a[9]
	fmt.Println(s2)
	s3 := a[5:10] //a[5 6 7 8 9]
	s4 := a[5:len(a)]
	fmt.Println(s3)
	fmt.Println(s4)
	//声明slice类型,元素,容量
	ss1 := make([]int, 3, 10)
	fmt.Println(ss1, len(ss1), cap(ss1))

	c := []byte{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k'}
	sa := c[2:5]
	sb := c[3:5]
	fmt.Println(string(sa))
	fmt.Println(string(sb))

	sc := sa[3:5] //c相当于slice sa的1
	fmt.Println(string(sc))

	ss2 := make([]int, 3, 6)
	//打印ss2的内存地址
	fmt.Printf("%p\n", ss2)
	ss2 = append(ss2, 1, 2, 3)
	fmt.Printf("%v %p\n", ss2, ss2)
	ss2 = append(ss2, 1, 2, 3)
	fmt.Printf("%v %p\n", ss2, ss2)

	d := []int{1, 2, 3, 4, 5}
	sd := d[2:5]
	se := d[1:3]
	fmt.Println(sd, se)
	//se = append(se, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1)
	sd[0] = 9
	fmt.Println(sd, se)

	sj := []int{1, 2, 3, 4, 5, 6}
	sk := []int{7, 8, 9}
	copy(sj, sk)
	fmt.Println(sj)
	copy(sk, sj)
	fmt.Println(sk)
	copy(sk, sj[1:2])
	fmt.Println(sk)
	copy(sk[0:3], sj[3:6])
	fmt.Println(sk)
}
