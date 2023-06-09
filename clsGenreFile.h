#ifndef CLSGENREFILE_H_INCLUDED
#define CLSGENREFILE_H_INCLUDED

class GenreFile : public File
{
private:
    char name[30];

public:
    GenreFile(const char *name_) { strcpy(this->name, name_); };

    void addRecord();
    void listByID();

    Genre readRecord(int position);
    int getIDPosition(int index);

    bool changeOriginDate();
    bool toCancel();
};

int GenreFile::getIDPosition(int index)
{
    Genre genre;
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
            fread(&genre, sizeof genre, 1, file);
            if (genre.getId() == index)
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

int ID = 0;
void GenreFile::addRecord()
{
    Genre genre;
    FILE *file;
    file = fopen(name, "ab");

    if (file == NULL)
    {
        std::cout << "NO SE PUDO ACCEDER/CREAR EL ARCHIVO" << std::endl;
        return;
    }
    genre.setProperties();
    ID++;
    genre.setId(ID);
    fwrite(&genre, sizeof(Genre), 1, file);

    std::cout << endl;

    fclose(file);
}

void GenreFile::listByID()
{
    Genre genre;
    int genreID,
        found = 0;

    std::cout << "INGRESE ID PARA BUSCAR GENERO: ";
    std::cin >> genreID;

    FILE *file;
    file = fopen(name, "rb");

    int records = countRecords(2);
    if (records > 0)
    {
        for (int i = 0; i < records; i++)
        {
            fread(&genre, sizeof genre, 1, file);
            if (genreID == genre.getId())
            {
                genre.showProperties();
                std::cout << endl;
                found = 1;
            }
        }
    }
    if (found == 0)
        std::cout << "No se encontraron géneros con ese ID";

    fclose(file);
    std::cout << endl;
}

bool GenreFile::toCancel()
{
    int genreID;

    Genre genre;
    FILE *filePointer;
    filePointer = fopen(name, "rb");

    if (filePointer == NULL)
    {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        return false;
    }

    std::cout << "ID del genero a dar de baja: ";
    std::cin >> genreID;

    system("cls");

    int recordIndex = getIDPosition(genreID);

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

    genre = readRecord(recordIndex);
    if (genre.getState() == false)
    {
        std::cout << "EL ID INGRESADO YA ESTA DADO DE BAJA" << std::endl;
        return false;
    }
    genre.setState(false);
    bool aux = changeRecord(genre, recordIndex);
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

    Genre genre;
    int genreID, year;

    cout << "INGRESE ID PARA CAMBIAR EL AÑO: ";
    cin >> genreID;

    int position = getIDPosition(genreID);
    genre = readRecord(position);

    cout << "INGRESE ANIO NUEVO: ";
    cin >> year;
    genre.setYear(year);
    bool aux = changeRecord(genre, position);

    return aux;
}

#endif // CLSGENREFILE_H_INCLUDED
