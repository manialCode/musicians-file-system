#ifndef CLSINTRUMENTFILE_H_INCLUDED
#define CLSINTRUMENTFILE_H_INCLUDED

int InstrumentFileID = 0;

class InstrumentFile : public File
{
private:
    char name[30];

public:
    InstrumentFile(const char *name_) { strcpy(this->name, name_); };

    void addRecord();
    void listByID();

    Instrument readRecord(int position);
    int getIDPosition(int index);

    bool changeName();
    bool toCancel();
};

int InstrumentFile::getIDPosition(int index)
{
    Instrument instrument;
    int pos = 0;
    FILE *file;

    file = fopen(name, "rb");
    if (file == NULL)
    {
        cout << "No se puedo abrir el archivo" << endl;
        return -2;
    }

    int records = countRecords(3);
    if (records > 0)
    {
        for (int i = 0; i < records; i++)
        {
            fread(&instrument, sizeof instrument, 1, file);
            if (instrument.getId() == index)
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

void InstrumentFile::addRecord()
{
    Instrument instrument;
    FILE *file;
    file = fopen(name, "ab");

    if (file == NULL)
    {
        std::cout << "NO SE PUDO ACCEDER/CREAR EL ARCHIVO" << std::endl;
        return;
    }
    instrument.setProperties();
    InstrumentFileID = InstrumentFileID + 1;
    instrument.setId(InstrumentFileID);
    fwrite(&instrument, sizeof(Instrument), 1, file);

    std::cout << endl;

    fclose(file);
}

void InstrumentFile::listByID()
{
    Instrument instrument;
    int instrumentID,
        found = 0;

    std::cout << "INGRESE ID DEL INTRUMENTO: ";
    std::cin >> instrumentID;

    FILE *file;
    file = fopen(name, "rb");

    int records = countRecords(2);
    if (records > 0)
    {
        for (int i = 0; i < records; i++)
        {
            fread(&instrument, sizeof instrument, 1, file);
            if (instrumentID == instrument.getId())
            {
                instrument.showProperties();
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

bool InstrumentFile::changeName()
{
    Instrument instrument;
    int instrumentID;
    char newName[30];

    cout << "INGRESE ID PARA CAMBIAR EL AÑO: ";
    cin >> instrumentID;

    int position = getIDPosition(instrumentID);
    instrument = readRecord(position);

    cout << "INGRESE NOMBRE NUEVO: ";
    loadChar(newName, 30);
    instrument.setName(newName);
    bool aux = changeRecord(instrument, position);

    return aux;
}

bool InstrumentFile::toCancel()
{
    int intrumentID;

    Instrument instrument;
    FILE *filePointer;
    filePointer = fopen(name, "rb");

    if (filePointer == NULL)
    {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        return false;
    }

    std::cout << "ID del genero a dar de baja: ";
    std::cin >> intrumentID;

    system("cls");

    int recordIndex = getIDPosition(intrumentID);

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

    instrument = readRecord(recordIndex);
    if (!(instrument.getState()))
    {
        std::cout << "EL ID INGRESADO YA ESTA DADO DE BAJA" << std::endl;
        return false;
    }
    instrument.setState(false);
    bool aux = changeRecord(instrument, recordIndex);
    return aux;
}

Instrument InstrumentFile::readRecord(int position)
{
    Instrument obj;
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
#endif // CLSINTRUMENTFILE_H_INCLUDED
