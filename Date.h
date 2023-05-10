#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

class Date
{
private:
    int day,
        month,
        year;
    bool isValid;

public:
    Date(int day_ = 1, int month_ = 1, int year_ = 1)
    {
        this->day = day_;
        this->month = month_;
        this->year = year_;
        this->isValid = true;
    };

    // getters
    int getDay() { return day; };
    int getMonth() { return month; };
    int getYear() { return year; };
    int getIsValid() { return isValid; };

    // setters
    void setDay(int loadedDay) { day = loadedDay; };
    void setMonth(int loadedMonth) { month = loadedMonth; };
    void setYear(int loadedYear) { year = loadedYear; };
    void setIsValid(int loadedIsValid) { isValid = loadedIsValid; };

    void setProperties();
    void showProperties();
};

void Date::setProperties()
{
    int aux[3], systemDate[3];
    getSystemDate(systemDate);

    std::cout << "Ingrese el día: ";
    std::cin >> aux[0];
    std::cout << std::endl;

    std::cout << "Ingrese el mes: ";
    std::cin >> aux[1];
    std::cout << std::endl;

    std::cout << "Ingrese el año: ";
    std::cin >> aux[2];
    std::cout << std::endl;

    // *optimización
    if (aux[0] < 1 || aux[0] > 31 || aux[1] < 1 || aux[1] > 12 || aux[2] < 1900 || aux[2] > systemDate[2])
    {
        std::cout << "Fecha invalida, saliendo..." << std::endl;
        setIsValid(false);
        return;
    }

    if (aux[2] > systemDate[2] || (aux[1] > systemDate[1] && aux[2] >= systemDate[2]) || (aux[0] > systemDate[0] && aux[1] >= systemDate[1] && aux[2] >= systemDate[2]))
    {
        std::cout << "Fecha invalida, saliendo..." << std::endl;
        setIsValid(false);
        return;
    }

    setDay(aux[0]);
    setMonth(aux[1]);
    setYear(aux[2]);
}

void Date::showProperties()
{
    std::cout << getDay() << "/" << getMonth() << "/" << getYear() << std::endl;
};

// *Mi validación
// if (aux[0] >= 1 && aux[0] <= 31)
// {
//     if (aux[0] <= systemDate[0] || aux[1] <= systemDate[1])
//         setDay(aux[0]);
// }
// else
// {
//     std::cout << "Fecha invalida, saliendo..." << std::endl;
//     return;
// }

// if (aux[1] >= 1 && aux[1] <= 12)
// {
//     if (aux[1] <= systemDate[1] || aux[2] < systemDate[2])
//         setMonth(aux[1]);
// }
// else
// {
//     std::cout << "Fecha invalida, saliendo..." << std::endl;
//     return;
// }

// if (aux[2] >= 1900 && aux[2] <= systemDate[2])
//     setYear(aux[2]);
// else
// {
//     std::cout << "Fecha invalida, saliendo..." << std::endl;
//     return;
// }

#endif // DATE_H_INCLUDED
