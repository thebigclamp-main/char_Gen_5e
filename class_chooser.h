#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <stdio.h>
#include <io.h>
#include <string>
#include <algorithm>

#define CLASSES 12

std::string classes(int statArray[]) {
    std::string Class = "";
    int counter = 0;
    //rulla en tärning på vilken klass du kommer få (input för switchen)
    int roll = dice(12);
    int zeroCheck = 0;

    for (int i = 0; i < 6; i++) {
        counter += statArray[i];
    }

    do {
        if (counter == 0) {
            break;
        }
        roll = dice(12);
        std::cout << ' ' << roll << '\n';
    //switchen tar tärningskastet och anger en klass för kastet
        switch (roll) {
        case 1:
            if (statArray[0] > 12)
            Class = "Barbarian";
            break;
        case 2:
            if (statArray[5] > 12)
            Class = "Bard";
            break;
        case 3:
            if (statArray[4] > 12)
            Class = "Cleric";
            break;
        case 4:
            if (statArray[4] > 12)
            Class = "Druid";
            break;
        case 5:
            if (statArray[1] > 12 || statArray[0] > 12)
            Class = "Fighter";
            break;
        case 6:
            if (statArray[4] > 12 && statArray[1] > 12)
            Class = "Monk";
            break;
        case 7:
            if (statArray[0] > 12 && statArray[5] > 12)
            Class = "Paladin";
            break;
        case 8:
            if (statArray[4] > 12 && statArray[1] > 12)
            Class = "Ranger";
            break;
        case 9:
            if (statArray[4] > 12)
            Class = "Sorcerer";
            break;
        case 10:
            if (statArray[1] > 12)
            Class = "Rogue";
            break;
        case 11:
            if (statArray[5] > 12)
            Class = "Warlock";
            break;
        case 12:
            if (statArray[3] > 12)
            Class = "Wizard";
            break;
        default:
            Class = "";

    }
    } while (Class == "");

    return Class;
}



//ange vilken klass karaktären har fått
//inputs för functionen krävs
void class_setup(std::string *Classes, int Level, int statArray[]) {
    //array för att lagra alla klassval
    //std::string Classes[Level] = {};
    int sizeClasses = sizeof(Classes)/sizeof(Classes[0]);


    for (int i = 0; i < 6; i++) {
        statArray[i] = 12;
    }

    statArray[3]++;

    for (int i = 0; i < Level; i++) {
        Classes[i] = classes(statArray);
        std::cout << Classes[i] << ' ';
    }

    //sorterar arrayn
    sort(Classes, Classes+Level);
}




