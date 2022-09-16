#include "classes.hpp"
#include <iostream>
std::string Appointment::get_date()
{
    return m_date;
}
std::string Appointment::get_time()
{
    return m_time;
}
int Appointment::get_id()
{
    return m_id_of_appointment;
}
int Appointment::get_application_id()
{
    return m_application_id;
}
std::string *Appointment::get_name()
{
    return m_name;
}
std::string *Appointment::get_surname()
{
    return m_surname;
}
std::string *Appointment::get_passport_number()
{
    return m_passport_number;
}
Appointment::Appointment(class Embassy *embassy, class User_account *account, int id, std::string date, std::string time)
{
    m_application_id = id;
    int index;
    m_id_of_appointment = embassy->optimal_appointment_id();
    
    m_date = date;
    m_time = time;
    m_name = account->get_name();
    m_surname = account->get_surname();
    m_date_of_birth = account->get_date_of_birth();
    m_passport_number = account->get_passport_number();
}
void Appointment::admin_display_appointment()
{
    std::cout << "Appointment id " << m_id_of_appointment << std::endl;
    std::cout << "Application id: " << m_application_id << std::endl;
    std::cout << "Name: " << *m_name << " " << *m_surname << std::endl;
    std::cout << "Date: " << m_date << std::endl;
    std::cout << "Time: " << m_time << std::endl;
    std::cout << std::endl;
}