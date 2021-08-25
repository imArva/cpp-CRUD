#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int maxrow = 10; // Max File or Records (easily change by changing the number of array)

string Name[maxrow] = {};
string  ID[maxrow] = {};

void OpenFile()
{
    string line;
    ifstream myfile("database.txt");
    if (myfile.is_open())
    {
        int x = 0;
        while (getline(myfile, line))
        {
            int l = line.length();
            ID[x] = line.substr(0,3);
            Name[x] = line.substr(4, 1 - 4);
            x++;
        }
        
    }else
    {
        cout << "Unable To Open File!" << endl;
    }
        
    
}

void AddRecord()
{
    char Rname[50]; // Name max lenght is 49 (easily change by changing the number of array)
    char Rid[5]; // ID max lenght is 4 (easily change by changing the number of array)

    cin.ignore();

    cout << "Student ID.  ";
    cin.getline(Rid, 50);
    cout << "Student Name.  ";
    cin.getline(Rname, 50);

    for (int x = 0; x < maxrow; x++)
    {
        if (ID[x] == "\0")
        {
            ID[x] = Rid;
            Name[x] = Rname;

            break;
        }
        
    }
    

    
}

void ListRecord()
{
    system("CLS");
    cout << "Curent Record(s)" << endl;
    cout << "======================================" << endl;

    int counter = 0;
    cout << " No. |   ID    |        Name   " << endl << "----------------------------------\n";
    for (int i = 0; i < maxrow; i++)
    {
        if (ID[i] != "\0")
        {
            counter++;
            cout << "   " << counter << "     " << ID[i] << "           " << Name[i] << endl;
        }
        
    }
    
    if (counter == 0)
    {
        cout << "No Record found!" << endl;
    }
        
    cout << "======================================" << endl << endl;
    
}

void SearchRecordByID(string search)
{
    system("CLS");
    cout << "Current Record(s)" << endl;
    cout << "====================================" << endl;

    int counter = 0;
    for (int i = 0; i < maxrow; i++)
    {
        if (ID[i] == search)
        {
            counter++;
            cout << "   " << counter << "       " << ID[i] << "         " << Name[i] << endl;
            break;
        }
        
    }

    if (counter == 0)
    {
        cout << "No Record found!" << endl;
    }
    cout << "======================================" << endl;
        
}

void SearchRecordByName(string search)
{
    system("CLS");
    cout << "Current Record(s)" << endl;
    cout << "====================================" << endl;

    int counter = 0;
    for (int i = 0; i < maxrow; i++)
    {
        if (Name[i] == search)
        {
            counter++;
            cout << "   " << counter << "       " << ID[i] << "         " << Name[i] << endl;
            break;
        }
        
    }

    if (counter == 0)
    {
        cout << "No Record found!" << endl;
    }
    cout << "======================================" << endl;
}

void UpdateRecordByID(string search)
{
    char Rname[50];
    char Rid[5];
    int opt;

    cout << "=======================\n";
    cout << "1-Edit Name\n";
    cout << "2-Edit ID\n";
    cout << "=======================\n";
    cout << "Select Option >> ";
    cin >> opt;

    cin.ignore();

    int counter = 0;

    switch (opt)
    {
    case 1:
        // Edit Name
        for ( int i = 0; i < maxrow; i++)
        {
            if (ID[i] == search)
            {
                counter++;

                cout << "=====================" << endl;
                cout << "Change Name: ";
                cin.getline(Rname, 50);
                cout << "=====================" << endl;

                Name[i] = Rname;

                system("CLS");

                cout << "==========================" << endl;
                cout << "Update Successfull!" << endl;
                cout << "==========================" << endl;
            
                break;
            }

        }

        if (counter == 0)
        {
            cout << "=====================" << endl;
            cout << "ID Does not exist!" << endl;
            cout << "=====================" << endl;
        }
        break;
    
    case 2:
        // Edit ID:
        for ( int i = 0; i < maxrow; i++)
        {
            if (ID[i] == search)
            {
                counter++;

                cout << "=====================" << endl;
                cout << "Change ID: ";
                cin.getline(Rid, 5);
                cout << "=====================" << endl;

                ID[i] = Rid;

                system("CLS");

                cout << "==========================" << endl;
                cout << "Update Successfull!" << endl;
                cout << "==========================" << endl;

                break;
            }
        }

        if (counter == 0)
        {
            cout << "=====================" << endl;
            cout << "ID Does not exist!" << endl;
            cout << "=====================" << endl;
        }
        break;

    default:
        break;
    }
    
}

void UpdateRecordByName(string search)
{
    char Rname[50];
    char Rid[5];
    int opt;

    system("CLS");

    cout << "=======================\n";
    cout << "1-Edit Name\n";
    cout << "2-Edit ID\n";
    cout << "=======================\n";
    cout << "Select Option >> ";
    cin >> opt;

    cin.ignore();

    int counter = 0;

    system("CLS");

    switch (opt)
    {
    case 1:
        // Edit Name
        for ( int i = 0; i < maxrow; i++)
        {
            if (Name[i] == search)
            {
                counter++;

                cout << "=====================" << endl;
                cout << "Change Name: ";
                cin.getline(Rname, 50);
                cout << "=====================" << endl;

                Name[i] = Rname;

                system("CLS");

                cout << "==========================" << endl;
                cout << "Update Successfull!" << endl;
                cout << "==========================" << endl;

                break;
            } 
        }

        if (counter == 0)
        {
            cout << "=====================" << endl;
            cout << "ID Does not exist!" << endl;
            cout << "=====================" << endl;
        }
        break;
    
    case 2:
        // Edit ID:
        for ( int i = 0; i < maxrow; i++)
        {
            if (Name[i] == search)
            {
                counter++;

                cout << "=====================" << endl;
                cout << "Change ID: ";
                cin.getline(Rid, 5);
                cout << "=====================" << endl;

                ID[i] = Rid;

                system("CLS");

                cout << "==========================" << endl;
                cout << "Update Successfull!" << endl;
                cout << "==========================" << endl;
            
                break;
            }
        }

        if (counter == 0)
        {
            cout << "=====================" << endl;
            cout << "ID Does not exist!" << endl;
            cout << "=====================" << endl;
        }
        break;

    default:
        break;
    }

}

void DeleteRecordByID(string search)
{
    int counter = 0;
    for (int i = 0; i < maxrow; i++)
    {
        if (ID[i] == search )
        {
            counter++;

            Name[i] = "\0";
            ID[i] = "\0";

            cout << "==========================" << endl;
            cout << "Successfully Deleted!" << endl;
            cout << "==========================" << endl;
            break;
        }
        
    }
    
    if (counter == 0)
    {
        cout << "=====================" << endl;
        cout << "ID Does not exist!" << endl;
        cout << "=====================" << endl;
    }
}

void DeleteRecordByName(string search)
{
    int counter = 0;
    for (int i = 0; i < maxrow; i++)
    {
        if (Name[i] == search )
        {
            counter++;

            Name[i] = "\0";
            ID[i] = "\0";

            cout << "==========================" << endl;
            cout << "Successfully Deleted!" << endl;
            cout << "==========================" << endl;
            break;
        }
        
    }
    
    if (counter == 0)
    {
        cout << "=====================" << endl;
        cout << "ID Does not exist!" << endl;
        cout << "=====================" << endl;
    }
}

void SaveToFile()
{
    ofstream myfile;
    myfile.open("database.txt");
    
    for (int i = 0; i < maxrow ; i++)
    {
        if (ID[i] == "\0")
        {
            break;
        }else
        {
            myfile << ID[i] + "," + Name[i] << endl;
        }
    }
}

int main()
{
    cout << "Menu\n";
    int option; // For Menu Option
    string srchID; // searchID
    string srchName; // searchName
    int opt; // option for case 2 and 4
    system("CLS");
    OpenFile(); // Opening database.txt if exist

    do
    {
        // Menu
        cout << "1-Create Records" << endl;
        cout << "2-Update Records" << endl;
        cout << "3-Delete Records" << endl;
        cout << "4-Search Records" << endl;
        cout << "5-Display all Records" << endl;
        cout << "6-Exit and Save to Textfile" << endl;
        cout << "================================" << endl;

        cout << "Select Option >>";
        cin >> option;

        // The Option
        switch (option)
        {
        case 1: // Create
            AddRecord();
            system("CLS");
            break;
        case 2: // Update
            cin.ignore();

            system("CLS");

            // Update Menu (choosing search by id or name)
            cout << "=======================\n";
            cout << "1-Update By ID\n";
            cout << "2-Update By Name\n";
            cout << "=======================\n";
            cout << "Select Option >> ";
            cin >> opt;

            system("CLS");

            // Update Option
            switch (opt)
            {
            case 1: // By ID
                cin.ignore();
                cout << "=======================\n";
                cout << "Update by ID >>";
                getline(cin,srchID);
                cout << "=======================\n";
                UpdateRecordByID(srchID);
                break;
            case 2: // By Name
                cin.ignore();
                cout << "=======================\n";
                cout << "Update by Name >>";
                getline(cin,srchName);
                cout << "=======================\n";
                UpdateRecordByName(srchName);
            default:
                break;
            }
            break;
        case 3: // Delete
            cin.ignore();

            system("CLS");

            // Update Menu (choosing delete by id or name)
            cout << "=======================\n";
            cout << "1-Delete By ID\n";
            cout << "2-Delete By Name\n";
            cout << "=======================\n";
            cout << "Select Option >> ";
            cin >> opt;

            system("CLS");

            // Option Delete
            switch (opt)
            {
            case 1: // Delete By Id
                cin.ignore();

                cout << "Insert ID to delete >>";
                getline(cin,srchID);
                DeleteRecordByID(srchID);
                break;
            case 2:
                cin.ignore();

                cout << "Insert Name to delete >>";
                getline(cin,srchName);
                DeleteRecordByName(srchName);
                break;
            default:
                break;
            }

            
            break;
        case 4: // Search
            cin.ignore();

            system("CLS");

            // Search Menu (choosing search by id or name)
            cout << "=======================\n";
            cout << "1-Search By ID\n";
            cout << "2-Search By Name\n";
            cout << "=======================\n";
            cout << "Select Option >> ";
            cin >> opt;

            system("CLS");
            
            // Search Option
            switch (opt)
            {
            case 1: // Search By Id
                
                cin.ignore();
                cout << "Search by ID >>";
                getline(cin,srchID);
                SearchRecordByID(srchID);
                break;
            case 2: // Search By Name
                cin.ignore();
                cout << "Search by Name >>";
                getline(cin,srchName);
                SearchRecordByName(srchName);
                break;
            default:
                break;
            }
            break;
        case 5: // Display All List(s)
            ListRecord();
            break;  
        default:
            break;
        }
    } while (option != 6);
    
    // Saving File To database.txt
    cout << "Wait... Saving File.." << endl;
    SaveToFile();
    cout << "Done!" << endl;
    cin.get();
    return 0;
}