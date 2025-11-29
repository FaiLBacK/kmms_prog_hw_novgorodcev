#include "menu_functions.hpp"

#include <cstdlib>
#include <iostream>

const NovSev::MenuItem* NovSev::show_menu(const MenuItem* current) {
    std::cout << "Главное меню: " << std::endl;
    for (int i = 1; i < current->children_count; i++) {
        std::cout << current->children[i]->title << std::endl;
    }
    std::cout << current->children[0]->title << std::endl;
    std::cout << "";

    int user_input;
    std::cin >> user_input;
    std::cout << std::endl;

    return current->children[user_input];
}

const NovSev::MenuItem* NovSev::Play_football(const MenuItem* current) {
    std::play_footbal(0);
}

const NovSev::MenuItem* NovSev::Enter_main_menu(const MenuItem* current) {
    return current->parent->parent;
}

const NovSev::MenuItem* NovSev::Learning_programming(const MenuItem* current) {
    std::cout << current->title << std::endl;
    std::cout << std::endl;
    return current->parent;
}

const NovSev::MenuItem* NovSev::Learning_languages_of_programming(const MenuItem* current) {
    std::cout << current->title << std::endl;
    std::cout << std::endl;
    return current->parent;
}


const NovSev::MenuItem* NovSev::Alhoritms_and_structs(const MenuItem* current) {
    std::cout << current->title << std::endl;
    std::cout << std::endl;
    return current->parent;
}

const NovSev::MenuItem* NovSev::Other_technologies(const MenuItem* current) {
    std::cout << current->title << std::endl;
    std::cout << std::endl;
    return current->parent;
}

const NovSev::MenuItem* NovSev::Bases_of_data(const MenuItem* current) {
    std::cout << current->title << std::endl;
    std::cout << std::endl;
    return current->parent;
}

const NovSev::MenuItem* NovSev::Multithreaded_programming(const MenuItem* current) {
    std::cout << current->title << std::endl;
    std::cout << std::endl;
    return current->parent;
}

const NovSev::MenuItem* NovSev::Network_technologies(const MenuItem* current) {
    std::cout << current->title << std::endl;
    std::cout << std::endl;
    return current->parent;
}


