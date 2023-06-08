#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

const char *MUSICIAN_FILE = "Musicos.dat";
const char *MUSICIAN_BACK_UP = "Musicos.bak";

const char *GENRES_FILE = "Generos.dat";
const char *GENRES_BACK_UP = "Generos.bak";

const char *INTRUMENTS_FILE = "Instumentos.dat";
const char *INTRUMENTS_BACK_UP = "Instumentos.bak";

const char *COUNTRIES_FILE = "Paises.dat";
const char *COUNTRIES_BACK_UP = "Paises.bak";

#include "functions.h"
#include "Date.h"

#include "clsMusician.h"
#include "clsGenre.h"
#include "clsInstrument.h"
#include "clsCountry.h"

#include "File.h"

#include "clsMusicianFile.h"
#include "clsGenreFile.h"
#include "clsInstrument.h"
#include "clsCountryFile.h"

#include "reportes.h"
#include "menus.h"

int main()
{
    mainMenu();
    return 0;
}
