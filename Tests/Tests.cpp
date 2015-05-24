// Tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../Student/Student.h"

BOOST_FIXTURE_TEST_SUITE(CStudentTestSuite)

BOOST_AUTO_TEST_CASE(TestNewObject)
{
	try
	{
		CStudent student("John", "Silverman", "", 18);
	}
	catch(std::invalid_argument & e)
	{
		std::cerr << e.what() << std::endl;
		BOOST_CHECK(false);
	}
	catch(std::out_of_range & e)
	{
		std::cerr << e.what() << std::endl;
		BOOST_CHECK(false);
	}
	
	try
	{
		CStudent student("Ashley", "Williams", " Madeline ", 13);
	}
	catch(std::invalid_argument & e)
	{
		BOOST_CHECK(true);
	}
	catch(std::out_of_range & e)
	{
		std::cerr << e.what() << std::endl;
		BOOST_CHECK(false);
	}
}

CStudent student("John", "Silverman", "", 18);

BOOST_AUTO_TEST_CASE(CheckMethodsOfObject)
{
	BOOST_CHECK_EQUAL(student.GetName(), "John");
	BOOST_CHECK_EQUAL(student.GetSurname(), "Silverman");
	BOOST_CHECK_EQUAL(student.GetPatronymic(), "");
	BOOST_CHECK_EQUAL(student.GetAge(), 18);
}

BOOST_AUTO_TEST_CASE(TestChangingOfObject)
{
	try
	{
		student.Rename("Johnny", "Goldman", "");
		student.SetAge(20);
		BOOST_CHECK(true);
	}
	catch(std::invalid_argument & e)
	{
		std::cerr << e.what() << std::endl;
		BOOST_CHECK(false);
	}
	catch(std::out_of_range & e)
	{
		std::cerr << e.what() << std::endl;
		BOOST_CHECK(false);
	}
}

BOOST_AUTO_TEST_CASE(TestWrongChangingOfObject)
{
	try
	{
		student.Rename(" gg", "", " w e");
		student.SetAge(15);
	}
	catch(std::invalid_argument & e)
	{
		BOOST_CHECK(true);
	}
	catch(std::out_of_range & e)
	{
		std::cerr << e.what() << std::endl;
		BOOST_CHECK(false);
	}
}

BOOST_AUTO_TEST_CASE(Back_n_rollTest)
{
	BOOST_CHECK_EQUAL(student.GetName(), "Johnny");
	BOOST_CHECK_EQUAL(student.GetSurname(), "Goldman");
	BOOST_CHECK_EQUAL(student.GetPatronymic(), "");
	BOOST_CHECK_EQUAL(student.GetAge(), 20);
}

BOOST_AUTO_TEST_SUITE_END()
