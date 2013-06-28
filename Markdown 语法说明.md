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

      I get 10 times more traffic from [Google] [1] than from
      [Yahoo] [2] or [MSN] [3].
      
      [1]: http://google.com/        "Google"
      [2]: http://search.yahoo.com/  "Yahoo Search"
      [3]: http://search.msn.com/    "MSN Search"

如果改成用链接名称的方式写：

      I get 10 times more traffic from [Google][] than from
      [Yahoo][] or [MSN][].
      
      [google]: http://google.com/        "Google"
      [yahoo]:  http://search.yahoo.com/  "Yahoo Search"
      [msn]:    http://search.msn.com/    "MSN Search"

上面两种写法都会产生下面的 HTML。

      <p>I get 10 times more traffic from <a href="http://google.com/"
      title="Google">Google</a> than from
      <a href="http://search.yahoo.com/" title="Yahoo Search">Yahoo</a>
      or <a href="http://search.msn.com/" title="MSN Search">MSN</a>.</p>

###代码区块
   
和程序相关的写作或是标签语言原始码通常会有已经排版好的代码区块，通常这些区块我们并不希望它以一般段落文件的方式去排版，而是照原来的样子显示，Markdown 会用 `<pre>` 和 `<code> `标签来把代码区块包起来。   
   
要在 Markdown 中建立代码区块很简单，只要简单地缩进 4 个空格或是 1 个制表符就可以，例如，下面的输入：
<pre>
这是一个普通段落：

	这是一个代码区块。
</pre>
Markdown 会转换成：

	<p>这是一个普通段落：</p>
	
	<pre><code>这是一个代码区块。
	</code></pre>
这个每行一阶的缩进（4 个空格或是 1 个制表符），都会被移除，例如：

	Here is an example of AppleScript:
	
		tell application "Foo"
			beep
		end tell
会被转换为：

	<p>Here is an example of AppleScript:</p>
	
	<pre><code>tell application "Foo"
		beep
	end tell
	</code></pre>
一个代码区块会一直持续到没有缩进的那一行（或是文件结尾）。
