/**
 * TEST模块：ArrayListCore
 * @author lq
 * @version 0.1
 * @date 2020/2/12
 */
#include "ArrayListCore.h"
#include <stdio.h>

void testAdd() {
    int i;
    addByInfo("bob", "10086", "London", NULL);
    ContactInfo **contacts = findAll();
    for(i = 0; contacts[i]->id != END_ID_CODE; i++){
        printf("id=%d, name=%s\n",contacts[i]->id,contacts[i]->name);
    }
}

int main(){
    testAdd();
    return 0;
}

