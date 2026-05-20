#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

void clearScreen(const int clearScreen) {
    if (clearScreen == 1) {
        system("cls");
    }
}


// ======[[MENU OPTION]]====== //

menuOption* createMenuOption(const char* StringName, int (*callback)(void*), void* args) {
    if (StringName == NULL || callback == NULL) return NULL;
    menuOption* option = (menuOption*)malloc(sizeof(menuOption));
    
    if (option == NULL) return NULL;

    option->name = _strdup(StringName);
    option->callback = callback;
    option->args = args;

    return option;
}

int clickMenuOption(const menuOption* option) {
    int result = 0;
    result = option->callback(option->args);

    // if (result <= 0) {
    //     fprintf(stderr,"Error occured in callback of menu option %s",option->name);
    //     exit(-1);
    // }

    return result;
};

void printMenuOption(const menuOption* option,const int selected) {
    if (selected == 1) {
        printf("~> (%s)\n", option->name);
    } else {
        printf("   (%s)\n", option->name);
    }
}

void deleteMenuOption(menuOption* option) {
    free(option);
}

// ======[[MENU]]====== //

menu* createMenu(const char* name,const unsigned int maxLength) {
    if (name == NULL) return NULL;

    menu* Menu = (menu*)malloc(sizeof(menu));
    if (Menu == NULL) return NULL;

    menuOption** menuoptions = (menuOption**)malloc(sizeof(menuOption*) * (maxLength));
    if (menuoptions == NULL) {deleteMenu(Menu); return NULL;}

    Menu->name = name;

    Menu->options = menuoptions;

    Menu->selectedOption = 0;
    Menu->menuLength = 0;
    Menu->maxLength = maxLength;


    return Menu;
};
int pushMenuOptionToMenu(menu* Menu,menuOption* option) {
    if (Menu == NULL || option == NULL) return -1;
    if (Menu->menuLength >= Menu->maxLength) return -1;

    Menu->options[Menu->menuLength] = option;
    Menu->menuLength++;
    return 0;
};
const menuOption* popMenuOptionFromMenu(menu* Menu, const unsigned int index) {
    if (Menu == NULL) return NULL;
    
    Menu->menuLength--;

    menuOption* poppedItem = Menu->options[Menu->menuLength];
    Menu->options[Menu->menuLength] = NULL;

    return poppedItem;
};

void printMenu(const menu* Menu) {
    if (Menu == NULL) return;

    for (int i = 0;i < Menu->menuLength;i++) {
        printMenuOption(Menu->options[i], Menu->selectedOption == i);
    }

};

void deleteMenu(menu* Menu) {
    for (int i = 0;i < Menu->menuLength;i++) {
        deleteMenuOption(Menu->options[i]);
    }
    free(Menu->options);
    free(Menu);
};