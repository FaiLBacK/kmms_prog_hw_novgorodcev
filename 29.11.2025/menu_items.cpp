#include "menu_items.hpp"

#include <cstddef>

#include "menu_functions.hpp"

const NovSev::MenuItem NovSev::ALHORITMS_AND_STRUCTS = {
    "1 - Алгоритмы и структуры", NovSev::Alhoritms_and_structs, &NovSev::LEARNING_PROGRAMING;
};

const NovSev::MenuItem NovSev::LEARNING_LANGUAGES_OF_PROGRAMING = {
    "2 - Изучать языки программирования", NovSev::Learning_languages_of_programming, &NovSev::LEARNING_PROGRAMING;
};

const NovSev::MenuItem NovSev::OTHER_TECHNOLOGIES = {
    "3 - Другие технологии", NovSev::Other_technologies, &NovSev::LEARNING_PROGRAMING;
};

const NovSev::MenuItem NovSev::ENTER_MAIN_MENU = {
    "0 - выйти в главное меню", NovSev::Enter_main_menu, &NovSev::LEARNING_PROGRAMING;
};

namespace {
    const NovSev::MenuItem* study_programming_children[] = {
		&NovSev::ALHORITMS_AND_STRUCTS,
		&NovSev::LEARNING_LANGUAGES_OF_PROGRAMING,
		&NovSev::OTHER_TECHNOLOGIES,
		&NovSev::ENTER_MAIN_MENU,
		
		const int study_programming_size = sizeof(study_programming_children) / sizeof(study_programming_children[0]);
}

const NovSev::MenuItem NovSev::BASES_OF_DATA = {
    "1 - Базы данных", NovSev::Bases_of_data, &NovSev::OTHER_TECHNOLOGIES;
};
const NovSev::MenuItem NovSev::MULTITHREADED_PROGRAMING = {
    "2 - Многопоточное программирование", NovSev::Multithreaded_programming, &NovSev::OTHER_TECHNOLOGIES;
};

const NovSev::MenuItem NovSev::NETWORK_TECHNOLOGIES = {
    "3 - Другие технологии", NovSev::Network_technologies, &NovSev::OTHER_TECHNOLOGIES;
};

const NovSev::MenuItem NovSev::ENTER_MAIN_MENU = {
    "0 - Выйти в главное меню", NovSev::Enter_main_menu, &NovSev::OTHER_TECHNOLOGIES;
};

namespace {
    const NovSev::MenuItem* other_technologies_children[] = {
		&NovSev::BASES_OF_DATA,
		&NovSev::MULTITHREADED_PROGRAMING,
		&NovSev::NETWORK_TECHNOLOGIES,
		&NovSev::ENTER_MAIN_MENU,
		const int other_technologies_children_size = sizeof(other_technologies_children) / sizeof(other_technologies_children[0]);
}

const NovSev::MenuItem NovSev::LEARNING_OF_PROGRAMING = {
    "1 - Изучать программирование", NovSev::show_menu, &NovSev::MAIN, study_programming_children, study_programming_size;
};
const NovSev::MenuItem NovSev::PLAY_FOOTBALL = {
    "0 - Пойти играть в футбол", NovSev::Play_football, &NovSev::MAIN;
};

namespace {
    const NovSev::MenuItem* main_children_size[] = {
		&NovSev::LEARNING_OF_PROGRAMING,
		&NovSev::PLAY_FOOTBALL,
		const int main_children = sizeof(main_children_size) / sizeof(main_children_size[0]);
}

const NovSev::MenuItem NovSev::MAIN = {
    nullptr, NovSev::show_menu, nullptr, main_children, main_children_size
};