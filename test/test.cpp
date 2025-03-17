#define CATCH_CONFIG_MAIN			// this line tells Catch to provide a main() function
#define CATCH_CONFIG_COLOUR_NONE

#include "catch2\catch.hpp"
#include "db.h"

TEST_CASE("General testing")
{
	std::string db = "db";
	std::string us = "us";
	std::string pw = "pw";


	Database* db1 = Database::getInstance("TestDB", "admin", "pass123");
	CHECK(Database::getInstance("TestDB", "admin", "pass123"));
	CHECK_THROWS(Database::getInstance("TestDB", "admin", "pass1234"));



}