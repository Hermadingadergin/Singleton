#define CATCH_CONFIG_MAIN			// this line tells Catch to provide a main() function
#define CATCH_CONFIG_COLOUR_NONE

#include "catch2\catch.hpp"
#include "db.h"

TEST_CASE("General testing")
{
	std::string db = "db";
	std::string us = "us";
	std::string pw = "pw";

	Database::getInstance(db, us, pw);
	CHECK(Database::getInstance(db, us, pw).get_username() == us);
	CHECK(Database::getInstance(db, us, pw).get_password() == pw);
	CHECK_THROWS(Database::getInstance(db, us, "pwe"));



}