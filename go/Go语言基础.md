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
        a = true   //赋值操作
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
####字符串
Go语言中都是采用UTF-8字符集编码，字符串是用一对("")或反引号(``)括起来定义，它的类型是string。

    var a string  //声明变量为字符串的一般方法
    var b string = ""   //声明了一个字符串变量，初始化为空字符串
    func test(){
        x,y,z := "hello","world","hw"  //剪短声明，同时声明多个变量
        v := "vv"  //同上
        u = "uv"   //常规赋值
    }
在Go语言中字符串是不可变的，例如，如下代码编译时会报错：

    var a string = "hello"
    s[0] = 'c'
但如果真的想修改怎么办？下面的代码可以实现。
    
    a := "hello"
    b := []byte(a)   //将字符串a转换为[]byte类型
    b[0] = 'c'
    c := string(b)  //再转换回string类型
    fmt.Printf("%s\n",c)
Go语言中可以使用"+"操作符来连接两个字符串：

    a := "hello"
    b := "world"
    c := a + b
    fmt .Printf("%s\n",c)
修改字符串也可写为：

    a := "hello"
    a = "c" + a[1:]  //字符串虽不能更改，但可进行切片操作
    fmt.Printf("%s\n",a)
如果要声明一个多行的字符串怎么办？可以通过“`”来声明。

    a := `hello
          wolrd`
“`”括起来的字符串为Raw字符串，即字符串在代码中的形式就是打印时的形式，它没有字符转义，换行也将原样输出。
####错误类型
Go语言内置有一个error类型，专门用来处理错误信息，Go语言的package里面还专门有一个包errors来处理错误。

    err := errors.New("错误信息")
    if err != nil {
        fmt.Print(err)
    }
####分组声明：

    import (
        "fmt"
        "os"
    )
<br/>

    const (
        a = 100
        b = 3.1415
        c = "Go"
    )
<br/>

    var (
        a int
        b float32
        c string
    )
####iota枚举
每个const分组的第一个常量被默认设置为它的O值，第二及后续的常量被默认设置为它前面那个常量的值，如果前面那个常量的值是iota,则它也被设置为iota.

    const (
        a = iota  // a == 0
        b = iota  // b == 1
        c = iota  // c == 2
    )
<br/>

    const (
        a = iota  // a == 0
        b         // b == 1
        c         // c == 2
    )
<br/>

    const (
        a = iota  // a == 0
        b         // b == 1
        c         // c == 2
    )
    
    const d = iota // d == 0
####Go语言程序设计的一些规则
+ 大写字母开头的变量是可导出的，即其他包可以读取，是公用变量；小写字母开头的不可导出，是私有变量。         
+ 大写字母开头的函数也是一样，相当于class中带public关键词的公有函数；小写字母开头就是有private关键词的私有函数。                 
