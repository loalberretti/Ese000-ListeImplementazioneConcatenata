#include <stdlib.h>
#include ".\linkedList.h"

/*
 * Inserts the new key at the beginning of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLInsertAtBeginning(LLElement * first, int key) {
    LLElement * temp;
    temp = (LLElement *)malloc(sizeof(LLElement));
    if(temp != NULL) {/*
        temp=first;
        first->key=key;
        first->next=temp;*/
    
        temp->next = first;
        temp->key = key;
        first = temp;
    }
    return first;
}

/*
 * Inserts the new key at the end of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLInsertAtEnd(LLElement * first, int key) {
}

/*
 * Inserts the new key at the specified positon of the list.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * 
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLInsertAtPosition(LLElement * first, int key, int position) {
    // TODO To be implemented
    return NULL;
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
    temp=first; //il puntatore parte dall'inizio
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
    // TODO To be implemented
    return -1;
}

/*
 * Remove the first element of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLRemoveFirst(LLElement * first) {
    LLElement * temp;
    temp = (LLElement *)malloc(sizeof(LLElement));
    if(temp != NULL) {
        temp=first; //faccio puntare al primo della lista
        first=first->next; //due indirizzi accendo al campo 
        free(temp);
    }
    return first;
}

/*
 * Remove the last element of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLRemoveLast(LLElement * first){
    LLElement * temp;
    temp = (LLElement *)malloc(sizeof(LLElement));
    if(temp != NULL) {
   
    return NULL;
}

/*
 * Remove the element at the specified position.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * 
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLRemoveAtPosition(LLElement * first, int position) {
    // TODO To be implemented
    return NULL;
}




