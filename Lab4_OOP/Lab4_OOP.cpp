#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class PrintedMaterial
{
public:
    string name;
    int pages;

    PrintedMaterial() : name(""), pages(0) {}
    PrintedMaterial(string str, int pagesCount) : name(str), pages(pagesCount) {}

    ~PrintedMaterial() {}
};


class Newspaper : public PrintedMaterial 
{
public:
    float pageSize;
    int copies;
    int publicationFrequency; //per week

    Newspaper() : PrintedMaterial(), pageSize(0), copies(0), publicationFrequency(0) {}
    Newspaper(string str, int pagesCount, float size, int copiesCount, int frequency) : PrintedMaterial(str, pagesCount), 
            pageSize(size), copies(copiesCount), publicationFrequency(frequency) {}
    
    ~Newspaper() {}

    float PaperUsedPerWeek()
    {
        return (pages * pageSize * publicationFrequency);
    }
};

void PrintPaperUsed(Newspaper materials[], int count);
void SortByPaperUsed(Newspaper materials[], int count);

void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Newspaper newspapers[] =
    {
        Newspaper("Бізнес", 20, 0.26f, 1000, 3),
        Newspaper("Культура і життя", 16, 0.17f, 850, 2),
        Newspaper("Добрий господар", 30, 0.21f, 770, 1),
        Newspaper("День", 25, 0.19f, 1120, 2),
    };

    int count = sizeof(newspapers) / sizeof(Newspaper);

    PrintPaperUsed(newspapers, count);

    SortByPaperUsed(newspapers, count);
    puts("\nВідсортований список:");
    PrintPaperUsed(newspapers, count);

    system("pause");
}

void PrintPaperUsed(Newspaper newspapers[], int count)
{
    float totalPaperUsed = 0;

    puts("\nКількість використаного паперу в тиждень на кожну газету (у м.кв.):");
    puts("-------------------------------------------------------------------");
    for (int i = 0; i < count; i++)
    {
        float paperUsed = newspapers[i].PaperUsedPerWeek();
        cout << "Газета: " << newspapers[i].name << " - " << paperUsed << " м.кв на одну газету" 
            << "; " << paperUsed * newspapers[i].copies << " м.кв на всі примірники" << endl;

        totalPaperUsed += paperUsed * newspapers[i].copies;
    }
    puts("-------------------------------------------------------------------");

    cout << endl <<  "Загальна к-сть використаного паперу на всі примірники: " << totalPaperUsed << " м.кв" << endl << endl;
}

void SortByPaperUsed(Newspaper newspapers[], int count)
{
    Newspaper temp;
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (newspapers[i].PaperUsedPerWeek() >= newspapers[j].PaperUsedPerWeek())
            {
                temp = newspapers[i];
                newspapers[i] = newspapers[j];
                newspapers[j] = temp;
            }
        }
    }
}