package main

import (
  "fmt"
)

func main() {
	z := make(map[string]string)
	z["slice"] = "slice的for range使用方法："
	z["map"] = "map字典的声明需要在使用之前使用make初始化："

	fmt.Println(z["slice"])
	//创建一个值(value)为int的slice
	a := []int{1, 2, 3, 4, 6}
	for k, v := range a {
		fmt.Println("a的索引为 = :", k)
		fmt.Println("a的值为 = :", v)
	}

	b := []string{"allen.w", "alleness", "cootos"}
	for _, v := range b {
		fmt.Println("b的值为:", v)
	}

	c := []string{"allen.w", "allen", "cootos"}
	for k, _ := range c {
		fmt.Println("c的索引为:", k)
	}

	d := []int{100, 99, 98}
	for v := range d {
		fmt.Println("d的索引为：", v)
	}

	fmt.Println(z["map"])
	
	//创建一个map类型，以字符串为键(key),float32为值(value)
	x := make(map[string]float32)
	x["第一个"] = 4.5
	x["第二个"] = 5.6
	fmt.Println(x)
	//map有两个返回值，第二个返回值，如果不存在key,那么ok为false,如果存在key,ok为true
	xx, ok := x["第一个"]
	if ok {
		fmt.Println(xx)
	} else {
		fmt.Println("不存在")
	}
	//删除key为"第一个"的元素
	delete(x, "第一个")

	map1 := map[string]int{"a": 10, "b": 11, "c": 12}
	map1["a"] = 20
	for k, v := range map1 {
		fmt.Println("map1字典的索引是:", k)
		fmt.Println("map1字典的值是:", v)
	}

	map2 := map[int]string{5: "allen.", 7: "w", 0: "先生"}
	for _, v := range map2 {
		fmt.Println("map2的字典值是：", v)
	}
}
