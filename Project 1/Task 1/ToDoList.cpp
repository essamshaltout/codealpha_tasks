#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int no_of_current_tasks = 0;
    string tasks[10000][2];
    int app_task = -1;
    while(app_task != 4)
    {
        app_task = -1;
        cout<<"What do you want to do\n";
        cout<<"1. Add New Tasks\n";
        cout<<"2. Mark Tasks as Completed\n";
        cout<<"3. View Current Tasks\n";
        cout<<"4. End The Program\n";
        do
        {
            cout<<"Enter Number : ";
            cin>>app_task;
        } while (app_task < 1 || app_task > 4);
        


        
        if(app_task == 1)
        {
            string task;
            cout<<"Enter Task : ";
            cin>>task;
            tasks[no_of_current_tasks][0] = task;
            tasks[no_of_current_tasks][1] = "Not Completed";
            no_of_current_tasks++;
        }

        if(app_task == 2)
        {
            int num,x;
            cout<<"Enter Number of tasks you want to check : ";
            cin>>num;
            for(int i = 0; i < num; i++)
            {
                cout<<"Enter Number of task you want to check as completed : ";
                cin>>x;
                tasks[x - 1][1] = "Completed";
            }
        }

        if(app_task == 3)
        {
            for(int i = 0; i < no_of_current_tasks; i++)
            {
                cout<< i + 1 << " - " << tasks[i][0] << "           \t" << tasks[i][1] <<"\n";
            }
        }

        cout<<"\n\n";
      
    }



    return 0;
}