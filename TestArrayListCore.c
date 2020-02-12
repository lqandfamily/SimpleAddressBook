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
    init();
    addByInfo("bob", "10086", "London", NULL);
    addByInfo("tom", "10001", "Shanghai", NULL);
    ContactInfo **contacts = findAll();
    for(i = 0; contacts[i]->id != END_ID_CODE; i++){
        printf("%d,%s,%s\n",contacts[i]->id,contacts[i]->name,contacts[i]->phoneNum);
    }
}

int main(){
    testAdd();
    return 0;
}

