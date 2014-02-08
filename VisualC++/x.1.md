#MySQL Connector/C
下载地址: [http://dev.mysql.com/downloads/connector/c/](http://dev.mysql.com/downloads/connector/c/)			
把下载回来的文件解压后存放结构如下:		
```text
D:\lib\mysql\include
D:\lib\mysql\lib
```
生成->配置管理器->活动解决方案平台->新建->键入或选择新平台->x64->确定->配置->Release

项目->项目属性-> VC++ 目录->包含目录->`D:\lib\mysql\include`

项目->项目属性-> 链接器 ->常规->附加库目录->`D:\lib\mysql\lib`

项目->项目属性-> 链接器 ->输入->附加依赖项->`libmysql.lib;`
```c
#include <iostream>
#include <stdio.h>
#include "mysql.h"
#pragma comment(lib,"libmysql.lib")

using namespace std;

MYSQL *mysql_init(MYSQL *mysql);
MYSQL *mysql_real_connect(MYSQL *mysql,
	const char *host,
	const char *user,
	const char *passwd,
	const char *db,
	unsigned int port,
	const char *unix_socket,
	unsigned long client_flag);
void mysql_close(MYSQL *mysql);
int mysql_options(MYSQL *mysql, enum mysql_option option, const void *arg);

int main()
{
	MYSQL *conn_ptr;

	conn_ptr = mysql_init(NULL);

	if (!conn_ptr){
		fprintf(stderr, "mysql_init failed\n");
		return EXIT_FAILURE;
	}
	conn_ptr = mysql_real_connect(conn_ptr, "localhost", "root", "secret", "mysql", 0, NULL, 0);

	if (conn_ptr){
		printf("Connection sucess\n");
	}
	else{
		printf("Connection failed\n");
	}

	mysql_close(conn_ptr);

	return EXIT_SUCCESS;
}
```
生成->重新生成解决方案

调试->开始执行。提示错误。把`libmysql.dll`复制到`C:\Windows\System32`目录下，或者项目`Release`目录下，即可。
