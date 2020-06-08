#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <stdio.h>
#include <io.h>
#include <string>

#include "dice_roll.h"
#include "class_chooser.h"
#include "race_handler.h"
#include "generic_class_feats.h"




//setup ger input för programmet (namn och level som karaktären ska vara)
void setup(std::string *Name, int *level) {
    std::cout << "\n\t\t Please enter your name:";
    std::cin >> *Name;
    std::cout << "\n\t\t Please enter level:";
    std::cin >> *level;
    std::cout << '\n';
}

//stat kör med rulla 4 tärningar och ta bort den lägstaför stats.
//kastar tillbaka outputten av dem (kanske redundant om man vill
//bygga up en generisk function för det)
int stat () {
    int dices[4];

    //volatile?
    volatile int pointer = 0;

    //rulla 4 tärning och lägg dem i en icke-ordnad lista
    for (int i = 0; i < 4; i++) {
        dices[i] = dice(6);
    }

    //start värde på första kastet
    //place är för att peka ut vilket kast som inte ska vara med
    pointer = dices[0];
    int place = 0;

    //titta om den nuvrande lägsta tärningen är mindre än nästa
    //byt platsen på nuvarande om det är så
    for (int i = 1; i < 4; i++) {
        if (pointer > dices[i]) {
            pointer = dices[i];
            place = i;
        }
    }

    //töm det kastet som var lägst
    //skapa värde som kommer outputta totallen
    //av tärningarna
    dices[place] = 0;
    int total = 0;

    //summera alla tärningskasten
    for (int i = 0; i < 4; i++) {
        total = total + dices[i];
    }

    //spotta ut totalen
    return total;
}

void countClasses(std::string *Classes, std::string outPut) {

}


//huvud logiken för programmet
int main () {
    //seeda spontana nummer generatorn
    //förbered fil outputten för att spara karaktären
    srand(time(NULL));
    std::string name;
    int level= 1;
    std::ofstream file;

    //setup för att ta in user input
    setup(&name, &level);

    //generar vilken ras som spelaren får
    std::string race = race_gen();
    /*
    if (mkdir("../kenku" ) != 0) {
        std::cout << "did not work!";
    }
    //*/

    //en array för att införa stat arrayn som genereras
    int statArray[6];
    for (int i = 0; i < 6; i++) {
        statArray[i] = stat();
    }


    //skapar det som krävs för UX ska vara tydligare,dessa är bara för att visa senare
    std::string names[6];
    names[0] = "Strength: ";
    names[1] = "Dexterity: ";
    names[2] = "Constitution: ";
    names[3] = "Intelligence: ";
    names[4] = "Wisdom: ";
    names[5] = "Charisma: ";

    //kallar för att generera stats och ange vilken subrace man är
    std::string subRace = race_stats(statArray, race);

    //skapar output filen
    file.open (name + " " + subRace + " "  + std::to_string(level) + ".txt");

    //anger statsen i stat arrayn och vilka värden de är
    //(UX)
    for (int i = 0; i < 6; i++) {
        file << names[i] << statArray[i] << "\n";
    }

    //skriver till filen, sedan stänger ned den och avslutar programmet
    file<< "\n\n" << subRace << '\n';

    std::string classes[level] = {};

   class_setup(classes, level);



    for (int i = 0; i < level; i++) {
        file << classes[i] << "\n";
    }

    file.close();
    return 0;
}



