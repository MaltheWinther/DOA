#include <iostream>

void bookletPrint(int startpage, int endpage, int originalStartpage){
    
    if(startpage > endpage){
        return;
    }
    std::cout << "Sheet " << (startpage-originalStartpage)/2+1 << " contains pages: " << startpage << ", " << startpage+1 << ", " << endpage-1 << ", " << endpage << std::endl;
    bookletPrint(startpage+2,endpage-2,originalStartpage);

}


int main() {
   
    bookletPrint(5,12,5);
   
    return 0;
}