package main

import (
  "fmt"
)

type test struct{}

type person struct {
	Name string
	Age  int
	//匿名结构
	Contact struct {
		/*Phone string
		City  string*/
		Phone, City string
	}
}

type new struct {
	//匿名字段
	string
	int
}

type human struct {
	Sex int
}

type teacher struct {
	//嵌入结构
	human
	Name string
	Age  int
}

type student struct {
	//嵌入结构
	human
	Name string
	Age  int
}

func main() {
	z := test{}
	fmt.Println(z)

	//&取person结构地址，取结构地区
	a := &person{
		Name: "joe",
		Age:  19,
	}
	/*a := person{}
	a.Name = "allen"
	a.Age = 19*/
	//person结构中匿名结构的初始化
	a.Contact.Phone = "12345677"
	a.Contact.City = "beijing"
	fmt.Println(a)

	a.Name = "ok"
	fmt.Println(a)

	A(a)
	B(a)
	fmt.Println(a)
	//匿名结构
	b := &struct {
		Name string
		Age  int
	}{
		Name: "joe",
		Age:  19,
	}
	fmt.Println(b)

	n := &new{"allen", 27}
	fmt.Println(n)
	//修改human的Sex字段
	c := teacher{Name: "joe", Age: 19, human: human{Sex: 0}}
	d := student{Name: "joe", Age: 20, human: human{Sex: 1}}
	c.Name = "joe2"
	c.Age = 13
	//修改human的Sex字段
	c.Sex = 100
	fmt.Println(c, d)

}

func A(per *person) {
	per.Age = 13
	fmt.Println("A", per)
}

func B(per *person) {
	per.Age = 15
	fmt.Println("A", per)
}
