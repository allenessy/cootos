package main

import (
	"fmt"
)

func main() {
	m1 := map[int]string{1: "a", 2: "b", 3: "c", 4: "d", 5: "e"}
	fmt.Println(m1)
	m2 := make(map[string]int)

	for k, v := range m1 {
		m2[v] = k
	}
	fmt.Println(m2)

	D(1, 2, 3, 4, 5, 6, 7)

	a, b := 1, 2
	E(a, b)
	fmt.Println(a, b)

	s1 := []int{1, 2, 3, 4}
	F(s1)
	fmt.Println(s1)

	v := 1
	G(v)
	fmt.Println(v)

	m := 1
	H(&m)
	fmt.Println(m)

	I()

	f := closure(10)
	fmt.Println(f(1))
	fmt.Println(f(2))

	for i := 0; i < 3; i++ {
		defer func() {
			fmt.Println(i)
		}() //()调用这个匿名函数的意思
	}
	//defer按照相反顺序逐个执行
	for i := 0; i < 3; i++ {
		defer fmt.Println(i)
	}
	//defer的作用就是调用某一个函数
	fmt.Println("a")
	defer fmt.Println("b")
	defer fmt.Println("c")

	A1()
	B1()
	C1()

}

//func 函数名称(参数名称 类型)(返回值 类型)
//func A(a,b,c int)()多个同类型参数
//func A()(a,b,c int)多个同类型返回值
func A(a int, b string) (int, string) {
	a = 1
	b = "good"
	return a, b
}

func B() (int, int, int) {
	a, b, c := 1, 2, 3
	return a, b, c
}

func C() (a, b, c int) {
	a, b, c = 1, 2, 3
	return
}

//不指定长度变参,只能放在最后面
func D(a ...int) {
	fmt.Println(a)
}

func E(s ...int) {
	s[0] = 3
	s[1] = 4
	fmt.Println(s)
}

func F(t []int) {
	t[0] = 5
	t[1] = 6
	t[2] = 7
	t[3] = 8
	fmt.Println(t)
}

//拷贝值
func G(v int) {
	v = 2
	fmt.Println(v)
}

//拷贝地址
func H(m *int) {
	*m = 2
	fmt.Println(*m)
}

func I() {
	a := 0
	//&取出内存地址
	b := &a
	//*指针类型
	fmt.Println(*b)
}

//闭包函数
func closure(x int) func(int) int {
	fmt.Printf("%p\n", &x)
	return func(y int) int {
		fmt.Printf("%p\n", &x)
		return x + y
	}
}

func A1() {
	fmt.Println("Func A1")
}

func B1() {
	//defer把程序从panic状态recover回来
	defer func() {
		if err := recover(); err != nil {
			fmt.Println("Recover in B1")
		}
	}()
	panic("Panic in B1")
}

func C1() {
	fmt.Println("Func C1")
}
