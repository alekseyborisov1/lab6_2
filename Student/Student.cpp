#include "stdafx.h"
#include "Student.h"

CStudent::CStudent(std::string name, std::string surname, std::string patronymic, int age):
	m_name(name), m_surname(surname), m_patronymic(patronymic), m_age(age)
{
	isCorrect(name, "Name");
	isCorrect(surname, "Surname");
	isCorrect(patronymic, "Patronymic");
	isCorrect(age);
}


std::string CStudent::GetName()
{
	return m_name;
}

std::string CStudent::GetSurname()
{
	return m_surname;
}

std::string CStudent::GetPatronymic()
{
	return m_patronymic;
}

int CStudent::GetAge()
{
	return m_age;
}

void CStudent::Rename(std::string name, std::string surname, std::string patronymic)
{
	if (isCorrect(name, "Cant rename. New name ") && isCorrect(surname, "Cant rename. New surname ") &&
		isCorrect(patronymic, "Patronymic"))
	{
		m_name = name;
		m_surname = surname;
		m_patronymic = patronymic;
	}
}

void CStudent::SetAge(int age)
{
	if(m_age > age)
	{
		throw std::domain_error("Cant change age. New age must be less then previous");
	}
	if(isCorrect(age))
	{
		m_age = age;
	}
}

bool isCorrect(std::string str, std::string message)
{
	  if ((str.empty()) && (message != "Patronymic"))
	  {
		  throw std::invalid_argument(message + " is empty");
	  }

	  for (int i = 0; i < str.length(); ++i)
	  {
		  if(str[i] == ' ')
		  {
			  throw std::invalid_argument(message + "\"" + str + "\"" + " have a space(-s).");
		  }
	  }
	  return true;
}

bool isCorrect(int num)
{
	if ((num < 14) || (num > 60))
	{
		 throw std::out_of_range("Incorrect age");
	}
	return true;
}