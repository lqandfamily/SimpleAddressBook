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
    del(0);
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

/**
 * 测试修改姓名和电话
 */
void testAltNameOrPhone() {
    int i;
    init();
    addByInfo("bob", "10086", "London", NULL);
    addByInfo("tom", "10001", "Shanghai", NULL);
    ContactInfo *findBobInfo = findByAbsoluteName("bob");

    int resultCode = altName(findBobInfo->id, "BOB");
    altPhone(findBobInfo->id, "1111");

    switch (resultCode) {
        case ID_NOT_EXIST:
            printf("ID_NOT_EXIST!\n");
            break;
        case NAME_NULL:
            printf("NAME_NULL!\n");
            break;
        case NAME_EXIST:
            printf("NAME_EXIST!\n");
            break;
        default:
            break;
    }

    ContactInfo **contacts = findAll();
    for (i = 0; contacts[i]->id != END_ID_CODE; i++) {
        printf("%d,%s,%s\n", contacts[i]->id, contacts[i]->name, contacts[i]->phoneNum);
    }
    destroy();
}

/**
 * 测试修改地址和分组
 */
void testAltAddressOrGroup() {
    int i;
    init();
    addByInfo("bob", "10086", "London", NULL);
    addByInfo("tom", "10001", "Shanghai", NULL);
    ContactInfo *findBobInfo = findByAbsoluteName("bob");

    int resultCode = altAddress(findBobInfo->id, "Guizhou");
    altGroup(findBobInfo->id, "friends");

    if (resultCode == ID_NOT_EXIST) {
        printf("ID_NOT_EXIST!\n");
    }

    ContactInfo **contacts = findAll();
    for (i = 0; contacts[i]->id != END_ID_CODE; i++) {
        printf("%d,%s,%s,%s,%d\n", contacts[i]->id, contacts[i]->name, contacts[i]->phoneNum, contacts[i]->address,
               contacts[i]->groupId);
    }
    destroy();
}

void testFindByGroup() {
    int i;
    init();
    addByInfo("bobb", "10086", "London", "family");
    addByInfo("blili", "10001", "Shanghai", "family");
    addByInfo("tom", "10003", "Shanghai", "friend");
    addByInfo("fbf", "10002", "Shanghai", "friend");

    printf("findByName>:\n");
    ContactInfo **contacts = findByGroup("family");
    for (i = 0; contacts[i]->id != END_ID_CODE; i++) {
        printf("%d,%s,%s\n", contacts[i]->id, contacts[i]->name, contacts[i]->phoneNum);
    }

    destroy();
}


/**
 * 测试添加分组和查找所有分组
 */
void testAddAndFindAllGroup() {
    int i;
    init();
    addByInfo("bob", "10086", "London", "friend");
    addByInfo("tom", "10001", "Shanghai", "friend");
    addByInfo("alice", "100011", "Zunyi", "family");

    ContactInfo **contacts = findAll();
    for (i = 0; contacts[i]->id != END_ID_CODE; i++) {
        printf("%d,%s,%s,%s,%d,%s\n", contacts[i]->id, contacts[i]->name, contacts[i]->phoneNum, contacts[i]->address,
               contacts[i]->groupId,getGroupName(contacts[i]->groupId));
    }

    Group **groups = findGroups();
    for(i = 0; groups[i]->id != END_ID_CODE; i++){
        printf("%d,%s\n",groups[i]->id,groups[i]->group);
    }

    destroy();
}

/**
 * 单独测试添加分组和查询所有分组
 */
void testAddGroup(){
    int i;
    init();

    addGroup("friend");
    addGroup("family");
    Group **groups = findGroups();

    for(i = 0; groups[i]->id != END_ID_CODE; i++){
        printf("%d,%s\n",groups[i]->id,groups[i]->group);
    }

    destroy();
}

int main() {
//    testAdd();
//    testDelAndDestroy();
//     testAddRepeat();
//    testFindByNameOrPhone();
//    testAltNameOrPhone();
//    testAltAddressOrGroup();
//    testFindByGroup();
    testAddAndFindAllGroup();
//testAddGroup();
    return 0;
}

