/**
 * TEST模块：ArrayListCore
 * @author lq
 * @version 0.1
 * @date 2020/2/12
 */
#include "ArrayListCore.h"
#include <stdio.h>

/**
 * 测试添加联系人以及查找所有
 */
void testAdd() {
    int i;
    init();
    addByInfo("bob", "10086", "London", NULL);
    addByInfo("tom", "10001", "Shanghai", NULL);
    ContactInfo **contacts = findAll();
    for (i = 0; contacts[i]->id != END_ID_CODE; i++) {
        printf("%d,%s,%s\n", contacts[i]->id, contacts[i]->name, contacts[i]->phoneNum);
    }

    destroy();
}

/**
 * 测试删除和销毁
 */
void testDelAndDestroy() {
    int i;
    init();
    addByInfo("bob", "10086", "London", NULL);
    addByInfo("tom", "10001", "Shanghai", NULL);
//    del(0)
//    destroy();
    ContactInfo **contacts = findAll();
    for (i = 0; contacts[i]->id != END_ID_CODE; i++) {
        printf("%d,%s,%s\n", contacts[i]->id, contacts[i]->name, contacts[i]->phoneNum);
    }

    destroy();
}

/**
 * 测试添加重复联系人以及精确查找
 */
void testAddRepeat() {
    int i;
    init();
    addByInfo("bob", "10086", "London", NULL);
    addByInfo("tom", "10001", "Shanghai", NULL);
    int resultCode = addByInfo("ss", "10086", "London", NULL);
    if (resultCode == NAME_EXIST) {
        printf("Repeat Name!!!\n");
    }

    if (resultCode == PHONE_EXIST) {
        printf("Repeat Phone!!!\n");
    }

    ContactInfo **contacts = findAll();
    for (i = 0; contacts[i]->id != END_ID_CODE; i++) {
        printf("%d,%s,%s\n", contacts[i]->id, contacts[i]->name, contacts[i]->phoneNum);
    }

    printf("Absolute Find>:\n");
    printf("%s", findByAbsoluteName("bob")->phoneNum);

    destroy();
}

void testFindByNameOrPhone() {
    int i;
    init();
    addByInfo("bobb", "10086", "London", NULL);
    addByInfo("blili", "10001", "Shanghai", NULL);
    addByInfo("tom", "10003", "Shanghai", NULL);
    addByInfo("fbf", "10002", "Shanghai", NULL);

    printf("findByName>:\n");
    ContactInfo **contacts = findByName("b");
    for (i = 0; contacts[i]->id != END_ID_CODE; i++) {
        printf("%d,%s,%s\n", contacts[i]->id, contacts[i]->name, contacts[i]->phoneNum);
    }

    printf("\nfindByPhoneNum>:\n");
    contacts = findByPhoneNum("1");
    for (i = 0; contacts[i]->id != END_ID_CODE; i++) {
        printf("%d,%s,%s\n", contacts[i]->id, contacts[i]->name, contacts[i]->phoneNum);
    }

    destroy();
}


int main() {
//    testAdd();
//    testDelAndDestroy();
//     testAddRepeat();
    testFindByNameOrPhone();
    return 0;
}

