#include "menu_items.hpp"

#include <cstddef>

#include "menu_functions.hpp"

const NovSev::MenuItem NovSev::STUDY_ALGEBRA_SUMM = {
    "1 - Хочу научиться складывать!", NovSev::study_algebra_summ, &NovSev::STUDY_ALGEBRA
};
const NovSev::MenuItem NovSev::STUDY_ALGEBRA_SUBSTRACT = {
    "2 - Хочу научиться вычитать!", NovSev::study_algebra_substract, &NovSev::STUDY_ALGEBRA
};
const NovSev::MenuItem NovSev::STUDY_ALGEBRA_MULTIPLY = {
    "3 - Хочу научиться умножать!", NovSev::study_algebra_multiply, &NovSev::STUDY_ALGEBRA
};
const NovSev::MenuItem NovSev::STUDY_ALGEBRA_DEVIDE = {
    "4 - Хочу научиться делить!", NovSev::study_algebra_devide, &NovSev::STUDY_ALGEBRA
};
const NovSev::MenuItem NovSev::STUDY_ALGEBRA_GO_BACK = {
    "0 - Вернуться назад", NovSev::study_go_back, &NovSev::STUDY_ALGEBRA
};

namespace {
    const NovSev::MenuItem* study_algebra_children[] = {
        &NovSev::STUDY_ALGEBRA_GO_BACK,
        &NovSev::STUDY_ALGEBRA_SUMM,
        &NovSev::STUDY_ALGEBRA_SUBSTRACT,
        &NovSev::STUDY_ALGEBRA_MULTIPLY,
        &NovSev::STUDY_ALGEBRA_DEVIDE,
    };
    const int study_algebra_size = sizeof(study_algebra_children) / sizeof(study_algebra_children[0]);
}

const NovSev::MenuItem NovSev::STUDY_CALCULUS_DIFF = {
    "1 - Хочу изучить дифференциальное счисление!", NovSev::study_calculus_diff, &NovSev::STUDY_CALCULUS
};
const NovSev::MenuItem NovSev::STUDY_CALCULUS_INTEGRAL = {
    "2 - Хочу изучить интегральное счисление!", NovSev::study_calculus_integral, &NovSev::STUDY_CALCULUS
};
const NovSev::MenuItem NovSev::STUDY_CALCULUS_GO_BACK = {
    "0 - Вернуться назад", NovSev::study_go_back, &NovSev::STUDY_CALCULUS
};

namespace {
    const NovSev::MenuItem* study_calculus_children[] = {
        &NovSev::STUDY_CALCULUS_GO_BACK,
        &NovSev::STUDY_CALCULUS_DIFF,
        &NovSev::STUDY_CALCULUS_INTEGRAL,
    };
    const int study_calculus_size = sizeof(study_calculus_children) / sizeof(study_calculus_children[0]);
}

const NovSev::MenuItem NovSev::STUDY_ALGEBRA = {
    "1 - Хочу изучить алгебру!", NovSev::show_menu, &NovSev::STUDY, study_algebra_children, study_algebra_size
};
const NovSev::MenuItem NovSev::STUDY_CALCULUS = {
    "2 - Хочу изучить математический анализ!", NovSev::show_menu, &NovSev::STUDY, study_calculus_children, study_calculus_size
};
const NovSev::MenuItem NovSev::STUDY_GO_BACK = {
    "0 - Вернуться назад", NovSev::study_go_back, &NovSev::STUDY
};

namespace {
    const NovSev::MenuItem* study_children[] = {
        &NovSev::STUDY_GO_BACK,
        &NovSev::STUDY_ALGEBRA,
        &NovSev::STUDY_CALCULUS,
    };
    const int study_size = sizeof(study_children) / sizeof(study_children[0]);
}

const NovSev::MenuItem NovSev::STUDY = {
    "1 - Хочу учиться математике!", NovSev::show_menu, &NovSev::MAIN, study_children, study_size
};
const NovSev::MenuItem NovSev::EXIT = {
    "0 - Я лучше пойду посплю...", NovSev::exit, &NovSev::MAIN
};

namespace {
    const NovSev::MenuItem* main_children[] = {
        &NovSev::EXIT,
        &NovSev::STUDY
    };
    const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

const NovSev::MenuItem NovSev::MAIN = {
    nullptr, NovSev::show_menu, nullptr, main_children, main_size
};