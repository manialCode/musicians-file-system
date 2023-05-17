#ifndef CLSGENREFILE_H_INCLUDED
#define CLSGENREFILE_H_INCLUDED

class GenreFile
{
private:
    char name[30];

public:
    GenreFile(const char *name_) { strcpy(this->name, name_); };

    void addRecord();
    void showFile();
    void listByID();

    Genre readRecord(int position);
    int getIDPosition(int index);

    bool changeOriginDate();
    bool changeRecord(Genre obj, int pos);
    bool toCancel();
};

int GenreFile::getIDPosition(int index)
{
    Genre reg;
    int pos = 0;
    FILE *pGen;

    pGen = fopen(name, "rb");
    if (pGen == NULL)
    {
        cout << "no se puedo abrir el archivo" << endl;
        return -2;
    }
    while (fread(&reg, sizeof reg, 1, pGen) == 1)
    {
        if (reg.getId() == index)
        {
            fclose(pGen);
            return pos;
        }
        pos++;
    }
    fclose(pGen);
    return -1;
}

int ID = 0;
void GenreFile::addRecord()
{
    ID++;
    Genre obj;
    FILE *pGen;
    pGen = fopen(name, "ab");

    obj.setProperties();
    obj.setId(ID);
    fwrite(&obj, sizeof(Genre), 1, pGen);

    std::cout << endl;

    fclose(pGen);
}

void GenreFile::showFile()
{
    Genre obj;
    FILE *filePointer;
    filePointer = fopen(name, "rb");

    if (filePointer == NULL)
    {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        return;
    }

    while (fread(&obj, sizeof obj, 1, filePointer) == 1)
    {
        if (obj.getState())
            obj.showProperties();
        std::cout << std::endl;
    }
    fclose(filePointer);
}

void GenreFile::listByID()
{
    Genre obj;
    int bid,
        found = 0;

    std::cout << "INGRESE ID PARA BUSCAR GENERO: ";
    std::cin >> bid;

    FILE *pGen;
    pGen = fopen(name, "rb");
    while (fread(&obj, sizeof(Genre), 1, pGen) == 1)
    {
        if (bid == obj.getId())
        {
            obj.showProperties();
            std::cout << endl;
            found = 1;
        }
    }
    if (found == 0)
    {
        std::cout << "No se encontraron géneros con ese ID";
    }
    fclose(pGen);

    std::cout << endl;
}

bool GenreFile::toCancel()
{
    int bid;

    Genre instance;
    FILE *filePointer;
    filePointer = fopen(name, "rb");

    if (filePointer == NULL)
    {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        return false;
    }

    std::cout << "ID del genero a dar de baja: ";
    std::cin >> bid;

    system("cls");

    int recordIndex = getIDPosition(bid);

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

    instance = readRecord(recordIndex);
    if (instance.getState() == false)
    {
        std::cout << "EL ID INGRESADO YA ESTA DADO DE BAJA" << std::endl;
        return false;
    }
    instance.setState(false);
    bool aux = changeRecord(instance, recordIndex);
    return aux;
}

bool GenreFile::changeRecord(Genre obj, int pos)
{
    FILE *filePointer;
    filePointer = fopen(name, "rb+");

    int size = sizeof obj * pos;
    fseek(filePointer, size, 0);
    bool aux = fwrite(&obj, sizeof obj, 1, filePointer);
    fclose(filePointer);

    return aux;
}

Genre GenreFile::readRecord(int position)
{
    Genre obj;
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

bool GenreFile::changeOriginDate()
{

    Genre reg;
    int bid, year;

    cout << "INGRESE ID PARA CAMBIAR EL AÑO: ";
    cin >> bid;

    int pos = getIDPosition(bid);
    reg = readRecord(pos);

    cout << "INGRESE ANIO NUEVO: ";
    cin >> year;
    reg.setYear(year);
    bool aux = changeRecord(reg, pos);

    return aux;
}

#endif // CLSGENREFILE_H_INCLUDED
