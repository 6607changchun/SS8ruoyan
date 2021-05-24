/*******************************************************************************
* FileName:         MyString.cpp
* Author:           Your_Name
* Student Number:   3018216xxx
* Date:             2020/03/18 11:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #3
*                   完成程度：
*                       简要说一下自己写了多少，完成了哪些函数
*******************************************************************************/
#include <cstdio>
#include <cstdlib>
#include "MyString.h"


MyString::MyString(const char* str){
	int i = 0;
	len = 0;
	//ʹ��\0��Ϊ������־�ͳ��ȼ����� 
	while(str[i] != '\0'){
		value[len++] = str[i];
		i++;
	}
	value[len] = '\0';
}

MyString::~MyString(){
	//������ձ��� 
}

int MyString::length() const{
	return len;
}

void MyString::replace(const char* replace, int loc){
	//�ȼ��ڴ�locλ���¹����ַ��� 
	len = loc;
	int i = 0;
	while(replace[i] != '\0'){
		value[len++] = replace[i];
		i++;
	}
	value[len] = '\0';
}

int MyString::find(const char* str) const{
	//�մ��ж� 
	if(str[0] == '\0') return -1;
	//getNext
	int next[MAX_LENGTH];
	int i = 0,j = 0;
	next[0] = -1;
	while(str[i] != '\0'){
		if(j == -1||str[j] == str[i]) {i++;j++;next[i] = j;}
		else j = next[j];
	}
	//find
	i = 0;j = 0;
	while(value[i] != '\0'&&(j == -1||str[j]!='\0')){
		if(j == -1||str[j] == value[i]) {i++;j++;}
		else j = next[j];
	}
	if(str[j] == '\0') return i-j;
	else return -1;
}

const char* MyString::c_string() const{
	char * s = new char[len+1];
	int i = 0;
	while(i < len+1){
		s[i] = value[i];
		i++;
	}
	return s;
}
