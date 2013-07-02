package main

import (
	"fmt"
)

type A struct {
	Name string
}

type B struct {
	Name string
}

type C struct {
	Name string
}

type TZ int

type D struct {
	Name string
}

func main() {
	//声明结构A
	a := A{}
	//调用结构A的方法
	a.Print()

	b := B{}
	b.Print()

	c := C{}
	c.Print()
	fmt.Println(c.Name)

	var tz TZ
	tz.Print()
	(*TZ).Print(&tz)

	d := D{}
	d.Print()
	fmt.Println(d.Name)

}

//变量a 的接收者A ,Print()方法名称
func (a A) Print() {
	fmt.Println("A")
}

func (b B) Print() {
	fmt.Println("B")
}

//*修改地址才能修改里面的内容
func (c *C) Print() {
	c.Name = "CC"
	fmt.Println("C")
}

func (tz *TZ) Print() {
	fmt.Println("TZ")
}

func (d *D) Print() {
	d.Name = "allen.w"
	fmt.Println(d.Name)
}
