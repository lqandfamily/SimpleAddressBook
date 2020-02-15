/**
 * DOS菜单系统
 * @author lq
 * @date 2020/2/14
 * @version 0.3
 */

#ifndef DOS_MENU_H
#define DOS_MENU_H

#include "ArrayListCore.h"

char *MAIN_MENU = "**********SimpleAddressBook Software**********\n"
                  "1.show all contacts\n"
                  "2.show all groups\n"
                  "3.vague search\n"
                  "4.add\n"
                  "5.save to file\n"
                  ">>>input menu index:";
char *ALL_CONTACTS = "**********ALL CONTACTS*********\n"
                     "*****input 'q' to exit, input index to show details*****\n";

char *CONTACT_DETAILS = "*********CONTACT DETAILS**********\n"
                        "q.exit\n"
                        "1.modify\n"
                        "2.delete\n";
char *ALL_GROUPS = "**********ALL GROUPS**********\n"
                   "*****input 'q' to exit, input index to show  all contacts of the group******\n";

char *VAGUE_SEARCH = "**********VAGUE SEARCH**********\n"
                     "1.by name\n"
                     "2.by phoneNumber\n"
                     "3.by exact group name\n"
                     ">>>input menu index:";

char *ADD_CONTACT = "**********ADD**********\n"
                   "input name:";

char *INPUT_MENU_INDEX = ">>>input menu index:";

int mainMenu(int *menuIndex);

int showAllContacts(int *menuIndex);

int showAllGroups(int *menuIndex);

int showDetails(int *menuIndex);

int vagueSearch(int *menuIndex);

int deleteContact(int *menuIndex);

int modifyContact(int *menuIndex);

int loadFromFile();

int saveToFile(int *menuIndex);

#endif
