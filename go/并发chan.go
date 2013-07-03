package main

import (
  "fmt"
	"runtime"
	"sync"
	//"time"
)

func main() {
	/*	c := make(chan bool)
		go func() {
			fmt.Println("Go Go Go!!!")
			c <- true
		}()
		<-c
		//有缓存，是异步的
		c := make(chan bool, 1)
		go func() {
			fmt.Println("Go Go Go!!!")
			c <- true
		}()
		<-c

		c := make(chan bool, 1)
		go func() {
			fmt.Println("Go Go Go!!!")
			<-c
		}()
		c <- true
		//无缓存是同步阻塞的
		c := make(chan bool)
		go func() {
			fmt.Println("Go Go Go!!!")
			<-c
		}()
		c <- true*/

	c := make(chan bool)
	go func() {
		fmt.Println("Go Go Go!!!")
		c <- true
		close(c)
	}()
	//<-c
	for v := range c {
		fmt.Println(v)
	}

	/*go Go()
	time.Sleep(2 * time.Second)*/

	/*d := make(chan bool)

	for i := 0; i < 10; i++ {
		go cis_d(d, i)
	}
	<-d*/

	/*runtime.GOMAXPROCS(runtime.NumCPU())
	d := make(chan bool, 10)

	for i := 0; i < 10; i++ {
		go cis_d(d, i)
	}

	for i := 0; i < 10; i++ {
		<-d
	}*/

	runtime.GOMAXPROCS(runtime.NumCPU())
	wg := sync.WaitGroup{}
	wg.Add(10)
	for i := 0; i < 10; i++ {
		go cis_d(&wg, i)
	}

	wg.Wait()

	c1, c2 := make(chan int), make(chan string)
	o := make(chan bool)
	go func() {
		for {
			select {
			case v, ok := <-c1:
				if !ok {
					o <- true
					break
				}
				fmt.Println("c1", v)
			case v, ok := <-c2:
				if !ok {
					o <- true
					break
				}
				fmt.Println("c2", v)
			}
		}
	}()

	c1 <- 1
	c2 <- "h1"
	c1 <- 3
	c2 <- "hello"

	close(c1)
	close(c2)

	<-o
}

func Go() {

	fmt.Println("Go Go Go!!!")
}

/*func cis_d(d chan bool, index int) {
a := 1
for i := 0; i < 100000000; i++ {
	a += i
}
fmt.Println(index, a)

/*if index == 9 {
	d <- true
}*/

/*d <- true
}*/

func cis_d(wg *sync.WaitGroup, index int) {
	a := 1
	for i := 0; i < 100000000; i++ {
		a += i
	}
	fmt.Println(index, a)

	wg.Done()
}
