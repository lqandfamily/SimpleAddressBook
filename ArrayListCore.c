#include "ArrayListCore.h"

//核心联系人数组,使用指针来存储，减少内存开销
//为了识别最后一个联系人，使用特殊id(END_ID_CODE)做标记
ContactInfo *contactArr[MAX_CONTACT];

//Group数组，同样使用指针来存储
Group *groupArr[MAX_GROUP];

//分组数量，这里做id
int groupNum = -1;

//结束分组
Group *endGroup = NULL;

//联系人数量，这里做id
int contactNum = -1;

//结束联系人
ContactInfo *endContact = NULL;


ContactInfo *getEndContact() {
    if (endContact == NULL) {
        endContact = malloc(sizeof(ContactInfo));
        endContact->id = END_ID_CODE;
    }
    return endContact;
}

Group *getEndGroup() {
    if (endGroup == NULL) {
        endGroup = malloc(sizeof(Group));
        endGroup->id = END_ID_CODE;
    }
    return endGroup;
}

int destroy() {
    int i;
    for (i = 0; i <= contactNum; i++) {
        free(contactArr[i]);
        contactArr[i] = NULL;
    }
    for (i = 0; i <= groupNum; i++) {
        free(groupArr[i]);
        groupArr[i] = NULL;
    }
    return SUCCESS;
}

int init() {
    if (contactNum != -1 || groupNum != -1) {
        return ERROR;
    }
    contactArr[0] = getEndContact();
    groupArr[0] = getEndGroup();
    return SUCCESS;
}

int add(ContactInfo *contactInfo) {
    if (contactNum + 1 >= MAX_CONTACT - 1) {
        return RUN_OUT;
    }
    contactNum++;
    contactArr[contactNum] = contactInfo;
    //结束ID处理
    contactArr[contactNum + 1] = getEndContact();
    return SUCCESS;
}

int addByInfo(char *name, char *phoneNum, char *address, char *group) {
    if (name == NULL || strcmp(name, "") == 0) {
        return NAME_NULL;
    }
    if (phoneNum == NULL || strcmp(phoneNum, "") == 0) {
        return PHONE_NULL;
    }
    if (findByAbsoluteName(name) != NULL) {
        return NAME_EXIST;
    }
    if (findByAbsolutePhoneNum(phoneNum) != NULL) {
        return PHONE_EXIST;
    }
    /**
     * 动态申请内存地址
     */
    ContactInfo *newContact = malloc(sizeof(ContactInfo));
    if (newContact == NULL) {
        return MALLOC_ERROR;
    }
    newContact->id = contactNum + 1;
    strcpy(newContact->name, name);
    strcpy(newContact->phoneNum, phoneNum);
    if (address == NULL) {
        address = "";
    }
    if (group == NULL) {
        group = "";
    }
    strcpy(newContact->address, address);

    newContact->groupId = getGroupId(group);

    if (newContact->groupId == GROUP_NOT_EXIST) {
        newContact->groupId = addGroup(group);
    }

    if (add(newContact) == RUN_OUT) {
        return RUN_OUT;
    }

    return SUCCESS;
}

int addGroup(char *group) {
    int i;
    //TODO
    if (groupNum + 1 >= MAX_GROUP - 1) {
        return RUN_OUT;
    }
    if (group == NULL || strcmp(group, "") == 0) {
        return GROUP_NULL;
    }
    for (i = 0; i <= groupNum; i++) {
        if (strcmp(group, groupArr[i]->group) == 0) {
            return GROUP_EXIST;
        }
    }

    //动态申请内存地址
    Group *newGroup = malloc(sizeof(Group));
    if (newGroup == NULL) {
        return MALLOC_ERROR;
    }
    groupNum++;

    newGroup->id = groupNum;
    strcpy(newGroup->group, group);

    groupArr[groupNum] = newGroup;

    groupArr[groupNum + 1] = getEndGroup();
    return groupNum;
}

int del(int id) {
    int i;
    if (id < 0 || id > contactNum) {
        //TODO id不存在时的处理
        return ID_NOT_EXIST;
    }
    //处理到结束ID
    free(contactArr[id]);
    contactArr[id] = NULL;
    for (i = id; i <= contactNum; i++) {
        contactArr[i] = contactArr[i + 1];
    }
    return SUCCESS;
}

ContactInfo **findAll() {
    return contactArr;
}

Group **findGroups() {
    return groupArr;
}

int getGroupId(char *group) {
    int i;
    if (group == NULL || strcmp(group, "") == 0) {
        return GROUP_NULL;
    }
    for (i = 0; i <= groupNum; i++) {
        if (strcmp(group, groupArr[i]->group) == 0) {
            return i;
        }
    }
    return GROUP_NOT_EXIST;
}

char *getGroupName(int id) {
    if (id < 0 || id > groupNum) {
        return NULL;
    }
    return groupArr[id]->group;
}


ContactInfo **findByName(char *name) {
    int i, m = 0;
    /**
     * 另外，C 不支持在函数外返回局部变量的地址，除非定义局部变量为 static 变量
     */
    static ContactInfo *foundContacts[MAX_CONTACT];

    for (i = 0; i <= contactNum; i++) {
        if (strstr(contactArr[i]->name, name) != NULL) {
            foundContacts[m++] = contactArr[i];
        }
    }
    foundContacts[m] = getEndContact();
    return foundContacts;
}

ContactInfo *findByAbsoluteName(char *absoluteName) {
    int i;
    if (absoluteName == NULL || strcmp(absoluteName, "") == 0) {
        return NULL;
    }
    for (i = 0; i <= contactNum; i++) {
        if (strcmp(contactArr[i]->name, absoluteName) == 0) {
            return contactArr[i];
        }
    }
    return NULL;
}

ContactInfo **findByPhoneNum(char *phoneNum) {
    int i, m = 0;
    /**
     * 另外，C 不支持在函数外返回局部变量的地址，除非定义局部变量为 static 变量
     */
    static ContactInfo *foundContacts[MAX_CONTACT];

    for (i = 0; i <= contactNum; i++) {
        if (strstr(contactArr[i]->phoneNum, phoneNum) != NULL) {
            foundContacts[m++] = contactArr[i];
        }
    }

    foundContacts[m] = getEndContact();
    return foundContacts;
}

ContactInfo *findByAbsolutePhoneNum(char *absolutePhoneNum) {
    int i;
    if (absolutePhoneNum == NULL || strcmp(absolutePhoneNum, "") == 0) {
        return NULL;
    }
    for (i = 0; i <= contactNum; i++) {
        if (strcmp(contactArr[i]->phoneNum, absolutePhoneNum) == 0) {
            return contactArr[i];
        }
    }
    return NULL;
}

ContactInfo *getContactById(int id){
    if(id < 0 || id > contactNum){
        return NULL;
    }
    return contactArr[id];
}

ContactInfo **findByGroup(char *group) {
    int i, m = 0;
    int foundGroupId = getGroupId(group);
    static ContactInfo *foundContacts[MAX_CONTACT];

    if (foundGroupId == GROUP_NOT_EXIST) {
        foundContacts[0] = getEndContact();
        return foundContacts;
    }

    for (i = 0; i <= contactNum; i++) {
        if (contactArr[i]->groupId == foundGroupId) {
            foundContacts[m++] = contactArr[i];
        }
    }

    foundContacts[m] = getEndContact();
    return foundContacts;
}

ContactInfo **findByGroupId(int groupId){
    int i,m;
    static ContactInfo *contacts[MAX_CONTACT];
    if(groupId < 0 || groupId > groupNum){
        return NULL;
    }

    m = 0;
    for(i = 0; contactArr[i]->id != END_ID_CODE;i++){
        if(contactArr[i]->groupId == groupId){
            contacts[m] = contactArr[i];
            m++;
        }
    }
    if(m == 0){
        return NULL;
    }

    contacts[m] = getEndContact();

    return contacts;
}

int altName(int id, char *name) {
    if (id < 0 || id > contactNum || contactArr[id] == NULL) {
        return ID_NOT_EXIST;
    }
    if (name == NULL || strcmp(name, "") == 0) {
        return NAME_NULL;
    }
    if (findByAbsoluteName(name) != NULL) {
        return NAME_EXIST;
    }
    strcpy(contactArr[id]->name, name);
    return SUCCESS;
}

int altPhone(int id, char *phoneNum) {
    if (id < 0 || id > contactNum || contactArr[id] == NULL) {
        return ID_NOT_EXIST;
    }
    if (phoneNum == NULL || strcmp(phoneNum, "") == 0) {
        return NAME_NULL;
    }
    if (findByAbsolutePhoneNum(phoneNum) != NULL) {
        return NAME_EXIST;
    }
    strcpy(contactArr[id]->phoneNum, phoneNum);
    return SUCCESS;
}

int altAddress(int id, char *address) {
    if (id < 0 || id > contactNum || contactArr[id] == NULL) {
        return ID_NOT_EXIST;
    }
    if (address == NULL) {
        return ADDRESS_NULL;
    }
    strcpy(contactArr[id]->address, address);
    return SUCCESS;
}

int altGroup(int id, char *group) {
    if (id < 0 || id > contactNum || contactArr[id] == NULL) {
        return ID_NOT_EXIST;
    }

    if (group == NULL) {
        return GROUP_NULL;
    }

    contactArr[id]->groupId = getGroupId(group);
    if (contactArr[id]->groupId == GROUP_NOT_EXIST) {
        contactArr[id]->groupId = addGroup(group);
    }

    return SUCCESS;
}

int saveToDB() {
    if (writeAllToDB(contactArr, groupArr) != SUCCESS) {
        return ERROR;
    }
    return SUCCESS;
}

int loadFromDB() {
    if (readAllFromDB(contactArr, groupArr,&contactNum,&groupNum) != SUCCESS) {
        return ERROR;
    }
    return SUCCESS;
}




