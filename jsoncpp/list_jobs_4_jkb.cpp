#include<jsoncpp/json/json.h>
#include<iostream>
using namespace std;
int main()
{
	string str ="[{\"task_id\":684039}]";
	Json::Reader read;
	Json::Value root;
	read.parse(str,root);
	cout << root[0]["task_id"].asInt();
	return 1;

}
