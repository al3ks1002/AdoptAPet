//
// Created by alex on 16.05.2016.
//

#include <iostream>
#include <fstream>
#include "AdoptionList.h"

void AdoptionList::add(const Dog& dog) {
    this->dogs.push_back(dog);
    this->write_to_file();
}

std::vector<Dog> AdoptionList::get_dogs() {
    return this->dogs;
}


void CSVAdoptionList::show_adopted() {
    std::string shell = "gedit ";
    shell += this->filename;
    shell += " > /dev/null";
    system(shell.c_str());
}

void CSVAdoptionList::write_to_file() {
    std::ofstream fout(this->filename);

    for (Dog dog: dogs) {
        fout << dog.get_breed() << "," << dog.get_name() << "," << dog.get_age() << "," << dog.get_photo() << '\n';
    }

    fout.close();
}


void HTMLAdoptionList::show_adopted() {
    std::string shell = "google-chrome ";
    shell += this->filename;
    shell += " > /dev/null";
    system(shell.c_str());
}

void HTMLAdoptionList::write_to_file() {
    std::ofstream fout(this->filename);

    fout << "<!DOCTYPE html>\n";
    fout << "<html>" << "\n";
    fout << "<head>" << "\n";
    fout << "<title>Watchlist</title>" << "\n";
    fout << "</head>" << "\n";
    fout << "<body>" << "\n";
    fout << "<table border = 1>" << "\n";
    fout << "<tr>" << "\n";
    fout << "<td>Breed</td>" << "\n";
    fout << "<td>Name</td>" << "\n";
    fout << "<td>Age</td>" << "\n";
    fout << "<td>Photo</td>" << "\n";
    fout << "</tr>" << "\n";

    for (auto dog : this->dogs) {
        fout << "<tr>";
        fout << "<td>" << dog.get_breed() << "</td>" << "\n";
        fout << "<td>" << dog.get_name() << "</td>" << "\n";
        fout << "<td>" << dog.get_age() << "</td>" << "\n";
        fout << "<td><a href =" << dog.get_photo() << "> Photo</a></td>" << "\n";
        fout << "</tr>";
    }

    fout << "</table>" << "\n";
    fout << "</body>" << "\n";
    fout << "</html>" << "\n";

    fout.close();
}



