#include<iostream>
#include <string>
using namespace std;
class StringPool{
string *stringPool;
int currentSize;
int maxSize;
public:
//constructor
StringPool(){
maxSize=5;
currentSize=0;
stringPool=new string[maxSize];
cout<<"constructor String is created with maximum size "<<maxSize<<endl; \

}
// destructor
~StringPool(){
delete[]stringPool;
stringPool =nullptr;
cout<<" memory is freeed:"<< endl;
}
// add string to pool
void addString(const string & s){
if(currentSize>=maxSize){
cout<<"Pool is full ! cannot add: "<< s <<endl;
return;
}
stringPool[currentSize]=s;
currentSize++ ;
cout<< "Added: "<<s<< "(currentSize : "<< currentSize<<")"<<endl;
}
// Remove a string from the pool WITHOUT freeing memory (creates dangling pointer)
void removeString(int index){
if(index < 0|| index >= currentSize){
cout<< "Invalid index ! " <<endl;
return;
}
cout<<"Removing : "<< stringPool[index] <<" Memory not freed _ leak created" <<endl;
for(int i =index;i<currentSize-1 ;i++){
stringPool[i]=stringPool[i+1];
}
currentSize --;
} 
// Display pool status
void displayStatus() const {
cout << "\n--- Pool Status ---" << endl;
cout << "Current Size: " << currentSize << " / " << maxSize << endl;
cout << "Strings in pool: ";
if (currentSize == 0) {
cout << "(empty)";
} else {
for (int i = 0; i < currentSize; i++) {
cout << "\"" << stringPool[i] << "\" ";
}
}
cout << "\n-------------------\n" << endl;
}

// Detect and fix memory leak by clearing removed strings
void fixLeak() {
cout << "[FixLeak] Releasing unused memory in pool..." << endl;
for (int i = currentSize; i < maxSize; i++) {
stringPool[i].clear();
stringPool[i].shrink_to_fit();
}
cout << "[FixLeak] Memory leak fixed." << endl;
}
};

int main (){
cout<<" ==== Sttring pool demo ===\n"<<endl;
StringPool *pool =new StringPool();
// adding multiple strings
pool-> addString("tayyab");
pool->addString("Ahmed");
pool->addString("Fatima");
pool->addString("Abeera");
pool-> displayStatus();
// removing strings without freeing memory
pool->removeString(1);
pool->removeString(3);

pool-> displayStatus();
delete pool;
pool =nullptr;
cout<<"\n Program Ended "<<endl;
return 0;
}