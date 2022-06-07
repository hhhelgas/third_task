//
// Created by basya on 05.06.2022.
//

#ifndef THIRD_TASK_ABSTRACTLIST_H
#define THIRD_TASK_ABSTRACTLIST_H

#include <cstddef>

template <typename T> class AbstractIterator;

template <typename T> class AbstractList {

public:

    //Àáñòðàêòíûé êëàññ «Ñïèñîê» ñ ÷èñòî âèðòóàëüíûìè ìåòîäàìè ðàáîòû ñî ñïèñêîì
    AbstractList<T>() {};
    virtual void add(T& element, AbstractIterator<T>* it) = 0;//âñòàâèòü ýëåìåíò â ïîçèöèþ, îòìå÷åííóþ èòåðàòîðîì,
    virtual T& pop(AbstractIterator<T>* it) = 0;//	óäàëèòü ýëåìåíò, îòìå÷åííûé èòåðàòîðîì,
    virtual AbstractIterator<T>& findFirstInput(T elem) = 0;//	íàéòè ïåðâîå âõîæäåíèå ýëåìåíòà â ñïèñîê, ðåçóëüòàò – èòåðàòîð íà íàéäåííûé ýëåìåíò,
    virtual void clear() = 0;//	ñäåëàòü ñïèñîê ïóñòûì,
    virtual bool isEmpty() = 0;//	ïðîâåðêà íà ïóñòîòó,
    virtual size_t getSize() = 0;//	êîëè÷åñòâî ýëåìåíòîâ â ñïèñêå,
    virtual AbstractIterator<T>& begin() = 0;//	ïîëó÷èòü èòåðàòîð íà ïåðâûé ýëåìåíò ñïèñêà.
    virtual ~AbstractList<T>() = default;
};

template <typename T> class AbstractIterator {

public:

    //Àáñòðàêòíûé êëàññ «Èòåðàòîð» ñ ìåòîäàìè :
    AbstractIterator(){};
    virtual void start() = 0;//íà÷àòü ðàáîòó,
    virtual T& getElement() = 0;//	ïîëó÷èòü î÷åðåäíîé ýëåìåíò,
    virtual void next() = 0;//	ñäâèíóòü èòåðàòîð íà ñëåäóþùèé ýëåìåíò,
    virtual bool finish() = 0;//	ïðîâåðêà, âñå ëè ïðîèòåðèðîâàíî.
    virtual ~AbstractIterator() = default;
};
#endif //THIRD_TASK_ABSTRACTLIST_H
