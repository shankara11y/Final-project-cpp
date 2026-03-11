#include <iostream>
#include <string>
using namespace std;

class Notice
{
public:
    string title;
    string description;

    void inputNotice()
    {
        cout << "Enter Notice Title: ";
        getline(cin, title);

        cout << "Enter Notice Description: ";
        getline(cin, description);
    }

    void display()
    {
        cout << "Title: " << title << endl;
        cout << "Description: " << description << endl;
    }
};

int main()
{
    Notice notices[100];   
    int noticeCount = 0;
    int choice;

    do
    {
        cout << "\n===== DIGITAL NOTICE BOARD =====\n";
        cout << "1. Add Notice\n";
        cout << "2. Delete Notice\n";
        cout << "3. View Notices\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice)
        {
            case 1: 
            {
                if(noticeCount >= 100)
                {
                    cout << "Notice board is full!\n";
                    break;
                }

                notices[noticeCount].inputNotice();
                noticeCount++;

                cout << "New Notice Added Successfully!\n";
                break;
            }

            case 2: 
            {
                if(noticeCount == 0)
                {
                    cout << "No notices to delete.\n";
                    break;
                }

                int num;
                cout << "Enter notice number to delete: ";
                cin >> num;

                if(num < 1 || num > noticeCount)
                {
                    cout << "Invalid notice number.\n";
                    break;
                }

                for(int i = num-1; i < noticeCount-1; i++)
                {
                    notices[i] = notices[i+1];
                }

                noticeCount--;
                cout << "Notice deleted successfully.\n";
                break;
            }

            case 3: 
            {
                if(noticeCount == 0)
                {
                    cout << "No notices available.\n";
                    break;
                }

                cout << "\n------ DIGITAL NOTICE BOARD ------\n";

                cout << "Total Notices: " << noticeCount << endl;

                for(int i = 0; i < noticeCount; i++)
                {
                    cout << "\nNotice " << i+1 << endl;
                    notices[i].display();
                }

                cout << "----------------------------------\n";
                break;
            }

            case 4:
            {
                cout << "Exiting program...\n";
                break;
            }

            default:
                cout << "Invalid choice.\n";
        }

    } while(choice != 4);

    return 0;
}