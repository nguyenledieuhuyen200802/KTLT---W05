#pragma once
#ifndef Header_h
#define Header_h

#include <iostream>
#include <cstring>
#include <time.h>
using namespace std;

struct Student
{
	char name[51];
	int ID;
	float mark;
};

struct Node
{
	Student data;
	Node* next;
};

struct List
{
	Node* head;
	Node* tail;
};

Node* createNode(Student s);
void createList(List& l);
void input(Student& s);
void addHead(List& l, Student s);
void addTail(List& l, Student s);
void addNodeAfterHead(List& l, Student s);
void addNodeBeforeTail(List& l, Student s);
void randomString(char* code, int codeLength);
int randomInt(int min, int max);
float randomFloat(float min, float max);
void add5NodesWithRandomInformation(List& l, Student& s); // diem so
void deleteHead(List& l);
void deleteTail(List& l);
void deleteAllStudentsWhoseMarksJustEntered(List& l, float& target_marks);
void add10NodesWithRandomInformation(List& l, Student& s);
Node* removeDuplicates(List& l);
void reverse(List& l);
void insertAsc(Node* newnode);
void insertionSort(List& l);
bool checkCircle(List l);
void printH(List l);
void addOrUpdate(List& l);
void printStudent(Node* temp);
void output(List l);
void clear(List& l);
void menu();

#endif