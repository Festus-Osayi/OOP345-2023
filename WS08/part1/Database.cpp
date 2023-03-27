#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include "Database.h"

using namespace std;
namespace sdds{
    
    //A private constructor, and this will prevent clients to create instances.
    Database::Database(const std::string& filename){
        this->da_filename = filename;
        this->da_entries = 0;
        cout<<"["<<this<<"]"<<" Database(const std::string&)"<<endl;

        string keys{};
        string values{};

        ifstream data(filename);
        while(data >> keys >> values){
            // replace the underscores with spaces
            std::replace(keys.begin(), keys.end(), '_', ' ');
            SetValue(keys, values);
        }
        data.close(); //optional but best practices
    }
    // receives as a parameter a string representing the filename of the database file
    // - if the class `Database` has already been instantiated (the `static` attribute is not null), then this function returns the static attribute and does nothing else.
    std::shared_ptr<Database> Database::getInstance(const std::string& filename){
        if(da_database){
            da_database = da_database;
        }else{
            da_database = std::shared_ptr<Database>(new Database(filename));
        }
        return da_database;
    }

    // a query that searches in the array of keys for a the first parameter:
     Err_Status Database::GetValue(const std::string& key, std::string& value){
        Err_Status status { Err_Status::Err_NotFound };
        int success{};
        for (size_t i{}; i < da_entries && success == 0; i++) {
            if (this->da_keys[i] == key) {
                value = da_values[i];
                status = Err_Status::Err_Success;
                success = 1;
            }
        }
        return status;
    }

    // a modifier that receives as parameters a key and a value. If there is space in the database (the capacity of the array not been reached), the key/value pair is added and the function returns `Err_Success`. Otherwise, it returns `Err_OutOfMemory`.
    Err_Status Database::SetValue(const std::string& key, const std::string& value){
        Err_Status status { Err_Status::Err_OutOfMemory };
        if (da_entries < MAX_ENTRIES) {
            this->da_keys[da_entries] = key;
            this->da_values[da_entries] = value;
            da_entries++;
            status = Err_Status::Err_Success;
        }
        return status;
    }


    //A Destructor
    Database::~Database() {
        std::cout << "[" << this << "]" << " ~Database()" << std::endl;
        std::ofstream dataFile(da_filename + ".bkp.txt");
        size_t i{ 0 };
        while (i < da_entries) {
            dataFile << std::left << std::setw(25) << da_keys[i] << " -> " << da_values[i] << std::endl;
            i++;
        }
    }

     // Strips all the not required characters from a string
    std::string trim(const std::string& str) {
        std::string value {};
        size_t start_pos = str.find_first_not_of(" \t\r\n");
        size_t end_pos = str.find_last_not_of(" \t\r\n");
        if(start_pos == std::string::npos){
            value = str;
        }else{
            value = str.substr(start_pos, (end_pos - start_pos + 1));
        }
        
        return value;
    }
    
}
