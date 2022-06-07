//
// Created by basya on 05.06.2022.
//

#ifndef THIRD_TASK_LISTEXCEPTION_H
#define THIRD_TASK_LISTEXCEPTION_H
#include <exception>
class ListException: public std::exception {

    const char* message;
public:
    ListException(const char* msg) :message(msg) {};
    const char* what() { return message; }
};
#endif //THIRD_TASK_LISTEXCEPTION_H
