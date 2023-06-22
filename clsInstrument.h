#ifndef CLSINSTRUMENT_H_INCLUDED
#define CLSINSTRUMENT_H_INCLUDED

class Instrument
{
private:
    char name[30];
    int id;
    int clasification;
    bool state;

public:
    Instrument(const char *name_ = " ", int clasisfication_ = 0)
    {
        strcpy(this->name, name_);
        this->clasification = clasisfication_;
        this->state = true;
    }

    const char *getName() { return name; };
    int getId() { return id; }
    int getClasification() { return clasification; };
    bool getState() { return state; };

    void setName(const char *name_) { strcpy(this->name, name_); };
    void setId(int x) { id = x; };
    void setClasification(int x) { clasification = x; };
    void setState(bool state_) { state = state_; };

    void showProperties();
    void setProperties();
};
void Instrument::showProperties()
{
    if (state)
    {
        cout << "Id del intrumento: ";
        cout << id;
        cout << endl;
        cout << "Nombre: ";
        cout << name;
        cout << "clasificacion: ";
        cout << clasification;
        cout << endl;
    }
}

void Instrument::setProperties()
{
    int aux;
    cout << "INGRESE NOMBRE DEL INSTRUMENTO: ";
    loadChar(name, 30);
    cout << endl;
    cout << "INGRESE CLASIFICACION: ";
    cin >> aux;
    setClasification(aux);
    cout << endl;
}

#endif // CLSINSTRUMENT_H_INCLUDED
