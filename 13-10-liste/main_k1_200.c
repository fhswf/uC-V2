/*
 * main_liste.c
 *
 * Eine verkettete Liste von 2D-Punkten
 *
 *  (c) Prof. Tobias Ellermeyer
 *      Fachhochschule Suedwestfalen
 *
 *  Stand: SS 2026
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
	float x;
	float y;
} point2d_t;

// Ein Knoten der verketteten Liste
typedef struct node {
    point2d_t point;	// 2D-Punkt
    struct node *prev;
} node_t;

// Neuen Knoten am Anfang der Liste einfügen
uint8_t list_append(node_t **headptr, point2d_t p) {
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return(1);
    }
    new_node->point = p;
    new_node->prev = (*headptr);   // neuer Knoten zeigt auf den bisherigen Kopf
    (*headptr) = new_node;        // Kopf der Liste auf neuen Knoten setzen
    return 0;				  // Ohne Fehler
}

// Liste ausgeben
void list_print(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("(%4.1f/%4.1f) -> ", current->point.x, current->point.y);
        current = current->prev;
    }
    printf("NULL\n");
}

// Speicher der gesamten Liste freigeben
void list_free(node_t *kopf) {
    node_t *current = kopf;
    while (current != NULL) {
        node_t *temp = current;
        current = current->prev;
        free(temp);
    }
}

int main(void) {
    node_t *liste = NULL;   // leere Liste
    uint8_t status;

    // Werte (2D-Punkte) einfügen
    status = list_append(&liste, (point2d_t){3.0, 4.0});
    if (status) { printf("Fehler: Kein Speicher verfügbar!\n"); }
    status = list_append(&liste, (point2d_t){5.0, 6.0});
    if (status) { printf("Fehler: Kein Speicher verfügbar!\n"); }
    status = list_append(&liste, (point2d_t){7.0, 8.0});
    if (status) { printf("Fehler: Kein Speicher verfügbar!\n"); }

    printf("Verkettete Liste: ");       // Liste ausgeben
    list_print(liste);

    // Speicher freigeben
    list_free(liste);

    return 0;
}
