#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

void menuMusicians()
{
    int option;
    bool condition = true;
    MusicianFile musiciansManager(MUSICIAN_FILE);
    Musicians musician;

    while (condition)
    {
        system("cls");
        std::cout << "MENU MÚSICOS" << std::endl;
        std::cout << "------------------" << std::endl;
        std::cout << std::endl;

        std::cout << "1) AGREGAR MÚSICOS" << std::endl;
        std::cout << "2) LISTAR MÚSICO POR DNI" << std::endl;
        std::cout << "3) LISTAR TODOS LOS MÚSICOS" << std::endl;
        std::cout << "4) MODIFICAR FECHA DE INSCRIPCIÓN" << std::endl;
        std::cout << "5) ELIMINAR REGISTRO DE MÚSICO" << std::endl;
        std::cout << std::endl;
        std::cout << "--------------------------------" << std::endl;
        std::cout << std::endl;
        std::cout << "0) SALIR" << std::endl;

        std::cout << std::endl;
        std::cout << "Ingresa tu opción: ";
        std::cin >> option;

        switch (option)
        {
        case 1:
            system("cls");
            musiciansManager.addRecord();
            break;
        case 2:
            system("cls");
            musiciansManager.listByDni();
            system("pause");
            break;
        case 3:
            system("cls");
            musiciansManager.showFile(musician, 1);
            system("pause");
            break;
        case 4:
            system("cls");
            std::cout << std::endl;

            if (musiciansManager.changeAdmissionDate())
                std::cout << "Cambio de fecha de ingreso exitosa" << std::endl;
            else
                std::cout << "Lo sentimos, el cambio no se pudo realizar" << std::endl;

            system("pause");
            break;
        case 5:
            system("cls");
            std::cout << std::endl;

            if (musiciansManager.toCancel())
                std::cout << "Baja exitosa" << std::endl;
            else
                std::cout << "Lo sentimos, la baja no se pudo realizar" << std::endl;

            system("pause");
            break;
        case 0:
            condition = false;
            std::cout << std::endl;
            std::cout << "SALIENDO DEL MENU `MÚSICOS`" << std::endl;
            std::cout << std::endl;
            break;
        default:
            break;
        }
    }
}

void genreMenu()
{

    int op = 1;
    bool condition = true;
    GenreFile genreManager(GENRES_FILE);
    Genre genre;

    while (condition)
    {
        system("cls");
        cout << "         MENU GÉNEROS-";
        cout << endl;
        cout << "-------------------------------";
        cout << endl;
        cout << "1) AGREGAR GENERO";
        cout << endl;
        cout << "2) LISTAR GENERO POR ID";
        cout << endl;
        cout << "3) LISTAR TODO";
        cout << endl;
        cout << "4) MODIFICAR AÑO DE ORIGEN";
        cout << endl;
        cout << "5) ELIMINAR REGISTRO";
        cout << endl;
        cout << "-------------------------------";
        cout << endl;
        cout << "0) VOLVER AL MENU PRINCIPAL";
        cout << endl;
        cout << endl;
        cout << "INGRESE OPCIÓN: ";
        cin >> op;

        switch (op)
        {

        case 1:
            system("cls");
            genreManager.addRecord();
            system("pause");
            break;
        case 2:
            system("cls");
            genreManager.listByID();
            system("pause");
            break;
        case 3:
            system("cls");
            genreManager.showFile(genre, 2);
            system("pause");
            break;

        case 4:
            system("cls");
            if (genreManager.changeOriginDate())
                std::cout << "Cambio de fecha exitoso" << std::endl;
            else
                std::cout << "No se ah podido realizar el cambio" << std::endl;
            system("pause");
            break;

        case 5:
            system("cls");
            if (genreManager.toCancel())
                std::cout << "Dado de baja con éxito" << std::endl;
            else
                std::cout << "Ah habido un problema al dar de baja" << std::endl;
            system("pause");
            break;

        case 0:
            condition = false;
            std::cout << std::endl;
            std::cout << "SALIENDO DEL MENU `GENEROS`" << std::endl;
            std::cout << std::endl;

        default:
            break;
        }
    }
}

void instrumentsMenu()
{
    int op;
    bool condition = true;

    while (condition)
    {
        system("cls");
        cout << "         MENU GÉNEROS-";
        cout << endl;
        cout << "-------------------------------";
        cout << endl;
        cout << "1) AGREGAR GENERO";
        cout << endl;
        cout << "2) LISTAR GENERO POR ID";
        cout << endl;
        cout << "3) LISTAR TODO";
        cout << endl;
        cout << "4) MODIFICAR AÑO DE ORIGEN";
        cout << endl;
        cout << "5) ELIMINAR REGISTRO";
        cout << endl;
        cout << "-------------------------------";
        cout << endl;
        cout << "0) VOLVER AL MENU PRINCIPAL";
        cout << endl;
        cout << endl;
        cout << "INGRESE OPCIÓN: ";
        cin >> op;

        switch (op)
        {

        case 1:
            system("cls");
            //  todo
            system("pause");
            break;
        case 2:
            system("cls");
            //  todo
            system("pause");
            break;
        case 3:
            system("cls");
            //  todo
            system("pause");
            break;

        case 4:
            system("cls");
            //  todo
            break;

        case 5:
            system("cls");
            //  todo
            system("pause");
            break;

        case 0:
            condition = false;
            std::cout << std::endl;
            std::cout << "SALIENDO DEL MENU `INSTRUMENTOS`" << std::endl;
            std::cout << std::endl;

        default:
            break;
        }
    }
}

void countriesMenu()
{
    int op;
    bool condition = true;

    while (condition)
    {
        system("cls");
        cout << "         MENU GÉNEROS-";
        cout << endl;
        cout << "-------------------------------";
        cout << endl;
        cout << "1) AGREGAR GENERO";
        cout << endl;
        cout << "2) LISTAR GENERO POR ID";
        cout << endl;
        cout << "3) LISTAR TODO";
        cout << endl;
        cout << "4) MODIFICAR AÑO DE ORIGEN";
        cout << endl;
        cout << "5) ELIMINAR REGISTRO";
        cout << endl;
        cout << "-------------------------------";
        cout << endl;
        cout << "0) VOLVER AL MENU PRINCIPAL";
        cout << endl;
        cout << endl;
        cout << "INGRESE OPCIÓN: ";
        cin >> op;

        switch (op)
        {

        case 1:
            system("cls");
            //  todo
            system("pause");
            break;
        case 2:
            system("cls");
            //  todo
            system("pause");
            break;
        case 3:
            system("cls");
            //  todo
            system("pause");
            break;

        case 4:
            system("cls");
            //  todo
            break;

        case 5:
            system("cls");
            //  todo
            system("pause");
            break;

        case 0:
            condition = false;
            std::cout << std::endl;
            std::cout << "SALIENDO DEL MENU `PAÍSES`" << std::endl;
            std::cout << std::endl;

        default:
            break;
        }
    }
}

void reportsMenu()
{
    int option;
    bool condition = true;
    BateristFile obj(INSTRUMEN_FILE);

    while (condition)
    {
        system("cls");
        std::cout << "MENU REPORTES" << std::endl;
        std::cout << "------------------" << std::endl;
        std::cout << std::endl;

        std::cout << "1) MOSTRAR PIANISTAS" << std::endl;
        std::cout << "2) PAISES CON MENOS DE 3 GENEROS" << std::endl;
        std::cout << "3) CREAR ARCHIVO DE BATERISTAS" << std::endl;
        std::cout << "4) MOSTRAR ARCHIVO DE BATERISTAS" << std::endl;
        std::cout << std::endl;
        std::cout << "--------------------------------" << std::endl;
        std::cout << std::endl;
        std::cout << "0) FIN DEL PROGRAMA" << std::endl;

        std::cout << std::endl;
        std::cout << "Ingresa tu opción: ";
        std::cin >> option;

        switch (option)
        {
        case 1:
            system("cls");
            showPianist();
            system("pause");
            break;
        case 2:
            system("cls");
            threeCountries();
            system("pause");
            break;
        case 3:
            system("cls");
            obj.createBaterist();
            system("pause");
            break;
        case 4:
            system("cls");
            obj.showFile();
            system("pause");
            break;
        case 0:
            condition = false;
            std::cout << std::endl;
            std::cout << "SALIENDO DEL MENU `REPORTES`" << std::endl;
            std::cout << std::endl;
            system("pause");
            break;
        default:
            break;
        }
    }
}

void configurationMenu()
{
    int option;
    bool condition = true;

    while (condition)
    {
        system("cls");
        std::cout << "MENU CONFIGURACIÓN" << std::endl;
        std::cout << "------------------" << std::endl;
        std::cout << std::endl;

        std::cout << "1) COPIA DE SEGURIDAD DEL ARCHIVO DE MUSICOS" << std::endl;
        std::cout << "2) COPIA DE SEGURIDAD DEL ARCHIVO DE GENEROS" << std::endl;
        std::cout << "3) RESTAURAR EL ARCHIVO DE MUSICOS" << std::endl;
        std::cout << "4) RESTAURAR EL ARCHIVO DE GENEROS" << std::endl;
        std::cout << "5) ESTABLECER DATOS DE INICIO" << std::endl;
        std::cout << std::endl;
        std::cout << "--------------------------------" << std::endl;
        std::cout << std::endl;
        std::cout << "0) VOLVER AL MENU PRINCIPAL" << std::endl;

        std::cout << std::endl;
        std::cout << "Ingresa tu opción: ";
        std::cin >> option;

        switch (option)
        {
        case 1:
            system("cls");
            copyMusicians();
            system("pause");
            break;
        case 2:
            system("cls");
            copyGenres();
            system("pause");
            break;
        case 3:
            system("cls");
            restoreMusicians();
            system("pause");
            break;
        case 4:
            system("cls");
            restoreGenres();
            system("pause");
            break;
        case 5:
            system("cls");
            establishData();
            system("pause");
            break;
        case 0:
            condition = false;
            std::cout << std::endl;
            std::cout << "SALIENDO DEL MENU `CONFIGURACIÓN`" << std::endl;
            break;
        default:
            break;
        }
    }
}

void mainMenu()
{
    int option;
    bool condition = true;

    while (condition)
    {
        system("cls");
        std::cout << "MENU MÚSICOS" << std::endl;
        std::cout << "------------------" << std::endl;
        std::cout << std::endl;

        std::cout << "1) MENU MUSICOS" << std::endl;
        std::cout << "2) MENU GENEROS" << std::endl;
        std::cout << "3) MENU INSTRUMENTOS" << std::endl;
        std::cout << "4) MENU PAÍSES" << std::endl;
        std::cout << "5) REPORTES" << std::endl;
        std::cout << "6) CONFIGURACIÓN" << std::endl;
        std::cout << std::endl;
        std::cout << "--------------------------------" << std::endl;
        std::cout << std::endl;
        std::cout << "0) FIN DEL PROGRAMA" << std::endl;

        std::cout << std::endl;
        std::cout << "Ingresa tu opción: ";
        std::cin >> option;

        switch (option)
        {
        case 1:
            system("cls");
            menuMusicians();
            system("pause");
            break;
        case 2:
            system("cls");
            genreMenu();
            system("pause");
            break;
        case 3:
            system("cls");
            instrumentsMenu();
            system("pause");
            break;
        case 4:
            system("cls");
            countriesMenu();
            system("pause");
            break;
        case 5:
            system("cls");
            reportsMenu();
            system("pause");
            break;
        case 6:
            system("cls");
            configurationMenu();
            system("pause");
            break;
        case 0:
            condition = false;
            std::cout << std::endl;
            std::cout << "FIN DEL PROGRAMA" << std::endl;
            break;
        default:
            break;
        }
    }
};

#endif // MENUS_H_INCLUDED
