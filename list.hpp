#include <iostream>
#ifndef LISTA_H
#define LISTA_H

using namespace std;
//TAD para lista encadeada
typedef struct Element2 *Point2;

struct List2
{
    Point2 First;
    Point2 Last;
    int Size;
};
//Definindo as variaveis necessárias para fazer as operações
typedef struct Item
{
    int id = 1;
    int idStop = 0;
    string name;
    string line;
    string company;
    List2 stops;
};

typedef struct Element *Point;

typedef struct Element
{
    Item item;
    Point next;
};
//TAD de lista simples
typedef struct List
{
    Point First;
    Point Last;
    int Size = 0;
};

struct Item2
{
    int id;
    string city;
    string time;
    string time2;
    float ticket;
};



struct Element2
{
    Point2 prev;
    Item2 item;
    Point2 next;
};




bool Created = false;
//declarando as funções
void CreateEmptyList(List *list);
bool VerifyEmptyList(List *list);
int ListSize(List *list);
void InsertFirst(List *list, Item *item);
void UpdateLast(List *list);
void InsertLast(List *list, Item *item);
void InsertAfterID(List *list, Item *item, int id);
void PrintList(List list);
Point SearchItem(List *list, int id);
void PrintItem(List *list, int id);
void PrintReceivedItem(Item item);
void RemoveFirst(List *list);
void RemoveLast(List *list);
void RemoveID(List *list, int id);
void CreateEmptyList2(List2 *list);
bool VerifyEmptyList2(List2 *list);
void InsertLast2(List2 *list, Item2 item);
void InsertFirst2(List2 *list, Item2 item);
void InsertAfterID2(List2 *list, Item2 item, int id);
Point2 FindID2(List2 *list, int id);
Item2 RemoveID2(List2 *list, int id);
void PrintItem2(Item2 item);
void PrintList2(List2 *list);
void PrintOpposite2(List2 *list);
void Menu();
void Autofill(List *lines, int *id);
void FindLine(List *lines);
void IncludeStop(List *lines);
void ChangeStop(List *lines);
void RemoveStop(List *lines);
void RemoveLine(List *lines);
void Maintenance(List *lines, int *id);

#endif