#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;
struct Course;
struct Student {
	string first_name;
	string last_name;
	char grade;
	int gradevalue;
	vector<Course*> courses;
};

struct Course {
	string name;
	vector<Student*> students;
};
struct studentRecord {
	string name;

};
//method to take file input student names and course grade output sorted students
//file name: input5
void student_grades(){
	int n=0;
	string line;
	ifstream file("input5.txt");
	//read in each line
	if(file.is_open())
	{
//		vector<Student*> s(n);
		while(file.peek()!=EOF)
		{
			getline(file, line);
			n++;
		}
		file.clear();
		file.seekg(0);
		//file.close();
		vector<Student> s(n);
		//vector<Student> s;
		for (int i = 0; i < n; i++) {
			cout<<i<<endl;
			file >> s[i].first_name >> s[i].last_name >> s[i].grade;
			cout << s[i].first_name << " ";
			cout << s[i].last_name << " ";
			cout << s[i].grade << endl;
			//grades from 5 to 1 (A to F)
			if (s[i].grade == 'A'){
				s[i].gradevalue = 5;
			}
			else if(s[i].grade == 'B'){
				s[i].gradevalue = 4;
			}
			else if(s[i].grade == 'C'){
				s[i].gradevalue = 3;
			}
			else if(s[i].grade == 'D'){
				s[i].gradevalue = 2;
			}
			else{
				s[i].gradevalue = 1;
			}
		}
		//sort
			Student tempstudent;
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					if(s[i].gradevalue > s[j].gradevalue){
						//change position in student vector?
						tempstudent = s[j];
						s[j] = s[i];
						s[i] = tempstudent;
					}
				}
			}
			cout << "\nNames of Students in order or their Grades :\n ";
			for (int i = 0; i < n; i++)
			{
				cout << s[i].first_name << " ";
				cout << s[i].last_name << " ";
				cout << s[i].grade << "\n ";
			}
	}
	else{
		cout<<"error"<<endl;
	}


}
//method to take file input student scores output compute course grade and sort students
//file name: input5-2
void student_scores(){

		int n=0;
		string line;
		ifstream file ("input5-2.txt");
		//read in each line
		if(file.is_open())
		{
			while(file.peek()!=EOF)
			{
				getline(file, line);
				n++;
			}
			file.clear();
			file.seekg(0);
			//file.close();
			//account sum for each student for sort later
			int score[n];
			//retrieved total lines = n
			//struct Student s[n];
			vector<Student> s(n);
			for (int i = 0; i < n; i++) {
				file >> s[i].first_name;
				file >> s[i].last_name;
				int sum = 0;
				for (int j = 0; j < 10; j++) {
					double x;
					file >> x;
					sum += x;
				}
				if (sum >= 90)
					s[i].grade = 'A';
				else if (sum >= 80)
					s[i].grade = 'B';
				else if (sum >= 70)
					s[i].grade = 'C';
				else if (sum >= 60)
					s[i].grade = 'D';
				else if (sum >= 0)
					s[i].grade = 'F';
				//for sorting
				score[i] = sum;

			}
			//sort descending order
			int temp;
			Student tempstudent;
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					if(score[i] > score[j]){
						//sort the students
						tempstudent = s[j];
						s[j] = s[i];
						s[i] = tempstudent;
					}
				}
			}
			cout << "\nNames of Students in order or their Grades :\n ";
			for (int i = 0; i < n; i++)
			{
				cout << s[i].first_name << " ";
				cout << s[i].last_name << " ";
				cout << s[i].grade << "\n ";
			}
		}
		else{
			cout<<"error!";
		}
}

//method to print a student's info
void print_student(Student* s) {
	//displaying name
	cout << s->first_name << " " << s->last_name << " is enrolled in these courses: " << endl;
	//looping through the courses vector, printing each course name
	for (int i = 0; i < s->courses.size(); i++) {
		cout << s->courses[i]->name << endl;
	}
}
//method to print a course info
void print_course(Course* c) {
	//displaying name of course
	cout << c->name << " has the following students: " << endl;
	//looping through the students vector, printing each student name
	for (int i = 0; i < c->students.size(); i++) {
		cout << c->students[i]->first_name << endl;
	}
}
//method to enroll a student in a course
void enroll(Student* s, Course* c) {
	//adding course to student's course vector
	s->courses.push_back(c);
	//adding student to course's students vector
	c->students.push_back(s);
}
int main() {
	student_grades();
	student_scores();
	//creating several Students and Courses
	Student smith;
	smith.first_name = "Smith";
	Student john;
	john.first_name = "John";
	Student leon;
	leon.first_name = "Leon";
	Course eng;
	eng.name = "English 101";
	Course his;
	his.name = "History 101";
	Course phy;
	phy.name = "Physics 130";
	//enrolling students and courses
	enroll(&smith, &eng);
	enroll(&john, &his);
	enroll(&smith, &phy);
	enroll(&john, &eng);
	enroll(&leon, &eng);
	//printing student Mary and Course English 101
	print_student(&smith);
	cout << endl;
	print_course(&eng);
	return 0;
}
