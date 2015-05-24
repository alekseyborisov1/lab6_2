#pragma once

class CStudent final
{

public:
	CStudent(std::string name, std::string surname, std::string patronymic, int age);

	std::string GetName();
	std::string GetSurname();
	std::string GetPatronymic();
	int GetAge();
	void Rename(std::string name, std::string surname, std::string patronymic);
	void SetAge(int age);

private:
	std::string m_name, m_surname, m_patronymic;
	int m_age;

    friend bool isCorrect(std::string str, std::string message);
	friend bool isCorrect(int num);

};