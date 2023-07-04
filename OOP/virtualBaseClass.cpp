#include <iostream>
using namespace std;

class Student
{
protected:
    int id;
    string name;

public:
    void setId(int id)
    {
        this->id = id;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void getId()
    {
        cout << "ID: " << id << endl;
    }
    void getName()
    {
        cout << "Name: " << name << endl;
    }
};

class Exam : virtual public Student
{
protected:
    float examScore;

public:
    void setExamScore(int examScore)
    {
        this->examScore = examScore;
    }
    void getExamScore()
    {
        cout << "Exam score: " << examScore << endl;
    }
};

class Sports : virtual public Student
{
protected:
    float sportsScore;

public:
    void setSportsScore(int sportsScore)
    {
        this->sportsScore = sportsScore;
    }
    void getSportsScore()
    {
        cout << "Exam score: " << sportsScore << endl;
    }
};

class Result : public Sports, public Exam
{
private:
    float percentage;

public:
    void setPercentage()
    {
        percentage = 0.8 * examScore + 0.2 * sportsScore;
    }
    void getPercentage()
    {
        cout << "Total percentage: " << percentage << endl;
    }
};

int main()
{
    Result r;
    r.setId(27);
    r.setName("Aaryan");
    r.setSportsScore(92);
    r.setExamScore(98);
    r.setPercentage();
    r.getPercentage();
    r.getName();
    r.getId();

    return 0;
}