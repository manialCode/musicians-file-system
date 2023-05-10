#include <iostream>
#include <ctime>
#include <locale>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

const char *MUSICIAN_FILE = "Musicos.dat";
const char *MUSICIAN_BACK_UP = "Musicos.bak";

const char *GENRES_FILE = "Generos.dat";
const char *GENRES_BACK_UP = "Generos.bak";

#include "functions.h"
#include "Date.h"
#include "clsMusician.h"
#include "clsMusicianFile.h"
#include "menus.h"

int main()
{
    menuMusicians();
    return 0;
}
