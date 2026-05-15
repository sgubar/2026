#pragma once

// ======[[MENU OPTION]]====== //

typedef struct menuOption {
    int (*callback)(void*);
    void* args;
    const char* name;
} menuOption;

void clearScreen(const int clearScreen);

menuOption* createMenuOption(const char* name,int (*callback)(void*), void* args);

int clickMenuOption(const menuOption* option);
void printMenuOption(const menuOption* option, int selected);

void deleteMenuOption(menuOption* option);

// ======[[MENU]]====== //

typedef struct menu {
    int selectedOption;
    int menuLength;
    int maxLength;
    const char* name;
    menuOption** options;
} menu;

menu* createMenu(const char* name, const unsigned int maxLength);

int pushMenuOptionToMenu(menu* Menu,menuOption* option);
const menuOption* popMenuOptionFromMenu(menu* Menu, const unsigned int index);

void printMenu(const menu* Menu);

void deleteMenu(menu* Menu);