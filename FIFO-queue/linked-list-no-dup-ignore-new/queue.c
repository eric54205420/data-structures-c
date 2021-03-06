#include <stdlib.h>
#include <stdio.h>
#include "Item.h"
#include "QUEUE.h"

typedef struct QUEUEnode *link;
struct QUEUEnode {
	Item item;
	link next;
};

static link head, tail;

link NEW(Item item, link next) {
	link x = malloc(sizeof(*x));
	x->item = item;
	x->next = next;
	return x;
}

void QUEUEinit(int maxN) {
	head = NULL;
}

int QUEUEempty(void) {
	return head == NULL;
}

void QUEUEput(Item item) {
	link t;
	
	for (t = head; t != NULL; t = t->next) {
		if (t->item == item) {
			return;
		}
	}
	
	if (head == NULL) {
		head = (tail = NEW(item, head));
		return;
	}
	tail->next = NEW(item, tail->next);
	tail = tail->next;
}

Item QUEUEget(void) {
	Item item = head->item;
	link t = head->next;
	free(head);
	head = t;
	return item;
}
