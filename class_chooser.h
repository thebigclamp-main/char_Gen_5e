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
    //rulla en t�rning p� vilken klass du kommer f� (input f�r switchen)
    int roll = dice(12);
    std::string Class = "";
    //switchen tar t�rningskastet och anger en klass f�r kastet
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



//ange vilken klass karakt�ren har f�tt
//inputs f�r functionen kr�vs
void class_setup(std::string *Classes, int Level) {
    //array f�r att lagra alla klassval
    //std::string Classes[Level] = {};
    int sizeClasses = sizeof(Classes)/sizeof(Classes[0]);


    for (int i = 0; i < Level; i++) {
        Classes[i] = classes();
    }

    //sorterar arrayn
    sort(Classes, Classes+Level);
}




