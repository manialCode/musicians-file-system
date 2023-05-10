#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

void menuMusicians()
{
    int option;
    bool condition = true;
    MusicianFile musiciansManager(MUSICIAN_FILE);

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
            musiciansManager.showFile();
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
            system("pause");
            break;
        default:
            break;
        }
    }
}

#endif // MENUS_H_INCLUDED
