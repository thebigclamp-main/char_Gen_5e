#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <stdio.h>
#include <io.h>
#include <string>

//rulla en tärning av typen angivit av functions kallelsen
//typ 1d6 skulle skrivas som dType=6
volatile int dice(int dType) {
    int value = rand() % dType + 1;
    return value;
}

