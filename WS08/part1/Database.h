/*Filename: Database.h
Author:	Festus Osayi
Student Number : 170276216
-----------------------------------------------------------
Date: 2023/03/19
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete the workshop.*/

#ifndef _SDDS_DATABASE_H_
#define _SDDS_DATABASE_H_
#include <iostream>
#include <memory>
#define ARRAY_KEYS 20
#define ARRAY_VALUE 20
#define MAX_ENTRIES 20

namespace sdds{
    enum class Err_Status
    {
        Err_Success,
        Err_NotFound,
        Err_OutOfMemory,
    };

    class Database{
       inline static std::shared_ptr<Database> da_database;
       size_t da_entries{};
       std::string da_keys[ARRAY_KEYS];
       std::string da_values[ARRAY_VALUE];
       std::string da_filename{};
       Database(const std::string& filename);
       std::string trim(const std::string& str);


       public:
       static std::shared_ptr<Database> getInstance(const std::string& filename);
       Err_Status GetValue(const std::string& key, std::string& value);
       Err_Status SetValue(const std::string& key, const std::string& value);
       ~Database();
    };
}

#endif //end of an if statement..