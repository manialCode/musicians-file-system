#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

void loadChar(char *word, int size)
{
    int i;
    fflush(stdin);
    for (i = 0; i < size; i++)
    {
        word[i] = cin.get();
        if (word[i] == '\n')
            break;
    }
    word[i] = '\0';
    fflush(stdin);
}

void getSystemDate(int date[])
{
    time_t timeHolder;
    struct tm *tmPtr;

    timeHolder = time(NULL);
    tmPtr = localtime(&timeHolder);

    date[0] = tmPtr->tm_mday;        // Día del mes
    date[1] = tmPtr->tm_mon + 1;     // Mes (se suma 1 porque enero es 0)
    date[2] = tmPtr->tm_year + 1900; // Año (se suma 1900)
}

#endif // FUNCTIONS_H_INCLUDED
