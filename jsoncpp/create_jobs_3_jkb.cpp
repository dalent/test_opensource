#include<jsoncpp/json/json.h>
#include<iostream>
#include <curl/curl.h>
#include<sstream>
#include<stdlib.h>
#include<string.h>
using namespace std;
static size_t write_cb(char *ptr, size_t size, size_t nmemb, char *out)
{ 
    size_t r;
    r = size * nmemb;          
    strncat(out,ptr,r);        
    return(r);
} 

int main()
{
    char buf[2048];
    memset(buf,0,sizeof(buf));
    CURL *curl;
    CURLcode res;              
    string url = "http://api.jiankongbao.com/v2/site/create.json";
    url += "?access_token=";
    url += "e7abe4b20121c821015dc83323fa1a71edb3a4b3";     
    curl = curl_easy_init();   
    if(!curl)
    {
        return 0;
    }
   
	stringstream ss;
	Json::Value value;
	value["task_name"] = Json::Value("site_api");
	value["host"] = Json::Value("www.163.com");
	value["frequency"] = Json::Value("15");
	value["retry"] = Json::Value("3");
	value["task_type"] = Json::Value("ping");
	value["monitors"] = Json::Value("1");
	Json::Value root;
	root.append(value);
	Json::FastWriter fast;
	//ss<<"data: "<<fast.write(root);
	ss<<"data="<<"[{\"task_name\":\"site_api\u6d4b\u8bd5-163\",\"host\":\"www.163.com\",\"frequency\":\"5\","
		<<"\"retry\":\"3\",\"task_type\":\"ping\"}]";
	cout << ss.str()<< endl;

	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_cb);
    curl_easy_setopt(curl, CURLOPT_COPYPOSTFIELDS, ss.str().c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, buf);

    res = curl_easy_perform(curl);
    cout << buf<<endl;
	return 0;
}
