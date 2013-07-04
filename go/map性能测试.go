package main

import (
  "fmt"
	"runtime"
	"time"
)

func SeqGetMapBenchmark(N int, gc bool) {
	if gc {
		runtime.GC()
	}
	// 创建一个map类型，以字符串为键（key），整数为值（value）
	a := make(map[string]int, N)
	// 创建一个slice，用于存储访问顺序
	seq := make([]string, N)
	// Insert numbers
	for i := 0; i < N; i++ {
		key := fmt.Sprintf("%09d", i)
		a[key] = i
		seq[i] = key
	}
	sum := 0
	// 开始计时
	start := time.Now()
	for _, key := range seq {
		sum += a[key]
	}
	duration := time.Since(start)
	fmt.Printf("Map Seq. Access. iterations: %v. %v us/op\n",
		N, duration.Seconds()*1e6/float64(N))
}
func main() {
	gc := true
	SeqGetMapBenchmark(1000, gc)
	SeqGetMapBenchmark(10000, gc)
	SeqGetMapBenchmark(100000, gc)
	SeqGetMapBenchmark(1000000, gc)
	SeqGetMapBenchmark(10000000, gc)
}
