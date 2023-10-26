#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct BigInteger
{
    struct node *head;
    int length;
    int d, sign;
};
struct BigInteger initialize(char *s);
void create(struct node **head, int val);
void display(struct BigInteger a);
struct node *equal(struct node *, int);
struct node *reverse(struct node *head);
int length(struct node *p);
int zeros(struct node *head, int x);
struct BigInteger add(struct BigInteger a, struct BigInteger b);
struct BigInteger sub(struct BigInteger a, struct BigInteger b);
struct BigInteger div1(struct BigInteger a, struct BigInteger b);
struct BigInteger mul(struct BigInteger a, struct BigInteger b);
struct BigInteger mod(struct BigInteger a, struct BigInteger b);

#endif