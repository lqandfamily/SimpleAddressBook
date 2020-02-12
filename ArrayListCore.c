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
ContactInfo *getEndContact(){
    if(endContact == NULL){
        endContact = malloc(sizeof(ContactInfo));
        endContact->id = END_ID_CODE;
    }
    return endContact;
}

int add(ContactInfo *contactInfo){
    contactNum++;
    if(contactNum >= MAX_CONTACT){
        return RUN_OUT;
    }
    contactArr[contactNum] = contactInfo;
    //结束ID处理
    contactArr[contactNum + 1] = getEndContact();
    return SUCCESS;
}

int addByInfo(char *name,char *phoneNum, char *address, char *group){
    if(name == NULL || strcmp(name,"") == 0){
        return NAME_NULL;
    }
    if(phoneNum == NULL || strcmp(phoneNum,"") == 0){
        return PHONE_NULL;
    }
//    if(findByAbsoluteName(name) != NULL){
//        return NAME_EXIST;
//    }
//    if(findByAbsolutePhoneNum(phoneNum) != NULL){
//        return PHONE_EXIST;
//    }
    /**
     * 动态申请内存地址
     */
    ContactInfo *newContact = malloc(sizeof(ContactInfo));
    if(newContact == NULL){
        return MALLOC_ERROR;
    }
    newContact->id = contactNum + 1;
    strcpy(newContact->name,name);
    strcpy(newContact->phoneNum,phoneNum);
    if(address == NULL){
        address = "";
    }
    if(group == NULL){
        group = "";
    }
    strcpy(newContact->address,address);
    strcpy(newContact->group,group);

    if(add(newContact) == RUN_OUT){
        return RUN_OUT;
    }

    return SUCCESS;
}

int del(int id){
    int i;
    if(id < 0 || id > contactNum - 2){
        //TODO id不存在时的处理
        return ID_NOT_EXIST;
    }
    //处理到结束ID
    for(i = id; i < contactNum; i++){
        contactArr[i] = contactArr[i+1];
    }
    return SUCCESS;
}

ContactInfo **findAll(){
    return contactArr;
}

