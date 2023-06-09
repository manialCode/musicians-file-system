#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

class File
{
private:
    char name[30];

public:
    File(const char *name_ = "") { strcpy(this->name, name_); };

    void showFile(Musicians obj, int indicator);
    void showFile(Genre obj, int indicator);
    /* void showFile(Instrument obj, int indicator);
    void showFile(Country obj, int indicator);
 */
    int countRecords(int indicator);

    bool changeRecord(Musicians obj, int index);
    bool changeRecord(Genre obj, int index);
    bool changeRecord(Instrument obj, int index);
    bool changeRecord(Country obj, int index);
};

// Show Files
void File::showFile(Musicians obj, int indicator)
{
    FILE *file;
    file = fopen(MUSICIAN_FILE, "rb");

    if (file == NULL)
    {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        return;
    }

    int records = countRecords(indicator);
    if (records > 0)
    {
        for (int i = 0; i < records; i++)
        {
            fread(&obj, sizeof obj, 1, file);
            if (obj.getState())
                obj.showProperties();
        }
    }

    fclose(file);
}

void File::showFile(Genre obj, int indicator)
{
    FILE *file;
    file = fopen(GENRES_FILE, "rb");
    if (file == NULL)
    {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        return;
    }

    if (countRecords(indicator) > 0)
    {
        for (int i = 0; i < countRecords(indicator); i++)
        {
            fread(&obj, sizeof obj, 1, file);
            if (obj.getState())
                obj.showProperties();
        }
    }

    fclose(file);
}

/* void File::showFile(Instrument obj, int indicator)
{
    FILE *file;
    file = fopen(INSTRUMENTS_FILE, "rb");
    if (file == NULL)
    {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        return;
    }

    if (countRecords(indicator) > 0)
    {
        for (int i = 0; i < countRecords(indicator); i++)
        {
            fread(&obj, sizeof obj, 1, file);
            if (obj.getState())
                obj.showProperties();
        }
    }

    fclose(file);
}

void File::showFile(Country obj, int indicator)
{
    FILE *file;
    file = fopen(COUNTRIES_FILE, "rb");
    if (file == NULL)
    {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        return;
    }

    if (countRecords(indicator) > 0)
    {
        for (int i = 0; i < countRecords(indicator); i++)
        {
            fread(&obj, sizeof obj, 1, file);
            if (obj.getState())
                obj.showProperties();
        }
    }

    fclose(file);
}
 */
// Count Records

int File::countRecords(int indicator)
{
    FILE *p;
    if (indicator == 1)
        p = fopen(MUSICIAN_FILE, "rb");

    if (indicator == 2)
        p = fopen(GENRES_FILE, "rb");

    if (indicator == 3)
        p = fopen(INSTRUMENTS_FILE, "rb");

    if (indicator == 4)
        p = fopen(COUNTRIES_FILE, "rb");

    if (p == NULL)
        return -1;
    fseek(p, 0, 2);
    int size = ftell(p);
    fclose(p);

    switch (indicator)
    {
    case 1:
        return size / sizeof(Musicians);
        break;

    case 2:
        return size / sizeof(Genre);
        break;

    case 3:
        return size / sizeof(Instrument);
        break;

    case 4:
        return size / sizeof(Country);
        break;

    default:
        return 0;
        break;
    }
}

// Change Records
bool File::changeRecord(Musicians obj, int index)
{

    FILE *file;
    file = fopen(MUSICIAN_FILE, "rb+");

    fseek(file, sizeof obj * index, 0);
    bool aux = fwrite(&obj, sizeof obj, 1, file);
    fclose(file);

    return aux;
}

bool File::changeRecord(Genre obj, int index)
{

    FILE *file;
    file = fopen(GENRES_FILE, "rb+");

    fseek(file, sizeof obj * index, 0);
    bool aux = fwrite(&obj, sizeof obj, 1, file);
    fclose(file);

    return aux;
}

/*
bool File::changeRecord(int index, Instrument obj)
{

    FILE *file;
    file = fopen(INSTRUMENT_FILE, "rb+");

    fseek(file, sizeof obj * index, 0);
    bool aux = fwrite(&obj, sizeof obj, 1, file);
    fclose(file);

    return aux;
}

bool File::changeRecord(int index, Country obj)
{

    FILE *file;
    file = fopen(COUNTRY_FILE, "rb+");

    fseek(file, sizeof obj * index, 0);
    bool aux = fwrite(&obj, sizeof obj, 1, file);
    fclose(file);

    return aux;
}
*/
#endif // FILE_H_INCLUDED
