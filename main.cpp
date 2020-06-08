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




//setup ger input f�r programmet (namn och level som karakt�ren ska vara)
void setup(std::string *Name, int *level) {
    std::cout << "\n\t\t Please enter your name:";
    std::cin >> *Name;
    std::cout << "\n\t\t Please enter level:";
    std::cin >> *level;
    std::cout << '\n';
}

//stat k�r med rulla 4 t�rningar och ta bort den l�gstaf�r stats.
//kastar tillbaka outputten av dem (kanske redundant om man vill
//bygga up en generisk function f�r det)
int stat () {
    int dices[4];

    //volatile?
    volatile int pointer = 0;

    //rulla 4 t�rning och l�gg dem i en icke-ordnad lista
    for (int i = 0; i < 4; i++) {
        dices[i] = dice(6);
    }

    //start v�rde p� f�rsta kastet
    //place �r f�r att peka ut vilket kast som inte ska vara med
    pointer = dices[0];
    int place = 0;

    //titta om den nuvrande l�gsta t�rningen �r mindre �n n�sta
    //byt platsen p� nuvarande om det �r s�
    for (int i = 1; i < 4; i++) {
        if (pointer > dices[i]) {
            pointer = dices[i];
            place = i;
        }
    }

    //t�m det kastet som var l�gst
    //skapa v�rde som kommer outputta totallen
    //av t�rningarna
    dices[place] = 0;
    int total = 0;

    //summera alla t�rningskasten
    for (int i = 0; i < 4; i++) {
        total = total + dices[i];
    }

    //spotta ut totalen
    return total;
}

void countClasses(std::string *Classes, std::string outPut) {

}


//huvud logiken f�r programmet
int main () {
    //seeda spontana nummer generatorn
    //f�rbered fil outputten f�r att spara karakt�ren
    srand(time(NULL));
    std::string name;
    int level= 1;
    std::ofstream file;

    //setup f�r att ta in user input
    setup(&name, &level);

    //generar vilken ras som spelaren f�r
    std::string race = race_gen();
    /*
    if (mkdir("../kenku" ) != 0) {
        std::cout << "did not work!";
    }
    //*/

    //en array f�r att inf�ra stat arrayn som genereras
    int statArray[6];
    for (int i = 0; i < 6; i++) {
        statArray[i] = stat();
    }


    //skapar det som kr�vs f�r UX ska vara tydligare,dessa �r bara f�r att visa senare
    std::string names[6];
    names[0] = "Strength: ";
    names[1] = "Dexterity: ";
    names[2] = "Constitution: ";
    names[3] = "Intelligence: ";
    names[4] = "Wisdom: ";
    names[5] = "Charisma: ";

    //kallar f�r att generera stats och ange vilken subrace man �r
    std::string subRace = race_stats(statArray, race);

    //skapar output filen
    file.open (name + " " + subRace + " "  + std::to_string(level) + ".txt");

    //anger statsen i stat arrayn och vilka v�rden de �r
    //(UX)
    for (int i = 0; i < 6; i++) {
        file << names[i] << statArray[i] << "\n";
    }

    //skriver till filen, sedan st�nger ned den och avslutar programmet
    file<< "\n\n" << subRace << '\n';

    std::string classes[level] = {};

   class_setup(classes, level);



    for (int i = 0; i < level; i++) {
        file << classes[i] << "\n";
    }

    file.close();
    return 0;
}



