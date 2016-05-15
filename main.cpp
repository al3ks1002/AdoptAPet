#include <iostream>
#include <fstream>
#include "Tests.h"
#include "RepositoryAdmin.h"
#include "ControllerAdmin.h"
#include "UI.h"

int main() {
    Tests::run_tests();

    RepositoryAdmin my_repo_admin("/home/alex/ClionProjects/AdoptAPet/input.txt");
    RepositoryUser my_repo_user{};

    ControllerAdmin my_ctrl_admin{my_repo_admin};
    ControllerUser my_ctrl_user{my_repo_admin, my_repo_user};
    UI my_UI{my_ctrl_admin, my_ctrl_user};

    my_UI.run_UI();

    return 0;
}