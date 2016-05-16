//
// Created by alex on 22.03.2016.
//

#ifndef ADOPTAPET_UI_H
#define ADOPTAPET_UI_H


#include "ControllerAdmin.h"
#include "ControllerUser.h"

class UI {
public:
    UI(const ControllerAdmin& ctrl_admin, const ControllerUser& ctrl_user) : controller_admin(ctrl_admin),
                                                                             controller_user(ctrl_user) { };

    void run_UI();

    static int read_integer(const std::string& message, int min_value, int max_value);

    static std::string read_nonempty_string(const std::string& message);

    static std::string read_string(const std::string& message);

private:
    ControllerAdmin controller_admin;
    ControllerUser controller_user;

    static void print_menu();

    static void print_admin_menu();

    static void print_user_menu();

    static void print_playlist_menu();

    void run_admin();

    void run_user();

    void add();

    void remove();

    void update();

    void show_all();

    void see_all();

    void see_filtered();

    void show_adopted();

    void run_playlist();
};


#endif //ADOPTAPET_UI_H

