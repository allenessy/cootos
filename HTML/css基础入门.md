生成圆角矩形的CSS样式表：

    -webkit-border-radius: 3px;
    -moz-border-radius: 3px;
    border-radius: 3px;

关于左上 1px，右上 2px，左下 3px，右下 5px 分别设置边角样式表：

    -webkit-border-top-left-radius: 1px;
    -webkit-border-top-right-radius: 2px;
    -webkit-border-bottom-right-radius: 5px;
    -webkit-border-bottom-left-radius: 3px;
    -moz-border-radius-topleft: 1px;
    -moz-border-radius-topright: 2px;
    -moz-border-radius-bottomright: 5px;
    -moz-border-radius-bottomleft: 3px;
    border-top-left-radius: 1px;
    border-top-right-radius: 2px;
    border-bottom-right-radius: 5px;
    border-bottom-left-radius: 3px;

设置背景图片

    background-image:url(bg.png);
    background:url(bg.png);

设置背景颜色

    background-color: #000000;
    background: #000000

background: #00FF00 url(bgimage.gif) no-repeat fixed top;   
设置背景如何重复背景图像   

    background:url(bg.png) repeat-y;

<table>
<tr><td>值</td><td>描述</td></tr>
<tr><td>repeat</td><td>默认。背景图像将在垂直方向和水平方向重复。</td></tr>
<tr><td>repeat-x</td><td>背景图像将在水平方向重复。</td></tr>
<tr><td>repeat-y</td><td>背景图像将在垂直方向重复。</td></tr>
<tr><td>no-repeat</td><td>背景图像将仅显示一次。</td></tr>
<tr><td>inherit</td><td>规定应该从父元素继承 background-repeat 属性的设置。</td></tr>
</table>

定义文本是否有划线以及划线的方式

text-decoration:none

<table>
<tr><td>值</td><td>描述</td></tr>
<tr><td>none</td><td>定义正常显示的文本</td></tr>
<tr><td>underline</td><td>定义有下划线的文本</td></tr>
<tr><td>overline</td><td>定义有上划线的文本</td></tr>
<tr><td>line-through</td><td>定义直线穿过文本</td></tr>
<tr><td>blink</td><td>定义闪烁的文本</td></tr>
<tr><td>inherit</td><td>规定应该从父元素继承 text-decoration 属性的值。</td></tr>
</table>

实例：

a{text-decoration:none}
h1{text-decoration:none}

设置列表项标记的类型

list-style-type:none;
list-style:none;

实例：

ul,li{list-style:none};

<table>
<tr><td>值</td><td>描述</td></tr>
<tr><td>none</td><td>默认。标记是实心圆。</td></tr>
<tr><td>circle</td><td>标记是空心圆。</td></tr>
<tr><td>square</td><td>标记是实心方块。</td></tr>
<tr><td>decimal</td><td>标记是数字。</td></tr>
<tr><td>decimal-leading-zero</td><td>0开头的数字标记。(01, 02, 03, 等。)</td></tr>
</table>
