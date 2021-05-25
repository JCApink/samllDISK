#pragma once
#include <string>
#include <mysql/mysql.h>
#include <iostream>
using namespace std;

class MyDb 
{
public:
    MyDb();
    ~MyDb();
    bool initDB(string host, string user, string pwd, string db_name, int port);
    bool exeSQL(string sql);
    bool select_one_SQL(std::string sql, string &str);
    bool select_many_SQL(std::string sql, string &str);
    
private:
    MYSQL *mysql;
    MYSQL_RES *result;
    MYSQL_ROW row;
};

