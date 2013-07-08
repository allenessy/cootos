###数组
数组可以构造成一系列键-值 ( key - value )对，其中每一对都是那个数组的一个项目或元素( element )。对于列表中的每个项目，都有一个与之关联的键(key)(或索引(index))

    键        值
    0         The Mynabirds
    1         Jeremy Messersmith
    2         The Shins
    3         Iron and Wine
    4         Alexi Murdoch

PHP支持两种数组：索引数组( indexed array )和关联数组( associative array ),前者使用数字作为键，后者使用字符串作为键。

    键        值
    MD        Maryland
    PA        Pennsylvania
    IL        Illinois
    MO        Missouri
    IA        Iowa

要在数组中检索特定的值，需要先引用数组变量名称，然后在方括号中指出键：

    $ar1 = $array[0];     //索引数组
    $ar2 = $array['MD'];  //关联数组
    echo "IL is {$array['IL']}.";

如果数组使用字符串作为键，用于括住键的引号将使语法变得混乱，引发解析错误。    
为了解决这个问题，当数组使用字符串作为它的键时，把数组名和键包括在花括号中。
