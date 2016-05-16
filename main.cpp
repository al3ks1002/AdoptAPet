#include <iostream>
#include "Tests.h"
#include "RepositoryAdmin.h"
#include "ControllerAdmin.h"
#include "UI.h"

int main() {
    Tests::run_tests();

    std::cout << "---Adoption list storage---\n";
    std::cout << "1. CSV file.\n";
    std::cout << "2. HTML file.\n";
    int command = UI::read_integer("Choose one option: ", 1, 2);

    AdoptionList* adoption_list;
    if (command == 1) {
        adoption_list = new CSVAdoptionList("/home/alex/ClionProjects/AdoptAPet/csv.txt");
    } else {
        adoption_list = new HTMLAdoptionList("/home/alex/ClionProjects/AdoptAPet/html.htm");
    }

    RepositoryAdmin my_repo_admin("/home/alex/ClionProjects/AdoptAPet/input.txt");
    RepositoryUser my_repo_user(adoption_list);

    ControllerAdmin my_ctrl_admin(my_repo_admin);
    ControllerUser my_ctrl_user(my_repo_admin, my_repo_user);
    UI my_UI(my_ctrl_admin, my_ctrl_user);

    my_UI.run_UI();
    return 0;
}