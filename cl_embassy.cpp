Embassy::Embassy()
{
}
int Embassy::display_initial_menu()
{
    std::string temp;
    std::cout << "Welcome to the Embassy!" << std::endl;
    std::cout << "1. Civil cases" << std::endl;
    std::cout << "2. Login as an administator" << std::endl;
    std::cout << "3. Exit the program" << std::endl;
    int choice = -1;
    while (true)
    {
        getline(std::cin, temp);
        if (temp[0] >= '0' && temp[0] <= '9')
        {
            choice = std::stoi(temp);
        }
        if (choice == 1 || choice == 2 || choice == 3)
        {
            break;
        }
        else
        {
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    }
    return choice;
}
int Embassy::get_accounts_size()
{
    return accounts.size();
}
int Embassy::get_applications_size()
{
    return applications.size();
}
bool Embassy::check_login(std::string login)
{
    for (std::list<User_account>::iterator it = accounts.begin(); it != accounts.end(); it++)
    {
        if (it->get_login() == login)
        {
            return true;
        }
    }
    return false;
}
bool Embassy::check_passport_number(std::string passport_number)
{
    for (std::list<User_account>::iterator it = accounts.begin(); it != accounts.end(); it++)
    {
        if (*it->get_passport_number() == passport_number)
        {
            return true;
        }
    }
    return false;
}
User_account &Embassy::get_account(int index)
{
    std::list<User_account>::iterator it = accounts.begin();
    for (int i = 0; i < index; i++)
    {
        it++;
    }
    return *it;
}
int Embassy::display_user_first_menu()
{
    std::string temp;
    std::cout << "Civil cases || What do you want to do?" << std::endl;
    std::cout << "1. Login" << std::endl;
    std::cout << "2. Create a new account" << std::endl;
    std::cout << "3. Back" << std::endl;
    int choice = -1;
    while (true)
    {
        getline(std::cin, temp);
        if (temp[0] >= '0' && temp[0] <= '9')
        {
            choice = std::stoi(temp);
        }
        if (choice == 1 || choice == 2 || choice == 3)
        {
            break;
        }
        else
        {
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    }
    return choice;
}
int Embassy::logging_in()
{
    std::string login;
    std::string password;
    std::cout << "Enter your login and password." << std::endl;
    std::cout << "Enter login: ";
    getline(std::cin, login);
    std::cout << "Enter password: ";
    getline(std::cin, password);
    int index = -1;
    std::list<User_account>::iterator it = accounts.begin();
    for (int i = 0; it != accounts.end(); it++, i++)
    {
        if (it->get_login() == login)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        std::cout << "Invalid login or password. Try again." << std::endl;
        return -1;
    }
    else
    {
        if (it->get_password() == password)
        {
            std::cout << "You have successfully logged in." << std::endl;
            return index;
        }
        else
        {
            std::cout << "Invalid login or password. Try again." << std::endl;
            return -1;
        }
    }
}
void Embassy::add_user()
{
    std::string login;
    std::string password;
    while (true)
    {

        std::cout << "Create login: ";
        getline(std::cin, login);
        std::cout << "Create password: ";
        getline(std::cin, password);
        if (login.size() > 0 && password.size() > 0 && check_login(login) == false)
        {
            break;
        }
        else
        {
            std::cout << "Login and password should have at least 1 symbol, or the login is already taken . Try again." << std::endl;
        }
    }
    std::string name;
    while (true)
    {
        std::cout << "Enter your name: ";
        getline(std::cin, name);
        if (name.size() > 0)
        {
            break;
        }
        else
        {
            std::cout << "Name should have at least 1 symbol" << std::endl;
        }
    }
    std::string surname;
    while (true)
    {
        std::cout << "Enter your surname: ";
        getline(std::cin, surname);
        if (surname.size() > 0)
        {
            break;
        }
        else
        {
            std::cout << "Surname should have at least 1 symbol" << std::endl;
        }
    }
    std::string date_of_birth;
    while (true)
    {
        std::cout << "Enter your date of birth (dd.mm.yyyy): ";
        getline(std::cin, date_of_birth);
        if (date_of_birth.size() == 10 && date_of_birth[2] == '.' && date_of_birth[5] == '.' && date_of_birth[0] >= '0' && date_of_birth[0] <= '9' && date_of_birth[1] >= '0' && date_of_birth[1] <= '9' && date_of_birth[3] >= '0' && date_of_birth[3] <= '9' && date_of_birth[4] >= '0' && date_of_birth[4] <= '9' && date_of_birth[6] >= '0' && date_of_birth[6] <= '9' && date_of_birth[7] >= '0' && date_of_birth[7] <= '9' && date_of_birth[8] >= '0' && date_of_birth[8] <= '9' && date_of_birth[9] >= '0' && date_of_birth[9] <= '9')
        {
            if (check_valid_date(date_of_birth, 1))
                break;
            else
                std::cout << "Invalid date. Try again." << std::endl;
        }
        else
        {
            std::cout << "Wrong date of birth format" << std::endl;
        }
    }
    std::string passport_number;
    while (true)
    {
        std::cout << "Enter your passport number: ";
        getline(std::cin, passport_number);
        if (passport_number.size() > 0 && check_passport_number(passport_number) == false)
        {
            break;
        }
        else
        {
            std::cout << "Passport number should have at least 1 symbol or it is already in the system. Try again." << std::endl;
        }
    }
    std::string sex;
    while (true)
    {
        std::cout << "Enter your sex(F/M): ";
        getline(std::cin, sex);
        if (sex.size() == 1 && (sex[0] == 'F' || sex[0] == 'M' || sex[0] == 'f' || sex[0] == 'm'))
        {
            if (sex[0] == 'f' || sex[0] == 'm')
            {
                sex[0] = (sex[0] - 'a') + 'A';
            }
            break;
        }
        else
            std::cout << "Wrong input, try again." << std::endl;
    }
    std::string nationality;

    while (true)
    {
        std::cout << "Enter your nationality: ";
        getline(std::cin, nationality);
        if (nationality.size() > 0)
        {
            break;
        }
        else
        {
            std::cout << "Nationality should have at least 1 symbol. Try again." << std::endl;
        }
    }
    int id = get_accounts_size() + 1;
    User_account user(this, login, password, name, surname, sex[0], date_of_birth, passport_number, nationality);

    accounts.push_back(user);
}
int Embassy::optimal_account_id()
{
    int optimal_id = 0;
    std::list<User_account>::iterator it = accounts.begin();
    for (int i = 0; i < accounts.size(); it++, i++)
    {
        if (it->get_id() > optimal_id)
        {
            optimal_id = it->get_id();
        }
    }
    return optimal_id + 1;
}
int Embassy::optimal_application_id()
{
    int optimal_id = 0;
    std::list<Application>::iterator it = applications.begin();
    for (int i = 0; i < applications.size(); it++, i++)
    {
        if (it->get_application_id() > optimal_id)
        {
            optimal_id = it->get_application_id();
        }
    }
    return optimal_id + 1;
}
int Embassy::optimal_appointment_id()
{
    std::list<Appointment>::iterator it = appointments.begin();
    int optimal_id = 0;
    for (int i = 0; i < appointments.size(); it++, i++)
    {
        if (it->get_id() > optimal_id)
        {
            optimal_id = it->get_id();
        }
    }
    return optimal_id + 1;
}
bool Embassy::check_presence_of_application_by_account_id(int required_account_id)
{
    std::list<Application>::iterator it = applications.begin();
    for (int i = 0; i < applications.size(); it++, i++)
    {
        if (it->get_account_id() == required_account_id)
        {
            return true;
        }
    }
    return false;
}
int Embassy::display_admin_menu()
{
    std::string temp;
    std::cout << "Admin menu || What do you want to do?" << std::endl;
    std::cout << "1. Show all pending applications. " << std::endl;
    std::cout << "2. Show all current appointments. " << std::endl;
    std::cout << "3. Show all current accounts. " << std::endl;
    std::cout << "4. Change status of applications. " << std::endl;
    std::cout << "5. Delete a user. " << std::endl;
    std::cout << "6. Show applications with decisions. " << std::endl;
    std::cout << "7. Back. " << std::endl;
    bool flag = false;
    int choice = -1;
    while (choice < 1 || choice > 7)
    {
        std::cout << "Enter your choice: ";
        getline(std::cin, temp);
        if (temp[0] >= '0' && temp[0] <= '9')
        {
            choice = std::stoi(temp);
        }
        if (choice < 1 || choice > 7)
        {
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    }
    return choice;
}
void Embassy::show_all_pending_applications()
{
    int counter = 0;
    std::list<Application>::iterator it = applications.begin();

    for (int i = 0; i < applications.size(); it++, i++)
    {
        if (it->get_status() == 0)
        {
            it->amdin_display_application();
            counter++;
        }
    }
    if (counter == 0)
    {
        std::cout << "There are no pending applications." << std::endl;
    }
}
void Embassy::show_all_pending_appointments()
{
    std::list<Appointment>::iterator it = appointments.begin();
    if (appointments.size() == 0)
    {
        std::cout << "There are no appointments." << std::endl;
    }
    else
    {
        for (int i = 0; i < appointments.size(); it++, i++)
        {
            it->admin_display_appointment();
        }
    }
}
void Embassy::display_all_accounts()
{
    std::list<User_account>::iterator it = accounts.begin();
    if (accounts.size() == 0)
    {
        std::cout << "There are no accounts." << std::endl;
    }
    else
    {
        for (int i = 0; i < accounts.size(); it++, i++)
        {
            it->admin_display_account();
        }
    }
}
void Embassy::show_applications_with_decisions()
{
    std::list<Application>::iterator it = applications.begin();
    int counter = 0;
    for (int i = 0; i < applications.size(); it++, i++)
    {
        if (it->get_status() != 0)
        {
            it->amdin_display_application();
            counter++;
        }
    }
    if (counter == 0)
    {
        std::cout << "There are no applications with decisions." << std::endl;
    }
}
void Embassy::change_status_of_applications()
{
    std::list<Application>::iterator it = applications.begin();
    int counter = 0;
    std::string temp;
    bool flag = false;
    int choice = -1;
    for (int i = 0; i < accounts.size(); it++, i++)
    {
        if (it->get_status() == 0)
        {
            counter++;
        }
    }
    if (counter == 0)
    {
        std::cout << "There are no applications without a decision made." << std::endl;
    }
    else
    {
        it = applications.begin();
        for (int i = 0; i < applications.size(); it++, i++)
        {
            choice = -1;
            while (choice == -1)
            {
                if (it->get_status() == 0)
                {
                    it->amdin_display_application();
                }
                else
                    break;
                std::cout << "What do you want to do with this application?" << std::endl;
                std::cout << "1. Accept. " << std::endl;
                std::cout << "2. Reject. " << std::endl;
                std::cout << "3. Skip. " << std::endl;
                std::cout << "4. Choose application by id. " << std::endl;
                std::cout << "5. Back. " << std::endl;
                getline(std::cin, temp);

                if (temp[0] >= '0' && temp[0] <= '9')
                {
                    choice = std::stoi(temp);
                }
                if (choice < 1 || choice > 5)
                {
                    std::cout << "Invalid choice. Try again." << std::endl;
                    choice = -1;
                }
            }
            if (choice == 1)
            {
                int *indexes = new int;
                int counter = 0;
                std::list<Appointment>::iterator it2 = appointments.begin();
                for (int j = 0; j < appointments.size(); it2++, j++)
                {
                    if (it2->get_application_id() == it->get_application_id())
                    {
                        indexes[counter] = j;
                        counter++;
                    }
                }
                for (int j = 0; j < counter; j++)
                {
                    execute_delete_appointment(indexes[j]);
                }
                it->set_status(1);
                delete[] indexes;
                std::cout << "Application accepted." << std::endl;
            }
            else if (choice == 2)
            {
                int *indexes = new int;
                int counter = 0;
                std::list<Appointment>::iterator it2 = appointments.begin();
                for (int j = 0; j < appointments.size(); it2++, j++)
                {
                    if (it2->get_application_id() == it->get_application_id())
                    {
                        indexes[counter] = j;
                        counter++;
                    }
                }
                for (int j = 0; j < counter; j++)
                {
                    execute_delete_appointment(indexes[j]);
                }
                delete[] indexes;
                it->set_status(-1);
                std::cout << "Application rejected." << std::endl;
            }
            else if (choice == 3)
            {
                std::cout << "Application skipped." << std::endl;
            }
            else if (choice == 4)
            {
                std::cout << "Enter application id: ";
                getline(std::cin, temp);
                int id = -1;
                if (temp[0] >= '0' && temp[0] <= '9')
                {
                    id = std::stoi(temp);
                }
                std::list<Application>::iterator it2 = applications.begin();
                flag = false;
                for (int j = 0; j < applications.size(); it2++, j++)
                {
                    if (it2->get_application_id() == id)
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag == false)
                {
                    std::cout << "Application not found." << std::endl;
                    continue;
                }
                else
                {
                    choice = -1;
                    it2->amdin_display_application();
                    std::cout << "What do you want to do with this application?" << std::endl;
                    std::cout << "1. Accept. " << std::endl;
                    std::cout << "2. Reject. " << std::endl;
                    std::cout << "3. Skip. " << std::endl;
                    std::cout << "4. Back. " << std::endl;
                    getline(std::cin, temp);
                    if (temp[0] >= '0' && temp[0] <= '9')
                    {
                        choice = std::stoi(temp);
                    }
                    if (choice < 1 || choice > 4)
                    {
                        std::cout << "Invalid choice. Try again." << std::endl;
                        choice = -1;
                    }
                    std::list<Appointment>::iterator it3 = appointments.begin();
                    int *indexes = new int;
                    int counter = 0;
                    switch (choice)
                    {
                    case 1:
                        for (int j = 0; j < appointments.size(); it3++, j++)
                        {
                            if (it3->get_application_id() == it2->get_application_id())
                            {
                                indexes[counter] = it3->get_id();
                                counter++;
                            }
                        }
                        for (int j = 0; j < counter; j++)
                        {
                            execute_delete_appointment(indexes[j]);
                        }
                        it->set_status(1);
                        std::cout << "Application accepted." << std::endl;
                        break;
                    case 2:
                        for (int j = 0; j < appointments.size(); it3++, j++)
                        {
                            if (it3->get_application_id() == it2->get_application_id())
                            {
                                indexes[counter] = it3->get_id();
                                counter++;
                            }
                        }
                        for (int j = 0; j < counter; j++)
                        {
                            execute_delete_appointment(indexes[j]);
                        }
                        it->set_status(-1);
                        std::cout << "Application rejected." << std::endl;
                        break;
                    case 3:
                        std::cout << "Application skipped." << std::endl;
                        break;
                    case 4:
                        break;
                    }
                    delete[] indexes;
                }
            }
            else if (choice == 5)
            {
                break;
            }
        }
    }
}
void Embassy::delete_user()
{
    if (accounts.size() == 0)
    {
        std::cout << "There are no accounts." << std::endl;
        return;
    }
    std::list<User_account>::iterator it = accounts.begin();
    int choice = -1;
    std::string temp;
    while (choice == -1)
    {
        display_acconts_ids();
        std::cout << "Enter the id of the user you want to delete: ";
        getline(std::cin, temp);
        if (temp[0] >= '0' && temp[0] <= '9')
        {
            choice = std::stoi(temp);
            break;
        }
    }
    execute_delete_user_account(choice);
}
void Embassy::display_acconts_ids()
{
    std::cout << "Accounts ids: " << std::endl;
    std::list<User_account>::iterator it = accounts.begin();
    if (accounts.size() == 0)
    {
        std::cout << "There are no accounts." << std::endl;
    }
    else
    {
        for (int i = 0; i < accounts.size(); it++, i++)
        {
            std::cout << it->get_id() << " ";
        }
    }
    std::cout << std::endl;
}

bool Embassy::execute_delete_appointment(int id)
{
    bool exists = false;
    int application_id_to_check = -1;
    int user_id_to_check = -1;
    std::list<Appointment>::iterator app = appointments.begin();
    for (int i = 0; i < appointments.size(); app++, i++)
    {
        if (app->get_id() == id)
        {
            exists = true;
            break;
        }
    }
    if (exists == false)
    {
        return false;
    }
    else
    {
        application_id_to_check = app->get_application_id();
    }
    std::list<Application>::iterator appl = applications.begin();
    for (int i = 0; i < applications.size(); appl++, i++)
    {
        if (appl->get_application_id() == application_id_to_check)
        {
            user_id_to_check = appl->get_account_id();
            appl->erase_pointers_after_appointment_deleting(id);
            break;
        }
    }
    std::list<User_account>::iterator user = accounts.begin();
    for (int i = 0; i < accounts.size(); user++, i++)
    {
        if (user->get_id() == user_id_to_check)
        {
            user->erase_pointers_after_appointment_deleting(id);
            break;
        }
    }
    app = appointments.begin();
    for (int i = 0; i < appointments.size(); app++, i++)
    {
        if (app->get_id() == id)
        {
            appointments.erase(app);
            break;
        }
    }
    return true;
}
bool Embassy::execute_delete_application(int id)
{
    bool exists = false;
    int user_id_to_check = -1;
    std::list<Application>::iterator app = applications.begin();
    for (int i = 0; i < applications.size(); app++, i++)
    {
        if (app->get_application_id() == id)
        {
            exists = true;
            break;
        }
    }
    if (exists == false)
    {
        return false;
    }
    else
    {
        user_id_to_check = app->get_account_id();
    }
    bool flag = false;
    std::list<Appointment>::iterator Appoint_it = appointments.begin();
    for (int i = 0; i < appointments.size(); Appoint_it++, i++)
    {
        if (flag == true)
        {
            i = 0;
            Appoint_it = appointments.begin();
        }
        flag = false;
        if (Appoint_it->get_application_id() == id)
        {
            execute_delete_appointment(Appoint_it->get_id());
            flag = true;
            i = -1;
        }
    }
    std::list<User_account>::iterator user = accounts.begin();
    for (int i = 0; i < accounts.size(); user++, i++)
    {
        if (user->get_id() == user_id_to_check)
        {
            user->erase_pointers_after_application_deleting(id);
            break;
        }
    }
    app = applications.begin();
    for (int i = 0; i < applications.size(); app++, i++)
    {
        if (app->get_application_id() == id)
        {
            applications.erase(app);
            break;
        }
    }
    return true;
}
bool Embassy::execute_delete_user_account(int id)
{
    bool exists = false;
    std::list<User_account>::iterator user = accounts.begin();
    for (int i = 0; i < accounts.size(); user++, i++)
    {
        if (user->get_id() == id)
        {
            exists = true;
            break;
        }
    }
    if (exists == false)
    {
        return false;
    }
    bool flag = false;
    std::list<Application>::iterator appl = applications.begin();

    for (int i = 0; i < applications.size(); appl++, i++)
    {
        if (flag == true)
        {
            i = 0;
            appl = applications.begin();
        }
        flag = false;
        if (appl->get_account_id() == id)
        {
            execute_delete_application(appl->get_application_id());
            flag = true;
            i = -1;
        }
    }
    user = accounts.begin();
    for (int i = 0; i < accounts.size(); user++, i++)
    {
        if (user->get_id() == id)
        {
            accounts.erase(user);
            break;
        }
    }
    return true;
}
bool Embassy::check_valid_date(std::string date, int type)
{
    const time_t t = time(NULL);
    std::tm *now = std::localtime(&t);
    int day = -1;
    int month = -1;
    int year = -1;
    day = std::stoi(date.substr(0, 2));
    month = std::stoi(date.substr(3, 2));
    year = std::stoi(date.substr(6, 4));
    if (day < 1 || day > 31)
    {
        return false;
    }
    if (month < 1 || month > 12)
    {
        return false;
    }
    if (year < 1)
    {
        return false;
    }
    switch (month)
    {
    case 1:
        if (day > 31)
        {
            return false;
        }
        break;
    case 2:
        if (year % 4 == 0)
        {
            if (year % 100 == 0 && year % 400 == 0)
            {
                if (day > 28)
                {
                    return false;
                }
            }
            else
            {
                if (day > 29)
                {
                    return false;
                }
            }
        }
        else
        {
            if (day > 28)
            {
                return false;
            }
        }
        break;
    case 3:
        if (day > 31)
        {
            return false;
        }
        break;
    case 4:
        if (day > 30)
        {
            return false;
        }
        break;
    case 5:
        if (day > 31)
        {
            return false;
        }
        break;
    case 6:
        if (day > 30)
        {
            return false;
        }
        break;
    case 7:
        if (day > 31)
        {
            return false;
        }
        break;
    case 8:
        if (day > 31)
        {
            return false;
        }
        break;
    case 9:
        if (day > 30)
        {
            return false;
        }
        break;
    case 10:
        if (day > 31)
        {
            return false;
        }
        break;
    case 11:
        if (day > 30)
        {
            return false;
        }
        break;
    case 12:
        if (day > 31)
        {
            return false;
        }
        break;
    }
    if (type == 1)
    {
        if (year < 1900 || year > (now->tm_year + 1900))
        {
            return false;
        }
        if (year == (now->tm_year + 1900))
        {
            if (month > (now->tm_mon + 1))
            {
                return false;
            }
            else if (month == (now->tm_mon + 1))
            {
                if (day > now->tm_mday)
                {
                    return false;
                }
            }
        }
    }
    else if (type == 2)
    {
        if (year < (now->tm_year + 1900))
        {
            return false;
        }
        if (year == (now->tm_year + 1900))
        {
            if (month < (now->tm_mon + 1))
            {
                return false;
            }
            else if (month == (now->tm_mon + 1))
            {
                if (day <= now->tm_mday)
                {
                    return false;
                }
            }
        }
    }
    return true;
}
