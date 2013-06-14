package main

import (
  "database/sql"
	"fmt"
	_ "github.com/go-sql-driver/mysql"
)

func main() {
	db,err := sql.Open("mysql","用户名:密码@tcp(localhost:3306)/数据库名?charset=utf8")
	if err != nil {
		panic(err.Error())
	}
	defer db.Close()
/*	rows,err := db.Query("SELECT * FROM user")
	if err!= nil{
		panic(err.Error())
	}	
	columns,err := rows.Columns()
	if err !=nil{
		panic(err.Error())
	}*/
}
