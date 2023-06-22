#ifndef CLSCOUNTRYFILE_H_INCLUDED
#define CLSCOUNTRYFILE_H_INCLUDED

int countryID = 0;
class CountryFile : public File
{
private:
    char name[30];

public:
    CountryFile(const char *name_) { strcpy(this->name, name_); };

    void addRecord();
    void listByID();

    Country readRecord(int position);
    int getIDPosition(int index);

    bool changeNameDate();
    bool toCancel();
};

int CountryFile::getIDPosition(int index)
{
    Country contry;
    int pos = 0;
    FILE *file;

    file = fopen(name, "rb");
    if (file == NULL)
    {
        cout << "no se puedo abrir el archivo" << endl;
        return -2;
    }

    int records = countRecords(2);
    if (records > 0)
    {
        for (int i = 0; i < records; i++)
        {
            fread(&contry, sizeof contry, 1, file);
            if (contry.getId() == index)
            {
                fclose(file);
                return pos;
            }
            pos++;
        }
    }
    fclose(file);
    return -1;
}

void CountryFile::addRecord()
{
    Country contry;
    FILE *file;
    file = fopen(name, "ab");

    if (file == NULL)
    {
        std::cout << "NO SE PUDO ACCEDER/CREAR EL ARCHIVO" << std::endl;
        return;
    }
    contry.setProperties();
    countryID++;
    contry.setId(countryID);
    fwrite(&contry, sizeof(Country), 1, file);

    std::cout << endl;

    fclose(file);
}

void CountryFile::listByID()
{
    Country contry;
    int contryID,
        found = 0;

    std::cout << "INGRESE ID PARA BUSCAR GENERO: ";
    std::cin >> contryID;

    FILE *file;
    file = fopen(name, "rb");

    int records = countRecords(2);
    if (records > 0)
    {
        for (int i = 0; i < records; i++)
        {
            fread(&contry, sizeof contry, 1, file);
            if (contryID == contry.getId())
            {
                contry.showProperties();
                std::cout << endl;
                found = 1;
            }
        }
    }
    if (found == 0)
        std::cout << "No se encontraron pa�ses con ese ID";

    fclose(file);
    std::cout << endl;
}

bool CountryFile::toCancel()
{
    int contryID;

    Country contry;
    FILE *filePointer;
    filePointer = fopen(name, "rb");

    if (filePointer == NULL)
    {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        return false;
    }

    std::cout << "ID del genero a dar de baja: ";
    std::cin >> contryID;

    system("cls");

    int recordIndex = getIDPosition(contryID);

    if (recordIndex == -1)
    {
        cout << "NO EXISTE GENERO CON ESE ID" << endl;
        return false;
    }
    if (recordIndex == -2)
    {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        return false;
    }

    contry = readRecord(recordIndex);
    if (contry.getState() == false)
    {
        std::cout << "EL ID INGRESADO YA ESTA DADO DE BAJA" << std::endl;
        return false;
    }
    contry.setState(false);
    bool aux = changeRecord(contry, recordIndex);
    return aux;
}

Country CountryFile::readRecord(int position)
{
    Country obj;
    if (position < 0)
    {
        obj.setId(-3);
        return obj;
    }

    FILE *filePointer;
    filePointer = fopen(name, "rb");
    if (filePointer == NULL)
    {
        obj.setId(-2);
        return obj;
    }

    const int size = sizeof obj;
    fseek(filePointer, size * position, 0);
    int aux = fread(&obj, sizeof obj, 1, filePointer);
    fclose(filePointer);

    if (aux == 0)
        obj.setId(-1);

    return obj;
}

bool CountryFile::changeNameDate()
{

    Country contry;
    int contryID;
    char country[30];

    cout << "INGRESE ID PARA CAMBIAR EL NOMBRE: ";
    cin >> contryID;

    int position = getIDPosition(contryID);
    contry = readRecord(position);

    cout << "INGRESE NOMBRE NUEVO: ";
    loadChar(country, 30);
    contry.setCountry(country);
    bool aux = changeRecord(contry, position);

    return aux;
}
#endif // CLSCOUNTRYFILE_H_INCLUDED
