#ifndef CLSMUSICIANFILE_H_INCLUDED
#define CLSMUSICIANFILE_H_INCLUDED

class MusicianFile : public File
{
private:
    char name[30];

public:
    MusicianFile(const char *name_ = "") { strcpy(this->name, name_); };
    void addRecord();
    void listByDni();

    Musicians readRecord(int position);
    bool changeAdmissionDate();
    bool toCancel();

    int getDniPosition(int dni);
};

void MusicianFile::addRecord()
{
    Musicians musician;
    FILE *filePointer;
    filePointer = fopen(name, "ab");

    if (filePointer == NULL)
    {
        std::cout << "NO SE PUDO ACCEDER/CREAR EL ARCHIVO" << std::endl;
        return;
    }

    musician.setProperties();
    int objDNI = musician.getDni();

    if (getDniPosition(objDNI) >= 0)
    {
        std::cout << "DNI YA EXISTENTE, CARGA DENEGADA..." << std::endl;
        system("pause");
        fclose(filePointer);
        return;
    }

    if (!(musician.getAdmissionDate().getIsValid()))
    {
        fclose(filePointer);
        return;
    }

    if (musician.getDepartment() < 1 || musician.getDepartment() > 4 ||
        musician.getMainInstrument() < 1 || musician.getMainInstrument() > 15 ||
        musician.getMusicType() < 1 || musician.getMusicType() > 10)
    {
        fclose(filePointer);
        std::cout << "VALORES INVALIDOS, CARGA DENEGADA..." << std::endl;
        return;
    }

    fwrite(&musician, sizeof(Musicians), 1, filePointer);
    std::cout << std::endl;
    std::cout << "CARGA EXITOSA" << std::endl;
    fclose(filePointer);
}

void MusicianFile::listByDni()
{
    int dni;
    Musicians musician;
    FILE *filePointer;
    filePointer = fopen(MUSICIAN_FILE, "rb");

    if (filePointer == NULL)
    {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        return;
    }

    std::cout << "DNI a listar: ";
    std::cin >> dni;

    system("cls");

    int check = getDniPosition(dni);
    if (check >= 0)
    {
        int records = countRecords(1);
        for (int i = 0; i < records; i++)
        {
            fread(&musician, sizeof musician, 1, filePointer);
            if (musician.getDni() == dni && musician.getState())
                musician.showProperties();
        }
    }
    else
        std::cout << "Este dni no existe, saliendo" << std::endl;
    fclose(filePointer);
};

int MusicianFile::getDniPosition(int dni)
{
    Musicians musician;
    FILE *filePointer;
    filePointer = fopen(name, "rb");

    int position = 0;

    if (filePointer == NULL)
    {
        fclose(filePointer);
        return -2;
    }

    int records = countRecords(1);
    for (int i = 0; i < records; i++)
    {
        fread(&musician, sizeof musician, 1, filePointer);
        if (musician.getDni() == dni)
        {
            fclose(filePointer);
            return position;
        }
        position++;
    }

    fclose(filePointer);
    return -1;
}

bool MusicianFile::toCancel()
{
    int dni;

    Musicians instance;
    FILE *filePointer;
    filePointer = fopen(MUSICIAN_FILE, "rb");

    if (filePointer == NULL)
    {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        return false;
    }

    std::cout << "DNI de cliente a dar de baja: ";
    std::cin >> dni;

    system("cls");

    int recordIndex = getDniPosition(dni);

    if (recordIndex == -1)
    {
        cout << "NO EXISTE CLIENTE CON ESE DNI" << endl;
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
        std::cout << "EL CLIENTE INGRESADO YA ESTA DADO DE BAJA" << std::endl;
        return false;
    }
    instance.setState(false);
    bool aux = changeRecord(instance, recordIndex);
    return aux;
}

bool MusicianFile::changeAdmissionDate()
{
    int dni;

    Musicians instance;
    FILE *filePointer;
    filePointer = fopen(name, "rb");

    if (filePointer == NULL)
    {
        std::cout << "NO SE PUEDE ABRIR EL ARCHIVO" << std::endl;
        return false;
    }

    std::cout << "DNI para cambiar fecha de ingreso" << std::endl;
    std::cin >> dni;

    int recordIndex = getDniPosition(dni);
    if (recordIndex == -1)
    {
        cout << "NO EXISTE CLIENTE CON ESE DNI" << endl;
        return false;
    }

    if (recordIndex == -2)
    {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        return false;
    }

    instance = readRecord(recordIndex);

    if (recordIndex >= 0)
        instance.setAdmissionDate();

    bool aux = changeRecord(instance, recordIndex);
    return aux;
}

Musicians MusicianFile::readRecord(int position)
{
    Musicians obj;
    if (position < 0)
    {
        obj.setDni(-3);
        return obj;
    }

    FILE *filePointer;
    filePointer = fopen(name, "rb");
    if (filePointer == NULL)
    {
        obj.setDni(-2);
        return obj;
    }

    const int size = sizeof obj;
    fseek(filePointer, size * position, 0);
    int aux = fread(&obj, sizeof obj, 1, filePointer);
    fclose(filePointer);

    if (aux == 0)
        obj.setDni(-1);

    return obj;
}

#endif // CLSMUSICIANFILE_H_INCLUDED
