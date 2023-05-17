#ifndef CLSGENRE_H_INCLUDED
#define CLSGENRE_H_INCLUDED

class Genre
{
private:
    char name[30];
    int genreID;
    int country;
    int year;
    bool state;

public:
    Genre(const char *name_ = " ", int country_ = 0, int year_ = 0)
    {
        this->state = true;
        this->year = year_;
        this->country = country_;
        strcpy(this->name, name_);
    }

    void setCountry(int x)
    {
        if (x >= 1 && x <= 100)
            this->country = x;
    }

    void setYear(int x)
    {
        if (x >= 1500 and x <= 2023)
            this->year = x;
    }

    void setId(int x) { this->genreID = x; };

    void setState(bool x) { this->state = x; };

    void setProperties();
    void showProperties();

    int getId() { return genreID; }
    int getYear() { return year; }
    bool getState() { return state; }
    int getCountry() { return country; }
};

// int id = 0;
void Genre::setProperties()
{
    int aux;
    std::cout << "INGRESE NOMBRE DEL GENre: ";
    loadChar(name, 30);
    std::cout << endl;

    // id++;
    // setId(id);

    std::cout << "INGRESE country DE ORIGEN (ENTRE 1 Y 100): ";
    cin >> aux;
    setCountry(aux);
    std::cout << endl;

    std::cout << "INGRESE EL AÑO (ENTRE 1500 Y 2023): ";
    cin >> aux;
    setYear(aux);
    state = true;
    std::cout << endl;
}

void Genre::showProperties()
{
    if (state && this->genreID > 0)
    {
        std::cout << "Id de Genero musical : ";
        std::cout << genreID;
        std::cout << endl;
        std::cout << "Nombre: ";
        std::cout << name;
        std::cout << endl;
        std::cout << "country de origen: ";
        std::cout << country;
        std::cout << endl;
        std::cout << "Año de origen: ";
        std::cout << year;
        std::cout << endl;
    }
    std::cout << endl;
}

#endif // CLSGENRE_H_INCLUDED
