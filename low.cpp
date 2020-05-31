#include "Stdafx.h"
#include "low.h"

using namespace std;

/*
Создать очередь из вещественных чисел. Определить минимальный элемент очереди. Организовать просмотр 
данных очереди
*/

void low()
{
	system("cls");
	cout << "\nLow level task: \n";
	queue* q;
	q = (queue*)malloc(sizeof(queue*));
	init(q);
	int count = 10 + rand() % 20;
	cout << "\nКоличество значений очереди: " << count <<" Значения очереди: \n";
	for (size_t i = 0; i < count; i++)
	{
		insert(q, 0.3 + (rand() % 100) / 12.1);
	}
	print(q);
	double min = min_elem(q);
	printf("\nМинимальный элемент очереди -> %1.1f\n", min); 
	cout << "Нажмите Enter для завершения...";
	while(getchar() != '\n')
		continue;
}
struct list
{
	double digit;
	list* next;
};

struct queue
{
	list* front, * tail;
};
double min_elem(queue* q)
{
	list* h;
	if (isempty(q) == 1) {
		printf("Очередь пуста!\n");
		return 0.0;
	}
	double min = 1000.0;
	for (h = q->front; h != nullptr; h = h->next)
		if (h->digit < min)
			min = h->digit;
	return min;
}
double remove(queue* q)
{
	struct list* temp;
	double digit;
	if (isempty(q) == 1) {
		printf("Очередь пуста!\n");
		return 0;
	}
	digit = q->front->digit;
	temp = q->front;
	q->front = q->front->next;
	free(temp);
	return digit;
}

void print(queue* q)
{
	list* h;
	if (isempty(q) == 1) {
		printf("Очередь пуста!\n");
		return;
	}
	for (h = q->front; h != nullptr; h = h->next)
		printf("%1.1f ", h->digit);
	return;
}


void init(queue* q)
{
	q->front = nullptr;
	q->tail = nullptr;
}

int isempty(queue* q)
{
	if (q->front == nullptr)
		return 1;
	return 0;
}

void insert(queue* q, double digit)
{
	if ((q->tail == nullptr) && (q->front == nullptr)) {
		q->tail = push_back(digit);
		q->front = q->tail;
	}
	else
		q->tail = addelem(q->tail, digit);
}

list* addelem(list* lst, double digit)
{
	list* temp, * p;
	temp = (list*)malloc(sizeof(list));
	p = lst->next; // сохранение указателя на следующий узел
	lst->next = temp; // предыдущий узел указывает на создаваемый
	temp->digit = digit; // сохранение поля данных добавляемого узла
	temp->next = p; // созданный узел указывает на следующий элемент
	return(temp);
}

list* push_back(double digit)
{
	list* lst;
	// выделение памяти под корень списка
	lst = (list*)malloc(sizeof(list));
	lst->digit = digit;
	lst->next = nullptr; // это последний узел списка
	return(lst);
}



