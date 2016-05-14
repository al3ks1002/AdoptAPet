#include <iostream>
#include "Tests.h"
#include "RepositoryAdmin.h"
#include "ControllerAdmin.h"
#include "UI.h"

using namespace std;

int main() {
    Tests::run_tests();

    RepositoryAdmin my_repo_admin{};
    RepositoryUser my_repo_user{};

    Dog d1{4, "Pitbull", "Rex", "http://www.wlivenews.com/wp-content/uploads/2015/05/Pit-Bull-Dog-4.jpg"};
    Dog d2{4, "Husky", "Max", "http://elelur.com/data_images/dog-breeds/siberian-husky/siberian-husky-02.jpg"};
    Dog d3{1, "Husky", "Hachi", "https://s-media-cache-ak0.pinimg.com/736x/6f/07/ab/6f07ab1cdb7f3fc96abd58883af1a125.jpg"};
    Dog d4{1, "Shepherd", "Derek", "http://1.bp.blogspot.com/-N9wTCUXWl3E/UN10I6Y9gsI/AAAAAAAADaU/YZqIbWGz8d4/s1600/szkocki-owczarek-collie.jpeg"};
    Dog d5{3, "Pitbull", "Buddy", "http://hdwallpapersd.com/wp-content/uploads/2015/08/Brown-american-Pitbull-Dog-hd-Wallpapers-new-desktop-background-images-of-pitbull-dog-widescreen.jpg"};

    my_repo_admin.add(d1);
    my_repo_admin.add(d2);
    my_repo_admin.add(d3);
    my_repo_admin.add(d4);
    my_repo_admin.add(d5);

    ControllerAdmin my_ctrl_admin{my_repo_admin};
    ControllerUser my_ctrl_user{my_repo_admin, my_repo_user};
    UI my_UI{my_ctrl_admin, my_ctrl_user};

    my_UI.run_UI();

    return 0;
}