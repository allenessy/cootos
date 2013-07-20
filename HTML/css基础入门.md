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
