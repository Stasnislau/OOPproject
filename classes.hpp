#ifndef MIGRATIONSERVICE
#define MIGRATIONSERVICE
// m_ stands for member of the class
class Application;
class Appointment;
class User_account
{
    int m_id;                      // unique id of the user account
    char m_sex;                    // sex of the applicant
    std::string m_login;           // login of a user
    std::string m_password;        // password of a user
    std::string m_name;            // name, which is gonna be used by appointments and applications
    std::string m_surname;         // same as name, but for surname
    std::string m_date_of_birth;   // date of birth, gonna be used by appointments and applications
    std::string m_passport_number; // passport number, gonna be used by appointments and applications, should be unique
    std::string m_nationality;     // nationality of the applicant

    std::vector<Application *> account_applications; // vector of applications, created by this user
    std::vector<Appointment *> account_appointments; // vector of appointments, created by this user

public:
    User_account(class Embassy *embassy, std::string login, std::string password, std::string name, std::string surname, char sex, std::string date_of_birth, std::string passport_number, std::string nationality); // constructor
    User_account();                                                                                                                                                                                                  // default constructor
    std::string get_login();                                                                                                                                                                                         // returns login of a user
    std::string get_password();                                                                                                                                                                                      // returns password of a user
    int get_id();                                                                                                                                                                                                    // returns id of a user
    std::string *get_name();                                                                                                                                                                                         // returns name of a user
    std::string *get_surname();                                                                                                                                                                                      // returns surname of a user
    std::string *get_passport_number();                                                                                                                                                                              // returns passport number of a user
    std::string *get_date_of_birth();                                                                                                                                                                                // returns date of birth of a user
    std::string *get_nationality();
    char get_sex();
    int get_account_applications_size();
    Application *get_account_application(int index);

    int display_application_ids();
    void create_application(class Embassy *embassy); // creates application for a user
    void delete_application(class Embassy *embassy); // deletes application for a user
    void display_current_applications();             // displays all applications of a user
    void create_appointment(class Embassy *embassy); // creates appointment for a user
    void delete_appointment(class Embassy *embassy); // deletes appointment for a user
    void display_current_appointments();             // displays all appointments of a user
    int display_user_second_menu();                  // displays menu of choices for a user and returns their choice
    void display_current_applications_ids();         // displays all ids of applications of a user
    void admin_display_account();                    // displays all information about a user

    void erase_pointers_after_application_deleting(int id_of_application);
    void erase_pointers_after_appointment_deleting(int id_of_appointment);
    void erase_pointers_after_account_deleting();
};
class Appointment
{
    std::string m_date;             // date of the appointment
    std::string m_time;             // time of the appointment
    std::string *m_name;            // name of the applicant
    std::string *m_surname;         // surname of the applicant
    std::string *m_date_of_birth;   // date of birth of the applicant
    std::string *m_passport_number; // passport number of the applicant

    int m_id_of_appointment; // id of the appointment
    int m_application_id;    // id of the application, which is related to the appointment

public:
    Appointment();                                                                                                 // default constructor
    Appointment(class Embassy *embassy, class User_account *accountm, int id, std::string date, std::string time); // constructor

    std::string get_date();             // returns date of the appointment
    std::string get_time();             // returns time of the appointment
    std::string *get_name();            // returns name of the applicant
    std::string *get_surname();         // returns surname of the applicant
    std::string *get_date_of_birth();   // returns date of birth of the applicant
    std::string *get_passport_number(); // returns passport number of the applicant

    int get_id();             // returns id of the appointment
    int get_application_id(); // returns id of the application, which is related to the appointment

    void admin_display_appointment(); // displays appointment in a format, which is suitable for admin
};
class Application
{
    int m_account_id;     // id of the user, who is related to the application
    int m_application_id; // unique id of the application
    int m_status;         // 0 if is being processed, 1 if approved, -1 if rejected;
    int m_type;           // 0 -visa, 1 - TRP, 2 - refugee

    std::string *m_name;            // name of the applicant
    std::string *m_surname;         // surname of the applicant
    std::string *m_date_of_birth;   // date of birth of the applicant
    char m_sex;                     // F or M of the applicant
    std::string *m_nationality;     // nationality of the applicant
    std::string *m_passport_number; // passport number of the applicant

    std::vector<Appointment *> application_appointments; // vector of appointments connected with this application

public:
    Application();                                                              // default constructor
    Application(class Embassy *embassy, class User_account *account, int type); // constructor

    int get_application_id();           // return id of the application
    int get_account_id();               // return id of the account connected to this application
    int get_status();                   // return status of the application
    void set_status(int status);        // set status of the application
    int get_type();                     // returns type of the application
    std::string *get_name();            // returns name of the applicant
    std::string *get_surname();         // returns surname of the applicant
    std::string *get_date_of_birth();   // returns date of birth of the applicant
    char get_sex();                     // returns sex of the applicant
    std::string *get_nationality();     // returns nationality of the applicant
    std::string *get_passport_number(); // returns passport number of the applicant

    void creat_application();                                             // creates an application
    friend void User_account::create_appointment(class Embassy *embassy); // creates appointment for a user
    void amdin_display_application();                                     // displays application in a format, which is suitable for admin
    int erase_pointers_after_appointment_deleting(int id_of_appointment); // deletes appointment from the vector of appointments, if id = -1, deletes all
    int erase_pointers_after_application_deleting();                      // deletes application from the vector of applications
};
class Embassy
{
    std::list<User_account> accounts;    // list of all accounts
    std::list<Appointment> appointments; // list of all appointments
    std::list<Application> applications; // list of all applications

public:
    Embassy(); // constructor

    User_account &get_account(int index); // returns account with given index
    int get_accounts_size();              // returns size of the accounts list
    int get_applications_size();          // returns size of the applications list

    // displays initial menu and returns choice of the user
    int display_initial_menu();
    // displays next menu of choices for a user and returns their choice
    int display_user_first_menu();

    // adds user to the accounts list
    void add_user();
    // deletes user from the accounts list
    void delete_user();

    // logs in a user and returns id of the user
    int logging_in();
    // checks if login is unique
    bool check_login(std::string login);
    // checks if passport number is unique
    bool check_passport_number(std::string passport_number);

    // returns id of the account, which is optimal for the application
    int optimal_account_id();
    // returns id of the application, which is optimal for the appointment
    int optimal_application_id();
    // returns id of the appointment, which is optimal for the application
    int optimal_appointment_id();
    // checks if there is an application for a user with given id
    bool check_presence_of_application_by_account_id(int required_account_id);
    // displays menu of choices for an admin and returns their choice
    int display_admin_menu();
    // displays all pending applications
    void show_all_pending_applications();
    // displays all pending appointments
    void show_all_pending_appointments();
    // displays all applications which are not pending anymore and have a decision
    void show_applications_with_decisions();

    // displays all accounts
    void display_all_accounts();
    // displays all ids of accounts
    void display_acconts_ids();
    // changes status of applications
    void change_status_of_applications();
    // changes status of appointments by id
    void change_status_of_appointments_by_id();
    friend void User_account::create_application(class Embassy *embassy);
    friend void User_account::create_appointment(class Embassy *embassy);

    // deletes appointment with given id
    bool execute_delete_appointment(int id);
    // deletes application with given id
    bool execute_delete_application(int id);
    // deletes user with given id
    bool execute_delete_user_account(int id);
    // checks if date is valid, type 1 - date of birth, type 2 - date of appointment
    bool check_valid_date(std::string date, int type);
};
#endif