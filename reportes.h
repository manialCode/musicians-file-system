#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

void showPianist()
{

    FILE *pMusicians;
    pMusicians = fopen(MUSICIAN_FILE, "rb");
    Musicians musician;

    if (pMusicians == NULL)
    {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        return;
    }

    while (fread(&musician, sizeof musician, 1, pMusicians) == 1)
    {
        if (musician.getMainInstrument() == 3)
        {
            std::cout << "Nombre: " << musician.getName() << std::endl;
            std::cout << "Apellido: " << musician.getSurname() << std::endl;
            std::cout << "DNI: " << musician.getDni() << std::endl;
            std::cout << "Calustro: " << musician.getDepartment() << std::endl;
        }
    }
    system("pause");

    fclose(pMusicians);
}

void threeCountries()
{
    Genre genre;
    FILE *pGenre;
    pGenre = fopen(GENRES_FILE, "rb");
    if (pGenre == NULL)

    {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        return;
    }

    int countries[100]{0};

    while (fread(&genre, sizeof(Genre), 1, pGenre) == 1)
    {
        for (int i = 0; i < 100; i++)
        {
            if (genre.getCountry() == (i + 1))
                countries[i]++;
        }
    }
    fclose(pGenre);

    std::cout << "Países con menos de tres generos" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        if (countries[i] < 3)
            std::cout << "Pais " << i + 1 << std::endl;
    }
}

const char *INSTRUMEN_FILE = "Intrumentos.dat";
class Baterist
{
private:
    int dni;
    char name[30], surname[30], phone[30];

public:
    void setDni(int dni_) { this->dni = dni_; }
    void setPhone(const char *phone_) { strcpy(this->phone, phone_); }
    void setName(const char *name_) { strcpy(this->name, name_); }
    void setSurname(const char *surname_) { strcpy(this->surname, surname_); }

    int getDni() { return dni; }
    const char *getPhone() { return phone; }
    const char *getName() { return name; }
    const char *getSurname() { return surname; }

    void showProperties()
    {
        std::cout << "Nombre: " << name << std::endl;
        std::cout << "Apellido: " << surname << std::endl;
        std::cout << "DNI: " << dni << std::endl;
        std::cout << "Telefono: " << phone << std::endl;
    }
};

class BateristFile
{
private:
    char name[30];

public:
    BateristFile(const char *name_) { strcpy(this->name, name_); };

    void createBaterist();
    void showFile();
};

void BateristFile::createBaterist()
{
    Baterist baterist;
    FILE *pBaterist;
    pBaterist = fopen(name, "ap");

    FILE *pMusicians;
    pMusicians = fopen(MUSICIAN_FILE, "rb");
    Musicians musician;

    if (pMusicians == NULL || pBaterist == NULL)
    {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        return;
    }

    while (fread(&musician, sizeof musician, 1, pMusicians) == 1)
    {
        if (musician.getMainInstrument() == 3)
        {
            baterist.setName(musician.getName());
            baterist.setSurname(musician.getSurname());
            baterist.setDni(musician.getDni());
            baterist.setPhone(musician.getPhone());
        }
    }

    fwrite(&baterist, sizeof(Baterist), 1, pBaterist);
    fclose(pBaterist);
    fclose(pMusicians);
}

void BateristFile::showFile()
{
    Baterist obj;
    FILE *filePointer;
    filePointer = fopen(name, "rb");
    if (filePointer == NULL)
    {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        return;
    }

    while (fread(&obj, sizeof obj, 1, filePointer) == 1)
    {
        obj.showProperties();
    }
    fclose(filePointer);
}

#endif // REPORTES_H_INCLUDED
