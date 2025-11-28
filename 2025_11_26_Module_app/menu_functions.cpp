#include "menu_functions.hpp"

#include <cstdlib>
#include <iostream>

const NovSev::MenuItem* NovSev::show_menu(const MenuItem* current) {
    std::cout << "Привет, это обучайка!" << std::endl;
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

const NovSev::MenuItem* NovSev::exit(const MenuItem* current) {
    std::exit(0);
}

const NovSev::MenuItem* NovSev::study_go_back(const MenuItem* current) {
    //TODO
    return current->parent->parent;
}

const NovSev::MenuItem* NovSev::study_algebra_summ(const MenuItem* current) {
    //TODO
    std::cout << current->title << std::endl;
    std::cout << std::endl;
    return current->parent;
}

const NovSev::MenuItem* NovSev::study_algebra_substract(const MenuItem* current) {
    //TODO
    std::cout << current->title << std::endl;
    std::cout << std::endl;
    return current->parent;
}

const NovSev::MenuItem* NovSev::study_algebra_multiply(const MenuItem* current) {
    //TODO
    std::cout << current->title << std::endl;
    std::cout << std::endl;
    return current->parent;
}

const NovSev::MenuItem* NovSev::study_algebra_devide(const MenuItem* current) {
    //TODO
    std::cout << current->title << std::endl;
    std::cout << std::endl;
    return current->parent;
}

const NovSev::MenuItem* NovSev::study_calculus_diff(const MenuItem* current) {
    //TODO
    std::cout << current->title << std::endl;
    std::cout << std::endl;
    return current->parent;
}

const NovSev::MenuItem* NovSev::study_calculus_integral(const MenuItem* current) {
    //TODO
    std::cout << current->title << std::endl;
    std::cout << std::endl;
    return current->parent;
}