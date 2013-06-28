###标题    
Markdown 支持两种标题的语法，类 Setext 和类 atx 形式。         
      
类 Setext 形式是用底线的形式，利用 = （最高阶标题）和 - （第二阶标题），例如：         
<pre>
This is an H1
=============
This is an H2
-------------
</pre>
任何数量的 = 和 - 都可以有效果。   
   
类 Atx 形式则是在行首插入 1 到 6 个 # ，对应到标题 1 到 6 阶，例如：   
<pre>
# 这是 H1

## 这是 H2

###### 这是 H6
</pre>
###列表   
   
Markdown 支持有序列表和无序列表。   
   
无序列表使用星号、加号或是减号作为列表标记：   
<pre>
*   Red
*   Green
*   Blue
</pre>
等同于：
<pre>
+   Red
+   Green
+   Blue
</pre>
也等同于：
<pre>
-   Red
-   Green
-   Blue
</pre>
有序列表则使用数字接着一个英文句点：
<pre>
1.  Bird
2.  McHale
3.  Parish
</pre>
###超链接
下面是一个参考式链接的范例：   
<pre><code>
I get 10 times more traffic from [Google] [1] than from
[Yahoo] [2] or [MSN] [3].

  [1]: http://google.com/        "Google"
  [2]: http://search.yahoo.com/  "Yahoo Search"
  [3]: http://search.msn.com/    "MSN Search"
</code></pre>
如果改成用链接名称的方式写：
<pre><code>
I get 10 times more traffic from [Google][] than from             
[Yahoo][] or [MSN][].              
                  
  [google]: http://google.com/        "Google"                
  [yahoo]:  http://search.yahoo.com/  "Yahoo Search"                 
  [msn]:    http://search.msn.com/    "MSN Search"               
</pre>
上面两种写法都会产生下面的 HTML。
<pre>
<p>I get 10 times more traffic from <a href="http://google.com/"                
title="Google">Google</a> than from                
<a href="http://search.yahoo.com/" title="Yahoo Search">Yahoo</a>                
or <a href="http://search.msn.com/" title="MSN Search">MSN</a>.</p>              
</pre>
