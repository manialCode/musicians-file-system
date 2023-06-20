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
