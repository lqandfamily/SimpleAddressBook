#include "ArrayListCore.h"

int add(ContactInfo *contactInfo){
    contactNum++;
    if(contactNum >= MAX_CONTACT){
        return RUN_OUT;
    }
    contactArr[contactNum] = contactInfo;
    return SUCCESS;
}

int addByInfo(char *name,char *phoneNum, char *address, char *group){
    if(name == NULL || strcmp(name,"") == 0){
        return NAME_NULL;
    }
    if(phoneNum == NULL || strcmp(phoneNum,"") == 0){
        return PHONE_NULL;
    }
    if(findByAbsoluteName(name) != NULL){
        return NAME_EXIST;
    }
    if(findByAbsolutePhoneNum(phoneNum) != NULL){
        return PHONE_EXIST;
    }
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
