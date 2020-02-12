#include "ArrayListCore.h"

//核心联系人数组,使用指针来存储，减少内存开销
//为了识别最后一个联系人，使用特殊id(END_ID_CODE)做标记
ContactInfo *contactArr[MAX_CONTACT];
//联系人数量，这里做id
int contactNum = -1;
//结束联系人
ContactInfo *endContact = NULL;

/**
 * 结束联系人标志
 */
ContactInfo *getEndContact() {
    if (endContact == NULL) {
        endContact = malloc(sizeof(ContactInfo));
        endContact->id = END_ID_CODE;
    }
    return endContact;
}

int destroy() {
    int i;
    for (i = 0; i <= contactNum; i++) {
        free(contactArr[i]);
        contactArr[i] = NULL;
    }
    return SUCCESS;
}

int init() {
    if (contactNum != -1) {
        return ERROR;
    }
    contactArr[0] = getEndContact();
    return SUCCESS;
}

int add(ContactInfo *contactInfo) {
    contactNum++;
    if (contactNum >= MAX_CONTACT) {
        return RUN_OUT;
    }
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
    strcpy(newContact->group, group);

    if (add(newContact) == RUN_OUT) {
        return RUN_OUT;
    }

    return SUCCESS;
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
    if (m == 0) {
        return NULL;
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

ContactInfo **findByPhoneNum(char *phoneNum){
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
    if (m == 0) {
        return NULL;
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

ContactInfo **findByGroup(char *group);

int altName(int id, char *name){
    if(id <0 || id > contactNum || contactArr[id] == NULL){
        return ID_NOT_EXIST;
    }
    if(name == NULL || strcmp(name,"") == 0){
        return NAME_NULL;
    }
    if(findByAbsoluteName(name) != NULL){
        return NAME_EXIST;
    }
    strcpy(contactArr[id]->name,name);
    return SUCCESS;
}

int altPhone(int id, char *phoneNum){
    if(id <0 || id > contactNum || contactArr[id] == NULL){
        return ID_NOT_EXIST;
    }
    if(phoneNum == NULL || strcmp(phoneNum,"") == 0){
        return NAME_NULL;
    }
    if(findByAbsolutePhoneNum(phoneNum) != NULL){
        return NAME_EXIST;
    }
    strcpy(contactArr[id]->phoneNum,phoneNum);
    return SUCCESS;
}

int altAddress(int id, char *address){
    if(id <0 || id > contactNum || contactArr[id] == NULL){
        return ID_NOT_EXIST;
    }
    if(address == NULL){
        address = "";
    }
    strcpy(contactArr[id]->address,address);
    return SUCCESS;
}

int altGroup(int id, char *group){
    if(id <0 || id > contactNum || contactArr[id] == NULL){
        return ID_NOT_EXIST;
    }
    if(group == NULL){
        group = "";
    }
    strcpy(contactArr[id]->group,group);
    return SUCCESS;
}


