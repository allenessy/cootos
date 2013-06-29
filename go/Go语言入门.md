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
	break        default           func      interface      select
	case         defer             go        map            struct
	chan         else              goto      package        switch
	const        fallthrough       if        range          type
	continue     for               import    return         var

###Go注释方法    
    
// ：单行注释    
/* */：多行注释    


Go程序的一般结构：demo.go    
    
Go程序是通过 `package` 来组织的（与python类似）    
只有 `package` 名称为 `main` 的包可以包含 `main` 函数    
一个可执行程序 有且仅有 一个 `main` 包    
    
通过 `import` 关键字来导入其它非 `main` 包    
通过 `const` 关键字来进行常量的定义    
通过在函数体外部使用 `var` 关键字来进行全局变量的声明与赋值    
通过 `type` 关键字来进行结构`(struct)`或接口`(interface)`的声明    
通过 `func` 关键字来进行函数的声明    

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
	根据约定，函数名首字母 小写 即为`private`     
<pre>
func getField(){
	...
}
</pre>

函数名首字母 大写 即为`public`

<pre>
func Getfile(){
	...
}
</pre>
###单元测试  
              
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
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;长度：1字节<br/>
取值范围：true, false<br/>
注意事项：不可以用数字代表true或false<br/>
<br/>
整型：int/uint<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;根据运行平台可能为32或64位<br/>
<br/>
&nbsp;&nbsp;8位整型：int8/uint8<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;长度：1字节<br/>
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
###类型零值

零值并不等于空值，而是当变量被声明为某种类型后的默认值，     
通常情况下值类型的默认值为`0`，`bool`为`false`，`string`为空字符串     

###类型别名
<pre>
type (
	byte int8
	rune int32
	文本 string
)
</pre>
<pre>
var b 文本
b = "中文类型名"
</pre>

###单个变量的声明与赋值  

变量的声明格式：`var <变量名称> <变量类型>`            
变量的赋值格式：`<变量名称> = <表达式>`            
声明的同时赋值：`var <变量名称> [变量类型] = <表达式>`               

<pre>
var a int //变量的声明
a = 123   //变量的赋值

//变量声明的同时赋值
var b int = 321
//上行的格式可省略变量类型，由系统推断
var c = 321
//变量声明与赋值的最简写法
d := 456
</pre>

###多个变量的声明与赋值
    
全局变量的声明可使用 `var()` 的方式进行简写       
全局变量的声明不可以省略 `var`，但可使用并行方式     
所有变量都可以使用类型推断      
局部变量不可以使用 `var()` 的方式简写，只能使用并行方式      

<pre>
var (
	//使用长规方式
	aaa = "hello"
	//使用并行方式以及类型推断
	sss,bbb = 1,2
	//ccc := 3 //不可以省略 var
)
</pre>

<pre>
//多个变量的声明
var a,b,c,d int
//多个变量的赋值
a,b,c,d = 1,2,3,4

//多个变量声明的同时赋值
var e,f,g,h int = 5,6,7,8
//省略变量类型，由系统推断
var i,j,k,l = 9,10,11,12
//多个变量声明与赋值的最简写法
i,m,n,o := 13,14,15,16
</pre>

###变量的类型转换
     
Go中不存在隐式转换，所有类型转换必须显式声明       
转换只能发生在两种相互兼容的类型之间           
类型转换的格式：         
\<ValueA\> \[\:\]= \<TypeOfValueA\>\(\<ValueB\>\)       
           
<pre>
//在相互兼容的两种类型之间进行转换
var a float32 = 1.1
b := int(a)

//以下表达式无法通过编译
d := int(c)
</pre>
###单元测试
         
请尝试运行以下代码，看会发生什么，并思考为什么。           

<pre>
func main() {
	var a int = 65
	b := string(a)
	fmt.Println(b)
}
</pre>

`string()` 表示将数据转换成文本格式，因为计算机中存储的任何东西              
本质上都是数字，因此此函数自然地认为我们需要的是用数字65表示         
的文本 A。          
             
###常量的定义             

常量的值在编译时就已经确定              
常量的定义格式与变量基本相同             
等号右侧必须是常量或者常量表达式            
常量表达式中的函数必须是内置函数          

<pre>
//定义单个变量
const a int = 1
const b = 'A'
const (
	text   = "123"
	length = len(text)
	num    = b * 20
)
</pre>
<pre>
//同时定义多个变量
const i,j,k = 1,"2",'3'
const (
	text2,length2,num2 = "456",len(text2),k*10
）
</pre>

常量的初始化规则与枚举             
             
在定义常量组时，如果不提供初始值，则表示将使用上行的表达式             
使用相同的表达式不代表具有相同的值                
`iota`是常量的计数器，从0开始，组中每定义1个常量自动递增1             
通过初始化规则与`iota`可以达到枚举的效果               
每遇到一个`const`关键字，`iota`就会重置为0           


	const (
		//a与b都为"A"
		a = "A"
		b
		c = iota
		d //d 的值为3
	)
<br/>

	const (
		e = iota
		f //f 的值为1
	）
<br/>

	//星期枚举
	const (
		//第一个常量不可省略表达式
		Monday = iota
		Tuesday
		Wednesday
		Thursday
		Friday
		Saturday
		Sunday
	)

###运算符
            
Go中的运算符均是从左至右结合               
              
优先级（从高到低）                        
             
	^      !                                        （一元运算符）                   
	*      /    %    <<    >>    &      &^
	+      -    |    ^                              （二元运算符）                   
	==    !=    <    <=    >=    >
	<-                                              （专门用于channel）                           
	&&
	||              
           
###单元测试
          
请尝试结合常量的`iota`与`<<`运算符实现计算机储存单位的枚举               

	const (
		_		   = iota
		KB float64 = 1 << (iota * 10)
		MB
		GB
		TB
		PB
		EB
		ZB
		YB
	)
输出:<br/>

	1024
	1.048576e+06
	1.073741824e+09
	1.099511627776e+12
	1.125899906842624e+15
	1.152921504606847e+18
	1.1805916207174113e+21
	1.2089258196146292e+24


###指针
                
Go虽然保留了指针，但与其它编程语言不同的是，在Go当中不              
支持指针运算以及`”->”`运算符，而直接采用`”.”`选择符来操作指针                            
目标对象的成员               
              
操作符`”&”`取变量地址，使用`”*”`通过指针间接访问目标对象               
默认值为 `nil` 而非 `NULL`               
               
           
递增递减语句                 
                        
在Go当中，`++` 与 `--` 是作为语句而并不是作为表达式              
            
###判断语句if
                  
条件表达式没有括号                    
支持一个初始化表达式（可以是并行方式）              
左大括号必须和条件语句或`else`在同一行              
支持单行模式                 
初始化语句中的变量为block级别，同时隐藏外部同名变量                
1.0.3版本中的编译器BUG                
            

	func main() {
		a := true
		if a, b, c := 1, 2, 3; a+b+c > 6 {
			fmt.Println("大于6")	
		} else {
			fmt.Println("小于等于6")
			fmt.Println(a)
		}
		fmt.Println(a)
	}


###循环语句for           
                 
Go只有`for`一个循环语句关键字，但支持3种形式               
初始化和步进表达式可以是多个值             
条件语句每次循环都会被重新检查，因此不建议在条件语句中               
使用函数，尽量提前计算好条件并以变量或常量代替           
左大括号必须和条件语句在同一行             
            

	func main() {
		a := 1
		for {
			a++
			if a > 3 {
				break
			}
		}
		fmt.Println(a)
	}
<br/>


	func main() {
		a := 1
		for a <= 3 {
			a++
		}
		fmt.Println(a)
	}
<br/>


	func main() {
		a := 1
		for i := 0; i < 3; i++ {
			a++
		}
		fmt.Println(a）
	}

###选择语句switch
           
可以使用任何类型或表达式作为条件语句           
不需要写`break`，一旦条件符合自动终止          
如希望继续执行下一个`case`，需使用`fallthrough`语句            
支持一个初始化表达式（可以是并行方式），右侧需跟分号           
左大括号必须和条件语句在同一行            
              

	func main() {
		a := 1
		switch a {
		case 0:
			fmt.Println("a=0")
		case 1:
			fmt.Println("a=1")
		}
		fmt.Println(a)
	}
<br/>

	func main() {
		a := 1
		switch {
		case a >= 0:
			fmt.Println("a=0")
			fallthrough
		case a >= 1:
			fmt.Println("a=1")
		}
		fmt.Println(a)
	}
<br/>

	func main() {
		switch a := 1; {
		case a >= 0:
			fmt.Println("a=0")
			fallthrough
		case a >= 1:
			fmt.Println("a=1")
		}
	}


###跳转语句goto, break, continue        
               
三个语法都可以配合标签使用            
标签名区分大小写，若不使用会造成编译错误           
`Break`与`continue`配合标签可用于多层循环的跳出             
`Goto`是调整执行位置，与其它2个语句配合标签的结果并不相同            
          

	func main() {
	LABEL:
		for {
			for i := 0; i < 100; i++ {
				if i > 2 {
					break LABEL
				} else {
					fmt.Println(i)
				}
			}
		}
	}
<br/>


	func main() {
	LABEL:
	for i := 0; i < 10; i++ {
			for {
				fmt.Println(i)
				continue LABEL
			}
		}
	}

###单元测试       
              
将下图中的`continue`替换成`goto`，程序运行的结果还一样吗？                 
请尝试并思考为什么。            

	func main() {
	LABEL:
		for i := 0; i < 10; i++ {
			for {
				fmt.Println(i)
				continue LABEL
			}
		}
	}

Goto是调整执行位置           
             
###数组Array
           
定义数组的格式：`var <varName> [n]<type>，n>=0`                  
数组长度也是类型的一部分，因此具有不同长度的数组为不同类型           
注意区分指向数组的指针和指针数组              
数组在Go中为值类型                
数组之间可以使用`==`或`!=`进行比较，但不可以使用`<或>`                 
可以使用`new`来创建数组，此方法返回一个指向数组的指针            
Go支持多维数组             
          
            
Go语言版冒泡排序          
         
###切片Slice
         
其本身并不是数组，它指向底层的数组               
作为变长数组的替代方案，可以关联底层数组的局部或全部            
为引用类型             
可以直接创建或从底层数组获取生成            
使用`len()`获取元素个数，`cap()`获取容量          
一般使用`make()`创建              
如果多个`slice`指向相同底层数组，其中一个的值改变会影响全部            
              
`make([]T, len, cap)`            
其中`cap`可以省略，则和`len`的值相同            
`len`表示存数的元素个数，`cap`表示容量              


