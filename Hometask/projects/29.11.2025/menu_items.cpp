#include <cstddef>
#include "menu_items.hpp"
#include "menu_functions.hpp"

namespace NovSev {

namespace {
    const NovSev::MenuItem* study_programming_children[] = {
        &NovSev::ENTER_MAIN_MENU_PROG,      
        &NovSev::LEARNING_LANGUAGES_OF_PROGRAMING, 
        &NovSev::ALHORITMS_AND_STRUCTS,      
        &NovSev::OTHER_TECHNOLOGIES,        
    };
    const int study_programming_size = sizeof(study_programming_children) / sizeof(study_programming_children[0]);

    const NovSev::MenuItem* other_technologies_children[] = {
        &NovSev::ENTER_MAIN_MENU_TECH,      
        &NovSev::BASES_OF_DATA,             
        &NovSev::MULTITHREADED_PROGRAMING,  
        &NovSev::NETWORK_TECHNOLOGIES,     
    };
    const int other_technologies_children_size = sizeof(other_technologies_children) / sizeof(other_technologies_children[0]);

    const NovSev::MenuItem* main_children[] = {
        &NovSev::PLAY_FOOTBALL,             
        &NovSev::LEARNING_OF_PROGRAMING,    
    };
    const int main_children_size = sizeof(main_children) / sizeof(main_children[0]);
}

const MenuItem ALHORITMS_AND_STRUCTS = {
    "2 - Алгоритмы и структуры",  
    NovSev::Alhoritms_and_structs, 
    &NovSev::LEARNING_OF_PROGRAMING,
    nullptr,
    0
};

const MenuItem LEARNING_LANGUAGES_OF_PROGRAMING = {
    "1 - Изучать языки программирования",  
    NovSev::Learning_languages_of_programming, 
    &NovSev::LEARNING_OF_PROGRAMING,
    nullptr,
    0
};

const MenuItem OTHER_TECHNOLOGIES = {
    "3 - Другие технологии", 
    NovSev::show_3lvl_menu,
    &NovSev::LEARNING_OF_PROGRAMING,
    other_technologies_children,
    other_technologies_children_size
};

const MenuItem ENTER_MAIN_MENU_PROG = {
    "0 - Выйти в главное меню", 
    NovSev::Enter_main_menu, 
    &NovSev::LEARNING_OF_PROGRAMING,
    nullptr,
    0
};

const MenuItem BASES_OF_DATA = {
    "1 - Базы данных", 
    NovSev::Bases_of_data, 
    &NovSev::OTHER_TECHNOLOGIES,
    nullptr,
    0
};

const MenuItem MULTITHREADED_PROGRAMING = {
    "2 - Многопоточное программирование", 
    NovSev::Multithreaded_programming, 
    &NovSev::OTHER_TECHNOLOGIES,
    nullptr,
    0
};

const MenuItem NETWORK_TECHNOLOGIES = {
    "3 - Сетевые технологии",  
    NovSev::Network_technologies, 
    &NovSev::OTHER_TECHNOLOGIES,
    nullptr,
    0
};

const MenuItem ENTER_MAIN_MENU_TECH = {
    "0 - Выйти в предыдущее меню",  
    NovSev::Enter_main_menu, 
    &NovSev::OTHER_TECHNOLOGIES,
    nullptr,
    0
};

const MenuItem LEARNING_OF_PROGRAMING = {
    "1 - Изучать программирование", 
    NovSev::show_2lvl_menu,  
    &NovSev::MAIN, 
    study_programming_children, 
    study_programming_size
};

const MenuItem PLAY_FOOTBALL = {
    "0 - Пойти играть в футбол", 
    NovSev::Play_football, 
    &NovSev::MAIN,
    nullptr,
    0
};

const MenuItem MAIN = {
    "Главное меню",  
    NovSev::show_main_menu,  
    nullptr, 
    main_children, 
    main_children_size
};

}