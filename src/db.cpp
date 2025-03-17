#include "db.h"
#include <string>

//constructor that helps creating instance of db(e.g. sales.db) accepts name of the database, username, password. 
//ToDo
Database::Database(std::string database, std::string un, std::string pw)
{
    db = database;
    username = un;
    password = pw;
    connected = false;
}

//destructor that disconnects the connection if connected.
//ToDo
Database::~Database()
{
    if (connected)
    {
        disconnect();
    }
    //delete instance;
}

//"getInstance" that creates and returns the instance of the database. If called first time it sets the username and password. However, subsequent time, it matches the database name, username and password and returns the previous instance if matched else it throws std::runtime_error("invalid database name, username or password"). We are using Singleton Design Pattern that creates only one instance of the databse. The instance is still created by the constructor.
 //ToDo
Database* Database::getInstance(std::string database, std::string un, std::string pw)
{
    if (instance == nullptr)
    {
        instance = new Database(database, un, pw);
    }
    else
    {
        if (instance->db != database || instance->username != un || instance->password != pw)
        {
            throw std::runtime_error("invalid database name, username or password");
        }
    }
    return instance;
}

//"connect" that sets "connected" to true (return void)
//ToDo
void Database::connect()
{
    connected = true;
}

//"disconnect" that sets "connected" to false (return void)
//ToDo
void Database::disconnect()
{
    connected = false;
}

// return status of connected true/false (return bool)
//ToDo
bool Database::isConnected()
{
    return connected;
}

//overload the new operator that allocates memory using malloc of given size and returns pointer of type void and prints " overloaded new " (cout is okay in this case). std::cout << "overloaded new ";
//If the memory allocation fails it should throw std::bad_alloc()
//ToDo
void* Database::operator new (size_t size)
{
    std::cout << "overloaded new ";
    void* p = malloc(size);
    if (p == NULL)
    {
        throw std::bad_alloc();
    }
    return p;
}

//overload the delete operator that deallocates memory and prints "overloaded delete " (cout is okay in this). std::cout << "overloaded delete ";
//ToDo
void Database::operator delete(void* p)
{
    std::cout << "overloaded delete ";
    free(p);
}

//set_username and get_username for username
//ToDo
void Database::set_username(std::string un)
{
    username = un;
}
//ToDo
std::string Database::get_username()
{
    return username;
}
//set_password and get_password for password.
//ToDo
void Database::set_password(std::string pw)
{
    password = pw;
}
//ToDo
std::string Database::get_password()
{
    return password;
}

//The static "resetInstance" as defined below.
void Database::resetInstance()
{
    if (instance != nullptr) {
        delete instance;
        instance = nullptr;
    }
}

Database* Database::instance = nullptr;

//Singleton* Singleton::instance = nullptr;
//
//Singleton& Singleton::get() {
//    // may be responsible for creating its own unique instance.
//    if (nullptr == instance) instance = new Singleton;
//    return *instance;
//}
//void Singleton::destruct() {
//    delete instance;
//    instance = nullptr;
//}
//// existing interface goes here
//int Singleton::getValue() {
//    return value;
//}
//void Singleton::setValue(int value_) {
//    value = value_;
//}