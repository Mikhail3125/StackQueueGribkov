#include "Stdafx.h"
using namespace std;
/*
Создать очередь строковых значений, для реализации используя односвязные списки. Реализовать операции добавления (enqueue) 
и удаления (dequeue) элемента из очереди. Добавьте в очередь строки «one», «two», «three», «four» и распечатайте содержимое
очереди. Удалите 2 элемента из очереди, затем добавьте в очередь строку «inf» и распечатайте очередь еще раз.  Найдите 
суммарную длину строк, принадлежащих очереди, кроме первой строки очереди
*/
void midle()
{
	system("cls");
	cout << "\nMidle task level:\n";
	const int count_str = 4;
	string mas_str[count_str] = { "one", "two", "three", "four" };
	queue * _queue_str; 
	_queue_str =  (queue*)malloc(sizeof(struct queue* ));
 	init(_queue_str);
	for (size_t i = 0; i < count_str; i++)
	{
		insert(_queue_str, mas_str[i]);
	}
	print(_queue_str);
	getchar();
}

struct list
{
	string strvar;
	list* next;
};

struct queue
{
	list* front, * tail;
};

string remove( queue* q) 
{
	struct list* temp;
	string strvar;
	if (isempty(q) == 1) {
		printf("Очередь пуста!\n");
		return 0;
	}
	strvar = q->front->strvar;
	temp = q->front;
	q->front = q->front->next;
	free(temp);
	return strvar;
}

void print( queue* q)
{
	 list* h;
	if (isempty(q) == 1) {
		printf("Очередь пуста!\n");
		return;
	}
	for (h = q->front; h != nullptr; h = h->next)
		printf("%s ", h->strvar);
	return;
}


void init(queue* q) 
{
	q->front = nullptr;
	q->tail  = nullptr;
}

int isempty( queue* q) 
{
	if (q->front == 0)
		return 1;
	return 0;
}

void insert( queue* q, string strvar)
{
	if ((q->tail == nullptr) && (q->front == nullptr)) {
		q->tail = push_back(strvar);
		q->front = q->tail;
	}
	else
		q->tail = addelem(q->tail, strvar);
}

list* addelem(list* lst, string strvar)
{
	 list* temp, * p;
	temp = ( list*)malloc(sizeof(list));
	p = lst->next; // сохранение указателя на следующий узел
	lst->next = temp; // предыдущий узел указывает на создаваемый
	temp->strvar = strvar; // сохранение поля данных добавляемого узла
	temp->next = p; // созданный узел указывает на следующий элемент
	return(temp);
}

 list* push_back(string strvar) 
{
	 list* lst;
	// выделение памяти под корень списка
	lst = ( list*)malloc(sizeof( list));
	lst->strvar = strvar;
	lst->next = nullptr; // это последний узел списка
	return(lst);
}

