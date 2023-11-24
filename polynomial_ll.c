#include <stdio.h>
#include <stdlib.h>

struct poly {
    int coef, expo;
    struct poly *link;
} *phead, *qhead, *rhead;

struct poly* polynomial_p(int n1) {
    struct poly *temp, *ptr;
    int i, coef1, expo1;
    phead = NULL;
    for (i = 0; i < n1; i++) {
        temp = (struct poly*)malloc(sizeof(struct poly));
        printf("enter the coefficient of the term \n");
        scanf("%d", &coef1);
        printf("enter the exponent of the term\n");
        scanf("%d", &expo1);
        temp->coef = coef1;
        temp->expo = expo1;
        temp->link = NULL;
        if (phead == NULL) {
            phead = temp;
            ptr = phead;
        } else {
            ptr->link = temp;
            ptr = temp;
        }
    }
    return phead;
}

struct poly* polynomial_q(int n2) {
    struct poly *temp, *ptr;
    int i, coef2, expo2;
    qhead = NULL;
    for (i = 0; i < n2; i++) {
        temp = (struct poly*)malloc(sizeof(struct poly));
        printf("enter the coefficient of the term \n");
        scanf("%d", &coef2);
        printf("enter the exponent of the term\n");
        scanf("%d", &expo2);
        temp->coef = coef2;
        temp->expo = expo2;
        temp->link = NULL;
        if (qhead == NULL) {
            qhead = temp;
            ptr = qhead;
        } else {
            ptr->link = temp;
            ptr = temp;
        }
    }
    return qhead;
}

void display(struct poly* polynomial_p) {
    while (polynomial_p != NULL) {
        printf("%d x^%d ", polynomial_p->coef, polynomial_p->expo);
        if (polynomial_p->link != NULL) {
            printf("+ ");
        }
        polynomial_p = polynomial_p->link;
    }
    printf("\n");
}

struct poly* add_polynomial(struct poly* phead, struct poly* qhead) {
    struct poly *p, *q, *r, *rhead = NULL, *temp = NULL;
    p = phead;
    q = qhead;

    while (p != NULL && q != NULL) {
        temp = (struct poly*)malloc(sizeof(struct poly));
        temp->link = NULL;

        if (p->expo > q->expo) {
            temp->coef = p->coef;
            temp->expo = p->expo;
            p = p->link;
        } else if (p->expo < q->expo) {
            temp->coef = q->coef;
            temp->expo = q->expo;
            q = q->link;
        } else {
            temp->coef = p->coef + q->coef;
            temp->expo = p->expo;
            p = p->link;
            q = q->link;
        }

        if (rhead == NULL) {
            rhead = temp;
            r = temp;
        } else {
            r->link = temp;
            r = temp;
        }
    }

    // Append remaining terms of p or q
    while (p != NULL) {
        temp = (struct poly*)malloc(sizeof(struct poly));
        temp->coef = p->coef;
        temp->expo = p->expo;
        temp->link = NULL;

        if (rhead == NULL) {
            rhead = temp;
            r = temp;
        } else {
            r->link = temp;
            r = temp;
        }
        p = p->link;
    }

    while (q != NULL) {
        temp = (struct poly*)malloc(sizeof(struct poly));
        temp->coef = q->coef;
        temp->expo = q->expo;
        temp->link = NULL;

        if (rhead == NULL) {
            rhead = temp;
            r = temp;
        } else {
            r->link = temp;
            r = temp;
        }
        q = q->link;
    }

    return rhead;
}

void main() {
    int n1, n2;
    printf("enter the no of elements first  polynomial\n");
    scanf("%d", &n1);
    phead = polynomial_p(n1);
    display(phead);
    printf("enter the no. of elements of second polynomial\n");
    scanf("%d", &n2);
    qhead = polynomial_q(n2);
    display(qhead);
    printf("Sum of the given Polynomial \n");
    rhead = add_polynomial(phead, qhead);
    display(rhead);
}

