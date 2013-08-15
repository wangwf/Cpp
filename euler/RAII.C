//
// RAII: Resources Acquistion Is Initization

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <mutex>

void Write_to_file(const std::string& message){
  //mutex to protect file access
  static std::mutex mutex; 
  //lock mutex before access file
  std::lock_guard<std::mutex> lock(mutex);

  // Open file 
  std::ofstream file("example.txt"); 
  if(!file.is_open()) throw std::runtime_error("unable to open file");

  //write message to file
  file<<message<<std::endl; 

  //  file.close();  // NOT need 
  //file will be closed first when leaving scope (regarding of exception)
  //mutex will be unlocked second (from lock destructor) when leaving scope
  // (regardless of exception)


}

int main(){

  std::string mess="This is a test message!"; 

  Write_to_file(mess); 
  return 0; 
}
