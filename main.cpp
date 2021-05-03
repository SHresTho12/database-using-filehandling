#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

 struct Employee{
    int employee_Id;
    string name;
    string blood_group;
    int age;
    string gender;
    int project_id;
    string team_leader;
    string role;




};
struct Project{
    int project_Id;
    string project_name;
    string employeer_name;
    string estimated_time;
    int estimated_budget;
    int number_of_employee;
    string status;





};
//Function for showing instructions
void instruction(){
cout<<"-------- Choose one ----------"<<endl;
cout<<"    Enter 1 For adding a new Employee   "<<endl;
cout<<"    Enter 2 For Showing Employee Info  "<<endl;
cout<<"    Enter 3 for adding new Project     "<<endl;
cout<<"    Enter 4 for Removing Project     "<<endl;
cout<<"    Enter 0 for quiting the process     "<<endl;
}

//Function fr adding a new Employee to the database
void addEmployee(ofstream &employeeFile){
    Employee employee;
    cout<<"Enter Employee Id :";
    cin>>employee.employee_Id;
    cout<<"Enter Employee name:";
    cin>>employee.name;
    cout<<"Enter Employee Blood group :";
    cin>> employee.blood_group;
    cout<<"Enter Employee age:";
    cin>>employee.age;
    cout<<"Enter Employee gender : ";
    cin>> employee.gender;
    cout<<"Enter Employee Project id : :";
    cin>>employee.project_id;
    cout<<"Enter Employee Team Leader name :";
    cin>>employee.team_leader;
    cout<<"Enter Employee role :";
    cin>>employee.role;

employeeFile<<employee.employee_Id;
employeeFile<<" ";
employeeFile<<employee.name;
employeeFile<<" ";
employeeFile<<employee.blood_group;
employeeFile<<" ";
employeeFile<<employee.age;
employeeFile<<" ";
employeeFile<<employee.gender;
employeeFile<<" ";
employeeFile<<employee.project_id;
employeeFile<<" ";
employeeFile<<employee.team_leader;
employeeFile<<" ";
employeeFile<<employee.role;
employeeFile<<endl;
}
//Function for adding new project
void addProject(ofstream &projectFile){
    Project project;

    cout<<"Enter Project id:";
    cin>>project.project_Id;
    cout<<"Enter Project name:";
    cin>>project.project_name;
    cout<<"Enter employer name :";
    cin>> project.employeer_name;
    cout<<"Enter Estimated Budget : ";
    cin>> project.estimated_budget;
    cout<<"Enter Estimated time to finish:";
    cin>>project.estimated_time;
    cout<<"Enter Employee Number of Employee :";
    cin>>project.number_of_employee;
    cout<<"Enter Project status:";
    cin>>project.status;

projectFile<<project.project_Id;;
projectFile<<" ";
projectFile<<project.project_name;
projectFile<<" ";
projectFile<<project.employeer_name;
projectFile<<" ";
projectFile<<project.estimated_budget;
projectFile<<" ";
projectFile<<project.estimated_time;
projectFile<<" ";
projectFile<<project.number_of_employee;
projectFile<<" ";
projectFile<<project.status;
projectFile<<endl;
}

//Function for showing a employee info
void showEmployee(ifstream &employeeFile , string employee_ID){

char c;
string id;
string line;

while(getline(employeeFile, line))
{
    id = "";
    for(int i = 0; i < line.size(); i++)
    {
        c = line[i];
        if(c == ' ' || c == '\t')
            break;
        else
            id += c;
    }
    if(id == employee_ID){
           for(int i=0;i<line.size();i++){
            c=line[i];
            if(c == ' ' || c == '\t'){
                cout<<endl;
            }
            else cout<<c;
           }

        break;
    }
    else{
        cout<<"No employee Found With that id"<<endl;
    }

}





}



//Remove Project

void removeProject(ifstream &projectFile , string minbudget){

char c;
string budget;
string line;
ofstream temp;
temp.open("temp.text");
while(getline(projectFile, line))
{
    budget = "";
    int space;
    for(int i = 0; i < line.size(); i++)
    {
        c = line[i];

        if(c == '\t'){ break;}

        else if(c == ' '){
        space++;
            if(space==4){
                if(stoi(budget) >= stoi(minbudget)){
                 temp << line << endl;
                       break;                             }
                        }
        budget = "";

    }
            else{
                 budget += c;
            }

        }

    }

temp.close();
projectFile.close();
remove("Project.text");
rename("temp.text","Project.text");
}









int main() {
  // Create and open

     ofstream myfile1 ("Employee.text",ios::app);
        ofstream myfile2 ("Project.text",ios::app);
    //Checking if the file is created or not

        int i;

        instruction();


    while(1){
            cin>>i;
        if(i==0) break;
        if(i==1){
            addEmployee(myfile1);
        }
        if(i==2){
            string id;
            cout<<"Enter the Employee Id you want to find"<<endl;
            cin>>id;
            ifstream myfile1 ("Employee.text");
            showEmployee(myfile1,id);
        }

        if(i==3){

            addProject(myfile2);

        }

        if(i==4){
            myfile2.close();
            string budget;
            cout<<"Enter the minimum Budget :";
            cin>>budget;
            ifstream myfile2 ("Project.text");
            removeProject(myfile2,budget);


        }

        instruction();


    }

  // Close the file
  myfile1.close();
  myfile2.close();
}
