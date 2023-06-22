#ifndef CLSCOUNTRY_H_INCLUDED
#define CLSCOUNTRY_H_INCLUDED

class Country
{
private:
    int id;
    char country[30];
    bool state;
    char continent[30];

public:
    Country(const char *country_ = " ", const char *continent_ = " ")
    {
        strcpy(this->country, country_);
        strcpy(this->continent, continent_);
        this->state = true;
    }

    int getId() { return id; };
    bool getState() { return state; };
    char const *getContinent() { return continent; };
    char const *getCountry() { return country; }

    void setId(int x) { id = x; };
    void setState(bool state_) { this->state = state_; };
    void setContinent(const char *continent_) { strcpy(this->continent, continent_); };
    void setCountry(const char *country_) { strcpy(this->country, country_); };

    void showProperties();
    void setProperties();
};
void Country::showProperties()
{
    if (state)
    {
        cout << "Id del pais";
        cout << id;
        cout << endl;
        cout << "Nombre: ";
        cout << country;
        cout << endl;
        cout << "continente: ";
        cout << continent;
        cout << endl;
    }
}
void Country::setProperties()
{
    cout << "INGRESE NOMBRE DEL PAIS: ";
    loadChar(country, 30);
    cout << endl;
    cout << "INGRESE CONTINENTE: ";
    loadChar(continent, 30);
    cout << endl;
}

#endif // CLSCOUNTRY_H_INCLUDED
