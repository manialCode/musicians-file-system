#ifndef CONFIGURATION_H_INCLUDED
#define CONFIGURATION_H_INCLUDED

void copyMusicians()
{
    Musicians musician;
    FILE *pMusicians, *pMusiciansBak;
    pMusicians = fopen(MUSICIAN_FILE, "rb");
    if (pMusicians == NULL)
    {
        cout << "NO SE PUDO LEER EL ARCHIVO" << endl;
        return;
    }
    pMusiciansBak = fopen(MUSICIAN_BACK_UP, "wb");
    if (pMusiciansBak == NULL)
    {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        fclose(pMusicians);
        return;
    }
    while (fread(&musician, sizeof musician, 1, pMusicians) == 1)
    {
        fwrite(&musician, sizeof musician, 1, pMusiciansBak);
    }
    std::cout << "COPIA DE SEGURIDAD REALIZADA" << endl;
    fclose(pMusicians);
    fclose(pMusiciansBak);
}

void copyGenres()
{
    Genre genres;
    FILE *pGenres, *pGenresBak;
    pGenres = fopen(GENRES_FILE, "rb");
    if (pGenres == NULL)
    {
        cout << "NO SE PUDO LEER EL ARCHIVO" << endl;
        return;
    }
    pGenresBak = fopen(GENRES_BACK_UP, "wb");
    if (pGenresBak == NULL)
    {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        fclose(pGenres);
        return;
    }
    while (fread(&genres, sizeof genres, 1, pGenres) == 1)
    {
        fwrite(&genres, sizeof genres, 1, pGenresBak);
    }
    std::cout << "COPIA DE SEGURIDAD REALIZADA" << endl;
    fclose(pGenres);
    fclose(pGenresBak);
}

void copyInstruments()
{
    Instrument instrument;
    FILE *instrument_file, *instrument_file_bk;
    instrument_file = fopen(INSTRUMENTS_FILE, "rb");
    instrument_file_bk = fopen(INSTRUMENTS_BACK_UP, "wb");

    if (instrument_file == NULL || instrument_file_bk == NULL)
    {
        cout << "NO SE PUDO LEER EL ARCHIVO" << endl;
        return;
    }

    while (fread(&instrument, sizeof instrument, 1, instrument_file) == 1)
    {
        fwrite(&instrument, sizeof instrument, 1, instrument_file_bk);
    }
    std::cout << "COPIA DE SEGURIDAD REALIZADA" << endl;
    fclose(instrument_file);
    fclose(instrument_file_bk);
}

void copyCountries()
{
    Country country;
    FILE *countries_file, *countries_file_bk;

    countries_file = fopen(COUNTRIES_FILE, "rb");
    countries_file_bk = fopen(COUNTRIES_BACK_UP, "wb");

    if (countries_file == NULL || countries_file_bk == NULL)
    {
        cout << "NO SE PUDO LEER EL ARCHIVO" << endl;
        return;
    }

    while (fread(&country, sizeof country, 1, countries_file) == 1)
    {
        fwrite(&country, sizeof country, 1, countries_file_bk);
    }
    std::cout << "COPIA DE SEGURIDAD REALIZADA" << endl;
    fclose(countries_file);
    fclose(countries_file_bk);
}

void restoreMusicians()
{
    Musicians musician;
    FILE *pMusicians, *pMusiciansBak;
    pMusicians = fopen(MUSICIAN_FILE, "wb");
    if (pMusicians == NULL)
    {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        return;
    }
    pMusiciansBak = fopen(MUSICIAN_BACK_UP, "rb");
    if (pMusiciansBak == NULL)
    {
        cout << "NO SE PUDO LEER EL ARCHIVO" << endl;
        fclose(pMusicians);
        return;
    }
    while (fread(&musician, sizeof musician, 1, pMusiciansBak) == 1)
    {
        fwrite(&musician, sizeof musician, 1, pMusicians);
    }
    std::cout << "ARCHIVO DE MUSICOS RESTAURADO" << endl;
    fclose(pMusicians);
    fclose(pMusiciansBak);
}

void restoreGenres()
{
    Genre genres;
    FILE *pGenres, *pGenresBak;
    pGenres = fopen(GENRES_FILE, "wb");
    if (pGenres == NULL)
    {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        return;
    }
    pGenresBak = fopen(GENRES_BACK_UP, "rb");
    if (pGenresBak == NULL)
    {
        cout << "NO SE PUDO LEER EL ARCHIVO" << endl;
        fclose(pGenres);
        return;
    }
    while (fread(&genres, sizeof genres, 1, pGenresBak) == 1)
    {
        fwrite(&genres, sizeof genres, 1, pGenres);
    }
    std::cout << "ARCHIVO DE G�NEROS RESTAURADO" << endl;
    fclose(pGenres);
    fclose(pGenresBak);
}

void restoreInstruments()
{
    Instrument instrument;
    FILE *instrument_file, *instrument_file_bk;

    instrument_file = fopen(INSTRUMENTS_FILE, "rb");
    instrument_file_bk = fopen(INSTRUMENTS_BACK_UP, "wb");

    if (instrument_file == NULL || instrument_file_bk == NULL)
    {
        cout << "NO SE PUDO LEER EL ARCHIVO" << endl;
        return;
    }

    while (fread(&instrument, sizeof instrument, 1, instrument_file_bk) == 1)
    {
        fwrite(&instrument, sizeof instrument, 1, instrument_file);
    }
    std::cout << "ARCHIVO DE MUSICOS RESTAURADO" << endl;
    fclose(instrument_file);
    fclose(instrument_file_bk);
}

void restoreCountries()
{
    Country country;
    FILE *countries_file, *countries_file_bk;

    countries_file = fopen(COUNTRIES_FILE, "rb");
    countries_file_bk = fopen(COUNTRIES_BACK_UP, "wb");

    if (countries_file == NULL || countries_file_bk == NULL)
    {
        cout << "NO SE PUDO LEER EL ARCHIVO" << endl;
        return;
    }

    while (fread(&country, sizeof country, 1, countries_file_bk) == 1)
    {
        fwrite(&country, sizeof country, 1, countries_file);
    }
    std::cout << "COPIA DE SEGURIDAD REALIZADA" << endl;
    fclose(countries_file);
    fclose(countries_file_bk);
}

void establishData()
{
    Musicians musician;
    Genre genres;
    FILE *pMusicians, *pGenres, *pRestMus, *pRestGen;
    pMusicians = fopen(MUSICIAN_FILE, "wb");
    if (pMusicians == NULL)
    {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        return;
    }
    pGenres = fopen(GENRES_FILE, "wb");
    if (pGenres == NULL)
    {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        fclose(pMusicians);
        return;
    }
    pRestMus = fopen(START_DATA_MUSICIAN, "rb");
    if (pRestMus == NULL)
    {
        cout << "NO SE PUDO LEER EL ARCHIVO 1" << endl;
        fclose(pMusicians);
        fclose(pGenres);
        return;
    }
    pRestGen = fopen(START_DATA_GENRES, "rb");
    if (pRestGen == NULL)
    {
        cout << "NO SE PUDO LEER EL ARCHIVO 2" << endl;
        fclose(pMusicians);
        fclose(pGenres);
        fclose(pRestMus);
        return;
    }

    while (fread(&musician, sizeof musician, 1, pRestMus) == 1)
    {
        fwrite(&musician, sizeof musician, 1, pMusicians);
    }
    while (fread(&genres, sizeof genres, 1, pRestGen) == 1)
    {
        fwrite(&genres, sizeof genres, 1, pGenres);
    }
    cout << "DATOS DE INICIO ESTABLECIDOS" << endl;
    fclose(pMusicians);
    fclose(pGenres);
    fclose(pRestMus);
    fclose(pRestGen);
}

#endif // CONFIGURATION_H_INCLUDED
