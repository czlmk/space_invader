#ifndef SERVER_H
#define SERVER_H

#include <string>
#include "mysql_driver.h"
#include <cppconn/driver.h>
#include <cppconn/connection.h>
#include <cppconn/prepared_statement.h>

using namespace std;
using namespace sql;

class Server {
public:
    Server(const string& host, const string& user, const string& password, const string& database);
    Server();
    ~Server();
    void insertUser(const string username, const string password);

private:
    Driver *driver;
    Connection *conn;
    PreparedStatement *stmt;
};

#endif