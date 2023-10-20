#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <fstream>
#include <ctime>
#include "dir1.h"
#include "search/search1.h"
#include "search/search1_1.h"
#include "menu/menu1.h"
#include "menu/about1.h"
#include "menu/helper1.h"

using namespace std;

getData G;
Rdis R;
About A;

void error() {
	system("cls");
	cout << "The format is not correct"; //show when the format of input is not correct
	Sleep(2000);
}

void exit() {
	system("cls");
	cout << "Exiting..";
	Sleep(2000);
}

void dir();
void search();
void searchbyName();
void searchbyID();
void searchbyTime();
void searchbyName_e();
void searchbyID_e();
void searchbyTime_e();
void menu1();
void menu1_about();
void menu1_help();
void menu1_about_binfo();
void menu1_about_minfo();

//main page
void dir() {
	dirMessage();
	G.read();
	char nh;
	cin >> nh;
	switch (nh) {
	case 's': {
		search();
		break;
	}
	case 'm': {
		menu1();
		break;
	}
	case 'E': {
		exit();
		break;
	}
	default: {
		error();
		dir();
		break;
	}
	}
}

//search
void search() {
	searchTip();
	char sh1;
	cin >> sh1;
	switch (sh1) {
	case 'n': {
		searchbyName();
		break;
	}
	case 's': {
		searchbyID();
		break;
	}
	case 't': {
		searchbyTime();
		break;
	}
	case 'N': {
		dir();
		break;
	}
	case 'P': {
		dir();
		break;
	}
	case 'E': {
		exit();
		break;
	}
	default: {
		error();
		search();
		break;
	}
	}
}
//search by name
void searchbyName() {
	G.name();
	char sh1_1;
	cin >> sh1_1;
	switch (sh1_1) {
	case 'N': {
		dir();
		break;
	}
	case 'P': {
		search();
		break;
	}
	case 'E': {
		exit();
		break;
	}
	case 'R': {
		searchbyName();
		break;
	}
	default: {
		searchbyName_e();
		break;
	}
	}
}
//if search by name meets error
void searchbyName_e() {
	error();
	system("cls");
	R.eFINISH();
	char sh1_1;
	cin >> sh1_1;
	switch (sh1_1) {
	case 'N': {
		dir();
		break;
	}
	case 'P': {
		search();
		break;
	}
	case 'E': {
		exit();
		break;
	}
	case 'R': {
		searchbyName();
		break;
	}
	default: {
		searchbyName_e();
		break;
	}
	}
}
//search by id
void searchbyID() {
	G.number();
	char sh1_2;
	cin >> sh1_2;
	switch (sh1_2) {
	case 'N': {
		dir();
		break;
	}
	case 'P': {
		search();
		break;
	}
	case 'E': {
		exit();
		break;
	}
	case 'R': {
		searchbyID();
		break;
	}
	default: {
		searchbyID_e();
		break;
	}
	}
}
//if search by id meet error
void searchbyID_e() {
	error();
	system("cls");
	R.eFINISH();
	char sh1_2;
	cin >> sh1_2;
	switch (sh1_2) {
	case 'N': {
		dir();
		break;
	}
	case 'P': {
		search();
		break;
	}
	case 'E': {
		exit();
		break;
	}
	case 'R': {
		searchbyID();
		break;
	}
	default: {
		searchbyID_e();
		break;
	}
	}
}
//search by time
void searchbyTime() {
	G.time();
	char sh1_3;
	cin >> sh1_3;
	switch (sh1_3) {
	case 'N': {
		dir();
		break;
	}
	case 'P': {
		search();
		break;
	}
	case 'E': {
		exit();
		break;
	}
	case 'R': {
		searchbyTime();
		break;
	}
	default: {
		searchbyTime_e();
		break;
	}
	}
}

void searchbyTime_e() {
	error();
	system("cls");
	R.eFINISH();
	char sh1_3;
	cin >> sh1_3;
	switch (sh1_3) {
	case 'N': {
		dir();
		break;
	}
	case 'P': {
		search();
		break;
	}
	case 'E': {
		exit();
		break;
	}
	case 'R': {
		searchbyTime();
		break;
	}
	default: {
		searchbyTime_e();
		break;
	}
	}
}
//menu
void menu1() {
	menu();
	char mh;
	cin >> mh;
	switch (mh)
	{
	case 'a': {
		menu1_about();
		break;
	}
	case 'h': {
		menu1_help();
		break;
	}
	case 'N': {
		dir();
		break;
	}
	case 'P': {
		dir();
		break;
	}
	case 'E': {
		exit();
		break;
	}
	default: {
		error();
		menu1();
		break;
	}
	}
}
//about
void menu1_about() {
	A.about();
	char mh1_1;
	cin >> mh1_1;
	switch (mh1_1) {
	case 'b': {
		menu1_about_binfo();
		break;
	}
	case 'm': {
		menu1_about_minfo();
		break;
	}
	case 'N': {
		dir();
		break;
	}
	case 'P': {
		menu1();
		break;
	}
	case 'E': {
		exit();
		break;
	}
	case 'M': {
		menu1();
		break;
	}
	default: {
		error();
		menu1_about();
		break;
	}
	}
}
//help
void menu1_help() {
	help();
	char mh1_2;
	cin >> mh1_2;
	switch (mh1_2) {
	case 'N': {
		dir();
		break;
	}
	case 'P': {
		menu1();
		break;
	}
	case 'E': {
		exit();
		break;
	}
	case 'M': {
		menu1();
		break;
	}
	default: {
		error();
		menu1_help();
		break;
	}
	}
}
//basic info
void menu1_about_binfo() {
	A.basic();
	char mh1_1_1;
	cin >> mh1_1_1;
	switch (mh1_1_1) {
	case 'N': {
		dir();
		break;
	}
	case 'P': {
		menu1_about();
		break;
	}
	case 'E': {
		exit();
		break;
	}
	case 'M': {
		menu1();
		break;
	}
	default: {
		error();
		menu1_about_binfo();
		break;
	}
	}
}
//member info
void menu1_about_minfo() {
	A.member();
	char mh1_1_2;
	cin >> mh1_1_2;
	switch (mh1_1_2) {
	case 'N': {
		dir();
		break;
	}
	case 'P': {
		menu1_about();
		break;
	}
	case 'E': {
		exit();
		break;
	}
	case 'M': {
		menu1();
		break;
	}
	default: {
		error();
		menu1_about_minfo();
		break;
	}
	}
}
