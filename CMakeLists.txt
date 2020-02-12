cmake_minimum_required(VERSION 3.15)
project(SimpleAddressBook C)

set(CMAKE_C_STANDARD 99)

add_executable(SimpleAddressBook main.c AddressBook.c AddressBook.h ArrayListCore.c ArrayListCore.h ErrorCode.h Config.h TestArrayListCore.c)