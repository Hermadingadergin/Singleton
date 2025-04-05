#include <string>
#include <iostream>
#include <fstream>
#include <ctime>

//db.h
class Database {
private:
        
    //member variable "db" is of string type
    //ToDo
    std::string db;
       
    //member variable "username" is of string type
    //ToDo
    std::string username;

    //member variable "password" is of string type
    //ToDo
    std::string password;
    
    //member variable "connected" is of boolean type
    //The "connected" is set to false initially.
    //ToDo
    bool connected;

    //member variable "instance" is static 
    //"instance" (pointer to Database) is a staic variable that stores the instance of the database. Its value is set in the function "getInstance"
    //ToDo
    static Database* instance;
        
    //constructor that helps creating instance of db(e.g. sales.db) accepts name of the database, username, password. 
    //ToDo
    Database(std::string db, std::string un, std::string pw);
         
    //destructor that disconnects the connection if connected.
    //ToDo
    ~Database();

     Database() = default;

     // copy constructor
     Database(const Database&);

     // copy assignment operator
     Database& operator=(const Database&);

     // move constructor
     Database(Database&&);

     // move assignment operator
     Database& operator=(Database&&);

     time_t last_activity;
     static const int TIMEOUT{ 5 };
public:
         
    //"getInstance" that creates and returns the instance of the database. If called first time it sets the username and password. However, subsequent time, it matches the database name, username and password and returns the previous instance if matched else it throws std::runtime_error("invalid database name, username or password"). We are using Singleton Design Pattern that creates only one instance of the databse. The instance is still created by the constructor.
     //ToDo
     static Database* getInstance(std::string database, std::string un, std::string pw);
         
     //"connect" that sets "connected" to true (return void)
     //ToDo
     void connect();

     //"disconnect" that sets "connected" to false (return void)
     //ToDo
     void disconnect();
     
     // return status of connected true/false (return bool)
     //ToDo
     bool isConnected();
         
     //overload the new operator that allocates memory using malloc of given size and returns pointer of type void and prints " overloaded new " (cout is okay in this case). std::cout << "overloaded new ";
     //If the memory allocation fails it should throw std::bad_alloc()
     //ToDo
     void* operator new (size_t size);
         
     //overload the delete operator that deallocates memory and prints "overloaded delete " (cout is okay in this). std::cout << "overloaded delete ";
     //ToDo
     void operator delete(void*);
        
     //set_username and get_username for username
     //ToDo
     const void set_username(std::string un);
     //ToDo
     const std::string get_username();
         //set_password and get_password for password.
     //ToDo
     const const void set_password(std::string pw);
     //ToDo
     const std::string get_password();

     //The static "resetInstance" as defined below.
     const static void resetInstance();

     // Checks if the connection has been inactive for longer than TIMEOUT seconds
     // Returns true if the timeout threshold has been exceeded, false otherwise
     bool isTimeout();

     // Updates the last_activity timestamp to the current time
     // Should be called whenever there is interaction with the database to reset the timeout
     void refreshConnection();

};

//class Singleton {
//public:
//    // defines an class operation that lets clients access its unique instance.
//    static Singleton& get();
//    Singleton(const Singleton&) = delete; // rule of three
//    Singleton& operator=(const Singleton&) = delete;
//    static void destruct();
//    int getValue();
//    void setValue(int value_);
//private:
//    Singleton() = default; // no public constructor
//    ~Singleton() = default; // no public destructor
//    static Singleton* instance; // declaration class variable
//    int value;
//};