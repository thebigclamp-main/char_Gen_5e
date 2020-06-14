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

#define CLASSES 12


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

void countClasses(std::string Classes[], std::string outPut, int level) {
    int barbarian = 0;
    int bard = 0;
    int cleric = 0;
    int druid = 0;
    int fighter = 0;
    int monk = 0;
    int paladin = 0;
    int ranger = 0;
    int rogue = 0;
    int sorceror = 0;
    int warlock = 0;
    int wizard = 0;

    int classes[CLASSES] = {};
    std::string cClass = {};
    int temp = 0;
    int raknare = 0;

    classes[0] = 1;
    cClass = Classes[0];


    while (Classes[raknare+1] != "") {
        if (cClass != Classes[raknare]) {

        }
    }


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

    class_setup(classes, level, statArray);


    //den mest hacky lösningen antagligen i hela koden. skrev den kl 5 på morgonen
    //klaga inte

    //en array för klasserna där den antar att allting är korrekt sorterat
    //increment för att byta klass i listan
    //i för att kunna nes öka värdet på den platsen
    int classLevels[level] = {};
    int increment = 0;
    int i = 0;
    //ansätter att den första klassen är den första för vidare jämförelser
    std::string currentClass = classes[0];
    //medens våran räknare är mindre än högsta leveln
    while (increment != level) {
            //debug kåd
            //std::cout << currentClass << " [current/next]" << Classes[increment] <<'\n';

        //kollar om den nuvarande klassen är lika då om den inte skilljer sig
        //kan vi veta att det är en extra level i den klassen
        if (classes[increment] != currentClass) {
            //skriver till filen när de skilljer sig då vi har den totala
            //level för den föregående klassen
            std::cout << classLevels[i] << ' ' << currentClass << '\n';
            file << classLevels[i] << ' ' << currentClass << '\n';
            //inkremiterar räknarna för att gå till nästa klass samt i
            //både level räknaren och vilken som är den nuvarande
            currentClass = classes[increment];
            classLevels[i++];
        }
        //annars gå till nästa plats i klass arrayn och öka nuvarande leveln
        increment = increment +1;
        classLevels[i] = classLevels[i] +1;


    }

    file.close();
    return 0;
}



