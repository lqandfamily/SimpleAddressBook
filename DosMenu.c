#include "DosMenu.h"

int mainMenu( ) {
    int menuIndex;
    loadFromFile();

    while (1) {
        puts(MAIN_MENU);

        inputMenuIndex(&menuIndex,5);

        switch (menuIndex){
            case -1:
                saveToFile();
                printf("good bye! exiting...\n");
                return 0;
            case 1:
                showAllContacts();
                break;
            case 2:
                showAllGroups();
                break;
            case 4:
                newContact();
                break;
            case 5:
                saveToFile();
                break;
            default:
                break;
        }

    }
}

int showAllContacts( ) {
    int i,menuIndex;

    ContactInfo **contacts = findAll();

    puts(ALL_CONTACTS);

    if (contacts[0]->id == END_ID_CODE) {
        printf("There no contact, please to add\n");
        return SUCCESS;
    }

    printf("ID  NAME    PHONE          ADDRESS          Group     \n");
    for (i = 0; contacts[i]->id != END_ID_CODE; i++) {
        printf("%-4d%-8s%-15s%-17s%-10s\n", contacts[i]->id + 1, contacts[i]->name, contacts[i]->phoneNum, contacts[i]->address, getGroupName(contacts[i]->groupId));
    }

    /**
     * 下级菜单
     */
    inputMenuIndex(&menuIndex,i);
    if(menuIndex == -1){
        return SUCCESS;
    } else{
        showDetails(menuIndex - 1);
    }

    return SUCCESS;
}

int showAllGroups(){
    int i,menuIndex;

    Group **groups = findGroups();

    puts(ALL_GROUPS);

    if (groups[0]->id == END_ID_CODE) {
        printf("There no group, please to add\n");
        return SUCCESS;
    }

    printf("ID  GROUP     \n");
    for (i = 0; groups[i]->id != END_ID_CODE; i++) {
        printf("%-4d%-10s\n", groups[i]->id + 1, groups[i]->group);
    }

    /**
     * 下级菜单
     */
    inputMenuIndex(&menuIndex,i);
    if(menuIndex == -1){
        return SUCCESS;
    } else{
        showContactsOfGroup(menuIndex - 1);
    }

    return SUCCESS;
}


int showContactsOfGroup(int groupId){
    //maxContactId 该分组下联系人中最大的id，用于下级菜单输入索引判断
    int i, menuIndex, maxContactId = -1;

    ContactInfo **contacts = findByGroup(getGroupName(groupId));

    puts(ALL_CONTACTS);

    if (contacts[0]->id == END_ID_CODE) {
        printf("There no contact, please to add\n");
        return SUCCESS;
    }

    printf("ID  NAME    PHONE          ADDRESS          Group     \n");
    for (i = 0; contacts[i]->id != END_ID_CODE; i++) {
        printf("%-4d%-8s%-15s%-17s%-10s\n", contacts[i]->id + 1, contacts[i]->name, contacts[i]->phoneNum, contacts[i]->address, getGroupName(contacts[i]->groupId));
    }

    /**
     * 下级菜单
     */

    inputMenuIndex(&menuIndex,MAX_MENU_INDEX);

    if(menuIndex == -1){
        return SUCCESS;
    } else{
        showDetails(menuIndex - 1);
    }

    return SUCCESS;
}


int showDetails(int id){
    int menuIndex;
    ContactInfo *contact = getContactById(id);

    puts(CONTACT_DETAILS);

    printf("ID  NAME    PHONE          ADDRESS          Group     \n");
    printf("%-4d%-8s%-15s%-17s%-10s\n", contact->id + 1, contact->name, contact->phoneNum, contact->address, getGroupName(contact->groupId));

    inputMenuIndex(&menuIndex,2);

    switch (menuIndex){
        case -1:
            return SUCCESS;
        case 1:
            modifyContact(id);
            break;
        case 2:
            deleteContact(id);
            break;
        default:
            break;
    }

    return SUCCESS;
}

int vagueSearch( );

int deleteContact(int id){
    int menuIndex;

    printf("DO you want to delete? '1' to delete, '-1' to cancel\n");

    inputMenuIndex(&menuIndex,1);

    if(menuIndex == 1){
        del(id);
    }

    return SUCCESS;
}

int modifyContact(int id){
    char line[50];

    printf("if you want modify the item, please input text, input enter to not modify\n");
    printf("input name:");

    fflush(stdin);
    gets(line);
    if(strcmp(line,"") != 0){
        altName(id,line);
    }


    printf("input phoneNumber:");
    fflush(stdin);
    gets(line);
    if(strcmp(line,"") != 0){
        altPhone(id,line);
    }


    printf("input address:");
    fflush(stdin);
    gets(line);
    if(strcmp(line,"") != 0){
        altAddress(id,line);
    }


    printf("input group:");
    fflush(stdin);
    gets(line);
    if(strcmp(line,"") != 0){
        altGroup(id,line);
    }

    return SUCCESS;
}

int newContact(){
    char name[20];
    char phone[20];
    char address[50];
    char group[20];

    puts(ADD_CONTACT);

    printf("input name:");

    fflush(stdin);
    gets(name);
    if(strcmp(name,"") == 0) {
        printf("ERROR:name can't be NULL!\n");
        return ERROR;
    }

    printf("input phoneNumber:");
    fflush(stdin);
    gets(phone);
    if(strcmp(phone,"") == 0) {
        printf("ERROR:phone can't be NULL!\n");
        return ERROR;
    }


    printf("input address:");
    fflush(stdin);
    gets(address);

    printf("input group:");
    fflush(stdin);
    gets(group);

    //添加
    if(addByInfo(name,phone,address,group) != SUCCESS){
        printf("ERROR:add a contact error!\n");
        return ERROR;
    }
    printf("SUCCESS:add a contact success!\n");

    return SUCCESS;
}

int loadFromFile() {

    if (loadFromDB() == ERROR) {
        printf("ERROR:read file error!\n");
        return ERROR;
    }
    printf("SUCCESS:load success!\n");
    return SUCCESS;
}

int saveToFile(){
    if(saveToDB() == ERROR){
        printf("ERROR:save to file error! sorry...\n");
        return ERROR;
    }
    printf("SUCCESS:save success!\n");
    return SUCCESS;
}

int inputMenuIndex(int *menuIndex , int maxMenuIndex) {
    char line[20];
    puts(INPUT_MENU_INDEX);
    scanf("%s", line);
    while ((*menuIndex = strtol(line, NULL, 0)) == 0 || *menuIndex < MIN_MENU_INDEX || *menuIndex > maxMenuIndex) {
        puts("\nindex Error!,please input again:");
        scanf("%s", line);
    }
    return SUCCESS;
}


int main() {
    int menuIndex = 999;
    mainMenu(&menuIndex);

    return 0;
}
