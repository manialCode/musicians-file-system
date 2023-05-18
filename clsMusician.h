#ifndef CLSMUSICIAN_H_INCLUDED
#define CLSMUSICIAN_H_INCLUDED

class Musicians
{
private:
    int dni,
        department,
        mainInstrument,
        musicType;

    char name[30],
        surname[30],
        email[30],
        phone[30];

    bool state;

    float registration;

    Date admissionDate;

public:
    Musicians(int dni_ = 0, int department_ = 0, int mainInstrument_ = 0, int musicType_ = 0,
              const char *name_ = " ", const char *surname_ = " ", const char *email_ = " ", const char *phone_ = " ", float registration_ = 0)
    {
        this->dni = dni_;
        this->department = department_;
        this->mainInstrument = mainInstrument_;
        this->musicType = musicType_;
        this->state = true;
        this->registration = registration_;
        strcpy(this->name, name_);
        strcpy(this->surname, surname_);
        strcpy(this->email, email_);
        strcpy(this->phone, phone_);
    };

    // Getters
    int getDni() { return dni; };
    int getDepartment() { return department; };
    int getMainInstrument() { return mainInstrument; };
    int getMusicType() { return musicType; };
    const char *getName() { return name; };
    const char *getSurname() { return surname; };
    const char *getEmail() { return email; };
    const char *getPhone() { return phone; };
    float getRegistration() { return registration; };
    bool getState() { return state; };
    Date getAdmissionDate() { return admissionDate; };

    // Setters
    void setDni(int dni_) { this->dni = dni_; };
    void setDepartment(int department_) { this->department = department_; };
    void setMainInstrument(int mainInstrument_) { this->mainInstrument = mainInstrument_; };
    void setMusicType(int musicType_) { this->musicType = musicType_; };
    void setName(const char *name_) { strcpy(this->name, name_); };
    void setSurname(const char *surname_) { strcpy(this->surname, surname_); };
    void setEmail(const char *email_) { strcpy(this->email, email_); };
    void setPhone(const char *phone_) { strcpy(this->phone, phone_); };
    void setRegistration(float registration_) { this->registration = registration_; };
    void setState(bool state_) { this->state = state_; };
    void setAdmissionDate() { this->admissionDate.setProperties(); };

    void setProperties();
    void showProperties();
};

void Musicians::setProperties()
{
    int auxInt;
    char auxChar[30];
    float auxFloat;

    std::cout << " ----INGRESO DE REGISTROS----" << std::endl;
    std::cout << " DNI: ";
    std::cin >> auxInt;
    setDni(auxInt);
    std::cout << std::endl;

    std::cout << " Nombre: ";
    loadChar(auxChar, 30);
    setName(auxChar);
    std::cout << std::endl;

    std::cout << " Apellido: ";
    loadChar(auxChar, 30);
    setSurname(auxChar);
    std::cout << std::endl;

    std::cout << " Email: ";
    loadChar(auxChar, 30);
    setEmail(auxChar);
    std::cout << std::endl;

    std::cout << " Teléfono: ";
    loadChar(auxChar, 30);
    setPhone(auxChar);
    std::cout << std::endl;

    std::cout << " Claustro: ";
    std::cin >> auxInt;
    if (auxInt >= 1 && auxInt <= 4)
        setDepartment(auxInt);
    else
    {
        std::cout << "Lo sentimos, ingreso no valido, saliendo..." << std::endl;
        system("pause");
        return;
    }
    std::cout << std::endl;

    std::cout << " Instrumento Principal: ";
    std::cin >> auxInt;
    if (auxInt >= 1 && auxInt <= 15)
        setMainInstrument(auxInt);
    else
    {
        std::cout << "Lo sentimos, ingreso no valido, saliendo..." << std::endl;
        system("pause");
        return;
    }
    std::cout << std::endl;

    std::cout << " Tipo de música: ";
    std::cin >> auxInt;
    if (auxInt >= 1 && auxInt <= 10)
        setMusicType(auxInt);
    else
    {
        std::cout << "Lo sentimos, ingreso no valido, saliendo..." << std::endl;
        system("pause");
        return;
    }
    std::cout << std::endl;

    std::cout << " Fecha de inscripción: " << std::endl;
    std::cout << std::endl;
    admissionDate.setProperties();
    if (!admissionDate.getIsValid())
        return;

    std::cout << "Matricula$: ";
    std::cin >> auxFloat;
    if (auxFloat >= 0)
        setRegistration(auxFloat);
    else
    {
        std::cout << "Lo sentimos, ingreso no valido, saliendo..." << std::endl;
        system("pause");
        return;
    }
}

void Musicians::showProperties()
{
    if (this->dni > 0)
    {
        std::cout << "DNI: " << this->dni << std::endl;
        std::cout << "NOMBRE: " << this->name << std::endl;
        std::cout << "APELLIDO: " << this->surname << std::endl;
        std::cout << "EMAIL: " << this->email << std::endl;
        std::cout << "TELÉFONO: " << this->phone << std::endl;
        std::cout << "CLAUSTRO: " << this->department << std::endl;
        std::cout << "INSTRUMENTO PRINCIPAL: " << this->mainInstrument << std::endl;
        std::cout << "TIPO DE MÚSICA: " << this->musicType << std::endl;
        std::cout << "FECHA DE INGRESO: ";
        this->admissionDate.showProperties();
        std::cout << "MATRICULA: " << this->registration << std::endl;
        std::cout << std::endl;
    }
}

#endif // CLSMUSICIAN_H_INCLUDED
