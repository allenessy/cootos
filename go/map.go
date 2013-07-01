package main

import (
	"fmt"
	"sort"
)

func main() {
	var m map[int]string
	m = map[int]string{}
	fmt.Println(m)

	var n map[int]string
	n = make(map[int]string)
	fmt.Println(n)

	var mn map[int]string = make(map[int]string)
	fmt.Println(mn)

	mnv := make(map[int]string)
	fmt.Println(mnv)

	mnz := make(map[int]string)
	mnz[1] = "OK"
	fmt.Println(mnz)
	a := mnz[1]
	fmt.Println(a)
	//删除键值
	delete(mnz, 1)
	b := mnz[1]
	fmt.Println(b)

	var z map[int]map[int]string
	//初始化最外层的map
	z = make(map[int]map[int]string)
	//初始化里面的map
	z[1] = make(map[int]string)
	z[1][1] = "OK"
	c := z[1][1]
	fmt.Println(c)
	d, ok := z[2][1]
	fmt.Println(d, ok)
	//用第二个返回值来检查是否初始化
	e, ok := z[3][1]
	fmt.Println(e, ok)
	if !ok {
		z[3] = make(map[int]string)
	}
	z[3][1] = "Good"
	e, ok = z[3][1]
	fmt.Println(e, ok)

	/*for i,v:=range slice{
		//修改slice中i对应的索引
		slice[i]=
	}*/

	/*for k,v:=range map{
		map[k]
	}*/

	sm := make([]map[int]string, 5)
	//不需要索引  v只是一个拷贝，对其的任何操作都不会影响到slice本身
	for _, v := range sm {
		v = make(map[int]string, 1)
		v[1] = "OK"
		fmt.Println(v)
	}
	fmt.Println(sm)

	u := make([]map[int]string, 5)
	for i := range u {
		u[i] = make(map[int]string, 1)
		u[i][1] = "OK"
		fmt.Println(u[i])
	}
	fmt.Println(u)

	t := map[int]string{1: "a", 2: "b", 3: "c", 4: "d", 5: "e"}
	s := make([]int, len(t))
	i := 0
	for k, _ := range t {
		s[i] = k
		i++
	}
	//用sort.Ints进行排序
	sort.Ints(s)
	//map的无序性，导致每次写入slice的值都不一样
	fmt.Println(s)
}
