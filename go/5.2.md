## array、slice、map
### array
array就是数组，它的定义方式如下：

    //var 数组名称 [数组的长度]存储元素的类型
    var a [10]int
<br/>

    var b [10]int //声明了一个int类型的数组
    b[0] = 42     //数组下标是从0开始
    b[2] = 50     //赋值操作
    fmt.Println("数组b的第一个值是：%d\n",b[0])    //获取数据，返回42
    fmt.Println("数组b的最后一个值是：%d\n",b[9])  //返回未赋值的最后一个元素，默认返回0
由于长度也是数组类型的一部分，因此[3]int与[4]int是不同的类型，数组也就不能改变长度。     
数组之间的赋值是值的赋值，即当把一个数组作为参数传入函数的时候，传入的其实是改数组的副本，而不是它的指针。    
如果使用指针，那么就需要用到后面介绍的slice类型了。    
数组可以使用另外一种`:=`来声明。

    a := [3]int{1,2,3}  //声明了一个长度为3的int数组
    b := [10]int{1,2,3} //声明了一个长度为10的int数组，其中前三个元素初始化为1、2、3，其他默认为0
    c := [...]int{4,5,6} //可以省略长度而采用`...`的方式，Go 语言会自动根据元素个数来计算
也许你会说，我想数组里面的值还是数组，Go语言支持嵌套数组，即多维数组。

    //声明了一个二维数组，改数组以两个数组为元素，其中每个数组中有个4个int类型的元素。
    a := [2][4]int{[4]int{1,2,3,4},[4]int{5,6,7,8}}
    
    //如果内部的元素和外部的一样，那么上面的声明可以简化，直接忽略内部的类型
    a := [2][4]int{{1,2,3,4}{5,6,7,8}}
### slice
在初始定义数组时，我们并不知道需要多大的数组，因此我们就需要”动态数组“在Go语言里面这种数据结构叫slice。    
slice并不是真在意义上的动态数组，而是一个引用类型。     
slice总是指向一个底层array，slice的声明也可以像array一样，只是不需要长度。

    //和声明array一样，只是少了长度
    var a []int
接下来我们可以声明一个slice，并初始化数据，如下所示：

    a := []byte {'a','b','c','d'}
slice可以从一个数组或一个已经存在的slice中再次声明。    
slice通过array[i:j]来获取，其中i是数组开始位置，j是结束位置，但不包含array[j]，它的长度是j-i。

    //声明一个含有10个元素,元素类型为byte的数组
    var a = [10]byte{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'k'}
    
    //声明两个含有byte的slice
	var b, c []byte
    
    //b指向数组的第3个元素开始，并到第5个元素结束
	b = a[2:5]
    //现在b含有元素：a[2]、a[3]、a[4]
    
    //c是数组a的另一个slice
	c = a[3:5]
    //c的元素是：a[3]、a[4]
 - 注：slice和数组在声明数组时，方括号内写明了数组的长度或使用...自动计算长度，而声明slice时，方括号内没有任何字符。

slice有一些简便的操作。

 - slice 的默认开始位置是0,array[:n]等价于array[0:n]
 - slice 的第二个序列默认是数组的长度，array[n:]等价于array[n:len(array)]           
 - 如果从一个数组里面直接获取slice，可以这样array[:]，因为默认第一个序列是0，第二个是数组的长度，即等价于array[0:len(array)]    

下面这个例子展示了更多关于slice的操作。

    //声明一个数组
    var a = [10]byte{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'k'}
    
    //声明两个slice
    var as, bs []byte
    
    //演示一些简便操作
    as = a[:3] //等价于 as = a[0:3]
    as = a[5:] //等价于 as = a[5:9]
    as = a[:] //等价于 as = a[0:9]
    
    as = a[3:7] //as包含元素 d,e,f,g len=4,cap=7
    bs = as[1:3] //bs包含as[1],as[2]也就是e,f
    bs = as[:3] //bs包含as[0],as[1],as[2]也就是d,e,f
    bs = as[0:5] //对slice的slice可以在cap范围内扩展，此时bs包含：d,e,f,g,h
    bs = as[:] //bs包含所有as的元素：d,e,f,g

slice是引用类型，所以当引用改变其中元素的值时，其他的所有引用都会改变改值，例如：

从概念上面来说slice像一个结构体，这个结构体包含了三个元素。
 - 一个指针，指向数组中slice指定的开始位置。
 - 长度，即`slice`的长度。
 - 最大长度，也就是`slice`开始位置到数组的最后位置的长度。

		a := [10]byte{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'k'}
		b := a[2:5]

对于slice有几个有用的内置函数。

 - len 获取slice的长度。
 - cap 获取slice的最大容量
 - append 向slice里面追加一个或者多个元素，然后返回一个和slice一样类型的slice
 - copy 函数copy从源slice 的src中复制元素到目标dst,并且返回复制的元素的个数

注：`append`函数会改变`slice`所引用的数组的内容，从而影响到引用同一数组的其它`slice`。
但当`slice`中没有剩余空间（即`(cap-len) == 0`）时，此时将动态分配新的数组空间。返回的`slice`数组指针将指向这个空间，而原数组的内容将保持不变；其它引用此数组的`slice`则不受影响。

最标准的slice切片定义方法：

	v := make([]int, 3, 10);     //一个slice，有三个参数 类型、slice长度、slice底层的array长度，即slice的最大容量。
不过普通使用中，不用这么麻烦，直接这样就行了。

	v := []int{1,2,3};   //如果没有元素就 v:= []int{} 这里定义的slice元素为3个，且底层array长度为3。相当于下面的代码
<br/>

	v := make([]int, 3, 3)   //如果没有元素就 v:= []int{} 这里定义的slice元素为3个，且底层array长度为3。相当于下面的代码
	v[0] = 1
	v[1] = 2
	v[2] = 3
如果要扩展 slice的大小使用 append添加元素。否则使用 v[4] = 10 这样增加元素的时候会报 索引出错。

	a := []int{1,2,3}
	b := append(a,4,5,6)
	fmt.Println(b)
	
copy复制切片：

	a := []int{1, 2, 3}
	b := []int{4, 5, 6}
	c := []int{7, 8, 9, 0}
	copy(a, b)      //复制b到a 
	fmt.Println(a)  //输出[4,5,6]
	fmt.Println(b)  //输出[4,5,6]
	copy(a, c[:2])  //复制c[0:2]到a
	fmt.Println(a)  //输出[7,8,6]
	copy(a, c[1:])  //复制c[1:3]
	fmt.Println(a)  //输出[8,9,0]
slice切片的长度、最大容量：

	a := make([]int, 10, 10)
	x := len(a)
	y := cap(a)
	fmt.Printf("a的长度是:%v , a的最大容量是：%v\n", x, y)
	fmt.Printf("x = %v, y = %v\n", &x, &y)

### map

`map`也就是Python中字典的概念，它的格式为`map[keyType]valueType`

我们看下面的代码，`map`的读取和设置也类似`slice`一样，通过`key`来操作，只是`slice`的`index`只能是｀int｀类型，而`map`多了很多类型，可以是`int`，可以是`string`及所有完全定义了`==`与`!=`操作的类型。

	// 声明一个key是字符串，值为int的字典,这种方式的声明需要在使用之前使用make初始化
	var numbers map[string] int
	// 另一种map的声明方式
	numbers := make(map[string]int)
	numbers["one"] = 1  //赋值
	numbers["ten"] = 10 //赋值
	numbers["three"] = 3

	fmt.Println("第三个数字是: ", numbers["three"]) // 读取数据
	// 打印出来如:第三个数字是: 3

这个`map`就像我们平常看到的表格一样，左边列是`key`，右边列是值

使用map过程中需要注意的几点：
- `map`是无序的，每次打印出来的`map`都会不一样，它不能通过`index`获取，而必须通过`key`获取
- `map`的长度是不固定的，也就是和`slice`一样，也是一种引用类型
- 内置的`len`函数同样适用于`map`，返回`map`拥有的`key`的数量
- `map`的值可以很方便的修改，通过`numbers["one"]=11`可以很容易的把key为`one`的字典值改为`11`

`map`的初始化可以通过`key:val`的方式初始化值，同时`map`内置有判断是否存在`key`的方式

通过`delete`删除`map`的元素：

	// 初始化一个字典
	rating := map[string]float32 {"C":5, "Go":4.5, "Python":4.5, "C++":2 }
	// map有两个返回值，第二个返回值，如果不存在key，那么ok为false，如果存在ok为true
	csharpRating, ok := rating["C#"]
	if ok {
		fmt.Println("C# is in the map and its rating is ", csharpRating)
	} else {
		fmt.Println("We have no rating associated with C# in the map")
	}

	delete(rating, "C")  // 删除key为C的元素


上面说过了，`map`也是一种引用类型，如果两个`map`同时指向一个底层，那么一个改变，另一个也相应的改变：

	m := make(map[string]string)
	m["Hello"] = "Bonjour"
	m1 := m
	m1["Hello"] = "Salut"  // 现在m["hello"]的值已经是Salut了


### make、new操作

`make`用于内建类型（`map`、`slice` 和`channel`）的内存分配。`new`用于各种类型的内存分配。

内建函数`new`本质上说跟其它语言中的同名函数功能一样：`new(T)`分配了零值填充的`T`类型的内存空间，并且返回其地址，即一个`*T`类型的值。用Go的术语说，它返回了一个指针，指向新分配的类型`T`的零值。有一点非常重要：

>`new`返回指针。

内建函数`make(T, args)`与`new(T)`有着不同的功能，make只能创建`slice`、`map`和`channel`，并且返回一个有初始值(非零)的`T`类型，而不是`*T`。本质来讲，导致这三个类型有所不同的原因是指向数据结构的引用在使用前必须被初始化。例如，一个`slice`，是一个包含指向数据（内部`array`）的指针、长度和容量的三项描述符；在这些项目被初始化之前，`slice`为`nil`。对于`slice`、`map`和`channel`来说，`make`初始化了内部的数据结构，填充适当的值。

>`make`返回初始化后的（非零）值。


关于“零值”，所指并非是空值，而是一种“变量未填充前”的默认值，通常为0。
此处罗列 部分类型 的 “零值”

	int     0
	int8    0
	int32   0
	int64   0
	uint    0x0
	rune    0 //rune的实际类型是 int32
	byte    0x0 // byte的实际类型是 uint8
	float32 0 //长度为 4 byte
	float64 0 //长度为 8 byte
	bool    false
	string  ""
make()分配：内部函数 make(T, args) 的服务目的和 new(T) 不同。             
它只生成切片，映射和程道，并返回一个初始化的（不是零）的，type T的，不是 *T 的值。              
这种区分的原因是，这三种类型的数据结构必须在使用前初始化.               
比如切片是一个三项的描述符，包含数据指针（数组内），长度，和容量；在这些项初始化前，切片为 nil 。                
对于切片、映射和程道，make初始化内部数据结构，并准备要用的值。              
记住 make() 只用于映射、切片和程道，不返回指针。要明确的得到指针用 new() 分配。          

	package main
	
	import (
		"fmt"
		"reflect"
	)
	
	func main() {
		var a = new([]int)
		b := reflect.ValueOf(a)
		fmt.Printf("变量a的类型：%s\n", b.Kind())
		var c = make(map[string]string)
		d := reflect.ValueOf(c)
		fmt.Printf("变量c的类型：%s\n", d.Kind())
	}
