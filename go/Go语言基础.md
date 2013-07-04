###你好，Go
第一个Go程序:
  
    package main
    
    import (
        "fmt"
    )
    
    func main() {
  	fmt.Println("Hello wolrd!你好，世界!")
    }
输出如下：

    Hello wolrd!你好，世界!
###定义变量

    //定义一个名称为"a",类型为"int"的变量
    var a int
  
    //定义多个变量
    var a,b,c int
  
    //定义变量并初始化值
    var a int=100
  
    //同时初始化多个变量
    var a,b,c int=100,200,300
  
    //定义三个变量，分别初始化值
    var a,b,c=10,20,30
  
    函数内部用:
    a,b,c:=1,2,3
  
    _(下划线)是个特殊的变量名，任何赋予它的值都会 被丢弃，在这个例子中，我们将值20赋予a,并同时丢弃10
    _，a:=10,20 
Go语言对于已声明但未使用的变量会在编译阶段报错，比如下面的代码就会产生一个错误：声明了i但未使用

    package main 
  
    import (
        "fmt"
    )
    
    func main() {
        var i int
    }
修改为：

    package main
    
    import (
        "fmt"
    )
    
    func main() {
    	  var a int
       	a = 10
      	fmt.Println(a)
    }
###常量
    
    //常量可定义为数值、布尔值或字符串等类型。
    const a = value
    //如果有需要，也可以明确指定常量的类型：
    const Pi float32 = 3.1415926
以下是一些常量声明的例子：

    const Pi = 3.1415926
    const i = 100
    const max = 10
    const pre = "allen.w"
###内置基础类型
####Boolean
在Go语言中，布尔值的类型为bool,值是true或false,默认为false

    var a bool //全局变量声明
    var enabled,disabled=true,false  //忽略类型的声明
<br/>

    func test() {
        var a bool //一般声明
        b := false //简短声明
        c = true   //赋值操作
    }
####数值类型
Go语言里面直接定义好的位数的类型：rune,int8,int16,int32,int64和byte,uint8,uint16,uint32,uint64.      
其中rune是int32的别称，byte是uint8的别称。     
需要注意的是，这些类型变量之间不允许互相赋值或操作，不然会在编译时报错。

    var a int8
    var b int32
    c := a + b
    //就会报错
另外尽管int的长度是32bit,但int与int32并不可以互用。    
浮点数的类型有float32和float64两种(没有float类型)，默认是float64    
Go还支持复数，它的默认类型是complex128(64位实数+64虚数)，再小一点有complex64(32位实数+32位虚数)复数的形式为RE+IMi,其中RE是实数部分，IM是虚数部分，而最后的i是虚数单位。下面是一个使用复数的例子。

    var a complex64=5+5i
    fmt.Printf("5+5i的复数值是：%v",a)

        
