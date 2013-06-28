Go编程基础
=====================
- 什么是Go？

  Go是一门 并发支持 、垃圾回收 的 编译型 系统编程语言，旨在创  
  造一门具有在静态编译语言的 高性能 和动态语言的 高效开发 之间拥有  
  良好平衡点的一门编程语言。  

- Go的主要特点有哪些？

  类型安全 和 内存安全  
  以非常直观和极低代价的方案实现 高并发  
  高效的垃圾回收机制  
  快速编译（同时解决C语言中头文件太多的问题）  
  为多核计算机提供性能提升的方案  
  UTF-8编码支持  

- Go存在的价值是什么？

  Go在谷歌：以软件工程为目的的语言设计

- Go是记事本编程吗？

  包括VIM，IDEA，Sublime Text，Eclipse等众多知名IDE均已支持

- Go目前有多少实际应用和资源？

  全球最大视频网站 Youtube（谷歌）   
  七牛云储存以及旗下网盘服务（Q盘）   
  爱好者开发的Go论坛及博客   
  已用Go开发服务端的著名企业：谷歌、盛大、七牛、360   
  其它海量开源项目：go-wiki、Go Walker、Go Language Resources   


- Go发展成熟了吗？

  作为一门2009年才正式发布的编程语言，Go是非常年轻的，因此   
  不能称为一门成熟的编程语言，但开发社区每天都在不断更新其核心代   
  码，给我们这些爱好者给予了很大的学习和开发动力。   

- Go的爱好者多吗？

  以Google Group为主的邮件列表每天都会更新10至20帖，国内   
  的Go爱好者QQ群和论坛每天也在进行大量的讨论，因此可以说目前   
  Go爱好者群体是足够壮大。  

  Golang相关QQ群

- 安装Go语言

  Go源码安装：参考链接   
  Go标准包安装：下载地址   
  第三方工具安装  
   
   
   
  Go环境变量与工作目录   
    
  根据约定，GOPATH下需要建立3个目录：  
  bin（存放编译后生成的可执行文件）  
  pkg（存放编译后生成的包文件）    
  src（存放项目源码）  


- Go命令

  在命令行或终端输入go即可查看所有支持的命令

- Go常用命令简介

  go get：获取远程包（需 提前安装 git或hg）   
  go run：直接运行程序   
  go build：测试编译，检查是否有编译错误   
  go fmt：格式化源码（部分IDE在保存时自动调用）   
  go install：编译包文件并编译整个程序   
  go test：运行测试文件   
  go doc：查看文档（CHM手册）   


Go语言版”Hello world!”    
hello.go

	package main
	
	import (
	  "fmt"
	)
	
	func main() {
		fmt.Printf("Hello,World!")
	}

执行：`go run hello.go`   
输出：`Hello,World!`   

Go基础知识:   
demo.go

	//当前程序的包名
	package main 
	
	//导入其它的包
	import "fmt"
	
	//常量的定义
	const PI = 3.14
	
	//全局变量的声明与赋值
	var name = "gopher"
	
	//一般类型声明
	type newType int 
	
	//结构的声明
	type gopher struct{}
	
	//接口的声明
	type golang interface{}
	
	//由 main 函数作为程序入口点启动
	func main() {
		fmt.Println("Hello,World!你好，世界！")
	}

###Go内置关键字（25个均为小写）
<p>
break&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;default&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;func&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;interface&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;select<br/>
case&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;defer&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;go&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;map&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;struct<br/>
chan&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;else&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;goto&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;package&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;switch<br/>
const&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;fallthrough&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;range&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;type<br/>
continue&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;for&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;import&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;return&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;var<br>
</p>

###Go注释方法    
    
// ：单行注释    
/* */：多行注释    


Go程序的一般结构：demo.go    
    
Go程序是通过 package 来组织的（与python类似）    
只有 package 名称为 main 的包可以包含 main 函数    
一个可执行程序 有且仅有 一个 main 包    
    
通过 import 关键字来导入其它非 main 包    
通过 const 关键字来进行常量的定义    
通过在函数体外部使用 var 关键字来进行全局变量的声明与赋值    
通过 type 关键字来进行结构(struct)或接口(interface)的声明    
通过 func 关键字来进行函数的声明    

###Go导入 package 的格式
<pre>
import "fmt"
import "os"
import "io"
import "time"
import "strings"
</pre>
更方便的写法为：
<pre>
import (
	"fmt"
	"io"
	"os"
	"strings"
	"time"
)
</pre>

导入包之后，就可以使用格式`<PackageName>`.`<FuncName>`   
来对包中的函数进行调用    
如果导入包之后 未调用 其中的函数或者类型将会报出编译错误：     
<pre>imported and not used: "io"</pre>
###package 别名    
     
当使用第三方包时，包名可能会非常接近或者相同，此时就可以使用    
别名来进行区别和调用
<pre>
import (
	io "fmt"
)
</pre>
<pre>
//使用别名调用包
io.Println("Hello world!")
</pre>
省略调用   
    
不建议使用，易混淆    
不可以和别名同时使用
<pre>
import (
	. "fmt"
)

func main() {
	//使用省略调用
	Println("Hello world!")
}
</pre>

###可见性规则
     
Go语言中，使用 大小写 来决定该 常量、变量、类型、接口、结构    
或函数 是否可以被外部包所调用：     
	根据约定，函数名首字母 小写 即为private     
<pre>
func getField(){
	...
}
</pre>

函数名首字母 大写 即为public

<pre>
func Getfile(){
	...
}
</pre>
测试:    
     
既然导入多个包时可以进行简写，那么声明多个 常量、全局变量     
或一般类型（非接口、非结构）是否也可以用同样的方法呢？     
     
请动手验证。     


<pre>
//常量的定义
const (
	PI     = 3.14
	const1 = "1"
	const2 = 2
	const3 = 3
)
</pre>
<pre>
//全局变量的声明与赋值
var (
	name  = "gopher"
	name1 = "1"
	name2 = "2"
	name3 = "3"
)
</pre>
<pre>
//一般类型声明
type (
	newType int
	type1   float32
	type2   string
	type3   byte
)
</pre>

###Go基本类型
<p>
&nbsp;&nbsp;&nbsp;&nbsp;布尔型：bool<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;长度：1字节<br/>
取值范围：true, false<br/>
注意事项：不可以用数字代表true或false<br/>
<br/>
整型：int/uint<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;根据运行平台可能为32或64位<br/>
<br/>
&nbsp;&nbsp;8位整型：int8/uint8<br/>
&nbsp;&nbsp;&nbsp;&nbsp;长度：1字节<br/>
取值范围：-128~127/0~255<br/>
&nbsp;&nbsp;&nbsp;&nbsp;字节型：byte（uint8别名）<br/>
<br/>
16位整型：int16/uint16<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;长度：2字节<br/>
取值范围：-32768~32767/0~65535<br/>
<br/>
32位整型：int32（rune）/uint32<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;长度：4字节<br/>
取值范围：-2^32/2~2^32/2-1/0~2^32-1<br/>
<br/>
64位整型：int64/uint64<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;长度：8字节<br/>
取值范围：-2^64/2~2^64/2-1/0~2^64-1<br/>
<br/>
浮点型：float32/float64<br/>
&nbsp;&nbsp;&nbsp;&nbsp;长度：4/8字节<br/>
小数位：精确到7/15小数位<br/>
<br/>
复数：complex64/complex128<br/>
长度：8/16字节<br/>
足够保存指针的 32 位或 64 位整数型：uintptr<br/>
<br/>
其它值类型：<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;array、struct、string<br/>
引用类型：<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;slice、map、chan<br/>
<br/>
接口类型：inteface<br/>
函数类型：func<br/>
</P>
