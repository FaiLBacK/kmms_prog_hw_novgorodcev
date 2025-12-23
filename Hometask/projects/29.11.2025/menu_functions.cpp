#include "menu_functions.hpp"
#include <cstdlib>
#include <iostream>

namespace {
    const NovSev::MenuItem* show_menu(const NovSev::MenuItem* current) {
        for (int i = 1; i < current->children_count; i++) {
            std::cout << current->children[i]->title << std::endl;
        }
        std::cout << current->children[0]->title << std::endl;
        std::cout << "Обучайка > ";

        int user_input;
        std::cin >> user_input;
        std::cout << std::endl;

        return current->children[user_input];
    }
}

const NovSev::MenuItem* NovSev::show_main_menu(const NovSev::MenuItem* current) {
    std::cout << "Главное меню:" << std::endl;
    return show_menu(current);
}

const NovSev::MenuItem* NovSev::show_2lvl_menu(const NovSev::MenuItem* current) {
    std::cout << "Второй уровень меню:" << std::endl;
    return show_menu(current);
}

const NovSev::MenuItem* NovSev::show_3lvl_menu(const NovSev::MenuItem* current) {
    std::cout << "Третий уровень меню:" << std::endl;
    return show_menu(current);
}

const NovSev::MenuItem* NovSev::exit(const NovSev::MenuItem* current) {
    std::exit(0);
    return nullptr;
}

const NovSev::MenuItem* NovSev::Play_football(const NovSev::MenuItem* current) {
    std::cout << "" << std::endl;
    std::cout << std::endl;
    return current->parent;
}

const NovSev::MenuItem* NovSev::Enter_main_menu(const NovSev::MenuItem* current) {
    return current->parent->parent;
}

const NovSev::MenuItem* NovSev::Learning_programming(const NovSev::MenuItem* current) {
    std::cout << current->title << std::endl;
    std::cout << "" << std::endl;
    std::cout << std::endl;
    return current->parent;
}

const NovSev::MenuItem* NovSev::Learning_languages_of_programming(const NovSev::MenuItem* current) {
    std::cout << current->title << std::endl;
    std::cout << "" << std::endl;
    std::cout << std::endl;
    return current->parent;
}

const NovSev::MenuItem* NovSev::Alhoritms_and_structs(const NovSev::MenuItem* current) {
    std::cout << current->title << std::endl;
    std::cout << "" << std::endl;
    std::cout << std::endl;
    return current->parent;
}

const NovSev::MenuItem* NovSev::Other_technologies(const NovSev::MenuItem* current) {
    return NovSev::show_3lvl_menu(current);
}

const NovSev::MenuItem* NovSev::Bases_of_data(const NovSev::MenuItem* current) {
    std::cout << current->title << std::endl;
    std::cout << "" << std::endl;
    std::cout << std::endl;
    return current->parent;
}

const NovSev::MenuItem* NovSev::Multithreaded_programming(const NovSev::MenuItem* current) {
    std::cout << current->title << std::endl;
    std::cout << "" << std::endl;
    std::cout << std::endl;
    return current->parent;
}

const NovSev::MenuItem* NovSev::Network_technologies(const NovSev::MenuItem* current) {
    std::cout << current->title << std::endl;
    std::cout << "" << std::endl;
    std::cout << std::endl;
    return current->parent;
}