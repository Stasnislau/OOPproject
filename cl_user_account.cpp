#include "classes.hpp"
#include <iostream>
User_account::User_account(class Embassy *embassy, std::string login, std::string password, std::string name, std::string surname, char sex, std::string date_of_birth, std::string passport_number, std::string nationality)
{
    m_login = login;
    m_password = password;
    m_name = name;
    m_surname = surname;
    m_date_of_birth = date_of_birth;
    m_passport_number = passport_number;
    m_sex = sex;
    m_nationality = nationality;
    m_id = embassy->optimal_account_id();
}
User_account::User_account()
{
}
char User_account::get_sex()
{
    return m_sex;
}
std::string *User_account::get_nationality()
{
    return &m_nationality;
}
std::string User_account::get_login()
{
    return m_login;
}
std::string User_account::get_password()
{
    return m_password;
}
int User_account::get_id()
{
    return m_id;
}
std::string *User_account::get_name()
{
    return &m_name;
}
std::string *User_account::get_surname()
{
    return &m_surname;
}
std::string *User_account::get_passport_number()
{
    return &m_passport_number;
}
std::string *User_account::get_date_of_birth()
{
    return &m_date_of_birth;
}
int User_account::get_account_applications_size()
{
    return account_applications.size();
}
Application *User_account::get_account_application(int index)
{
    return account_applications[index];
}
int User_account::display_user_second_menu()
{
    std::string temp;
    std::cout << "What do you want to do?" << std::endl;
    std::cout << "1. Create an application" << std::endl;
    std::cout << "2. Check your current applications" << std::endl;
    std::cout << "3. Delete your application" << std::endl;
    std::cout << "4. Book an appointment" << std::endl;
    std::cout << "5. Check your current appontments" << std::endl;
    std::cout << "6. Delete an appointment" << std::endl;
    std::cout << "7. Log out" << std::endl;
    int choice = -1;
    while (true)
    {
        getline(std::cin, temp);
        if (temp[0] >= '0' && temp[0] <= '9')
        {
            choice = std::stoi(temp);
        }
        if (choice >= 1 && choice <= 7)
        {
            break;
        }
        std::cout << "Wrong input. Try entering your option again." << std::endl;
    }
    return choice;
}
void User_account::create_application(class Embassy *embassy)
{
    std::string temp;
    std::cout << "In order to create an application you will be asked to provide some information:" << std::endl;
    std::cout << "What type of application do you want to apply for? 1 - Visa | 2 - TRP | 3 - Refugee: ";
    int choice = -1;
    while (choice < 1 || choice > 3)
    {
        getline(std::cin, temp);
        if (temp[0] >= '0' && temp[0] <= '9')
        {
            choice = std::stoi(temp);
        }
        if (choice > 0 && choice < 4)
            break;
        else
            std::cout << "wrong answer, try again" << std::endl;
    }
    Application application(embassy, this, choice);
    embassy->applications.push_back(application);
    account_applications.push_back(&embassy->applications.back());
}
void User_account::create_appointment(class Embassy *embassy)
{
    int id = -1;
    int index;
    std::string date;
    std::string time;
    if (account_applications.size() == 0)
    {
        std::cout << "You need to create an application first" << std::endl;
        return;
    }
    bool flag = false;
    std::string temp;
    while (flag == false)
    {
        while (true)
        {
            display_current_applications_ids();
            std::cout << "Enter the id of the application you want to book an appointment for: ";
            getline(std::cin, temp);
            if (temp[0] >= '0' && temp[0] <= '9')
            {
                id = std::stoi(temp);
                break;
            }
            else
                std::cout << "Wrong input. Try entering id again." << std::endl;
        }

        for (int i = 0; i < account_applications.size(); i++)
        {
            if (account_applications[i]->get_application_id() == id && account_applications[i]->get_status() == 0)
            {
                flag = true;
                index = i;
                break;
            }
        }
        if (flag == false)
        {
            std::cout << "Wrong id or the decision for this application has already been made." << std::endl;
            return;
        }
        while (true)
        {
            std::cout << "Enter the date of the appointment(dd.mm.yyyy): ";
            getline(std::cin, date);
            if (date.length() == 10 && date[2] == '.' && date[5] == '.' && date[0] >= '0' && date[0] <= '9' && date[1] >= '0' && date[1] <= '9' && date[3] >= '0' && date[3] <= '9' && date[4] >= '0' && date[4] <= '9' && date[6] >= '0' && date[6] <= '9' && date[7] >= '0' && date[7] <= '9' && date[8] >= '0' && date[8] <= '9' && date[9] >= '0' && date[9] <= '9')
            {
                if (embassy->check_valid_date(date,2))
                    break;
                else
                    std::cout << "Wrong date. You can't book an appointment for a date in the past or for today." << std::endl;
            }
            else
                std::cout << "wrong date, try again" << std::endl;
        }
        while (true)
        {
            std::cout << "Enter the time of the appointment(hh:mm): ";
            getline(std::cin, time);
            if (time.length() == 5 && time[2] == ':' && time[0] >= '0' && time[0] <= '2' && time[1] >= '0' && time[1] <= '9' && time[3] >= '0' && time[3] <= '9' && time[4] >= '0' && time[4] <= '9')
            {
                break;
            }
            else
                std::cout << "wrong time format, try again" << std::endl;
        }
    }
    if (account_applications.size() != 0)
    {
        Appointment appointment(embassy, this, id, date, time);
        embassy->appointments.push_back(appointment);
        account_appointments.push_back(&embassy->appointments.back());
        account_applications[index]->application_appointments.push_back(&embassy->appointments.back());
    }
    else
        std::cout << "You have to create an application first." << std::endl;
}
int User_account::display_application_ids()
{
    std::cout << "Currently applications with the following IDs are yours: ";

    if (account_applications.size() == 0)
    {
        std::cout << "none" << std::endl;
        return -1;
    }
    for (int i = 0; i < account_applications.size(); i++)
    {
        std::cout << account_applications[i]->get_application_id() << " ";
    }
    std::cout << std::endl;

    int id_to_delete = -1;
    std::string temp;
    while (id_to_delete < 0)
    {
        std::cout << "Enter the ID of the application you want to delete: ";
        getline(std::cin, temp);
        if (temp[0] >= '0' && temp[0] <= '9')
        {
            id_to_delete = std::stoi(temp);
        }
    }
    return id_to_delete;
}
void User_account::display_current_applications()
{
    bool flag = false;
    for (int i = 0; i < account_applications.size(); i++)
    {
        switch (account_applications[i]->get_type())
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
        std::cout << "Application id: " << account_applications[i]->get_application_id() << std::endl;
        switch (account_applications[i]->get_status())
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

        std::cout << "Name: " << *account_applications[i]->get_name() << " " << *account_applications[i]->get_surname() << std::endl;
        std::cout << "Date of birth: " << *account_applications[i]->get_date_of_birth() << std::endl;
        std::cout << "Sex: " << account_applications[i]->get_sex() << std::endl;
        std::cout << "Nationality: " << *account_applications[i]->get_nationality() << std::endl;
        std::cout << "Passport number: " << *account_applications[i]->get_passport_number() << std::endl;
        std::cout << std::endl;
        flag = true;
    }
    if (flag == false)
        std::cout << "You don't have any applications" << std::endl;
}
void User_account::display_current_appointments()
{
    bool flag = false;
    for (int i = 0; i < account_appointments.size(); i++)
    {
        std::cout << "Appointment id: " << account_appointments[i]->get_id() << std::endl;
        std::cout << "Name: " << *account_appointments[i]->get_name() << " " << *account_appointments[i]->get_surname() << std::endl;
        std::cout << "Date of the appointment: " << account_appointments[i]->get_date() << std::endl;
        std::cout << "Time of the appointment: " << account_appointments[i]->get_time() << std::endl;
        std::cout << "Passport number of the person: " << *account_appointments[i]->get_passport_number() << std::endl;
        std::cout << std::endl;
        flag = true;
    }
    if (flag == false)
        std::cout << "You don't have any appointments" << std::endl;
}
void User_account::display_current_applications_ids()
{
    bool flag = false;
    std::cout << "Application ids: ";
    for (int i = 0; i < account_applications.size(); i++)
    {
        std::cout << account_applications[i]->get_application_id() << " ";
        flag = true;
    }
    std::cout << std::endl;
}
void User_account::delete_appointment(class Embassy *embassy)
{
    std::cout << "Currently appointments with the following IDs are yours: ";

    if (account_appointments.size() == 0)
    {
        std::cout << "none" << std::endl;
        return;
    }
    for (int i = 0; i < account_appointments.size(); i++)
    {
        std::cout << account_appointments[i]->get_id() << " ";
    }
    std::cout << std::endl;
    std::string temp;

    int id_to_delete = -1;
    while (true)
    {
        std::cout << "Enter the ID of the appointment you want to delete: ";
        getline(std::cin, temp);
        if (temp[0] >= '0' && temp[0] <= '9')
        {
            id_to_delete = std::stoi(temp);
            break;
        }
    }

    bool deleted = false;
    deleted = embassy->execute_delete_appointment(id_to_delete);
    if (deleted == true)
    {
        std::cout << "Appointment deleted." << std::endl;
    }
    else
    {
        std::cout << "Appointment not found." << std::endl;
    }
}
void User_account::delete_application(class Embassy *embassy)
{
    std::cout << "Currently applications with the following IDs are yours: ";

    if (account_applications.size() == 0)
    {
        std::cout << "none" << std::endl;
        return;
    }
    for (int i = 0; i < account_applications.size(); i++)
    {
        std::cout << account_applications[i]->get_application_id() << " ";
    }
    std::cout << std::endl;
    std::string temp;

    int id_to_delete = -1;
    while (true)
    {
        std::cout << "Enter the ID of the application you want to delete: ";
        getline(std::cin, temp);
        if (temp[0] >= '0' && temp[0] <= '9')
        {
            id_to_delete = std::stoi(temp);
            break;
        }
    }

    bool deleted = false;
    deleted = embassy->execute_delete_application(id_to_delete);
    if (deleted == true)
    {
        std::cout << "Application deleted." << std::endl;
    }
    else
    {
        std::cout << "Application not found." << std::endl;
    }
}
void User_account::admin_display_account()
{
    std::cout << "Account id: " << m_id << std::endl;
    std::cout << "Login: " << m_login << std::endl;
    std::cout << "Name: " << m_name << " " << m_surname << std::endl;
    std::cout << "Sex: " << m_sex << std::endl;
    std::cout << "Date of birth " << m_date_of_birth << std::endl;
    std::cout << "Passport number: " << m_passport_number << std::endl;
    std::cout << "Nationality: " << m_nationality << std::endl;
    display_current_applications_ids();
    std::cout << std::endl;
}
void User_account::erase_pointers_after_application_deleting(int id_of_application)
{
    bool flag = false;
    for (int i = 0; i < account_applications.size(); i++)
    {
        if (flag == true)
        {
            i = 0;
        }
        flag = false;
        if (account_applications[i]->get_application_id() == id_of_application)
        {
            account_applications.erase(account_applications.begin() + i);
            flag = true;
            i = -1;
        }
    }
    for (int i = 0; i < account_appointments.size(); i++)
    {
        if (flag == true)
        {
            i = 0;
        }
        flag = false;
        if (account_appointments[i]->get_id() == id_of_application)
        {
            account_appointments.erase(account_appointments.begin() + i);
            flag = true;
            i = -1;
        }
    }
}
void User_account::erase_pointers_after_appointment_deleting(int id_of_appointment)
{
    bool flag = false;
    for (int i = 0; i < account_appointments.size(); i++)
    {
        if (flag == true)
        {
            i = 0;
        }
        flag = false;
        if (account_appointments[i]->get_id() == id_of_appointment)
        {
            account_appointments.erase(account_appointments.begin() + i);
            flag = true;
            i = -1;
        }
    }
}
