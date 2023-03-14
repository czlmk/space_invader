#include "server.h"

Server::Server(const string& host, const string& user, const string& password, const string& database) {
    // Initialize the MySQL Connector/C++ driver
    try{
    driver = get_driver_instance();

    // Connect to the MySQL database
    conn = driver->connect(host, user, password);
    conn->setSchema(database);

    // Prepare a statement for inserting user records
    stmt = conn->prepareStatement("INSERT INTO users (username, password) VALUES (?, ?)");
            } catch (sql::SQLException &e) {
        // Handle any SQL errors that occur
        cerr << "Error message: " << e.what() << endl;
        cerr << "Error code: " << e.getErrorCode() << endl;
        cerr << "SQL state: " << e.getSQLState() << endl;
    } catch (std::exception &e) {
        // Handle any other exceptions that occur
        cerr << "Exception message: " << e.what() << endl;
    }
}

Server::Server(){

    try{
        // Initialize the MySQL Connector/C++ driver
    driver = get_driver_instance();

    // Connect to the MySQL database
    conn = driver->connect("127.0.0.1:3306", "root", "zhenyiming");
    conn->setSchema("space_inv");

    // Prepare a statement for inserting user records
    stmt = conn->prepareStatement("INSERT INTO users (username, password) VALUES (?, ?)");
        } catch (sql::SQLException &e) {
        // Handle any SQL errors that occur
        cerr << "Error message: " << e.what() << endl;
        cerr << "Error code: " << e.getErrorCode() << endl;
        cerr << "SQL state: " << e.getSQLState() << endl;
    } catch (std::exception &e) {
        // Handle any other exceptions that occur
        cerr << "Exception message: " << e.what() << endl;
    }
}
Server::~Server() {
    // Clean up resources
    delete stmt;
    delete conn;
}

void Server::insertUser(const string username, const string password) {
    try{
    // Bind the parameters to the prepared statement
    stmt->setString(1, username);
    stmt->setString(2, password);

    // Execute the statement
    stmt->executeUpdate();
        } catch (sql::SQLException &e) {
        // Handle any SQL errors that occur
        cerr << "Error message: " << e.what() << endl;
        cerr << "Error code: " << e.getErrorCode() << endl;
        cerr << "SQL state: " << e.getSQLState() << endl;
    } catch (std::exception &e) {
        // Handle any other exceptions that occur
        cerr << "Exception message: " << e.what() << endl;
    }

}