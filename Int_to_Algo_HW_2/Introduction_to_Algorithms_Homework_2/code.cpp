     Date : 14.12.2012
//     		 QUEUE SIMULATION		*/

#include <stdio.h>
#define MAX 10

int queue_arr[MAX];
int tail = -1;// index position
int head = -1;// index position

/* Function Prototypes */
void add_customer();
void del_customer();
void display_queue();

void main()
{

	int choice;

	while (1)
	{
		printf("Main Menu:\n\n"
			"1.   Enter New Customer into queue\n"
			"2.   Read the next Customer from queue\n"
			"3.   Write out the Customers in queue\n"
			"4.   Exit Simulation\n\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			add_customer();
			break;
		case 2:
			del_customer();
			break;
		case 3:
			display_queue();
			break;
		case 4:
			return;
		default:
			printf("Wrong choice\n");
		}/*End of switch*/
	}/*End of while*/
}/*End of main()*/

void add_customer()
{
	int added_customer;

	if (tail - head == MAX - 1)
		printf("Queue is full\n");

	else
	{
		if (head == -1) /*If queue is initially empty */
			head = 0;

		printf("Input the customer's ID for adding in queue : ");
		scanf("%d", &added_customer);
		tail = tail + 1;
		queue_arr[tail] = added_customer;
	}/*End of else*/
}/*End of add_customer()*/

void del_customer()
{
	if (head == -1 || head > tail)
	{
		printf("Queue is empty\n");
		return;
	}

	else
	{
		printf("Customer's ID deleted from queue is : %d\n", queue_arr[head]);

		for (int i = 0; i < tail; i++) //customers shift to the left one position.
			queue_arr[i] = queue_arr[i + 1];

		tail--;
	}
}/*End of del_customer()*/

void display_queue()
{
	if (head == -1)
		printf("Queue is empty\n");

	else
	{
		printf("Queue is :\n");

		for (int i = head; i <= tail; i++)
			printf("%d ", queue_arr[i]);

		printf("\n");
	}/*End of else*/
}/*End of display_queue()*/
