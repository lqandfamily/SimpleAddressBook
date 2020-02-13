/**
 * 测试核心数据库存储
 * @author lq
 * @version 0.2
 * @date 2020/2/13
 */
#include "DataBaseCore.h"

void dbTestAdd() {
    init();
    addByInfo("bob", "10086", "London", "friends");
    addByInfo("tom", "10001", "London", "friends");
    ContactInfo **contacts = findAll();


    int resultCode = writeToDB(CONTACTS_DB_FILE_URL, contacts,KIND_CONTACT);
    printf("resultCode:%d\n", resultCode);
    destroy();
}

void dbTestReadAll() {
    int i;
    init();

    ContactInfo *contacts[MAX_CONTACT];
    readFromDB(CONTACTS_DB_FILE_URL, contacts,KIND_CONTACT);

    for (i = 0; contacts[i]->id != END_ID_CODE; i++) {
        printf("%d,%s,%s,%s,%d\n", contacts[i]->id, contacts[i]->name, contacts[i]->phoneNum, contacts[i]->address,
              contacts[i]->groupId);
    }
    destroy();

}

int main() {
    dbTestAdd();
    dbTestReadAll();

    return 0;
}
