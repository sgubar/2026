#include <stdio.h>
#include "menu.h"
#include "geometry.h"
#include <string.h>
#include <Windows.h>
#include <conio.h>

int CLEARSCREEN = 1;
int EXITREQUESTED = 0;
int TEST = 0;

circleArray* circles = NULL;
menu* MainMenu = NULL;
menu* InfoMenu = NULL;
int selectedMenu = 0;

int test_function() {
    printf("test\n");
    return -1;
}

int getInputfloat() {
    float result = 0;
    while (1)
    if (scanf("%f",&result) != 1) {
        while (getchar() != '\n');
    } else {
        while (getchar() != '\n');
        break;
    }
    return result;
}


int circleInfoTemplate_callback(void* args) {
    int id = (int)(intptr_t)args;

    clearScreen(CLEARSCREEN);
    printf("============\n№%d ",id);
    printCircleInfo(circles->circles[id]);
    printf("============\nНатисність будь-яку клавішу, щоб повернутись до меню.");
    _getch();
    return 1;
}

int createButton_callback() {
    clearScreen(CLEARSCREEN);

    // Getting user input
    float posx = 0;
    float posy = 0;
    float radx = 0;
    float rady = 0;

    printf("======[[Створення кола]]======\nВведіть координату х кола: ");\

    if (circles->arrayLength == circles->maxLength) {
        printf("\n======[[Невдача]]======\nЗабагато кіл. Натисність будь-яку клавішу, щоб повернутись до меню.");
        _getch();
        return -1;
    }
    posx = getInputfloat();
    printf("Введіть координату y кола: ");
    posy = getInputfloat();
    printf("Введіть радіус маленької піввісі: ");
    radx = getInputfloat();
    printf("Введіть радіус великої піввісі: ");
    rady = getInputfloat();

    //creating a circle
    circle* circ = createCircleFromCords(posx, posy, min(radx,rady), max(radx,rady));
    if (circ == NULL) {
        printf("======[[Невдача]]======\nСталась помилка при створенні кола.\nНатисність будь-яку клавішу, щоб повернутись до меню.\n============\n");
        _getch();
        return -1;
    }

    int circleId = circles->arrayLength;

    pushCircleToArray(circles,circ);

    //creating a button for info menu
    char textbuffer[] = "Коло №%d";
    snprintf(textbuffer,15,"Коло №%d",circleId);

    menuOption* circleButton = createMenuOption(textbuffer,&circleInfoTemplate_callback, (void*)(intptr_t)circleId);
    pushMenuOptionToMenu(InfoMenu,circleButton);

    printf("======[[Успіх]]======\nКоло №%d успішно створено!\nНатисність будь-яку клавішу, щоб повернутись до меню.\n============\n", circleId);
    _getch();
    return 1;
}

int info_callback() {
    selectedMenu = 1;
}



int back_callback() {
    selectedMenu = 0;
}

int exit_callback() {
    EXITREQUESTED = 1;
}

void test() {
    menuOption* option1 = createMenuOption("test1",&test_function,NULL);
    menuOption* option2 = createMenuOption("test2",&test_function,NULL);
    
    menu* Menu1 = createMenu("test",2);

    pushMenuOptionToMenu(Menu1,option1);
    pushMenuOptionToMenu(Menu1,option2);

    printMenu(Menu1);

    clickMenuOption(option1);


    deleteMenu(Menu1);

    circleArray* circArr = createCircleArray(3);

    circle* circ1 = createCircleFromArray((float[]){2,1,5,4});

    circle* circ2 = createCircleFromCords(1.2,1,2.5,2);

    vec2* pos = createVec2(0,0);
    vec2* size = createVec2(2,2);

    circle* circ3 = createCircleFromVectors(pos,size);

    pushCircleToArray(circArr,circ1);
    pushCircleToArray(circArr,circ2);
    pushCircleToArray(circArr,circ3);

    printCircleArray(circArr);

    printf("\n=======\n");
    circle* circ4 = createCircleFromCords(0,0,5,5);

    insertCircleToArray(circArr,circ4,1);

    printCircleArray(circArr);
    printf("\n=======\n");

    circle* circ5 = popCircleFromArray(circArr);

    printCircleArray(circArr);
    printf("\n======[[Test complete]]======\n");

    deleteCircle(circ5);
    deleteCircleArray(circArr);
}



void checkProgramArguments(int argc, char** argv) {
    for (int i = 1;i < argc;i++) {
        if (strcmp(argv[i],"--noclearscreen") == 0) {
            CLEARSCREEN = 0;
        } 
        else if (strcmp(argv[i],"--test") == 0) {
            TEST = 1;
        }
    }
}


int main(int argc, char** argv) {
    SetConsoleOutputCP(CP_UTF8);
    checkProgramArguments(argc,argv);
    
    if (TEST == 1) test();
    else {
        menu* Menus[2];
        

        menuOption* createButton = createMenuOption("Створити коло",&createButton_callback,NULL);
        menuOption* InfoButton = createMenuOption("Інформація про коло",&info_callback,NULL);
        menuOption* exitButton = createMenuOption("Вихід з програми",&exit_callback,NULL);

        menuOption* backButton = createMenuOption("Повернутись до головного меню",&back_callback,NULL);

        MainMenu = createMenu("Головне меню",3);
        pushMenuOptionToMenu(MainMenu,createButton);
        pushMenuOptionToMenu(MainMenu,InfoButton);
        pushMenuOptionToMenu(MainMenu,exitButton);

        InfoMenu = createMenu("Інформація про коло",6);
        pushMenuOptionToMenu(InfoMenu,backButton);


        Menus[0] = MainMenu;
        Menus[1] = InfoMenu;

        circles = createCircleArray(5);

        while (!EXITREQUESTED) {
            menu* neededMenu = Menus[selectedMenu];
            clearScreen(CLEARSCREEN);
            printf("======[[%s]]======\n", neededMenu->name);
            printMenu(neededMenu);
            printf("============\n");
            int key = _getch();

            if (key == 224) {
                key = _getch();
                if (key == 72) {
                    if (neededMenu->selectedOption > 0) neededMenu->selectedOption--;
                    else neededMenu->selectedOption = neededMenu->menuLength - 1;
                }
                else if (key == 80) {
                    if (neededMenu->selectedOption < neededMenu->menuLength - 1) neededMenu->selectedOption++;
                    else neededMenu->selectedOption = 0;
                }
                continue;
            }

            switch (key) {
            case 3:
                EXITREQUESTED = 1;
                break;
            case 13: // ENTER
                clickMenuOption(neededMenu->options[neededMenu->selectedOption]);
                break;
            default:
                break;
            }
        }
        deleteCircleArray(circles);

        deleteMenu(MainMenu);
        deleteMenu(InfoMenu);
        clearScreen(CLEARSCREEN);
    }
        
    return 0;
}