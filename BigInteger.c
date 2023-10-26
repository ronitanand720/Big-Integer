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
/*void main()
{
    char p1[100];
    char p2[100];
    printf("\nEnter 1st number:");
    gets(p1);
    printf("\nEnter 2nd number:");
    gets(p2);
    struct BigInteger a = initialize(p1);
    struct BigInteger b = initialize(p2);
    printf("\nNumber 1:     ");
    display(a);
    printf("\nNumber 2:     ");
    display(b);
    printf("\nAddition :     ");
    display(add(a, b));
    printf("\nSubtraction :  ");
    display(sub(a, b));
    printf("\nMultiply :     ");
    display(mul(a, b));
    printf("\nModolus:         ");
    display(mod(a, b));
    printf("\nDivision :     ");
    display(div1(a, b));
}*/

// to initialize struct BigInteger
struct BigInteger initialize(char *a)
{
    struct BigInteger b;
    b.sign = 1;
    int k = 0;
    struct node *temp = NULL;
    int x = 0;
    int i = 0;
    if (*a == '-')
    {
        i = 1;
        k = 1;
        b.sign = -1;
    }
    for (int p = i; *(a + p) != '\0'; p++)
        x++;
    b.length = x;
    if (*a == '-')
        x++;
    for (int j = x - 1; j >= k; j--)
        create(&temp, *(a + j) - '0');
    b.head = temp;
    b.d = 0;
    return b;
}

// to create Linked List
void create(struct node **head, int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->next = NULL;
    temp->data = val;
    if (*head == NULL)
    {
        *head = temp;
        return;
    }
    struct node *itr = *head;
    while (itr->next != NULL)
        itr = itr->next;
    itr->next = temp;
}

// to display Linked List
void display(struct BigInteger a)
{
    if (a.d != -5)
    {
        struct node *itr = a.head;
        struct node *ptr = a.head;
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = ptr->data;
        temp->next = NULL;
        ptr = ptr->next;
        while (ptr != NULL)
        {
            struct node *temp1 = (struct node *)malloc(sizeof(struct node));
            temp1->data = ptr->data;
            temp1->next = temp;
            temp = temp1;
            ptr = ptr->next;
        }
        while (temp->data == 0 && temp->next != NULL)
            temp = temp->next;
        while (temp != NULL)
        {
            printf("%d", temp->data);
            temp = temp->next;
        }
    }
}

// to make Linked list equal
struct node *equal(struct node *head, int x)
{
    struct node *itr = head;
    while (head->next != NULL)
        head = head->next;
    for (int i = 0; i < x; i++)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->next = NULL;
        temp->data = 0;
        head->next = temp;
        head = temp;
    }
    return itr;
}

// to reverse a Linked List
struct node *reverse(struct node *head)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = head->data;
    temp->next = NULL;
    head = head->next;
    while (head != NULL)
    {
        struct node *temp1 = (struct node *)malloc(sizeof(struct node));
        temp1->data = head->data;
        temp1->next = temp;
        temp = temp1;
        head = head->next;
    }
    return temp;
}

// to find length of linked list
int length(struct node *p)
{
    int x = 0;
    while (p != NULL)
    {
        x++;
        p = p->next;
    }
    return x;
}

// to find if no is zero
int zeros(struct node *head, int x)
{
    int p = 0;
    while (head != NULL)
    {
        if (head->data == 0)
            p++;
        head = head->next;
    }
    if (p == x)
        return 1;
    return 0;
}
// to add two big integers
struct BigInteger add(struct BigInteger a, struct BigInteger b)
{
    int y = 1;
    if (a.length - b.length < 0)
    {
        a.head = equal(a.head, b.length - a.length);
    }
    else if (a.length - b.length > 0)
    {
        b.head = equal(b.head, a.length - b.length);
    }
    if (a.sign == -1 && b.sign == 1)
    {
        a.sign = 1;
        return sub(b, a);
    }
    else if (b.sign == -1 && a.sign == 1)
    {
        b.sign = 1;
        return sub(a, b);
    }
    else if (b.sign == -1 && a.sign == -1)
        y = -1;
    struct BigInteger z;
    struct node *t1 = a.head;
    struct node *t2 = b.head;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *p = temp;
    temp->next = NULL;
    temp->data = (t1->data + t2->data) % 10;
    int x = (t1->data + t2->data) / 10;
    t1 = t1->next;
    t2 = t2->next;
    while (t1 != NULL || t2 != NULL)
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->next = NULL;
        n->data = (t1->data + t2->data + x) % 10;
        x = (t1->data + t2->data + x) / 10;
        temp->next = n;
        temp = n;
        t1 = t1->next;
        t2 = t2->next;
    }
    if (x >= 1)
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->next = NULL;
        n->data = x;
        temp->next = n;
    }
    // z.head = p;
    struct node *w;
    w = reverse(p);
    while (w->data == 0 && w->next != NULL)
    {
        w = w->next;
    }
    if (w->data != 0)
        (w->data) = (w->data) * y;
    z.head = p;
    return z;
}

// to subtract two big integers
struct BigInteger sub(struct BigInteger a, struct BigInteger b)
{
    if (a.sign == 1 && b.sign == -1)
    {
        b.sign = 1;
        return add(a, b);
    }
    else if (a.sign == -1 && b.sign == 1)
    {
        a.sign = 1;
        return add(a, b);
    }
    int p = 0, y = 1;
    struct BigInteger z;
    z.sign = 1;
    struct node *t1 = a.head;
    struct node *t2 = b.head;
    struct node *t11 = a.head;
    struct node *t22 = b.head;
    while (t11->next != NULL)
    {
        t11 = t11->next;
        t22 = t22->next;
    }
    if (t11->data < t22->data)
    {
        struct node *x = t1;
        t1 = t2;
        t2 = x;
        y = -1;
        z.sign = -1;
    }
    else if (t11->data == t22->data)
    {
        t11 = reverse(a.head)->next;
        t22 = reverse(b.head)->next;
        while (t11 != NULL)
        {
            if (t11->data < t22->data)
            {
                struct node *x = t1;
                t1 = t2;
                t2 = x;
                y = -1;
                z.sign = -1;
                break;
            }
            if (t11->data > t22->data)
                break;
            t11 = t11->next;
            t22 = t22->next;
        }
    }
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *itr = temp;
    temp->next = NULL;
    if (t1->next != NULL && t1->data < t2->data)
    {
        if (t1->next->data == 0)
        {
            t1->next->data = 9;
            t1->data += 10;
            p = 1;
        }
        else
        {
            t1->next->data--;
            t1->data += 10;
        }
        temp->data = t1->data - t2->data;
    }
    else
        temp->data = t1->data - t2->data;
    t1 = t1->next;
    t2 = t2->next;
    while (t1 != NULL || t2 != NULL)
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->next = NULL;
        if (t1->next != NULL && t1->data < t2->data)
        {
            if (t1->next->data == 0 && t1->next != NULL)
            {
                t1->next->data = 9;
                t1->data += 10;
                p = 1;
            }
            else
            {
                if (t1->next != NULL)
                {
                    t1->next->data--;
                    t1->data += 10;
                    p = 0;
                }
            }
            n->data = t1->data - t2->data;
        }
        else
        {
            if (p == 1 && t1->next != NULL)
            {
                t1->next->data--;
            }
            n->data = t1->data - t2->data;
        }
        temp->next = n;
        temp = n;
        t1 = t1->next;
        t2 = t2->next;
    }
    struct node *x;
    x = reverse(itr);
    itr = x;
    while (x->data == 0 && x->next != NULL)
    {
        x = x->next;
    }
    if (x->data != 0)
        (x->data) = (x->data) * y;
    z.head = reverse(itr);
    return z;
}

// to divide two big integers
struct BigInteger div1(struct BigInteger a, struct BigInteger b)
{
    if (a.head->data == 0 && b.head->data == 0 && zeros(a.head, length(a.head)) == 1 && zeros(b.head, length(b.head)) == 1)
    {
        printf("not defined");
        a.d = -5;
        return a;
    }
    else if (b.head->data == 0 && zeros(b.head, length(b.head)) == 1)
    {
        printf("infinity");
        a.d = -5;
        return a;
    }
    else if (a.head->data == 0 && zeros(a.head, length(a.head)) == 1)
    {
        a.head->data = 0;
        a.head->next = NULL;
        return a;
    }
    int p = -1;
    struct node *temp = a.head;
    struct node *itr = NULL;
    while (temp != NULL)
    {
        create(&itr, temp->data);
        temp = temp->next;
    }
    temp = reverse(a.head);
    while (temp->data == 0 && temp != NULL)
        temp = temp->next;
    while (temp->data >= 0)
    {
        struct BigInteger itr1 = sub(a, b);
        a.head = itr1.head;
        temp = reverse(a.head);
        while (temp->data == 0 && temp->next != NULL)
            temp = temp->next;
        p++;
    }
    a.d = p;
    b.d = p;
    struct node *x = NULL;
    if (a.d == 0)
    {
        a.head->data = 0;
        a.head->next = NULL;
        return a;
    }
    while (a.d > 0)
    {
        create(&x, (a.d) % 10);
        a.d = (a.d) / 10;
    }
    a.head = x;
    return a;
}

// to multiply two big integers
struct BigInteger mul(struct BigInteger a, struct BigInteger b)
{
    int k = 1, q = 0;
    struct BigInteger t, u, v;
    int c = 0;
    struct node *x = a.head;
    struct node *y = b.head;
    struct node *p = NULL;
    struct node *p1 = NULL;
    while (x != NULL)
    {
        create(&p1, ((x->data) * (y->data) + c) % 10);
        c = ((x->data) * (y->data) + c) / 10;
        x = x->next;
    }
    if (c != 0)
    {
        create(&p1, c);
    }
    t.head = p1;
    t.length = length(p1);
    c = 0;
    y = y->next;
    if (y == NULL)
    {
        return t;
    }
    while (y != NULL)
    {
        x = a.head;
        while (q < k)
        {
            create(&p, 0);
            q++;
        }
        while (x != NULL)
        {
            create(&p, ((x->data) * (y->data) + c) % 10);
            c = ((x->data) * (y->data) + c) / 10;
            x = x->next;
        }
        if (c != 0)
        {
            create(&p, c);
        }
        u.head = p;
        u.length = length(p);
        v = add(t, u);
        t.head = v.head;
        t.length = length(t.head);
        k++;
        q = 0;
        // t.head = p;
        y = y->next;
        p = NULL;
        c = 0;
    }
    return v;
}

// to find modolus of two Big Integer
struct BigInteger mod(struct BigInteger a, struct BigInteger b)
{
    if (a.head->data == 0 && b.head->data == 0 && zeros(a.head, length(a.head)) == 1 && zeros(b.head, length(b.head)) == 1)
    {
        printf("not defined");
        a.d = -5;
        return a;
    }
    else if (b.head->data == 0 && zeros(b.head, length(b.head)) == 1)
    {
        printf("infinity");
        a.d = -5;
        return a;
    }
    else if (a.head->data == 0 && zeros(a.head, length(a.head)) == 1)
    {
        a.head->data = 0;
        a.head->next = NULL;
        return a;
    }
    struct node *temp = a.head;
    struct node *itr = NULL;
    while (temp != NULL)
    {
        create(&itr, temp->data);
        temp = temp->next;
    }
    temp = reverse(a.head);
    while (temp->data == 0 && temp != NULL)
        temp = temp->next;
    while (temp->data >= 0)
    {
        struct BigInteger itr1 = sub(a, b);
        a.head = itr1.head;
        temp = reverse(a.head);
        while (temp->data == 0 && temp->next != NULL)
            temp = temp->next;
    }
    if (temp->data == 0)
        return a;
    temp = a.head;
    a.head = temp;
    while (temp->data == 0 && temp->next != NULL)
        temp = temp->next;
    if (temp->data != 0)
    {
        temp->data *= -1;
        a = sub(b, a);
    }
    return a;
}
