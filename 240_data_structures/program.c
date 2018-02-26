#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node
{
  int data;
  struct node* next;
};

struct node* list_insert_after(struct node** n, int d)
{
  struct node* new_node = malloc(sizeof(struct node));
  if(new_node == NULL)
  {
    fprintf(stderr,"error: malloc failed\n");
    exit(EXIT_FAILURE);
  }
  new_node->next = NULL;
  new_node->data = d;

  // list is empty (return new_node)
  if(n == NULL)
  {}

  // inserting at the tail
  else if((*n)->next == NULL)
  {
    (*n)->next = new_node;
  }

  // inserting somewhere in the middle
  else
  {
    new_node->next = (*n)->next;
    (*n)->next = new_node;
  }

  return new_node;
}

void list_free(struct node* head)
{
  struct node* n = head;
  struct node* tmp = NULL;
  while(n != NULL)
  {
    tmp = n;
    n = n->next;
    free(tmp);
  }
}

void list_print(struct node* head)
{
  struct node* current = head;
  while(current != NULL)
  {
    printf("%d\n",current->data);
    current = current->next;
  }
}

struct node* list_find(struct node* head, int value)
{
  struct node* current = head;
  while(current != NULL)
  {
    if(current->data == value)
      return current;
    current = current->next;
  }
  return NULL;
}

struct node* list_delete(struct node* head, struct node* unlink)
{
	if (unlink != NULL)
	{
		//printf("Deleting node: %p, starting at %p (%d)\n", unlink, head, head->data);
		if (head == unlink) {
			if (head->next == NULL) {
				printf("Can't return with only one node\n");
				return NULL;
			}

			head->data = head->next->data;
			unlink = head->next;
			head->next = head->next->next;
			free(unlink);
			return head;
		}

		struct node *prev = head;
		while (prev->next != NULL && prev->next != unlink) {
			prev = prev->next;
		}

		if (prev->next == NULL) {
			printf("Node not in list\n");
			return NULL;
		}

		prev->next = prev->next->next;
		free(unlink);
		return head;
	}
	return head;
}

unsigned int list_count(struct node* head)
{
  int count = 0;
  struct node* current = head;
  while(current != NULL)
  {
    count++;
    current = current->next;
  }
  return count;
}

int main(void)
{
	/*
	 * for i in $(seq 1 100); do make flag; done
	 * for i in $(seq 1 100); do echo $i && echo "$i\n" | ./answer; done
	 * 9eb9133481c00c9089831e1cb584dd54cf644913
	 */
  time_t t;
  srand((unsigned)time(&t));

  struct node* head = list_insert_after(NULL,0);

  int i;
  for(i = 1; i < 100; i++)
      list_insert_after(&head,rand()%100+1);

  head = list_delete(head, head);
  int unlink_count = rand()%50+1;
  //printf("Moving on from initial delete. Head at: %p\n", head);
  for(i = 0; i < unlink_count; i++) {
 	struct node *rand_node = list_find(head, rand()%100+1);
 //	printf("Trying to delete: %p\n", rand_node);
    head = list_delete(head,rand_node);
  }

  struct node* current = head;
  while(current->next != NULL)
    current = current->next;
  head = list_delete(head,current);

  printf("%d\n",list_count(head));
  list_free(head);
  return 0;
}
