/**
 * 测试核心数据库存储
 * @author lq
 * @version 0.2
 * @date 2020/2/13
 */
#include "DataBaseCore.h"

void dbTestWriteContacts() {
    int i;
    init();
    addByInfo("bob", "10086", "London", "friends");
    addByInfo("tom", "10001", "London", "family");
    addByInfo("alice", "10000", "London", "friends");
    ContactInfo **contacts = findAll();
    Group **groups = findGroups();

    for (i = 0; groups[i]->id != END_ID_CODE; i++){
        printf("***********:%d,%s\n",groups[i]->id,groups[i]->group);
    }


    int resultCodeContact = writeContactsToDB(CONTACTS_DB_FILE_URL, contacts);
    int resultCodeGroup = writeGroupsToDB(GROUPS_DB_FILE_URL, groups);
    printf("resultCodeContact:%d\n", resultCodeContact);
    printf("resultCodeGroup:%d\n", resultCodeGroup);
    destroy();
}

void dbTestReadContacts() {
    int i;
    init();

    ContactInfo *contacts[MAX_CONTACT];
    Group *groups[MAX_GROUP];

    readContactsFromDB(CONTACTS_DB_FILE_URL, contacts);
    readGroupsFromDB(GROUPS_DB_FILE_URL, groups);

    for (i = 0; contacts[i]->id != END_ID_CODE; i++) {
        printf("%d,%s,%s,%s,%d,%s\n", contacts[i]->id, contacts[i]->name, contacts[i]->phoneNum, contacts[i]->address,
              contacts[i]->groupId,groups[contacts[i]->groupId]->group);
    }
    destroy();

}

int main() {
    dbTestWriteContacts();
    dbTestReadContacts();

    return 0;
}
