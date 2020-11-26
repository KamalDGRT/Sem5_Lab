/* Paging */

#include <iostream>
using namespace std;
struct paging
{
    int framenumber, valid;
};
int main()
{
    int i, noofpages = 0, noofframes = 0, sizeofMM = 0, sizeofLM = 0, framesize = 0, physicaladdress = 0, disp = 0, pageno = 0, logicaladdress = 0;
    paging pagetable[10];
    cout << "program for paging techniques - fixed size partition";
    cout << "\n Enter the size of main memory:";
    cin >> sizeofMM;
    cout << "\n Enter the size of main memory frame:";
    cin >> framesize;
    noofframes = sizeofMM / framesize;
    cout << "\n Total no of frames in main memory is" << noofframes;
    cout << "\nEnter the size of logical memory:";
    cin >> sizeofLM;
    noofpages = sizeofLM / framesize;
    cout << "\n Total noofpages in logical memory is" << noofpages;
    cout << "\n Enter the frame values in page table\n";
    for (i = 0; i < noofpages; i++)
    {
        while (1)
        {
            cout << "n page" << i << " is stored in frame number:";
            cin >> pagetable[i].framenumber;
            pagetable[i].valid = 1;
            break;
        }
    }
    cout << "n \t PAGE TABLE";
    cout << "\nIndex|\t\tFrame number|\t\tvalid Bit|\n\n";
    for (i = 0; i < noofpages; i++)
    {

        cout << i << "\t\t" << pagetable[i].framenumber << "\t\t" << pagetable[i].valid;
    }
    for (i = 0; i < noofpages; i++)
    {
        cout << "Enter the logical address for mapping process:";
        cin >> logicaladdress;
        pageno = logicaladdress / framesize;
        disp = logicaladdress % framesize;
        physicaladdress = (pagetable[pageno].framenumber * framesize) + disp;
        cout << "physical addressvalue is" << physicaladdress << "\n";
    }
    return (0);
}
