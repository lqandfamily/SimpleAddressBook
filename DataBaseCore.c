#include "DataBaseCore.h"

int openFile(char *fileUrl, char *mode, FILE **dbFile);

int closeFile(FILE *dbFile);

int readContactsFromDB(char *fileUrl, ContactInfo *contactArr[], int *contactNum) {
    FILE *db;
    int i, flag;
    if (openFile(fileUrl, "r", &db) != SUCCESS) {
        return FILE_OPEN_ERROR;
    }


    i = 0;
    while (1) {
        //动态内存申请
        ContactInfo *newContact = malloc(sizeof(ContactInfo));
        if (newContact == NULL) {
            return MALLOC_ERROR;
        }
        flag = fscanf(db, "%d", &newContact->id);
        if (flag == EOF) {
            *contactNum = i - 1;
            contactArr[i] = getEndContact();
            if (closeFile(db) == FILE_CLOSE_ERROR) {
                return FILE_CLOSE_ERROR;
            }
            return SUCCESS;
        }

        fscanf(db, "%s", newContact->name);
        fscanf(db, "%s", newContact->phoneNum);
        fscanf(db, "%s", newContact->address);
        fscanf(db, "%d", &newContact->groupId);

        contactArr[i] = newContact;
        i++;
        //联系人数组用尽
        if (i >= MAX_CONTACT - 1) {
            *contactNum = i - 1;
            contactArr[i] = getEndContact();
            if (closeFile(db) == FILE_CLOSE_ERROR) {
                return FILE_CLOSE_ERROR;
            }
            return RUN_OUT;
        }

//        //此段为调试用代码
//        printf("************%d,%s,%s,%s,%d\n", newContact->id, newContact->name, newContact->phoneNum,
//               newContact->address, newContact->groupId);

    }

}

int writeContactsToDB(char *fileUrl, ContactInfo *contactArr[]) {
    int i;
    FILE *db = NULL;

    if (openFile(fileUrl, "w", &db) != SUCCESS) {
        return FILE_OPEN_ERROR;
    }

    for (i = 0; contactArr[i]->id != END_ID_CODE; i++) {

        if (EOF ==
            fprintf(db, "%d %s %s %s %d\n", contactArr[i]->id, contactArr[i]->name, contactArr[i]->phoneNum,
                    contactArr[i]->address,
                    contactArr[i]->groupId)) {
            return FILE_WRITE_ERROR;
        }
    }

    if (closeFile(db) == FILE_CLOSE_ERROR) {
        return FILE_CLOSE_ERROR;
    }
    return SUCCESS;
}


int readGroupsFromDB(char *fileUrl, Group *groupArr[], int *groupNum) {
    FILE *db;
    int i, flag;
    if (openFile(fileUrl, "r", &db) != SUCCESS) {
        return FILE_OPEN_ERROR;
    }


    i = 0;
    while (1) {
        //动态内存申请
        Group *newGroup = malloc(sizeof(Group));
        if (newGroup == NULL) {
            return MALLOC_ERROR;
        }
        flag = fscanf(db, "%d", &newGroup->id);
        if (flag == EOF) {
            *groupNum = i - 1;
            groupArr[i] = getEndGroup();
            if (closeFile(db) == FILE_CLOSE_ERROR) {
                return FILE_CLOSE_ERROR;
            }
            return SUCCESS;
        }
        fscanf(db, "%s", newGroup->group);

        groupArr[i] = newGroup;

        i++;
        //联系人数组用尽
        if (i >= MAX_CONTACT - 1) {
            *groupNum = i - 1;
            groupArr[i] = getEndGroup();
            if (closeFile(db) == FILE_CLOSE_ERROR) {
                return FILE_CLOSE_ERROR;
            }
            return RUN_OUT;
        }

//        //此段为调试用代码
//        printf("************%d,%s,%s,%s,%d\n", newContact->id, newContact->name, newContact->phoneNum,
//               newContact->address, newContact->groupId);

    }

}

int writeGroupsToDB(char *fileUrl, Group *groupArr[]) {
    int i;
    FILE *db = NULL;

    if (openFile(fileUrl, "w", &db) != SUCCESS) {
        return FILE_OPEN_ERROR;
    }

    for (i = 0; groupArr[i]->id != END_ID_CODE; i++) {

        if (EOF ==
            fprintf(db, "%d %s\n", groupArr[i]->id, groupArr[i]->group)) {
            return FILE_WRITE_ERROR;
        }
    }

    if (closeFile(db) == FILE_CLOSE_ERROR) {
        return FILE_CLOSE_ERROR;
    }
    return SUCCESS;
}

int readAllFromDB(ContactInfo *contactArr[],Group *groupArr[], int *contactNum, int *groupNum) {

    switch (readContactsFromDB(CONTACTS_DB_FILE_URL,contactArr, contactNum)) {
        case FILE_OPEN_ERROR:
            return FILE_OPEN_ERROR;
        case FILE_CLOSE_ERROR:
            return FILE_CLOSE_ERROR;
        case MALLOC_ERROR:
            return MALLOC_ERROR;
    }

    switch (readGroupsFromDB(GROUPS_DB_FILE_URL,groupArr,groupNum)) {
        case FILE_OPEN_ERROR:
            return FILE_OPEN_ERROR;
        case FILE_CLOSE_ERROR:
            return FILE_CLOSE_ERROR;
        case MALLOC_ERROR:
            return MALLOC_ERROR;
    }
    return SUCCESS;
}
int writeAllToDB(ContactInfo *contactArr[],Group *groupArr[]){
    switch (writeContactsToDB(CONTACTS_DB_FILE_URL,contactArr)) {
        case FILE_OPEN_ERROR:
            return FILE_OPEN_ERROR;
        case FILE_CLOSE_ERROR:
            return FILE_CLOSE_ERROR;
        case FILE_WRITE_ERROR:
            return FILE_WRITE_ERROR;
    }

    switch (writeGroupsToDB(GROUPS_DB_FILE_URL,groupArr)) {
        case FILE_OPEN_ERROR:
            return FILE_OPEN_ERROR;
        case FILE_CLOSE_ERROR:
            return FILE_CLOSE_ERROR;
        case FILE_WRITE_ERROR:
            return FILE_WRITE_ERROR;
    }
    return SUCCESS;
}

/**
 * 打开DB文件
 * @param fileUrl 文件全路径
 * @param mode 文件打开模式
 * @param dbFile File类型指针地址，用于接收打开的文件指针
 * @return FILE_OPEN_ERROR
 */
int openFile(char *fileUrl, char *mode, FILE **dbFile) {
    *dbFile = fopen(fileUrl, mode);
    if (*dbFile == NULL) {
        return FILE_OPEN_ERROR;
    }
    return SUCCESS;
}

/**
 * 关闭DB文件
 * @param dbFile
 * @return File_CLOSER_ERROR
 */
int closeFile(FILE *dbFile) {
    if (fclose(dbFile) != 0) {
        return FILE_CLOSE_ERROR;
    }
    return SUCCESS;
}