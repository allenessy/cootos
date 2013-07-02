package main

import (
	"fmt"
)

type Allen int

type USB interface {
  //两个方法
	Name() string
	//嵌入接口
	Connecter
}

//嵌入到USB接口的接口
type Connecter interface {
	Connect()
}

type PhoneConnecter struct {
	//用结构来实现方法
	name string
}

func main() {
	var a Allen
	a.Increase(100)
	fmt.Println(a)

	var b USB
	b = PhoneConnecter{"PhoneConncter"}
	b.Connect()
	Disconnect(b)

	c := PhoneConnecter{"PhoneConnecter"}
	var d Connecter
	d = Connecter(c)
	d.Connect()

	var x interface{}
	fmt.Println(x == nil)

	var y *int = nil
	x = y
	fmt.Println(x == nil)
}

func (allen *Allen) Increase(num int) {
	*allen += Allen(num)
}

func (pc PhoneConnecter) Name() string {
	return pc.name
}

func (pc PhoneConnecter) Connect() {
	fmt.Println("Connect:", pc.name)
}

//空接口
func Disconnect(usb interface{}) {
	/*if pc, ok := usb.(PhoneConnecter); ok {
		fmt.Println("Disconnected:", pc.name)
		return
	}
	fmt.Println("Unknown decive.")*/
	switch v := usb.(type) {
	case PhoneConnecter:
		fmt.Println("Disconnected:", v.name)
	default:
		fmt.Println("Unknown decive.")
	}
}
