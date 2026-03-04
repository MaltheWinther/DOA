#include <iostream>

void bookletPrintHelper(int startpage, int endpage, int originalStartpage){

    if(startpage > endpage){
        return;
    }
    std::cout << "Sheet " << (startpage-originalStartpage)/2+1 << " contains pages: " << startpage << ", " << startpage+1 << ", " << endpage-1 << ", " << endpage << std::endl;
    bookletPrintHelper(startpage+2,endpage-2,originalStartpage);

}

void bookletPrint(int startPage, int endPage){
    bookletPrintHelper(startPage, endPage, startPage);
}

int main() {

    bookletPrint(5,12);

    return 0;
}