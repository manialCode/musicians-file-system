#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

class File
{
private:
    char name[30];

public:
    File(const char *name_ = "") { strcpy(this->name, name_); };

    void showFile(int indicator, Musicians obj);
    void showFile(int indicator, Genre obj);
    void showFile(int indicator, Instrument obj);
    void showFile(int indicator, Country obj);

    int countRecords(int indicator);

    bool changeRecord(int index, Musicians obj);
    bool changeRecord(int index, Genre obj);
    bool changeRecord(int index, Instrument obj);
    bool changeRecord(int index, Country obj);
};

// Show Files
void File::showFile(int indicator, Musicians obj)
{
    FILE *file;
    file = fopen(name, "rb");
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

void File::showFile(int indicator, Genre obj)
{
    FILE *file;
    file = fopen(name, "rb");
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

void File::showFile(int indicator, Instrument obj)
{
    FILE *file;
    file = fopen(name, "rb");
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

void File::showFile(int indicator, Country obj)
{
    FILE *file;
    file = fopen(name, "rb");
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

// Count Records
int File::countRecords(int indicator)
{
    FILE *p;
    p = fopen(name, "rb");
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
bool File::changeRecord(int index, Musicians obj)
{

    FILE *file;
    file = fopen(name, "rb+");

    fseek(file, sizeof obj * index, 0);
    bool aux = fwrite(&obj, sizeof obj, 1, file);
    fclose(file);

    return aux;
}

bool File::changeRecord(int index, Genre obj)
{

    FILE *file;
    file = fopen(name, "rb+");

    fseek(file, sizeof obj * index, 0);
    bool aux = fwrite(&obj, sizeof obj, 1, file);
    fclose(file);

    return aux;
}

bool File::changeRecord(int index, Instrument obj)
{

    FILE *file;
    file = fopen(name, "rb+");

    fseek(file, sizeof obj * index, 0);
    bool aux = fwrite(&obj, sizeof obj, 1, file);
    fclose(file);

    return aux;
}

bool File::changeRecord(int index, Country obj)
{

    FILE *file;
    file = fopen(name, "rb+");

    fseek(file, sizeof obj * index, 0);
    bool aux = fwrite(&obj, sizeof obj, 1, file);
    fclose(file);

    return aux;
}

#endif // FILE_H_INCLUDED
