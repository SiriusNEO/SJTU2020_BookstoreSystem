//
// Created by SiriusNEO on 2020/11/7.
// Filename:DataOperation.h
// 数据操作类 声明文件
//

#ifndef BOOKSTORESYSTEM_DATAOPERATION_H
#define BOOKSTORESYSTEM_DATAOPERATION_H

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include "HashTable.h"

const int ISBNMaxl = 21;
const int BookMaxl = 61;
const int MaxQ = 100002;

class Book {
    public:
        std::string ISBN, name, author, keyword;
        double price;
        int quantity;
        bool isDeleted;
        Book();
        void Print() const;
};

class DataOperation {
    private:
        int selectBook;
        int tot;
        double bill[MaxQ];
        std::fstream dbFile, billFile;
        const std::string dbFileName, billFileName;
        HashTable ISBNHashTable, nameHashTable, authorHashTable, keywordHashTable;

    public:
        DataOperation();
        ~DataOperation();
        int Save(Book book);
        void SaveIn(Book book, int offset);
        Book Load(int offset);
        //void Print();
        int bookadd(const std::string& ISBN, const std::string& name, const std::string& author, const std::string& keyword, double price, int quantity);
        int select(const std::string& ISBN, int authority);
        int modify(std::string ISBN, std::string name, std::string author, std::string keyword, double price, int authority);
        void import(int quantity, double cost_price, int authority);
        void show(const std::string& ISBN, const std::string& name, const std::string& author, const std::string& keyword, int authority);
        void buy(const std::string& ISBN, int quantity, int authority);
        void show_finance(int time, int authority);
};

#endif //BOOKSTORESYSTEM_DATAOPERATION_H