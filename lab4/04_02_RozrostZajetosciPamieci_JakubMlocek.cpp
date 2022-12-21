#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

class linked_list
{
private:
    node *head,*tail;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

	void printList()
	{
		node *curr = new node;
		curr = head;
		while(curr->next != NULL){
			cout << curr->data << endl;
			curr = curr->next;
		}
	}
};

int main(int argc, char *argv[])
{
	if(argc != 2){
		cout << "Dodaj argument <ilość pamięci w MB>" << endl; 
		return 1;
	}

	int memory_to_fill = atoi(argv[1]);

	int nodes_to_be_done = memory_to_fill*62500; //62500 nodes fits in 1MB (1node - 16bytes)

	linked_list LL;

	cout << "gotowy do stworzenia " << nodes_to_be_done << " nodow!" << endl; 
	cin.get();
	for( int i = 0; i < nodes_to_be_done; i++)
	{
		LL.add_node(1);
	}
	cout << "trzymam zajeta pamiec" << endl;
	cin.get();

}

