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
    ContactInfo *bobContact = findByAbsoluteName("bob");


    printf("%s\n", bobContact->name);

    int resultCode = addContactToDB(CONTACTS_DB_FILE_URL, bobContact);
    printf("resultCode:%d\n", resultCode);
    destroy();
}

void dbTestReadAll() {
    int i;
    init();

    ContactInfo *contacts[MAX_CONTACT];
    readContactsFromDB(CONTACTS_DB_FILE_URL, contacts);

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
