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

const char *INSTRUMENTS_FILE = "Instumentos.dat";
const char *INSTRUMENTS_BACK_UP = "Instumentos.bak";

const char *COUNTRIES_FILE = "Paises.dat";
const char *COUNTRIES_BACK_UP = "Paises.bak";

const char *START_DATA_MUSICIAN = "Datos_de_inicio_musician.dat";
const char *START_DATA_GENRES = "Datos_de_inicio_genres.dat";

#include "functions.h"
#include "Date.h"

#include "clsMusician.h"
#include "clsGenre.h"
#include "clsInstrument.h"
#include "clsCountry.h"

#include "File.h"

#include "clsInstrumentFile.h"
#include "clsGenreFile.h"
#include "clsMusicianFile.h"
#include "clsCountryFile.h"

#include "reportes.h"
#include "configuration.h"
#include "menus.h"

int main()
{
    mainMenu();
    return 0;
}
