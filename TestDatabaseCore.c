/**
 * 测试核心数据库存储
 * @author lq
 * @version 0.2
 * @date 2020/2/13
 */
#include "DataBaseCore.h"

void dbTestAdd(){
    init();
    addByInfo("bob","10086","London","friends");
    ContactInfo *bobContact = findByAbsoluteName("bob");


    printf("%s\n",bobContact->name);

    int resultCode = addContactToDB(CONTACTS_DB_FILE_URL,bobContact);
    printf("resultCode:%d\n",resultCode);
    destroy();
}

void dbTestReadAll(){
    init();

    readContactsFromDB(CONTACTS_DB_FILE_URL,NULL);

    destroy();

}

int main(){
    dbTestAdd();
    dbTestReadAll();

    return 0;
}
