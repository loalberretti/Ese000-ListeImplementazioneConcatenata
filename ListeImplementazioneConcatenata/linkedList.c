#include <stdlib.h>
#include ".\linkedList.h"

/*
 * Inserts the new key at the beginning of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLInsertAtBeginning(LLElement * first, int key) {
    LLElement *newelement;
    newelement=(LLElement*)malloc(sizeof(LLElement));
    if(newelement != NULL) //verifico se è stato allocato
    {
        newelement->next= first;
        newelement->key= key;
        first=newelement;
    }
    return first;
}

/*
 * Inserts the new key at the end of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLInsertAtEnd(LLElement * first, int key) {
    LLElement **temp;
    LLElement *newelement;
    newelement=(LLElement*)malloc(sizeof(LLElement));
    if(newelement!=NULL)
    {
        temp=&first;
        while(*temp!=NULL) //quando sono all'ultimo esco
        {
            temp=&((*temp)->next);
        }
        newelement->key=key;
        newelement->next=NULL;
        *temp=newelement;// allaccio la lista
    }
    return first;
}

/*
 * Inserts the new key at the specified positon of the list.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * 
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLInsertAtPosition(LLElement * first, int key, int position) {
    LLElement **temp;
    LLElement *newelement;
    newelement=(LLElement*)malloc(sizeof(LLElement));
    if(newelement!=NULL){
        temp=&first;
        int i;
        for (i=0;i<position;i++)
            temp=&((*temp)->next);
        newelement->key=key;
        newelement->next= *temp;
        *temp=newelement;
    }
    return first;
}

/*
 * Returns the size of the list.
 */
int LLSize(LLElement * first) {
    int i=0;
    LLElement *temp;
    temp=first;
    while(temp!=NULL)
    {
        
        temp=temp->next;   //scorro la lista
        i++;
    }
    return(i);
}   

/*
 * Returns the key at the specified position.
 */ 
int LLGetKey(LLElement * first, int position) {
    int i;
    LLElement *temp;
    temp=first; 
    for(i=0;i<position;i++)
    {
        temp=temp->next;      
    }    
    return (temp->key);
}

/*
 * Returns the position of the first element, starting from startPosition, that
 * has the specified key.
 * Returns -1 if not found. 
 */ 
int LLFindKey(LLElement * first, int key, int startPosition) {
    int positionkey=-1; //chiave non trovata
    int i;
    for(i=0;i<startPosition;i++) // arrivo alla posizione iniziale
    {
        first=first->next; //scorro
    }
    while(first!= NULL && positionkey ==-1){
        if(first->key == key) {
            positionkey = i;
        }
        first=first->next;
        i++;
    }
    return positionkey;
}


/*
 * Remove the first element of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLRemoveFirst(LLElement * first) {
    LLElement *DeleteElement;
    
    if(first != NULL) { //verifico che la lista esista
        DeleteElement=first; //faccio puntare temp all'inzio della lista
        first=first->next; //accendo al campo lo riallaccio al prossimo 
        free(DeleteElement); //elimino il primo
    }
    return first;
}

/*
 * Remove the last element of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLRemoveLast(LLElement * first){
    LLElement **DeleteElement;
    if(first!=NULL)
    {
        DeleteElement=&first; //metto il puntatore all'inzio della lista
        while((*DeleteElement)->next!=NULL) // mi fermo all'ultimo della lista
        {
            DeleteElement=&((*DeleteElement)->next); //lo scorro
        }
        free(*DeleteElement);
        *DeleteElement=NULL;
    }
    return first;
}

/*
 * Remove the element at the specified position.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * 
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLRemoveAtPosition(LLElement * first, int position) {
    LLElement **temp;
    LLElement *DeleteElement;
        temp=&first;
        int i;
        for(i=0;i<position;i++)// quando sono arrivato all' elemento del campo next che punta all'elemento che devo eliminare 
        {
             temp=&((*temp)->next); 
        }
        DeleteElement=*temp; //posizione da eliminare
        if((*temp)->next!=NULL){
                *temp=((*temp)->next);//lo riallaccio al prossimo elemento
        }
            
    free(DeleteElement);
    return first;
}

LLElement * LLEmptyList(LLElement * first) {
    LLElement *DeleteElement;
    while(first != NULL)
    {
        DeleteElement=first;
        first=first->next;
        free(DeleteElement);
    }
    return NULL;
}

