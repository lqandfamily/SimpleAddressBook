/**
 * 核心数组和数据持久化联合调试
 * @author lq
 * @date 2020/2/14
 * @version 0.3
 */

#include "ArrayListCore.h"

ContactInfo *contacts[MAX_CONTACT];
Group *groups[MAX_GROUP];
/**
 * 测试环境初始化
 * @return
 */
void initEnv(){
    init();
    addByInfo("bob","10086","London","friends");
    addByInfo("tom","10010","Shanghai","family");
    addByInfo("alice","10001","Beijing","friends");
}

/**
 * 打印详细信息
 */
void printInfo(ContactInfo *mContacts[], Group *mGroups[]){
    int i;
    for(i = 0; mContacts[i]->id != END_ID_CODE; i++){
        printf("%d,%s,%s,%s,%d,%s\n", mContacts[i]->id, mContacts[i]->name, mContacts[i]->phoneNum, mContacts[i]->address,
               mContacts[i]->groupId, mGroups[mContacts[i]->groupId]->group);
    }
}

/**
 * 测试添加及持久化
 */
void uniTestAdd(){
    initEnv();

    printf("Memory Data:\n");
    printInfo(findAll(),findGroups());

    saveToDB();

    destroy();
}

/**
 * 测试读取
 */
void uniTestRead(){
    loadFromDB();

    printf("Memory Data:\n");
    printInfo(findAll(),findGroups());

    destroy();
}

/**
 * 测试删除
 */
void uniTestDel(){
    initEnv();
    printInfo(findAll(),findGroups());
    saveToDB();
    destroy();

    loadFromDB();
    int delId = findByAbsoluteName("bob")->id;
    printf("delete tom,id = %d\n",delId);
    del(delId);
    printInfo(findAll(),findGroups());
    saveToDB();
    destroy();

      //TODO 奇怪的BUG
//    loadFromDB();
//    printf("****************\n");
//    printInfo(findAll(),findGroups());
//    destroy();
}

/**
 * 测试修改
 */
void uniTestAlt(){
    initEnv();
    printInfo(findAll(),findGroups());
    saveToDB();
    destroy();

    loadFromDB();
    int altId = findByAbsoluteName("bob")->id;
    printf("alt tom,id = %d\n",altId);

    altName(altId,"BOB");

    printInfo(findAll(),findGroups());
    saveToDB();
    destroy();

    uniTestRead();

}

//int main(){
////    uniTestAdd();
////    uniTestRead();
////    uniTestDel();
//uniTestAlt();
//    return 0;
//}