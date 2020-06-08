#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <stdio.h>
#include <io.h>
#include <string>




std::string race_gen() {
    std::string race[10] = {"Human", "dragonborn", "elf", "dwarf", "aasimar", "goliath", "kenku", "lizard folk", "triton", "tiefling"};

    volatile int roll = dice(10)-1;

    std::string chosen = race[roll];

    return chosen;
}

std::string race_stats(int *statArray, std::string race) {
    std::string subrace;

    if (race == "Human") {
        volatile int roll = dice(5);
        //1 represents normal human
        if (roll == 1) {
            for (int i = 0; i < 6; i++) {
                statArray[i] += 1;
            }
        subrace = "Human";
        } else {
            //pickFeat(*statArray);
            for (int i = 0; i < 2; i++) {
               volatile int roll2 = dice(6);
               statArray[roll2] = statArray[roll2] + 1;
            }
            subrace = "Human Variant";
        }
    } else if (race == "dragonborn") {
        statArray[0] += 2;
        statArray[5] += 1;
        int roll = dice(10);
        if (roll == 1) {
            subrace = "Black";
        } else if (roll == 2) {
            subrace = "Blue";

        } else if (roll == 3) {
            subrace = "Brass";

        } else if (roll == 4) {
            subrace = "Copper";

        } else if (roll == 5) {
            subrace = "Gold";

        } else if (roll == 6) {
            subrace = "green";

        } else if (roll == 7) {
            subrace = "Red";

        } else if (roll == 8) {
            subrace = "Silver";

        } else if (roll == 9) {
            subrace = "white";
        }

    } else if (race == "elf") {
        int roll = dice(3);
        statArray[1] = statArray[1] + 2;

        if (roll == 1) {
            subrace = "High Elf";
            statArray[3] = statArray[3] + 1;

        } else if (roll == 2) {
            subrace = "Wood Elf";
            statArray[4] = statArray[4] + 1;

        } else if (roll == 3) {
            subrace = "Dark Elf";
            statArray[5] = statArray[5] + 1;

        }

    } else if (race == "dwarf") {
        statArray[2] = statArray[2] + 2;
        int roll = dice(2);
        if (roll == 1 ) {
            statArray[4] = statArray[4] + 1;
            subrace = "Hill Dwarf";
        } else {
            statArray[0] = statArray[0] + 2;
            subrace = "Mountain Dwarf";
        }
    } else if (race == "aasimar") {
        int roll = dice(3);
        statArray[5] = statArray[5] + 2;

        if (roll == 1) {
            statArray[0] = statArray[0] + 1;
            subrace = "Fallen Aasimar";
        } else if (roll == 2) {
            statArray[2] = statArray[2] + 1;
            subrace = "Scourge Aasimar";
        } else {
            statArray[4] = statArray[4] + 1;
            subrace = "Protector Aasimar";
        }

    } else if (race == "goliath") {
        statArray[0] = statArray[0] + 2;
        statArray[2] = statArray[2] + 1;
        subrace = "Goliath";
    } else if (race == "kenku") {
        statArray[1] = statArray[1] + 2;
        statArray[4] = statArray[4] + 1;
        subrace = "Kenku";

    } else if (race == "lizard folk") {
        statArray[2] = statArray[2] + 2;
        statArray[4] = statArray[4] + 1;
        subrace = "Kenku";

    } else if (race == "triton") {
        statArray[0] = statArray[0] + 1;
        statArray[2] = statArray[2] + 1;
        statArray[5] = statArray[5] + 1;
        subrace = "triton";

    } else if (race == "tiefling") {
        statArray[3] = statArray[3] + 1;
        statArray[5] = statArray[5] + 2;
        subrace = "Tiefling";
    }
    std::cout << "\n\n";
    return subrace;
}
