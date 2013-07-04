###你好，Go
  
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
###常量
