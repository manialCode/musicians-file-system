#ifndef CLSMUSICIANFILE_H_INCLUDED
#define CLSMUSICIANFILE_H_INCLUDED

class MusicianFile
{
private:
    char name[30];

public:
    MusicianFile(const char *name_ = "") { strcpy(this->name, name_); };

    void addRecord();
    void showFile();
    void listByDni();

    Musicians readRecord(int position);
    bool changeAdmissionDate();
    bool changeRecord(Musicians obj, int pos);
    bool toCancel();

    int getDniPosition(int dni);
};

void MusicianFile::addRecord()
{
    Musicians obj;
    FILE *filePointer;
    filePointer = fopen(name, "ab");

    if (filePointer == NULL)
    {
        std::cout << "NO SE PUDO ACCEDER/CREAR EL ARCHIVO" << std::endl;
        return;
    }

    obj.setProperties();
    int objDNI = obj.getDni();

    if (getDniPosition(objDNI) >= 0)
    {
        std::cout << "DNI YA EXISTENTE, CARGA DENEGADA..." << std::endl;
        system("pause");
        fclose(filePointer);
        return;
    }

    if (!(obj.getAdmissionDate().getIsValid()))
    {
        fclose(filePointer);
        return;
    }

    if ((obj.getDepartment() > 0 && obj.getDepartment() < 5) && (obj.getMainInstrument() >= 1 && obj.getMainInstrument() <= 15) && (obj.getMusicType() >= 1 && obj.getMusicType() <= 10))
    {
        fwrite(&obj, sizeof(Musicians), 1, filePointer);
        std::cout << std::endl;
        std::cout << "CARGA EXITOSA" << std::endl;
        system("pause");
    }

    fclose(filePointer);
}

void MusicianFile::showFile()
{
    Musicians obj;
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
    }
    fclose(filePointer);
}

void MusicianFile::listByDni()
{
    int dni;
    Musicians instance;
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
        while (fread(&instance, sizeof instance, 1, filePointer) == 1)
        {
            if (instance.getDni() == dni && instance.getState())
                instance.showProperties();
        }
    }
    else
        std::cout << "Este dni no existe, saliendo" << std::endl;
    fclose(filePointer);
};

int MusicianFile::getDniPosition(int dni)
{
    Musicians obj;
    FILE *filePointer;
    filePointer = fopen(name, "rb");

    int position = 0;

    if (filePointer == NULL)
    {
        fclose(filePointer);
        return -2;
    }

    while (fread(&obj, sizeof obj, 1, filePointer) == 1)
    {
        if (obj.getDni() == dni)
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

bool MusicianFile::changeRecord(Musicians obj, int pos)
{
    FILE *filePointer;
    filePointer = fopen(name, "rb+");

    fseek(filePointer, sizeof obj * pos, 0);
    bool aux = fwrite(&obj, sizeof obj, 1, filePointer);
    fclose(filePointer);

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
