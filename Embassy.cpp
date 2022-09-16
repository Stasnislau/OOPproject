#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <ctime>
#include "classes.hpp"
#include "cl_application.cpp"
#include "cl_appointment.cpp"
#include "cl_embassy.cpp"
#include "cl_user_account.cpp"
int main()
{
    bool exit = false;
    Embassy embassy;
    int menu_choice;
    int index = -1;
    while (menu_choice != 3)
    {
        menu_choice = 0;
        menu_choice = embassy.display_initial_menu();
        switch (menu_choice)
        {
        case 1:

            while (menu_choice != 3)
            {
                menu_choice = 0;
                menu_choice = embassy.display_user_first_menu();
                switch (menu_choice)
                {
                case 1:
                    index = -1;
                    index = embassy.logging_in();
                    if (index != -1)
                    {

                        while (menu_choice != 7)
                        {
                            menu_choice = 0;
                            menu_choice = embassy.get_account(index).display_user_second_menu();
                            switch (menu_choice)
                            {
                            case 1:
                                embassy.get_account(index).create_application(&embassy);
                                break;
                            case 2:
                                embassy.get_account(index).display_current_applications();
                                break;
                            case 3:
                                embassy.get_account(index).delete_application(&embassy); 
                                break;
                            case 4:
                                embassy.get_account(index).create_appointment(&embassy);
                                break;
                            case 5:
                                embassy.get_account(index).display_current_appointments();
                                break;
                            case 6:
                                embassy.get_account(index).delete_appointment(&embassy);
                                break;
                            case 7:
                                break;
                            }
                        }
                        menu_choice = 0;
                    }
                    break;
                case 2:
                    embassy.add_user();
                case 3:
                    break;
                }
            }
            menu_choice = 0;
            break;
        case 2:
            while (menu_choice != 7)
            {
                menu_choice = 0;
                menu_choice = embassy.display_admin_menu();
                switch (menu_choice)
                {
                case 1:
                    embassy.show_all_pending_applications();
                    break;
                case 2:
                    embassy.show_all_pending_appointments();
                    break;
                case 3:
                    embassy.display_all_accounts();
                    break;
                case 4:

                    embassy.change_status_of_applications();
                    break;
                case 5:
                    embassy.delete_user();
                    break;
                case 6:
                    embassy.show_applications_with_decisions();
                    break;
                case 7:
                    break;
                }
            }

        case 3:
            break;
        }
    }
    return 0;
}
