#include "classes.hpp"
#include <iostream>
int Application::get_type()
{
    return m_type;
}
std::string *Application::get_name()
{
    return m_name;
}
std::string *Application::get_surname()
{
    return m_surname;
}
std::string *Application::get_date_of_birth()
{
    return m_date_of_birth;
}
char Application::get_sex()
{
    return m_sex;
}
std::string *Application::get_nationality()
{
    return m_nationality;
}
std::string *Application::get_passport_number()
{
    return m_passport_number;
}
int Application::get_application_id()
{
    return m_application_id;
}
int Application::get_account_id()
{
    return m_account_id;
}
int Application::get_status()
{
    return m_status;
}
void Application::set_status(int status)
{
    m_status = status;
}
Application::Application()
{
}
Application::Application(class Embassy *embassy, class User_account *account, int type)
{
    m_name = account->get_name();
    m_surname = account->get_surname();
    m_date_of_birth = account->get_date_of_birth();
    m_passport_number = account->get_passport_number();
    m_sex = account->get_sex();
    m_nationality = account->get_nationality();
    m_type = type;

    m_account_id = account->get_id();
    m_application_id = embassy->optimal_application_id();
    m_status = 0;
}
void Application::amdin_display_application()
{
    switch (m_type)
    {
    case 0:
        std::cout << "Type: VISA" << std::endl;
        break;
    case 1:
        std::cout << "Type: Temperary Residence Permission" << std::endl;
        break;
    default:
        std::cout << "Type: Refugee" << std::endl;
        break;
    }
    std::cout << "Application id: " << m_application_id << std::endl;
    switch (m_status)
    {
    case 1:
        std::cout << "Status: Approved" << std::endl;
        break;
    case -1:
        std::cout << "Status: Rejected" << std::endl;
        break;
    case 0:
        std::cout << "Status: Pending" << std::endl;
        break;
    }
    std::cout << "Account ID: " << m_account_id << std::endl;
    std::cout << "Name: " << *m_name << " " << *m_surname << std::endl;
    std::cout << "Date of birth: " << *m_date_of_birth << std::endl;
    std::cout << "Sex: " << m_sex << std::endl;
    std::cout << "Nationality: " << *m_nationality << std::endl;
    std::cout << "Passport number: " << *m_passport_number << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}

int Application::erase_pointers_after_appointment_deleting(int id_of_appointment)
{
    for (int i = 0; i < application_appointments.size(); i++)
    {
        if (application_appointments[i]->get_id() == id_of_appointment)
        {
            application_appointments.erase(application_appointments.begin() + i);
            break;
        }
    }
    return m_account_id;
}
int Application::erase_pointers_after_application_deleting()
{
    for (int i = 0; i < application_appointments.size(); i++)
    {
        application_appointments.erase(application_appointments.begin() + i);
        i = 0;
    }
    return m_account_id;
}