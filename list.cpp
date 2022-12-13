#include <iostream>
#include "list.hpp"
#include <windows.h>


#define MAXTAM 5

using namespace std;

//aqui iremos usar algumas funçoes da TAD de lista duplamente encadeada e lista encadeada
//criando lista encadeada simples
void CreateEmptyList(List *list)
{
    if (!Created)
    {
        list->First = new Element;
        list->Last = list->First;
        list->Last->next = NULL;
        Created = true;
    }
    Sleep(1500);
}
//verificando se ela esta vazia
bool VerifyEmptyList(List *list)
{
    return (list->First == list->Last);
}
//verificando o tamanho dela
int ListSize(List *list)
{
    return list->Size;
}
//inserindo apos o primeiro item
void InsertFirst(List *list, Item *item)
{
    Point aux;
    aux = list->First->next;
    list->First->next = new Element;
    list->First->next->next = aux;
    list->First->next->item = *item;
    list->Size++;
    UpdateLast(list);
}
//atualizando o ultimo, sendo extremamente necessário para saber qual é o primeiro e ultimo da lista a todo momento
void UpdateLast(List *list)
{
    Point aux;
    aux = list->First;
    while (aux->next != NULL)
    {
        aux = aux->next;
    }
    list->Last = aux;
}
//inserindo elemento por ultimo
void InsertLast(List *list, Item *item)
{
    list->Last->next = new Element;
    list->Last = list->Last->next;
    list->Last->item = *item;
    list->Last->next = NULL;
    list->Size++;
}
//inserindo apos um id escolhido, aqui apos o usuário escolher um id o programa percorre a lista inteira até encontrar o id digitado se achar insere o elemento apos ele
void InsertAfterID(List *list, Item *item, int id)
{
    Point aux, pAux, x;
    bool find = false;
    pAux = list->First->next;
    while (pAux != NULL)
    {
        if (pAux->item.id == id)
        {
            find = true;
            x = pAux;
            aux = x->next;
            x->next = new Element;
            x->next->next = aux;
            x->next->item = *item;
            break;
        }
        pAux = pAux->next;
    }
    if (find)
    {
        cout << "Item inserted succesfully!";
        UpdateLast(list);
        list->Size++;
    }
    else
    {
        cout << "Previous element not found.";
    }
}
//imprime a lista
void PrintList(List list)
{
    if (VerifyEmptyList(&list))
    {
        cout << "list vazia!\n";
        Sleep(1000);
        return;
    }
    Point aux;
    aux = list.First->next;
    while (aux != NULL)
    {
        cout << "ID: " << aux->item.id << endl;
        cout << "Name: " << aux->item.name << endl
             << endl;
        aux = aux->next;
    }
    system("pause");
}
//procura item
Point SearchItem(List *list, int id)
{
    Point aux;
    aux = list->First->next;
    while (aux != NULL)
    {
        if (aux->item.id == id)
        {
            return aux;
        }
        aux = aux->next;
    }
    return aux;
}
//imprime item
void PrintItem(List *list, int id)
{
    Point aux;
    aux = list->First->next;
    while (aux != NULL)
    {
        if (aux->item.id == id)
        {
            cout << "ID: " << aux->item.id << endl;
            cout << "Name: " << aux->item.name << endl
                 << endl;
            break;
        }
        aux = aux->next;
    }
}
//aqui o item recebido
void PrintReceivedItem(Item item)
{
    cout << "ID: " << item.id << endl;
    cout << "Company: " << item.company << endl;
}
//remove o primeiro elemento da lista
void RemoveFirst(List *list)
{
    if (VerifyEmptyList(list))
    {
        return;
    }
    Point aux;
    aux = list->First->next;
    list->First->next = aux->next;
    delete aux;
    list->Size--;
}
//remove o ultimo elemento da lista
void RemoveLast(List *list)
{
    if (VerifyEmptyList(list))
    {
        return;
    }
    Point aux, current;
    current = list->First->next;
    aux = list->Last;
    while (current->next != list->Last)
    {
        current = current->next;
    }
    current->next = NULL;
    list->Last = current;
    delete aux;
    list->Size--;
}
//remove o item de acordo com o id digitado
void RemoveID(List *list, int id)
{
    if (VerifyEmptyList(list))
    {
        return;
    }

    Point aux, prevrior, x;

    x = list->First;

    while (x != NULL)
    {
        if (x->next->item.id == id)
        {
            prevrior = x;
            break;
        }
        x = x->next;
    }
    aux = prevrior->next;
    prevrior->next = aux->next;
    delete aux;
    list->Size--;
    UpdateLast(list);
}
//aqui começa a TAD de lista duplamente encadeada
//criando a lista
void CreateEmptyList2(List2 *list)
{
    list->First = new Element2;
    list->Last = list->First;
    list->Last->next = list->Last;
    list->Last->prev = list->Last;
    list->Size = 0;
}
//verificando se está vazia
bool VerifyEmptyList2(List2 *list)
{
    if (list->Size == 0 && list->Last == list->First)
    {
        return true;
    }
    return false;
}
//inserindo o ultimo elemento
void InsertLast2(List2 *list, Item2 item)
{
    list->Last->next = new Element2;
    list->Last->next->prev = list->Last;
    list->Last = list->Last->next;
    list->Last->item = item;
    list->Last->next = list->First;
    list->First->prev = list->Last;
    list->Size++;
}
//inserindo o primeiro elemento
void InsertFirst2(List2 *list, Item2 item)
{
    Point2 inserted = new Element2;
    inserted->item = item;

    inserted->next = list->First->next;
    inserted->prev = list->First;
    list->First->next->prev = inserted;
    list->First->next = inserted;
    list->Size++;
}
//inserindo apos o ID desejado
void InsertAfterID2(List2 *list, Item2 item, int id)
{
    Point2 current = FindID2(list, id);

    if (current == NULL)
    {
        cout << "\nChosen city does not exist.\n" << endl;
        return;
    }
    else
    {
        cout << "\nStop chosen.\n";
        return;
    }

    Point2 inserted = new Element2;
    inserted->item = item;

    if (current == list->Last)
    {
        InsertLast2(list, item);
    }
    else
    {
        inserted->next = current->next;
        inserted->prev = current;
        inserted->next->prev = inserted;
    }
    current->next = inserted;
    list->Size++;
}
//procurando o id desajado na lista
Point2 FindID2(List2 *list, int id)
{
    Point2 aux = list->First->next;
    while (aux != list->First)
    {
        if (aux->item.id == id)
        {
            return aux;
        }
        aux = aux->next;
    }
    return NULL;
}
//reomve o id na lista
Item2 RemoveID2(List2 *list, int id)
{
    Item2 ReturnTrip;
    ReturnTrip.id = -1;

    if (VerifyEmptyList2(list))
    {
        return ReturnTrip;
    }
    Point2 current = FindID2(list, id);

    if (current != list->First)
    {
        
        current->prev->next = current->next;

        //se for o ultimo ele atualiza o prev
        if (current == list->Last)
        {
            list->Last = current->prev;
            list->First->prev = list->Last;
        }
        //se não o current vira o prev
        else
        {
            current->next->prev = current->prev;
        }

        ReturnTrip = current->item;
        delete current;
    }
    list->Size--;
    return ReturnTrip;
}
//imprime um item
void PrintItem2(Item2 item)
{
    if (item.id == -1)
    {
        cout << "Item does not exist!" << endl;
        return;
    }

    cout << "ID: " << item.id << endl;
    cout << "City: " << item.city << endl;
    cout << "Arrival: " << item.time << endl;
    cout << "Exit: " << item.time2 << endl;
    cout << "Ticket Price: " << item.ticket << endl;
    cout << endl;
}
//imprime a lista
void PrintList2(List2 *list)
{
    Point2 aux = list->First->next;
    while (aux != list->First)
    {
        PrintItem2(aux->item);
        aux = aux->next;
    }
}
//imprime o oposto da lista
void PrintOpposite2(List2 *list)
{
    Point2 aux = list->Last;
    while (aux != list->First)
    {
        PrintItem2(aux->item);
        aux = aux->prev;
    }
}
//criando o menu
void Menu()
{
    cout << "1. Bus Station Menu.\n";
    cout << "2. Maintenance Menu\n";
    cout << "3. Leave\n\n";
}
//aqui iremos deixar uma rota já pré-definida apra facilitar no uso do programa
//deixando definido qaul os lugares e preços que o onibus passa
void Autofill(List *lines, int *id)
{
    Item item;
    item.id = *id;
    *id += 1;
    item.name = "SJE-BH";
    item.company = "Passaro Verde";

    CreateEmptyList2(&item.stops);

    Item2 stop;

    stop.id = item.idStop;
    item.idStop++;
    stop.time = "00:00";
    stop.time2 = "00:40";
    stop.city = "SJE";
    stop.ticket = 0;

    InsertLast2(&item.stops, stop);

    stop.id = item.idStop;
    item.idStop++;
    stop.time = "01:00";
    stop.time2 = "01:30";
    stop.city = "GHS";
    stop.ticket = 16.60;

    InsertLast2(&item.stops, stop);

    stop.id = item.idStop;
    item.idStop++;
    stop.time = "04:30";
    stop.time2 = "04:45";
    stop.city = "ITA";
    stop.ticket = 61.80;

    InsertLast2(&item.stops, stop);

    stop.id = item.idStop;
    item.idStop++;
    stop.time = "05:30";
    stop.time2 = "05:45";
    stop.city = "BH";
    stop.ticket = 49.05;

    InsertLast2(&item.stops, stop);

    InsertLast(lines, &item);
}
//aqui o programa procura uma linha que o usuário queira procurar, podendo pesquisar por código ou por cidade
void FindLine(List *lines)
{
    int op;
    while (op != 1 && op != 2 && op != 3)
    {
        cout << "1. Search city\n";
        cout << "2. Search for ID\n";
        cout << "3. Return\n";
        cout << "\nOption: ";
        cin >> op;
        system("cls");
    }

    if (op == 1)
    {
        float price = 0;
        int routes = 0; 

        bool OriginFind = false;
        bool DestinationFind = false;

        cout << "Type your city of origin: ";
        string origin;
        cin >> origin;
        cout << "Type your destination: ";
        string destination;
        cin >> destination;

        Point line = lines->First->next;
        Point2 aOrigin;
        Point2 aDestination;

        //aqui o programa percorre todas as linhas para achar a escolhida
        while (line != NULL)
        {
            aDestination = line->item.stops.First->next;

            while (aDestination != line->item.stops.First) // Percorre as stops.
            {
                if (aDestination->item.city == destination)
                {
                    DestinationFind = true;
                    aOrigin = aDestination;
                    price = 0;
                    //o while sempre começa pela cidade de destino para achar a origem
                    while (aOrigin != line->item.stops.First) 
                    {
                        if (aOrigin->item.city == origin)
                        {
                            OriginFind = true;
                            system("cls");
                            PrintReceivedItem(line->item);
                            cout << endl;
                            cout << "Ticket Price: " << price << endl;
                            cout << "Time of Departure: " << aOrigin->item.time2 << endl;
                            cout << "Time of Arrival: " << aDestination->item.time << endl;
                            cout << endl
                                 << endl;
                            routes++;
                        }
                        price += aOrigin->item.ticket;
                        aOrigin = aOrigin->prev;
                    }
                }
                aDestination = aDestination->next;
            }
            line = line->next;
        }
        //aqui é a mensagem de erro se nao achar a origem
        if (!OriginFind)
        {
            cout << "\nOrigin not found.\n\n";
        }
        //e aqui se não achar o destino
        if (!DestinationFind)
        {
            cout << "\nDestination not found.\n\n";
        }
        if (routes == 0 && !OriginFind && !DestinationFind)
        {
            cout << "\nLine not found.\n\n";
        }
        system("pause");
        system("cls");
        return;
    }
    //aqui o programa repete o processo porém pesquisando pelo id digitado
    if (op == 2)
    {
        cout << "Insert the line ID: ";
        Point aux;
        int id;
        cin >> id;

        aux = SearchItem(lines, id);

        if (aux == NULL)
        {
            cout << "Line not found";
        }
        PrintReceivedItem(aux->item);
        cout << endl;

        cout << "Chosen city does not belong in line.\n\n";
        PrintList2(&aux->item.stops);
        system("pause");
        system("cls");
    }
    if (op == 3)
    {
        return;
    }
}
//aqui o usuário pode incluir uma nova linha do onibus
void IncludeLine(List *lines, int *id)
{
    Item line;
    line.id = *id;

    cout << "Insert the name of the company: ";
    cin >> line.company;

    cout << "Insert the ID of the line: ";
    cin >> line.line;

    cout << "\n\nLine Created.\n\n";

    CreateEmptyList2(&line.stops);
    InsertLast(lines, &line);

    *id += 1;
}
//aqui adiciona os pontos de parada do onibus
void IncludeStop(List *lines)
{
    int id;

    cout << "Insert the ID of the line you wish to add a stop to: ";
    cin >> id;

    Point aux = SearchItem(lines, id);
    while (aux == NULL)
    {
        cout << "Line not found.\n\n";
    }

    Item2 stop;

    stop.id = aux->item.idStop;
    aux->item.idStop++;

    cout << "Insert the City ID: ";
    cin >> stop.city;
    cout << "Insert the time at which the bus will arrive: ";
    cin >> stop.time;
    cout << "Insert the time at which the bus will leave: ";
    cin >> stop.time2;
    cout << "Insert the ticket price: ";
    cin >> stop.ticket;

    if (VerifyEmptyList2(&aux->item.stops))
    {
        cout << "line without stops.\n\n";
        cout << "A stop was inserted.\n\n";

        InsertLast2(&aux->item.stops, stop);

        return;
    }
    PrintList2(&aux->item.stops);

    cout << "Where do you wish to insert a stop? (Type ''0'' to insert it in the very beginning).\n";
    cout << "ID: ";
    cin >> id;

    if (id == 0)
    {
        InsertFirst2(&aux->item.stops, stop);
        cout << "\nStop added.\n\n";
        return;
    }
    InsertAfterID2(&aux->item.stops, stop, id);
}
//nessa parte o programa dá a opção de editar uma parada já definida ou após ser criada
void ChangeStop(List *lines)
{
    int id;

    cout << "Insert the ID of the line where you wish to change a stop: ";
    cin >> id;

    Point aux = SearchItem(lines, id);

    if (aux == NULL)
    {
        cout << "\nLine not found.\n\n";
        return;
    }

    if (VerifyEmptyList2(&aux->item.stops))
    {
        cout << "\nLine without stops.\n\n";
        return;
    }

    PrintList2(&aux->item.stops);

    cout << "ID of the stop you wish to change: ";
    cin >> id;

    Point2 aux2 = FindID2(&aux->item.stops, id);

    if (aux2 == NULL)
    {
        cout << "\nStop not found.\n\n";
        return;
    }

    cout << "Before alterations:\n\n";

    PrintItem2(aux2->item);

    cout << "Insert the city code: ";
    cin >> aux2->item.city;
    cout << "Insert the time at which the bus will arrive: ";
    cin >> aux2->item.time;
    cout << "Insert the time at which the bus will leave: ";
    cin >> aux2->item.time2;
    cout << "Insert the ticket price ";
    cin >> aux2->item.ticket;
}
//aqui o usuário pode remover uma parada do onibus, caso o onibus não pare mais naquela cidade
void RemoveStop(List *lines)
{
    int id;

    cout << "Insert the ID of the line you wish to remove: ";
    cin >> id;

    Point aux = SearchItem(lines, id);

    if (aux == NULL)
    {
        cout << "\nLine not found.\n\n";
        return;
    }

    if (VerifyEmptyList2(&aux->item.stops))
    {
        cout << "\nLine without stops.\n\n";
        return;
    }

    PrintList2(&aux->item.stops);

    cout << "ID of the stop you wish to remove: ";
    cin >> id;

    Point2 aux2 = FindID2(&aux->item.stops, id);

    if (aux2 == NULL)
    {
        cout << "\nStop not found.\n\n";
        return;
    }

    RemoveID2(&aux->item.stops, id);
    cout << "\nStop removed from line.\n\n";
}
//aqui o usuário pode remover uma linha inteira
void RemoveLine(List *lines)
{
    int id;

    cout << "Insert the ID of the line you wish to remove: ";
    cin >> id;

    Point aux = SearchItem(lines, id);

    if (aux == NULL)
    {
        cout << "\nLine not found.\n\n";
        return;
    }

    RemoveID(lines, id);
    cout << "\nLine removed.\n\n";
}
//esse é o menu da manuteção onde o único usuário que tem acesso a esse menu é aquele que gerencia as linhas
//nesse menu ele possui acesso a todas as funções citadas acima
void Maintenance(List *lines, int *id)
{
    int op;

    while (op != 6)
    {
        cout << "1. Add new line\n";
        cout << "2. Include new stop in line\n";
        cout << "3. Change a stop\n";
        cout << "4. Remove a stop\n";
        cout << "5. Remove a line\n";
        cout << "6. Return\n\n";
        cout << "Option: ";

        cin >> op;

        cout << "\n\n";

        switch (op)
        {
        case 1:
            system("cls");
            IncludeLine(lines, id);
            break;

        case 2:
            system("cls");
            IncludeStop(lines);
            break;

        case 3:
            system("cls");
            ChangeStop(lines);
            break;

        case 4:
            system("cls");
            RemoveStop(lines);
            break;

        case 5:
            system("cls");
            RemoveLine(lines);
            break;

        default:
            break;
        }
        system("pause");
        system("cls");
    }
}
