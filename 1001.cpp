#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Student{
	public:
		Student();
		friend ostream &operator<<(ostream &os,const Student &m);
		void BonusCaculate();
		void Input();
		string name;
		int final_grade;
		int class_grade;
		char student_carde;
		char western_stu;
		short int papers;
		int bonus;
};
Student::Student(){
	bonus = 0;
}
void Student::Input(){
	cin>>name>>final_grade>>class_grade>>student_carde>>western_stu>>papers;
}
ostream &operator<<(ostream &os,const Student &m){
	os<<m.name<<endl<<m.bonus<<endl;
	return os;
}
void Student::BonusCaculate(){
	if(final_grade>80&&papers>=1)
		bonus += 8000;
	if(final_grade>85&&class_grade>80)
		bonus += 4000;
	if(final_grade>90)
		bonus += 2000;
	if(western_stu == 'Y'&&final_grade>85)
		bonus += 1000;
	if(student_carde == 'Y'&&class_grade>80)
		bonus += 850;
}

int main(){
	int n,p = 0,total_bonus = 0;
	cin>>n;
	vector<Student> students(n);
	for(int i = 0; i < n; i++){
		students[i].Input();
		students[i].BonusCaculate();
		total_bonus += students[i].bonus;
	}
	for(int i = 0; i < n-1;i++){
		if(students[p].bonus < students[i+1].bonus)
			p = i+1;
	}
	cout<<students[p]<<total_bonus;
	
	return 0;
}

