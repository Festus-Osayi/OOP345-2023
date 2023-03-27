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
#include <fstream>
#include <iomanip>
#include <algorithm>
#define MAX_VALUES 20

namespace sdds{

    enum class Err_Status
    {
        Err_Success,
        Err_NotFound,
        Err_OutOfMemory,
    };

    template <typename T>
    class Database{
       static std::shared_ptr<Database> da_database;
       size_t da_entries{};
       std::string da_keys[MAX_VALUES];
       T da_values[MAX_VALUES];
       std::string da_filename{};
        
        //A private constructor, and this will prevent clients to create instances.
       Database(const std::string& filename){
            da_filename = filename;
            da_entries = 0;
            std::cout<<"["<<this<<"]"<<" Database(const std::string&)"<<std::endl;

            std::string keys{};
            T values{};

            std::ifstream data(filename);
            while(data >> keys >> values){
                if(da_entries < MAX_VALUES){
                    // replace the underscores with spaces
                    std::replace(keys.begin(), keys.end(), '_', ' ');
                    encryptDecrypt(values);
                    SetValue(keys, values);
                }
                
            }
            data.close(); //optional but best practices
       }

        //std::string trim(const std::string& str);

        void encryptDecrypt(T& value);
       public:
       
    
       // receives as a parameter a string representing the filename of the database file - if the class `Database` has already been instantiated (the `static` attribute is not null), then this function returns the static attribute and does nothing else.
       static std::shared_ptr<Database> getInstance(const std::string& filename){
        
            if(da_database){
                da_database = da_database;
            }
            else {
                da_database = std::shared_ptr<Database>(new Database(filename));
            }
            return da_database;
       }

        // a query that searches in the array of keys for a the first parameter:
       Err_Status GetValue(const std::string& key, T& value){
        
             Err_Status status { Err_Status::Err_NotFound };
            int success{};
            for (size_t i{}; i < da_entries && success == 0; i++) {
                if (da_keys[i] == key) {
                    value = da_values[i];
                    status = Err_Status::Err_Success;
                    success = 1;
                }
            }
            return status;
        }

        // a modifier that receives as parameters a key and a value. If there is space in the database (the capacity of the array not been reached), the key/value pair is added and the function returns `Err_Success`. Otherwise, it returns `Err_OutOfMemory`.
       Err_Status SetValue(const std::string& key, const T& value){
            Err_Status status { Err_Status::Err_OutOfMemory };
            if (da_entries < MAX_VALUES) {
                da_keys[da_entries] = key;
                da_values[da_entries] = value;
                da_entries++;
                status = Err_Status::Err_Success;
            }
            return status;
       }

        //A Destructor
       ~Database(){
            std::cout << "[" << this << "]" << " ~Database()" << std::endl;
            std::ofstream dataFile(da_filename + ".bkp.txt");
            size_t i{ 0 };
            while (i < da_entries) {
                encryptDecrypt(da_values[i]);
                dataFile << std::left << std::setw(25) << da_keys[i] << " -> " << da_values[i] << std::endl;
                i++;
            }

           
       }

       
    }; 
    template<typename T>
    std::shared_ptr<sdds::Database<T>> sdds::Database<T>::da_database = nullptr;
    
    
    
    

    // specialize the `encryptDecrypt()` for the type `std::string`
    template <>
    void Database<std::string>::encryptDecrypt(std::string &value){
        const char secret[]{ "secret encryption key" };
        for (char& c : value) {
            for (const char& k : secret) {
                c = c ^ k;
            }
        }
    }

    //specialize the `encryptDecrypt()` for the type `long long`
    template<>
    void Database<long long>::encryptDecrypt(long long& value) {
        const char secret[]{ "super secret encryption key" };
        char* numOfBytes{reinterpret_cast<char*>(&value)};
        size_t bytes{sizeof(value)};
        for (size_t i = 0; i < bytes; i++) {
            for (const char& k : secret) {
                numOfBytes[i] = numOfBytes[i] ^ k;
            }
        }
    }

}

#endif //end of an if statement..