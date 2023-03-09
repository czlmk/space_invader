#include <iostream>
#include <mysqlx/xdevapi.h>
#include <memory>



class MySQLCon {
public:
    MySQLCon(const std::string& host, int port, const std::string& user, const std::string& password, const std::string& database) :
        host_(host), port_(port), user_(user), password_(password), database_(database)
    {
        try {
            session_ = std::make_unique<mysqlx::Session>(host_, port_, user_, password_);
            session_->getDefaultSchema().createCollection("users", true);
        } catch (const mysqlx::Error& err) {
            std::cerr << "Error: " << err << std::endl;
        }
    }

    ~MySQLCon() {
        session_->close();
    }

    void addUserToDatabase(const std::string& host, int port, const std::string& user, const std::string& password, const std::string& database, const std::string& name, const std::string& passwordHash) {
    try {
        
        session_->getDefaultSchema().createCollection("users", true);

        mysqlx::Table usersTable = session_->getDefaultSchema().getTable("users");
        mysqlx::Row userRow;
        userRow.set(0,name);
        userRow.set(1,password);

        
        usersTable.insert(userRow).execute();
        
    } catch (const mysqlx::Error& err) {
        std::cerr << "Error: " << err << std::endl;
    }
}
private:
    std::string host_;
    int port_;
    std::string user_;
    std::string password_;
    std::string database_;
    std::unique_ptr<mysqlx::Session> session_;
};