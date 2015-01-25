#include <stdlib.h>
#include ".\linkedList.h"

/*
 * Inserts the new key at the beginning of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLInsertAtBeginning(LLElement * first, int key) {
    LLElement *temp;
    temp=(LLElement*)malloc(sizeof(LLElement));
    if(temp != NULL) //verifico se è stato allocato
    {
        temp->next= first;
        temp->key= key;
        first=temp;
    }
    return first;
}

/*
 * Inserts the new key at the end of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLInsertAtEnd(LLElement * first, int key) {
    LLElement **temp;
    LLElement *new;
    new=(LLElement*)malloc(sizeof(LLElement));
    if(new!=NULL)
    {
        temp=&first;
        while(*temp!=NULL) //quando sono all'ultimo esco
        {
            temp=&((*temp)->next);
        }
        new->key=key;
        new->next=NULL;
        *temp=new;// allaccio la lista
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
    LLElement *new;
    new=(LLElement*)malloc(sizeof(LLElement));
    if(new!=NULL){
        temp=&first;
        int i;
        for (i=0;i<position;i++)
            temp=&((*temp)->next);
        new->key=key;
        new->next= *temp;
        *temp=new;
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
    int r=-1;
    int i;
    for(i=0;i<startPosition;i++)
    {
        
    }
    
    
    return r;
}

/*
 * Remove the first element of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLRemoveFirst(LLElement * first) {
    LLElement * temp;
    
    if(first != NULL) { //verifico che la lista esista
        temp=first; //faccio puntare temp all'inzio della lista
        first=first->next; //accendo al campo e  scorro la lista 
        free(temp); //elimino il primo
    }
    return first;
}

/*
 * Remove the last element of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLRemoveLast(LLElement * first){
    LLElement **temp;
    if(first!=NULL)
    {
        temp=&first; //metto il puntatore all'inzio della lista
        while((*temp)->next!=NULL) // mi fermo all'ultimo della lista
        {
            temp=&((*temp)->next); //lo scorro
        }
        free(*temp);
        *temp=NULL;
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
    LLElement *elimina;
        temp=&first;
        int i;
        for(i=0;i<position;i++)// quando sono arrivato all' elemento del campo next che punta all'elemento che devo eliminare 
        {
             temp=&((*temp)->next); 
        }
        elimina=*temp; //posizione da eliminare
        if((*temp)->next!=NULL){
                *temp=((*temp)->next);//lo riallaccio al prossimo elemento
        }
            
    free(elimina);
    return first;
}

LLElement * LLEmptyList(LLElement * first) {
   // TODO To be implemented
    return NULL;
}
