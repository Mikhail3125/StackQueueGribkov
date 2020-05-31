#include "Stdafx.h"
#include "hard.h"
using namespace std;

/*
Дано число N (> 0) и две непустые очереди; адреса начала и конца первой равны P1 и P2, а второй — P3 
и P4. Переместить N начальных элементов первой очереди в конец второй очереди. Если первая очередь 
содержит менее N элементов, то переместить из первой очереди во вторую все элементы. Вывести новые 
адреса начала и конца первой, а затем второй очереди (для пустой очереди дважды вывести null). 
Операции выделения и освобождения памяти не использовать
*/

struct queue
{
	list* tail, * front;
	int count = 0;
};

struct list
{
	int digit;
	list* next;
};
void hard()
{
	system("cls");
	cout << "\nHard level task: \n";

	///<Исходные данные>
	int N = 1;  
		cout << "\nN = " << N <<"\n";

	queue* q1 = (queue*)malloc(sizeof(queue*)),	
		 * q2 = (queue*)malloc(sizeof(queue*));
	   enq(q1); enq(q2);
	   int count_first_q = 4,//1 + rand() % 10,
		   count_secnd_q = 5;//1 + rand() % 10;
	q1->count = count_first_q, q2->count = count_secnd_q;

	FillQueue(q1, count_first_q); 	FillQueue(q2, count_secnd_q);
	cout << "\nЭлементы 1-ой очереди: \n";
	Show(q1); cout << endl; 
	cout << "\nЭлементы 2-ой очереди: \n";
	Show(q2);
	list* P1 = q1->front, * P2 = q1->tail,
		* P3 = q2->front, * P4 = q2->tail;
	///<\Исходные данные>
	move(q1, q2, N);
	cout << "\nСостояния очередей после внесеных изминений: \n";
	cout << "\nСостояния 1-ой очереди после внесеных изминений: \n";
	Show(q1);
	cout << "\nСостояния 2-ой очереди после внесеных изминений: \n";
	Show(q2);
	cout << "\nНажмите Enter для завершения...";
	while (getchar() != '\n')
		continue;
}
void clear(queue* q, int count_del)
{
	int i = 0;
	while( i!=count_del || q->front<=q->tail)
	{
		i++;
		pop(q);
	}
}
void move(queue* q1, queue* q2, int N)//ф-ия пер-ия элементов 1-ой очереди
{
	bool flag = N < q1->count ? true : false;
	queue* temp = q1;
	if (flag)
	{
		int counter = 0;
		list* h; 
			for (h = temp->front; h != nullptr, counter !=N; h = h->next)
			{
				push(q2, h->digit);
							//	pop(q1);
				counter++;
			}	
	}
	else
	{
		list* h;
		for (h = temp->front; h != nullptr ; h = h->next)
		{
			push(q2, h->digit);
			//pop(q1);
		}
	}
}


void FillQueue(queue* q, int count)
{
	for (size_t i = 0; i < count; i++)
	{
		push(q, rand() % 50);
	}
}

int pop(queue* q)
{
	struct list* temp;
	int digit;
	if (IsEmpty(q) == 1) {
		printf("Очередь пуста!\n");
		return 0;
	}
	digit = q->front->digit;
	temp = q->front;
	q->front = q->front->next;
	free(temp);
	return digit;
}

void Show(queue* q)
{
	list* h;
	if (IsEmpty(q) == 1) {
		printf("Очередь пуста!\n");
		return;
	}
	for (h = q->front; h != nullptr; h = h->next)
		printf("%d ", h->digit);
	return;
}


void enq(queue* q)
{
	q->front = nullptr;
	q->tail = nullptr;
}

int IsEmpty(queue* q)
{
	if (q->front == nullptr)
		return 1;
	else
	{
		return 0;
	}
}

void push(queue* q, double digit)
{
	if ((q->tail == nullptr) && (q->front == nullptr)) {
		q->tail = push_list(digit);
		q->front = q->tail;
	}
	else
		q->tail = addnode(q->tail, digit);
}

list* addnode(list* lst, double digit)
{
	list* temp, * p;
	temp = new list;
	p = lst->next; // сохранение указателя на следующий узел
	lst->next = temp; // предыдущий узел указывает на создаваемый
	temp->digit = digit; // сохранение поля данных добавляемого узла
	temp->next = p; // созданный узел указывает на следующий элемент
	return(temp);
}

list* push_list(double digit)
{
	list* lst;
	// выделение памяти под корень списка
	lst =new list;
	lst->digit = digit;
	lst->next = nullptr; // это последний узел списка
	return(lst);
}
