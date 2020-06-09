#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <stdio.h>
#include <io.h>
#include <string>
#include <algorithm>

#define CLASSES 12

std::string classes() {
    //rulla en tärning på vilken klass du kommer få (input för switchen)
    int roll = dice(12);
    std::string Class = "";
    //switchen tar tärningskastet och anger en klass för kastet
    switch (roll) {
    case 1:
        Class = "Barbarian";
        break;
    case 2:
        Class = "Bard";
        break;
    case 3:
        Class = "Cleric";
        break;
    case 4:
        Class = "Druid";
        break;
    case 5:
        Class = "Fighter";
        break;
    case 6:
        Class = "Monk";
        break;
    case 7:
        Class = "Paladin";
        break;
    case 8:
        Class = "Ranger";
        break;
    case 9:
        Class = "Sorcerer";
        break;
    case 10:
        Class = "Rogue";
        break;
    case 11:
        Class = "Warlock";
        break;
    case 12:
        Class = "Wizard";
        break;

    }

    return Class;
}



//ange vilken klass karaktären har fått
//inputs för functionen krävs
void class_setup(std::string *Classes, int Level) {
    //array för att lagra alla klassval
    //std::string Classes[Level] = {};
    int sizeClasses = sizeof(Classes)/sizeof(Classes[0]);


    for (int i = 0; i < Level; i++) {
        Classes[i] = classes();
    }

    //sorterar arrayn
    sort(Classes, Classes+Level);
}




